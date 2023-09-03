# BFS Traversal (Breadth First Search)
Here, The nodes on the similar height/level are visited first, and then we move on to next height siblings.

## Example

![Binary_Tree](https://user-images.githubusercontent.com/82600388/184525938-cba5ca0d-8d65-41da-9447-b948c0091a34.png)

Preorder Traversal : 
```
8 3 10 1 6 14 4 7 13
```

## Iterative Approach
### Algorithm :
Make an empty queue and add the root node to it.  
Make a vector of vector to store the answer level wise.  
While the queue is not empty, perform the following.
1. Run a loop till the size of queue.
2. Take out the front number and remove it from queue.
3. Push it's left and then right values if they exists.
4. Push the value of front number in a vector and then repeat from 1.
5. After this loop, Push the vector in a another vector to make a vector of vector and repeat till queue is not empty.

```cpp
vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for(int i = 0; i<size; i++) {
            Node* node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}
```
## Time and Space Complexity :

For both the cases
* Time Complexity: O(n)  
* Space Complexity: O(n)

### Next Step

[Binary Trees](./Binary_Trees.md)
