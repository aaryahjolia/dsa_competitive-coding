# Inorder Traversal
In this traversal approach, the left subtree is visited first, then the root, and finally the right subtree.

## Recursive Approach :
### Algorithm :
1. Call Inorder to traverse the left subtree
2. Go to the root.
3. Call Inorder to traverse the right subtree

``` cpp
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

## Iterative Approach :
### Algorithm :
1) Begin by making an empty stack S.
2) Make the current node root. 
3) Move the current node to S and set current = current->left until current is NULL.
4) If current is NULL and the stack is not empty, 
* Remove the top item from the stack.
* Print the popped item by setting current to popped item->right.
* Proceed to step 3.
5) If current is NULL and the stack is empty, we are finished.

```cpp
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
## Time and Space Complexity :

For both the cases
* Time Complexity: O(n)  
* Space Complexity: O(n)
