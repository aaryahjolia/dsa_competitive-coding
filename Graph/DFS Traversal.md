## DFS (Depth first search) traversal technique

-> 

Code:
```cpp
void dfst(int node, vector<int>adj[], vector<int> &v, vector<int> &dfs){
    v[node]=1;
    dfs.push_back(node);
    for(auto it : adj[node]){
        if(!v[it]){
            dfst(it, adj, v, dfs);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]){
    vector<int> v (V,0);
    vector<int> dfs;
    int sn = 0; // starting node
        
    dfst(sn, adj, v, dfs);
    return dfs;
}

```