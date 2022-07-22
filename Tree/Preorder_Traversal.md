# Preorder Traversal :
The root node is visited first, followed by the left subtree, and ultimately the right subtree in this traversal strategy.

## Recursive Approach :
### Algorithm :
1. Go to the root.
2. Call Preorder to traverse the left subtree
3. Call Preorder to traverse the right subtree

```cpp
void preorder(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
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
void preorderIterative(Node* root)
{
        if(root==NULL) 
            return;
        stack<TreeNode* >stck;
        stck.push(root);
        while(!stck.empty()){
            root=stck.top();
            stck.pop();
            cout << root->data << " ";
            if(root->right!=NULL)
                stck.push(root->right);
            if(root->left!=NULL)
                stck.push(root->left);
        }
    }
}
```
## Time and Space Complexity :

For both the cases
* Time Complexity: O(n)  
* Space Complexity: O(n)
