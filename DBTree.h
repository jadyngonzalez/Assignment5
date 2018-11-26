#ifndef DBTREE_H
#define DBTREE_H
#include "TreeNode.h"

template <class T>
class DBTree
{
  public:
    DBTree()
    {
      root = NULL;
    };

    ~DBTree()
    {
      //tbd
    };

    void insert(T k)
    {
      TreeNode<T> *node = new TreeNode<T>(k);
      if(root == NULL) //empty
      {
        root = node;
        ++size;
      }
      else
      {
        TreeNode<T> *curr = root;
        TreeNode<T> *parent = NULL;

        //finding insertion point
        while(true)
        {
          parent = curr;
          if(k < curr->key)
          {
            curr = curr->left;
            if(curr == NULL) //found it
            {
              parent->left = node;
              ++size;
              break;
            }
          }
          else if(k > curr->key)
          {
            curr = curr->right;
            if(curr == NULL) //found it
            {
              parent->right = node;
              ++size;
              break;
            }
          }
          else
          {
            break; //key is already in the tree
          }
        }
      }
    };

    bool contains(T k)
    {
      if(root == NULL)//empty tree
      {
        return false;
      }

      //start traversal
      TreeNode<T> *curr = root;
      while(curr->key != k)
      {
        if(k < curr->key)
        {
          curr = curr->left;
        }
        else
        {
          curr = curr->right;
        }
        if(curr == NULL)
        {
          return false; //didnt find it
        }
      }
      return true; //found it
    };

    bool deleteNode(T k)
    {
      if(root == NULL) //empty tree
      {
        return false; //cannot delete
      }

      TreeNode<T> *curr = root;
      TreeNode<T> *parent = root;
      bool isLeft = true;

      while(curr->key != k)
      {
        parent = curr;
        if(k < curr->key)
        {
          isLeft = true;
          curr = curr->left;
        }
        else
        {
          isLeft = false;
          curr = curr->right;
        }
        if(curr == NULL)
        {
          return false; //not found
        }
      }

      if(curr-> == NULL && curr->right == NULL) //no children
      {
        if(curr == root)
        {
          root == NULL;
        }
        else if(isLeft)
        {
          parent->left = NULL;
        }
        else
        {
          parent->right == NULL;
        }
        delete curr;
        --size;
      }
      else if(curr->right == NULL)
      {
        if(curr == root)
        {
          root = curr->left;
        }
        else if(isLeft)
        {
          parent->left = curr->left;
        }
        else
        {
          parent->right = curr->left;
        }
        delete curr;
        --size;
      }
      else if(curr->left == NULL)
      {
        if(curr == root)
        {
          root = curr->right;
        }
        else if(isLeft)
        {
          parent->left = curr->right;
        }
        else
        {
          parent->right = curr->right;
        }
        delete curr;
        --size;
      }
      else
      {
        TreeNode<T> *successor = getSuccessor(curr);
        if(curr == root)
        {
          root = successor;
        }
        else if(isLeft)
        {
          parent->left = successor;
        }
        else
        {
          parent->right = successor;
        }
        successor->left = curr->left;
        delete curr;
        --size;
      }
      return true;
    };

    bool isEmpty()
    {
      return size == 0;
    };

    int getSize()
    {
      return size;
    };

    string printTree(int traversal)
    {
      return printTree(root, traversal);
    };

    string printTree(TreeNode<T> *node, int type)
    {
      ostringstream print;
      switch(type)
      {
        case 1: //inorder traversal
        {
          if(node == NULL)
          {
            return print.str();
          }
          print << printTree(node->left, type);
          print << node->key << endl;
          print << printTree(node->right, type);
          break;
        }
        case 2://preorder traversal
        {
          if(node == NULL)
          {
            return print.str();
          }
          print << node->key << endl;
          print << printTree(node->left, type);
          print << printTree(node->right, type);
          break;
        }
        case 3://postorder traversal
        {
          if(node == NULL)
          {
            return print.str();
          }
          print << printTree(node->left, type);
          print << printTree(node->right, type);
          print << node->key << endl;
          break;
        }
      }
      return print.str();
    };

    TreeNode<T> *getSuccessor(TreeNode<T> *d)
    {
      TreeNode<T> *sparent = d;
      TreeNode<T> *successor = d;
      TreeNode<T> *curr = d->right;

      while(curr != NULL)
      {
        sparent = successor;
        successor = curr;
        curr = curr->left;
      }

      if(successor != d->right)
      {
        sparent->left = successor->right;
        successor->right = d->right;
      }
      return successor;
    };

    TreeNode<T> *getKey(unsigned int i)
    {
      TreeNode<T> **arr = new TreeNode<T>*[getSize()];
      ArrInsert(root, arr, 0);
      return arr[i];
    };

    TreeNode<T> *find(T k)
    {
      if(root == NULL)
      {
        return NULL;
      }
      TreeNode<T> *curr = root;
      while(curr->key != k)
      {
        if(k < curr->key)
        {
          curr = curr->left;
        }
        else
        {
          curr = curr->right;
        }
        if(curr == NULL)
        {
          return NULL;
        }
      }
      return curr;
    };

  private:
    TreeNode<T> *root;
    unsigned int size;

    TreeNode<T>* getRoot()
    {
      return root;
    };

    void destruct(TreeNode<T> *node)
    {
      if(node == NULL)
      {
        cerr << "Empty tree.";
      }
      else if(node->left != NULL)
      {
        destruct(node->left);
      }
      else if(node->right != NULL)
      {
        destruct(node->right);
      }
      else
      {
        deleteNode(node->key);
      }
      root = NULL;
    };

    int ArrInsert(TreeNode<T> *node, TreeNode<T>* arr[], int i)
    {
      if(node == NULL)
      {
        return i;
      }

      arr[i] = node;
      i++;
      if(node->left != NULL)
      {
        i = ArrInsert(node->left, arr, i);
      }
      if(node->right != NULL)
      {
        i = ArrInsert(node->right, arr, i);
      }
      return i;
    }
};
