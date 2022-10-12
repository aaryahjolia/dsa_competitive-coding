/*Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
*/
class Solution {
public:
    void t(TreeNode* root, int level, map<int, vector<int>> &m) {
        if(root==NULL) return;
        m[level].push_back(root->val);
        t(root->left, level+1, m);
        t(root->right, level+1, m);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        map<int, vector<int>> m;
        t(root, 0, m);
        vector<vector<int>> ans;
        for(int i=0;i<m.size();i++) {
            auto v = m[i];
            if(i&1) reverse(m[i].begin(), m[i].end());
            ans.push_back(m[i]);
        }
        return ans;
    }
};
