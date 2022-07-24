
Problem Link: [Number Of Islands](https://leetcode.com/problems/longest-consecutive-sequence/)
<br/>
Author: [Yuvraj Parashar](https://github.com/yvrjprshr)
*/

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Creating DSU
    struct DSU {
        vector<int> parent;
        vector<int> siz;
        int n;
        
        DSU(int V){
            n = V;
            parent.resize(V);
            siz.resize(V);
            for(int i = 0; i < n; i++){
                parent[i] = i;
                siz[i] = 1;
            }
        }
        
        int find_set(int v){
            return parent[v] == v ? v : parent[v] = find_set(parent[v]);
        }
        
        void union_sets(int a, int b){
            a = find_set(a);
            b = find_set(b);
            
            if(a != b){
                if(siz[b] > siz[a]){
                    swap(a,b);
                }
                parent[b] = a;
                siz[a] += siz[b];
            }
        }
    };
    
    int n,m;
    
    // We will have parent vector for all mxn nodes so to find index of cell in parent vector we will use this 
    int node_idx(int x, int y){
        return (x*m)+y;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        DSU dsu(n*m);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '0')continue;
                // check above
                if(i && (grid[i-1][j] == grid[i][j])){
                    dsu.union_sets(node_idx(i-1, j), node_idx(i,j));
                }
                // check left
                if(j && (grid[i][j-1] == grid[i][j])){
                    dsu.union_sets(node_idx(i, j-1), node_idx(i,j));
                }
            }
        }
        
        // set will contain unique nodes
        set<int> s;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1')
                s.insert(dsu.find_set(node_idx(i,j)));
            }
        }
        
        return s.size();
    }
};
```
Time Complexity:  O(n^2)