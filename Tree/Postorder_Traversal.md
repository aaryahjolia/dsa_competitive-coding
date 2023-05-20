# Postorder Traversal (DFS)
This traversal method visits the root node last, hence the name. We go through the left subtree first, then the right subtree, and lastly the root node.  
(Left, Right, Root)

## Example

![Binary_Tree](https://user-images.githubusercontent.com/82600388/184525938-cba5ca0d-8d65-41da-9447-b948c0091a34.png)

Postorder Traversal : 
```
1 4 7 6 3 13 14 10 8
```

## Recursive Approach :
### Algorithm :
1. Call Postorder to traverse the left subtree
2. Call Postorder to traverse the right subtree
3. Print the root.

```cpp
void postorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
```
## Time and Space Complexity :

For both the cases,
* Time Complexity: O(n)  
* Space Complexity: O(n)

### Run Code

https://ide.geeksforgeeks.org/online-cpp-compiler/a8f4fa9d-d164-4075-b7f7-0c32f042c5d0

## Iterative Approach :
### Algorithm :
1. Begin with an empty stack.
2. Perform the following when root is not NULL.
* Push root's right child to the stack, followed by root.
* Make root the left child of root.

3. Select an item from the stack and make it the root.
* Remove the right child from the stack, push the root back, and set root as the root's right child if the popped item has a right child and the right child is at the top of the stack.
* Alternatively, output root's data and set root to NULL.

4. Steps 2 and 3 must be repeated as long as the stack is not empty.

```cpp
class Solution {
public:
    vector<int> postorderTraversal(Node* root) {
        if (!root) return {};
        vector<int> ans;
        stack<Node*> stck;
        stck.push(root);
        while (!stck.empty()){
            Node* node = stck.top();
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
## Time and Space Complexity :

For both the cases,
* Time Complexity: O(n)  
* Space Complexity: O(n)

### Run Code

https://ide.geeksforgeeks.org/online-cpp-compiler/b05d8ddc-19e0-44fa-a11f-12d6bee03564

### Next Step

[Preorder Traversal](./Preorder_Traversal.md)
