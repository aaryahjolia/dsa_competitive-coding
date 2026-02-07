## Types of Binary Trees

1. Full BT : Either 0 or 2 Childrens
2. Complete BT : All levels are completely filled (except last level) and Last level has all nodes as left as posible.
3. Perfect BT : All Leaf nodes are at same level.
4. Balanced BT : Height of tree is at max log(n) where n is number of nodes.
5. Degenerate BT : Every node should have a single child only (Just as a Linked list).

## Initialise a Binary Tree in C++

```cpp
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data = value;
        this->left = this->right = NULL;
    }
};
```

### Next Step

[Inorder Traversal](./Inorder_Traversal.md)