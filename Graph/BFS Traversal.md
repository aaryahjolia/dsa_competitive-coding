## BFS (Breadth first search) traversal technique  

-> Also called Level wise traversal.  
-> The starting node will be specified in the question, take 0 otherwise.  
-> The nodes which are equidistant from parent node are said to be in level-1 and likewise.  
-> First print elements in level-0, then level-1 and so on.

## Approach

-> We need to have this before proceeding :

1) Queue Data structure
2) Visited Array – An array with all values initialised with 0.

-> We will push the 1st node into the queue data structure and mark it as visited. After this, we will find its adjacent nodes. If we get some unvisited node, we will simply push this adjacent node into the queue data structure

-> Now since the work of the 1st node is done, we will pop out this node from the queue. Now, this process goes on until the queue is not empty.

Code: (For Undirected Graph)
```cpp
// Assuming inputs are taken in adjacency list
vector<int> adj[n+1];

queue<int> q;
vector<int> vis(n+1,0);
vector<int> bfs;
int sn=0; // Starting node

q.push(sn);
vis[sn]=1;

while(!q.empty()){
    int node = q.front();
    q.pop();
    bfs.push_back(node);
    for(auto it : adj[node]){
        if(!vis[it]){
            q.push(it);
            vis[it]=1;
        }
    }
}

return bfs;
```

### Complexities:

-> Time Complexity : O(N + E)

N = Nodes , E = travelling through adjacent nodes

-> Space Complexity : O(N + E) + O(N) + O(N) 

Space for adjacency list, visited array, queue data structure