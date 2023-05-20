## Description

Searching non Linear Data using Pre-existing Data Structrue Stack.

<!-- ## Code -->

## Java

```java


import java.util.ArrayList;
import java.util.List;

public class DFS {
    static List<Integer> ans = new ArrayList<>();

    // Driver code
    public static void main(String[] args) {

        // Declar List to store neighbours elements in the form adj list
        List<List<Integer>> adj = new ArrayList<>();

        // Assigning number of vertices only
        int V = 5;

        // Assigning V number of empty list to store the neighbour vetex
        for (int i = 0; i <= V; i++) {
            adj.add(new ArrayList<>());
        }
        // Element asssignment
        adjL(adj, 1, 2);
        adjL(adj, 2, 3);
        adjL(adj, 2, 4);
        adjL(adj, 1, 5);

        DTraverse(adj, 1, new boolean[V + 1]);
        System.out.println(ans);
    }

    // For Undirected Graph assignment
    public static void adjL(List<List<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
        // If Directed graph just remove one Of this element.
        adj.get(v).add(u);
    }


    public static void DTraverse(List<List<Integer>> dfs, int startIndex, boolean[] vis) {
        // If the current is visited already then no need to continue just return
        if (vis[startIndex])
            return;

        // If it is not visited then mark it visited
        vis[startIndex] = true;

        // Store in an ans array
        ans.add(startIndex);

        // Traverse its adjecent element as well to find out its connected node
        for (Integer each : dfs.get(startIndex)) {
            // Call the Function recursively to check that element wheather that element is visited or not.

            // you may write the base condition here as well.
            DTraverse(dfs, each, vis);
        }
    }
}
```

## C++

```cpp


#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;

void dfs(vector<vector<int>>& adj, int startIndex, vector<bool>& visited) {
    // If the current vertex is already visited, return
    if (visited[startIndex])
        return;

    // Mark the current vertex as visited
    visited[startIndex] = true;

    // Add it to the answer vector
    ans.push_back(startIndex);

    // Traverse its adjacent vertices recursively
    for (int neighbor : adj[startIndex]) {
        dfs(adj, neighbor, visited);
    }
}

int main() {
    int V = 5;  // Number of vertices

    // Declare a vector to store the neighbor elements in the form of an adjacency list
    vector<vector<int>> adj(V + 1);

    // Element assignment
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[1].push_back(5);

    vector<bool> visited(V + 1, false);

    dfs(adj, 1, visited);

    for (int vertex : ans) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}


```

## Complexities

### T.C :

O(n)[Traver the element] + O(n)[Traversing the adjecent neighbour ele] --> O(n)[Final Complexity]

### Auxiliary S.C :

O(n)[Visited Array Space] + O(n)[Stack Call Space] --> O(n)[Final Complexity]
