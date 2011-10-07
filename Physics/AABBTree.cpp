#include <Physics/AABBTree.h>

// AABBTreeNode
AABBTreeNode::AABBTreeNode():
    _parent(0), _data(0), _height(0), _child0(0), _child1(0)
{}

AABBTreeNode::~AABBTreeNode() {
    if(_child0) { delete _child0; }
    if(_child1) { delete _child1; }
}

bool AABBTreeNode::isLeaf() {
    return _child0 == 0;
}

void AABBTreeNode::clearChildren() {
    _child0 = 0;
    _child1 = 0;
}

void AABBTreeNode::recomputeCachedValues() {
    _bounds = AABB::Combine(_child0->_bounds, _child1->_bounds);
    _height = std::max(_child0->_height, _child1->_height);
}

// AABBTree
AABBTree::AABBTree():
    _root(0)
{
    _nodePool = new ResourcePool<AABBTreeNode>(32);
}

AABBTree::~AABBTree() {
    if(_root) { delete _root; }
    if(_nodePool) { delete _nodePool; }
}

void AABBTree::insert(const AABB& bounds, void *data) {
    AABBTreeNode *leaf = _nodePool->allocate();

    leaf->_bounds = bounds;
    leaf->_data = data;
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
    AABBTreeNode *current = _root;
    while(!current->isLeaf()) {
        // Get the perimeter of the combined AABBs of the leaf node and the current node
        float combinedPerim = AABB::Combine(bounds, current->_bounds).getPerimeter();
    
        // Compute the cost of creating a new parent node to contain the current node and the new leaf
        float cost = 2 * combinedPerim;
        
        // Compute the minimum cost of traversing further down in the tree
        float inheritCost = 2 * (combinedPerim - leafPerim);
        
        // Compute the cost of traversing to each child
        float combinedPerim0 = AABB::Combine(bounds, current->_child0->_bounds).getPerimeter(),
              combinedPerim1 = AABB::Combine(bounds, current->_child1->_bounds).getPerimeter();

        float child0Cost;
        if(current->_child0->isLeaf()) {
            child0Cost = combinedPerim0 + inheritCost;
        } else {
            child0Cost = (combinedPerim0 - current->_child0->_bounds.getPerimeter()) + inheritCost;
        }

        float child1Cost;
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
    AABBTreeNode *oldParent, *newParent, *sibling;

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
}

void AABBTree::balance(AABBTreeNode* node) {
    ASSERT(node);
    
    if(node->isLeaf() || node->_height < 2) {
        return;
    }
    
    ASSERT(node->_child0);
    ASSERT(node->_child1);
    
    unsigned int balance = node->_child1->_height - node->_child0->_height;
    if(balance > 1) {
        // Rotate child1 upward
        rotateUp(node->_child1);
    } else if(balance < -1) {
        // Rotate child0 upward
        rotateUp(node->_child0);
    }
}

void AABBTree::rotateUp(AABBTreeNode *node) {
    // Swap the node with its parent   
    AABBTreeNode *oldParent = node->_parent,
                 *child0 = node->_child0,
                 *child1 = node->_child1;

    ASSERT(child0);
    ASSERT(child1);

    node->_parent = oldParent->_parent;
    node->_child0 = oldParent;
    oldParent->_parent = node;
    
    if(node->_parent) {
        if(node->_parent->_child0 == oldParent) {
            node->_parent->_child0 = node;
        } else {
            ASSERT(node->_parent->_child1 == oldParent);
            node->_parent->_child1 = node;
        }
    } else {
        _root = node;
    }

    if(child0->_height > child1->_height) {
        node->_child1 = child0;
        if(oldParent->_child0 == node) {
            oldParent->_child0 = child1;
        } else {
            ASSERT(oldParent->_child1 == node);
            oldParent->_child1 = child1;
        }
        child1->_parent = oldParent;

        node->recomputeCachedValues();
        oldParent->recomputeCachedValues();
        
    } else {
    }
}