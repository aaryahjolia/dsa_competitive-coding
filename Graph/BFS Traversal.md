## BFS (Breadth first search) traversal technique  

-> Also called Level wise traversal.  
-> The starting node will be specified in the question, take 0 otherwise.  
-> The nodes which are equidistant from parent node are said to be in level-1 and likewise.  
-> First print elements in level-0, then level-1 and so on.

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