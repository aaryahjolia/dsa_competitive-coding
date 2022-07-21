## Recursive Approach


```
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& answer){
        if(root==NULL) return;
        dfs(root->left, answer);
        dfs(root->right, answer);
        answer.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        stack<TreeNode*> stck;
        stck.push(root);
        while (!stck.empty()){
            TreeNode* node = stck.top();
            if (node->left){
                stck.push(node->left);
                node->left = nullptr;
            }
            else if (node->right){
                stck.push(node->right);
                node->right = nullptr;
            }
            else{
                ans.push_back(node->val);
                stck.pop();
            }
        }
        return ans;
    }
};
```
