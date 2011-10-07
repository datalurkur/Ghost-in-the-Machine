#ifndef AABBTREE_H
#define AABBTREE_H

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

    void insert(const AABB& bounds, void* data);

protected:
    void balance(AABBTreeNode* node);
    void rotateUp(AABBTreeNode* node);

private:
    AABBTreeNode *_root;
    ResourcePool<AABBTreeNode> *_nodePool;
};

#endif
