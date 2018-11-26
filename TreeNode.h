#ifndef TREENODE_H
#define TREENODE_H

template <class T>
class TreeNoode
{
  public:
    TreeNode()
    {
      key = NULL;
      left = NULL;
      right = NULL;
    };

    TreeNode(T k)
    {
      key = k;
      left = NULL;
      right = NULL;
    };

    ~TreeNode()
    {

    };

    T key;
    TreeNode *left;
    TreeNode *right;
};
#endif
