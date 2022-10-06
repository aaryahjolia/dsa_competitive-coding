/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. 
There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
Return the vertical order traversal of the binary tree.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            root=q.front().first;
            int x=q.front().second.first,y=q.front().second.second;q.pop();
            mp[x][y].insert(root->val);
            if(root->left) q.push({root->left,{x-1,y+1}});
            if(root->right) q.push({root->right,{x+1,y+1}});
        }
        for(auto x:mp){
            vector<int> col;
            for(auto y:x.second){
                for(auto ele:y.second) col.push_back(ele);
            }
            ans.push_back(col);
        }
        return ans;
    }
};

