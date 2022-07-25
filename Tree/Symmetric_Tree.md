# Symmetric Tree

## Problem
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

## Approach
1. If left and right both are null return true.
2. If anyone of them is null return false. 
3. Check if current left and current right value is equal.
4. Give recursive call and check left node's left and right node's right.
5. Give recursive call and check left node's right and right node's left.

## Solution Function
```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true; //Tree is empty
        return dfs(root->left, root->right); //Pass left subtree and right subtree
    }
    bool dfs(TreeNode* l, TreeNode* r) {

        if(!l ^ !r) return 0; //one of them is Not NULL
        if(!l && !r) return 1; //left & right node is NULL
        if(l->val != r->val) return 0;
        //comparing left subtree's left child with right subtree's right child
        //comparing left subtree's right child with right subtree's left child
        return dfs(l->left, r->right) && dfs(l->right, r->left);
    }
};
```
