# Preorder Traversal (DFS)
The root node is visited first, followed by the left subtree, and ultimately the right subtree in this traversal strategy.
(Root, Left, Right)

## Example

![Binary_Tree](https://user-images.githubusercontent.com/82600388/184525938-cba5ca0d-8d65-41da-9447-b948c0091a34.png)

Preorder Traversal : 
```
8 3 1 6 4 7 10 14 13
```

## Recursive Approach :
### Algorithm :
1. Print the root.
2. Call Preorder to traverse the left subtree
3. Call Preorder to traverse the right subtree

```cpp
void preorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
```
## Time and Space Complexity :

For both the cases,
* Time Complexity: O(n)  
* Space Complexity: O(n)

### Run Code

https://ide.geeksforgeeks.org/online-cpp-compiler/251b1a51-5390-4b9b-bcf3-dd5f27879858

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
    stack<Node* >stck;
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
```
## Time and Space Complexity :

For both the cases
* Time Complexity: O(n)  
* Space Complexity: O(n)

### Run Code

https://ide.geeksforgeeks.org/online-cpp-compiler/ee44087a-933a-454e-ae91-e53a1e2328b9

### Next Step

[BFS Traversal](./BFS_Traversal.md)
