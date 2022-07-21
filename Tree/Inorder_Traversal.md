## Recursive Approach


```
class Solution {
    vector<int> res;
    int position = 0;
    void dfs(TreeNode *root) {
        // recursive call inorder: left
        if (root->left) dfs(root->left);
        // write the value into res
        res[position++] = root->val;
        // recursive call inorder: right
        if (root->right) dfs(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode *root) {
        res.resize(101);
        if (root) dfs(root);
        res.resize(position);
        return res;
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
