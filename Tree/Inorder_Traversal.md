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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> answer(101);
        int position = 0, stackPosition = 0;
        TreeNode *curr = root, *stck[101];
        // proceed as long as curr and stck are not empty
        while (curr || stackPosition) {
            // push in the left child till curr has one
            while (curr) {
                stck[stackPosition++] = curr;
                curr = curr->left;
            }
            // give a non NULL value to curr and pop it from the stack
            curr = stck[--stackPosition];
            // use curr (inorder)
            answer[position++] = curr->val;
            // move to the right
            curr = curr->right;
        }
        answer.resize(position);
        return answer;
    }
};
```
