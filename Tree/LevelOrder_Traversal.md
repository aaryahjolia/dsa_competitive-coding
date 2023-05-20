# Level Order Traversal in Tree
This traversal is used in order to move level-wise in a given binary tree.

**Example**: <br>
![image](https://github.com/Ashutosh0120/dsa_competitive-coding-GSSOC-2023/assets/24804042/0b7d6295-b119-4481-a611-bf5d1d6b1e28) 
<br><br>
**Output**: {1,2,3,4,5,6,7}
## Idea:

1. Take the root node, and push it into queue.
2. Initialize a vector **levelorder**.
3. Run a while loop, which will run until the queue becomes empty.
4. At each iteration of the while loop, visit the current node, remove it from queue and push it into **levelorder** vector.
5. Visit the current node->left child, if it is not NULL, push into queue.
6. Visit the current node->right child, if it is not NULL, push into queue.

## Code:
```cpp
vector<vector<int>> levelorder(Node* root)
{
    vector<int> levelorder;   // Create levelorder vector
    if (root == nullptr) {    // If root is NULL, means Tree is Empty
        return levelorder;
    }
    queue<TreeNode*> q;   // Queue
    q.push(root);   //Push the rootnode

    while(!q.empty()) {
        TreeNode *current= q.front();   //Select the current node
        q.pop();  //Remove from queue
        if(current->left != NULL) q.push(current->left);   //Check left child
        if(current->right != NULL)  q.push(current->right);   //Check right child
        levelorder.push_back(temp->val);   // Push the current node into levelorder 
    }
    return levelorder;   //final ans
}
```
## Complexity
1) Time: O(N) 
2) Space: O(N)
