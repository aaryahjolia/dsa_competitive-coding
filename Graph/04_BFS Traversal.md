# BFS (Breadth first search) traversal technique  

-> Also called Level wise traversal.  
-> The starting node will be specified in the question, take 0 otherwise (Graph can be 0-indexed or 1-indexed, Remember to code wisely).  
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

Time Complexity: O(V + 2E). (While loop will run for V vertex, for loop will run for degrees of that vertex and degree=2×edges).    
Space Complexity: O(3*N) ~ O(N). (2 Vector and 1 queue)

<!-- Adding an efficient approach for BFS Traversal -->
#include <iostream>
#include <queue>
#include <deque>
#include <list>

using namespace std;

void bfs(int startNode, vector<list<int>> &adj, int n) {
    deque<int> q;
    vector<bool> visited(n, false);
    
    q.push_back(startNode);
    visited[startNode] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop_front();
        
        // Instead of storing in a vector, directly print the node
        cout << node << " ";
        
        for (auto &neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push_back(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n = 5; // Example number of nodes
    vector<list<int>> adj(n);
    
    // Example graph setup (undirected)
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(0);
    adj[3].push_back(1);
    adj[4].push_back(1);
    
    int startNode = 0; // Starting node, can be modified as needed
    cout << "BFS traversal starting from node " << startNode << ": ";
    bfs(startNode, adj, n);
    
    return 0;
}
<!-- Key Changes and Optimizations:
Data Structure Change: Instead of using a vector to store the BFS traversal order, we use a deque for the BFS queue. This allows efficient insertion and deletion operations from both ends, which is slightly more optimal than using a vector or list.

Direct Printing: Instead of storing the traversal order in a vector, we directly print the nodes. This reduces memory usage since we're not maintaining an extra structure just to store the order of traversal.

Space Complexity: By avoiding an additional storage vector for the result and using direct printing, we slightly reduce the space complexity to O(N) for the visited list and the deque queue. This makes the space complexity closer to O(N).

Time Complexity:
The time complexity remains O(V + E), where V is the number of vertices and E is the number of edges. This is because each vertex is processed once, and each edge is considered once.

Space Complexity:
The space complexity using this approach is O(N):
O(N) for the visited array.
O(N) for the deque queue (since at most, all nodes might need to be queued).
By printing directly, we avoid an additional O(N) space for storing results.
This approach is particularly useful for environments where memory is constrained, or when you want to avoid the overhead of additional storage structures. -->
