# DFS (Depth first search) traversal technique

-> Uses Recursion for Depth traversal.

Code:
```cpp
void dfst(int node, vector<int>adj[], vector<int> &visited, vector<int> &dfs){
    visited[node]=1;
    dfs.push_back(node);
    for(auto it : adj[node]){
        if(!visited[it]){
            dfst(it, adj, visited, dfs);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]){
    vector<int> visited (V,0);
    vector<int> dfs;
    int sn = 0; // starting node
        
    dfst(sn, adj, v, dfs);
    return dfs;
}

```

### Complexities:

Time Complexity: O(N)+O(2E) (Recursion function call for O(N) and the for loop will run for all degrees and summation of degrees is 2×Edges)   
Space Complexity: O(3*N) ~ O(N). (2 Vector and recursion stack will have O(N) as worst case in case of linear graph like 1->2->3->4->...)