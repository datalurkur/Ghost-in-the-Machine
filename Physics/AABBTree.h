#ifndef AABBTREE_H
#define AABBTREE_H

#include <Base/Base.h>
#include <Base/ResourcePool.h>
#include <Physics/AABB.h>

class AABBTree;

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

    void *_data;

    friend class AABBTree;
};

class AABBTree {
public:
    AABBTree();
    ~AABBTree();

    AABBTreeNode* insert(const AABB& bounds, void* data);
	void remove(AABBTreeNode* node);

protected:
    void balance(AABBTreeNode* node);

	void validate();
	void validate(AABBTreeNode* node);

private:
    AABBTreeNode *_root;
    ResourcePool<AABBTreeNode> *_nodePool;
};

#endif
