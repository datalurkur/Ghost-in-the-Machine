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

protected:
    AABB _bounds;

    AABBTreeNode* _parent;
    AABBTreeNode* _children[2];

    friend class AABBTree;
};

class AABBTree {
public:
    AABBTree();
    ~AABBTree();

private:
    AABBTreeNode *_root;
    ResourcePool<AABBTreeNode> *_nodePool;
};

#endif
