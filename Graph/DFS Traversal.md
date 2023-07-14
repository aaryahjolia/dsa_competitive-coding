## DFS (Depth first search) traversal technique

-> Depth First Traversal is a traversal technique/algorithm, used to traverse through all the nodes in the given graph.
-> It starts traversal through any one of its neighbour nodes and explores the farthest possible node in each path/branch and then starts Back-tracking.

## Approach

1) Start with a random node from graph
2) Make an array to keep track of visited nodes, once visited make that node as visited
3) Print this current node
4) Get  neighbour nodes and perform above steps recursively for each node deeply/depthly if node is unvisited.


## Code
```cpp
void dfst(int node, vector<int>adj[], vector<int> &vis, vector<int> &dfs){
    vis[node]=1;
    dfs.push_back(node);
    for(auto it : adj[node]){
        if(!vis[it]){
            dfst(it, adj, vis, dfs);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]){
    vector<int> vis(V,0);
    vector<int> dfs;
    int sn = 0; // starting node
        
    dfst(sn, adj, vis, dfs);
    return dfs;
}

```

## Complexities

-> Time complexity: O(N + E)
    
    Where N is the time taken for visiting N nodes and E is for travelling through adjacent nodes.

-> Space Complexity: O(N + E) + O(N) + O(N)
    
    Space for adjacency list, Array, Auxiliary space.
