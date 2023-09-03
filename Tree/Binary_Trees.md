## Types of Binary Trees

1. Full BT : Either 0 or 2 Childrens
2. Complete BT : All levels are completely filled (except last level) and Last level has all nodes as left as posible.
3. Perfect BT : All Leaf nodes are at same level.
4. Balanced BT : Height of tree is at max log(n) where n is number of nodes.
5. Degenerate BT : Every node should have a single child only (Just as a Linked list).

## Initialise a Binary Tree in C++

```cpp
class Node {
public:
    int data;    // Data value of the node
    Node* left;  // Pointer to the left child node
    Node* right; // Pointer to the right child node

    // Constructor
    Node(int value) {
        this->data = value;
        this->left = this->right = NULL;
    }
};
```
## Time and Space Complexity :

For both the cases
* Time Complexity: O(1)  
* Space Complexity: O(1)

### Run Code

https://ide.geeksforgeeks.org/9721e25e-94d6-4f3a-89be-133386753efc

### Next Step

[Inorder Traversal](./Inorder_Traversal.md)
