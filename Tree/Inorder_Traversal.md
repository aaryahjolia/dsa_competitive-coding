## Recursive Approach


```
class Solution {
public:
    void dfs(TreeNode* root, vector<int> &answer){
        if(root==NULL) return;
        dfs(root->left, answer);
        answer.push_back(root->val);
        dfs(root->right, answer);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        dfs(root, answer);
        return answer;
    }
};
```

## Iterative Approach


```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> stck;
        while(root or !stck.empty()){
            while (root) {
                stck.push(root);
                root = root->left;
            }
            root = stck.top();
            stck.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};
```
