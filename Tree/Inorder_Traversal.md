# Inorder Traversal (DFS)
In this traversal approach, the left subtree is visited first, then the root, and finally the right subtree.  
(Left, Root, Right)

## Example

![Binary_Tree](https://user-images.githubusercontent.com/82600388/184525938-cba5ca0d-8d65-41da-9447-b948c0091a34.png)

Inorder Traversal : 
```
1 3 4 6 7 8 10 13 14
```

## Recursive Approach :
### Algorithm :
1. Call Inorder to traverse the left subtree
2. Print the root
3. Call Inorder to traverse the right subtree

```cpp
void inorder(Node* root)
{    
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
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
1) If current is NULL and the stack is empty, we are finished.

```cpp
class Solution {
public:
    vector<int> inorderTraversal(Node* root) {
        stack<Node*> stck;
        while(root || !stck.empty()){
            while (root) {
                stck.push(root);
                root = root->left;
            }
            root = stck.top();
            stck.pop();
            cout<<root->data<<" ";
            root = root->right;
        }
    }
};
```
## Time and Space Complexity :

For both the cases,
* Time Complexity: O(n)  
* Space Complexity: O(n)

### Next Step

[Postorder Traversal](./Postorder_Traversal.md)