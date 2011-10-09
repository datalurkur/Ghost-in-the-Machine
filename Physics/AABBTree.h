#ifndef AABBTREE_H
#define AABBTREE_H

#include <Base/Base.h>
#include <Base/ResourcePool.h>
#include <Physics/AABB.h>

template <typename T>
class AABBTree;

template <typename T>
class AABBTreeNode {
public:
    AABBTreeNode();
    ~AABBTreeNode();

    bool isLeaf();
    void clearChildren();
    void recomputeCachedValues();

protected:
    AABB _bounds;
    unsigned int _height;

    AABBTreeNode *_parent;
    AABBTreeNode *_child0, *_child1;

    T *_data;

    friend class AABBTree<T>;
};

template <typename T>
class AABBTree {
public:
    AABBTree();
    ~AABBTree();

    void insert(T* t, const AABB& bounds);
	void remove(T* t);

	void query(const AABB& bounds, std::list<T*> &intersections);

protected:
    void balance(AABBTreeNode<T>* node);

	void validate();
	void validate(AABBTreeNode<T>* node);

private:
    AABBTreeNode<T>* _root;
    ResourcePool<AABBTreeNode<T>> *_nodePool;

	std::map<T*, AABBTreeNode<T>*> _nodeMap;
};

// AABBTreeNode
template <typename T>
AABBTreeNode<T>::AABBTreeNode():
    _parent(0), _data(0), _height(0), _child0(0), _child1(0)
{}

template <typename T>
AABBTreeNode<T>::~AABBTreeNode() {
    if(_child0) { delete _child0; }
    if(_child1) { delete _child1; }
}

template <typename T>
bool AABBTreeNode<T>::isLeaf() {
    return _child0 == 0;
}

template <typename T>
void AABBTreeNode<T>::clearChildren() {
    _child0 = 0;
    _child1 = 0;
}

template <typename T>
void AABBTreeNode<T>::recomputeCachedValues() {
    _bounds = AABB::Combine(_child0->_bounds, _child1->_bounds);
    _height = 1 + max(_child0->_height, _child1->_height);
}

// AABBTree
template <typename T>
AABBTree<T>::AABBTree():
    _root(0)
{
    _nodePool = new ResourcePool<AABBTreeNode<PhysicsBody>>(32);
}

template <typename T>
AABBTree<T>::~AABBTree() {
    if(_root) { delete _root; }
    if(_nodePool) { delete _nodePool; }
}

template <typename T>
void AABBTree<T>::insert(T *t, const AABB& bounds) {
    AABBTreeNode<T> *leaf, *current, *oldParent, *newParent, *sibling;
					
	leaf = _nodePool->allocate();
	ASSERT(_nodeMap.find(t) == _nodeMap.end());
	_nodeMap[t] = leaf;

    leaf->_bounds = bounds;
    leaf->_data = t;
    leaf->clearChildren();

    // Do we already have a root node?
    if(_root == 0) {
        leaf->_parent = 0;
        _root = leaf;
        return;
    }
    
    // Get the perimeter of the leaf node
    float leafPerim = bounds.getPerimeter();

    // Begin traversing the tree
    current = _root;
    while(!current->isLeaf()) {
		float cost, inheritCost, child0Cost, child1Cost,
			  combinedPerim, combinedPerim0, combinedPerim1;

        // Get the perimeter of the combined AABBs of the leaf node and the current node
        combinedPerim = AABB::Combine(bounds, current->_bounds).getPerimeter();
    
        // Compute the cost of creating a new parent node to contain the current node and the new leaf
        cost = 2 * combinedPerim;
        
        // Compute the minimum cost of traversing further down in the tree
        inheritCost = 2 * (combinedPerim - leafPerim);
        
        // Compute the cost of traversing to each child
        combinedPerim0 = AABB::Combine(bounds, current->_child0->_bounds).getPerimeter();
        combinedPerim1 = AABB::Combine(bounds, current->_child1->_bounds).getPerimeter();

        if(current->_child0->isLeaf()) {
            child0Cost = combinedPerim0 + inheritCost;
        } else {
            child0Cost = (combinedPerim0 - current->_child0->_bounds.getPerimeter()) + inheritCost;
        }

        if(current->_child1->isLeaf()) {
            child1Cost = combinedPerim1 + inheritCost;
        } else {
            child1Cost = (combinedPerim1 - current->_child1->_bounds.getPerimeter()) + inheritCost;
        }
        
        // Either break here or continue traversing, based on the lowest cost
        if(cost < child0Cost && cost < child1Cost) {
            break;
        } else if(child0Cost < child1Cost) {
            current = current->_child0;
        } else {
            current = current->_child1;
        }
    }
    
    // Insert a new parent node here, making the current node and the leaf node siblings
    oldParent = current->_parent;
    sibling = current;

    newParent = _nodePool->allocate();
    newParent->_parent = oldParent;
    newParent->_data = 0;
    newParent->_bounds = AABB::Combine(leaf->_bounds, sibling->_bounds);
    newParent->_height = sibling->_height + 1;

    // If the new sibling was not the root, update its old parent's children
    if(oldParent) {
        if(oldParent->_child0 == sibling) {
            oldParent->_child0 = newParent;
        } else {
            oldParent->_child1 = newParent;
        }
    } else {
        _root = newParent;
    }

    // Set the parent's child pointers
    newParent->_child0 = sibling;
    newParent->_child1 = leaf;

    // Set the children's parent pointers
    sibling->_parent = newParent;
    leaf->_parent = newParent;

    current = newParent;
    while(current != 0) {
        // Balance the current node if it has become imbalanced
        balance(current);

        ASSERT(current->_child0);
        ASSERT(current->_child1);
        current->recomputeCachedValues();
        
        current = current->_parent;
    }

	validate();
}

