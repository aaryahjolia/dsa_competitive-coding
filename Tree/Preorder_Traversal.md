## Recursive Approach

```
class Solution {
 public:
      vector<int>answer;
      void pre(TreeNode* root){
      if(root==nullptr) return;
        answer.push_back(root->val);
        pre(root->left);
         pre(root->right);
 }
 vector<int> preorderTraversal(TreeNode* root){
     if(root==nullptr)
         return answer;
     pre(root);
         return answer;
 }
 };
```

## Iterative Approach

```
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) 
            return ans;
        stack<TreeNode* >stck;
        stck.push(root);
        while(!st.empty()){
            root=stck.top();
            stck.pop();
            ans.push_back(root->val);
            if(root->right!=NULL)
                stck.push(root->right);
            if(root->left!=NULL)
                stck.push(root->left);
        }
        return ans;
    }
};
```
