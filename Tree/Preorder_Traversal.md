# Preorder Traversal :
The root node is visited first, followed by the left subtree, and ultimately the right subtree in this traversal strategy.

## Recursive Approach :
### Algorithm :
1. Go to the root.
2. Call Preorder to traverse the left subtree
3. Call Preorder to traverse the right subtree

```cpp
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
### Algorithm :
Make an empty stack and add the root node to it.
While is not empty, perform the following.
1. Pop a stack item and print it.
2. Stack by pushing the right child of a popped item.
3. Stack the left offspring of a popped item.
4. To ensure that the left subtree is processed first, the right child is pushed before the left child.

```cpp
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
## Time and Space Complexity :

For both the cases
* Time Complexity: O(n)  
* Space Complexity: O(n)
