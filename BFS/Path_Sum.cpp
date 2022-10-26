/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool ans=false;
    void func(TreeNode* root, int tsum)
    {
        if(root==NULL) return;
        if(root->left==NULL&&root->right==NULL&&(tsum-root->val)==0) ans= true;
        func(root->left,tsum-root->val);
        func(root->right,tsum-root->val);
    }
    
    bool hasPathSum(TreeNode* root, int tsum) {
        func(root,tsum);
        return ans;
    }
};
