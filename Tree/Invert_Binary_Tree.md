# Invert Binary Tree 

## Problem Statement :
Given the root of a binary tree, invert the tree, and return its root.

## Approach :
This is a classic tree problem that lends itself nicely to a recursive solution.
* The inverse of an empty tree is the empty tree. (base case)
* The inverse of a tree with root r, and subtrees right and left, is a tree with root r, whose right subtree is the inverse of left, and whose left subtree is the inverse of right.

## Solution Function :

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        // Get Left Side of the Tree
        TreeNode *lft = invertTree(root->left);
        // Get Right Side of the Tree
        TreeNode *rght = invertTree(root->right);
        // Put Right Side to Left Side of the Tree
        root->left = rght;
        // Put Left Side to Right Side of the Tree
        root->right = lft;
        return root;
    }
};
```
## Explanation :
The invertTree function in the above code samples first determines whether the tree is empty. If not, it switches the root's two children and then recursively swaps the two sub-trees until the root has some value. The recursive calls are terminated when the root is NULL.
