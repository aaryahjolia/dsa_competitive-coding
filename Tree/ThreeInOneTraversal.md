# Binary Tree-DSA

In data structures and algorithms (DSA), a tree is a hierarchical data structure consisting of nodes connected by edges. Each node has a parent node and zero or more child nodes. Trees are widely used in computer science for organizing and structuring data efficiently. They are important because they provide a way to represent relationships between data entities, facilitate efficient search, insertion, deletion, and traversal operations, and are used in various applications such as file systems, database indexing, compiler design, and more.  

## Explanation of code

### Struct Definition (struct node):

This defines a structure called node, which represents a node in a binary tree. Each node contains an integer data and pointers to its left and right child nodes.

### Function create():

1. This function is used to create a binary tree recursively.
2. It prompts the user to enter data for each node.
3. If the entered data is -1, it returns NULL, indicating the end of the current branch.
4. Otherwise, it creates a new node, assigns the entered data to it, and prompts the user to enter data for its left and right children recursively.

### Traversal Functions (preorder(), postorder(), inorder()):

1. These functions perform preorder, postorder, and inorder traversals of the binary tree, respectively.
2. Preorder traversal visits the root node first, then its left subtree, and finally its right subtree.
3. Postorder traversal visits the left subtree, then the right subtree, and finally the root node.
4. Inorder traversal visits the left subtree, then the root node, and finally the right subtree.
5.Each function recursively traverses the tree, printing the data of each node in the specified order.

### main() Function:

1. This function serves as the entry point of the program.
2. It creates the binary tree by calling the create() function.
3. Then, it traverses the tree using the preorder(), postorder(), and inorder() functions, printing the sequence of traversal for each.