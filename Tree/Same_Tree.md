# Same Tree :
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

### Solution Function :

```cpp
  class Solution {
  public:
      bool isSameTree(TreeNode* p, TreeNode* q) {
          if(p==nullptr && q==nullptr) return true;
          if(p==nullptr || q==nullptr) return false;
          if(q->val!=p->val) return false;
          return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
      }
  };
  ```
  
  ### Complete Program :
  
  ```cpp
  #include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = this->right = nullptr;
    }
};
bool isSameTree(TreeNode* p, TreeNode* q) {
          if(p==nullptr && q==nullptr) return true;
          if(p==nullptr || q==nullptr) return false;
          if(q->val!=p->val) return false;
          return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
      }
int main()
{
    // construct the first tree
    TreeNode* x = nullptr;

    x = new TreeNode(1);
    x->left = new TreeNode(2);
    x->right = new TreeNode(3);
    x->right->right = new TreeNode(6);

    // construct the second tree
    TreeNode* y = nullptr;

    y = new TreeNode(1);
    y->left = new TreeNode(2);
    y->right = new TreeNode(3);
    y->right->right = new TreeNode(6);

    if (isSameTree(x, y)) {
        cout << "Given binary trees are Same";
    }
    else {
        cout << "Given binary trees are not Same";
    }

    return 0;
}

  ```