template <typename T>
void AABBTree<T>::remove(T *t) {
	AABBTreeNode<T> *parent, *superParent,
				 *sibling, *current, *node;

	ASSERT(_nodeMap.find(t) != _nodeMap.end());
	node = _nodeMap[t];

	if(node == _root) {
		_root = 0;
		return;
	}

	parent = node->_parent;
	superParent = parent->_parent;
	if(parent->_child0 == node) {
		sibling = parent->_child1;
	} else {
		ASSERT(parent->_child1 == node);
		sibling = parent->_child0;
	}

	if(superParent) {
		// Connect the sibling to the superParent
		if(superParent->_child0 == parent) {
			superParent->_child0 = sibling;
		} else {
			ASSERT(superParent->_child1 == parent);
			superParent->_child1 = sibling;
		}
		sibling->_parent = superParent;

		current = superParent;
		while(current) {
			balance(current);
			current->recomputeCachedValues();
			current = current->_parent;
		}
	} else {
		// Make the sibling the new root node
		_root = sibling;
		sibling->_parent = 0;
	}

	// Do away with the redundant parent
	_nodePool->free(parent);

	validate();
}

template <typename T>
void AABBTree<T>::query(const AABB& bounds, std::list<T*> &intersections) {
	std::stack<AABBTreeNode<T>*> nodeStack;
	AABBTreeNode<T> *current;

	nodeStack.push(_root);
	while(!nodeStack.empty()) {
		current = nodeStack.top();
		nodeStack.pop();

		if(current->_bounds.overlaps(bounds)) {
			if(current->isLeaf()) {
				intersections.push_back(current->_data);
			} else {
				nodeStack.push(current->_child0);
				nodeStack.push(current->_child1);
			}
		}
	}
}

template <typename T>
void AABBTree<T>::balance(AABBTreeNode<T>* node) {
    ASSERT(node);
    
    if(node->isLeaf() || node->_height < 2) {
        return;
    }
   
	AABBTreeNode<T> *child0 = node->_child0,
				    *child1 = node->_child1,
				    *subchild0, *subchild1, *superParent;
    ASSERT(child0);
    ASSERT(child1);
    
    unsigned int balance = child1->_height - child0->_height;
    if(balance > 1) {
		// Rotate child1 upward
		subchild0 = child1->_child0;
		subchild1 = child1->_child1;
		superParent = node->_parent;

		// Swap position of node and child1
		child1->_child1 = node;
		child1->_parent = superParent;
		node->_parent = child1;

		// Set node's old parent's child pointer (or set child1 as the new root if node was the root)
		if(superParent) {
			if(superParent->_child0 == node) {
				superParent->_child0 = child1;
			} else {
				ASSERT(superParent->_child1 == node);
				superParent->_child1 = child1;
			}
		} else {
			_root = child1;
		}

		// Rotate the subchildren in properly
		if(subchild0->_height > subchild1->_height) {
			child1->_child1 = subchild0;
			node->_child1 = subchild1;
			subchild1->_parent = node;
		} else {
			child1->_child1 = subchild1;
			node->_child1 = subchild0;
			subchild0->_parent = node;
		}

		// Recompute any dependent values that have changed
		child1->recomputeCachedValues();
		node->recomputeCachedValues();
    } else if(balance < -1) {
        // Rotate child0 upward
		subchild0 = child1->_child0;
		subchild1 = child1->_child1;
		superParent = node->_parent;

		// Swap position of node and child1
		child0->_child0 = node;
		child0->_parent = superParent;
		node->_parent = child0;

		// Set node's old parent's child pointer (or set child1 as the new root if node was the root)
		if(superParent) {
			if(superParent->_child0 == node) {
				superParent->_child0 = child0;
			} else {
				ASSERT(superParent->_child1 == node);
				superParent->_child1 = child0;
			}
		} else {
			_root = child0;
		}

		// Rotate the subchildren in properly
		if(subchild0->_height > subchild1->_height) {
			child0->_child1 = subchild0;
			node->_child0 = subchild1;
			subchild1->_parent = node;
		} else {
			child0->_child1 = subchild1;
			node->_child0 = subchild0;
			subchild0->_parent = node;
		}

		// Recompute any dependent values that have changed
		child1->recomputeCachedValues();
		node->recomputeCachedValues();
    }
}

template <typename T>
void AABBTree<T>::validate() {
	validate(_root);
}

template <typename T>
void AABBTree<T>::validate(AABBTreeNode<T> *node) {
	if(!node) { return; }

	if(node->isLeaf()) {
		ASSERT(node->_height == 0);
		ASSERT(node->_child0 == 0);
		ASSERT(node->_child1 == 0);
	} else {
		ASSERT(node->_child0->_parent == node);
		ASSERT(node->_child1->_parent == node);

		ASSERT(node->_height == max(node->_child0->_height, node->_child1->_height)+1);
		ASSERT(node->_bounds == AABB::Combine(node->_child0->_bounds, node->_child1->_bounds));
	}

	if(_root == node) {
		ASSERT(node->_parent == 0);
	}

	validate(node->_child0);
	validate(node->_child1);
}

#endif
