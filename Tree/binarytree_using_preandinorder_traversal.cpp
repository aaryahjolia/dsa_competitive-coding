//Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, 
//construct and return the binary tree.

#include <bits/stdc++.h>
using namespace std;

// Defining a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preorderStart, int preorderEnd, int inorderStart, int inorderEnd, unordered_map<int, int>& inorderMap) {
    if (preorderStart > preorderEnd || inorderStart > inorderEnd) {
        return nullptr;
    }

    int rootVal = preorder[preorderStart];
    TreeNode* root = new TreeNode(rootVal);

    int rootIndex = inorderMap[rootVal];
    int leftSubtreeSize = rootIndex - inorderStart;

    root->left = buildTreeHelper(preorder, inorder, preorderStart + 1, preorderStart + leftSubtreeSize,
                                 inorderStart, rootIndex - 1, inorderMap);
    root->right = buildTreeHelper(preorder, inorder, preorderStart + leftSubtreeSize + 1, preorderEnd,
                                  rootIndex + 1, inorderEnd, inorderMap);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();

    // Create a map to store the indices of inorder elements
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < n; i++) {
        inorderMap[inorder[i]] = i;
    }

    return buildTreeHelper(preorder, inorder, 0, n - 1, 0, n - 1, inorderMap);
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(preorder, inorder);

    cout << "Inorder traversal of the constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
