#include <Physics/AABBTree.h>

// AABBTreeNode
AABBTreeNode::AABBTreeNode():
    _parent(0)
{
    _children[0] = 0;
    _children[1] = 0;
}

AABBTreeNode::~AABBTreeNode() {
    if(_children[0]) { delete _children[0]; }
    if(_children[1]) { delete _children[1]; }
}

bool AABBTreeNode::isLeaf() {
    return (_children[0] == 0 && _children[1] == 0);
}

void AABBTreeNode::clearChildren() {
    _children[0] = 0;
    _children[1] = 0;
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
