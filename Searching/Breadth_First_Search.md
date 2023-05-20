## Description

Searching non Linear Data using Pre-existing Data Structrue Queue.

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

        BTraverse(adj, 1, new boolean[V + 1]);
        System.out.println(ans);
    }

    // For Undirected Graph assignment
    public static void adjL(List<List<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
        // If Directed graph just remove one Of this element.
        adj.get(v).add(u);
    }


    private static List<Integer> BTraversal(List<List<Integer>> adj, int V, int startIndex) {

        // Declaring a queue to search in breadth wise
        Queue<Integer> q = new LinkedList<>();

        // This is a visited array for check.
        boolean vis[] = new boolean[V + 1];

        // mark the current element visited
        vis[startIndex] = true;

        // push it in to the queue to further store
        q.add(startIndex);

        // Search it until the queue is empty
        while (!q.isEmpty()) {
            // remove the first element and traverse its adj. element.
            Integer ele = q.poll();

            for (Integer x : adj.get(ele)) {
                // If it is not visited yet then
                if (!vis[x]) {
                    // mark it visited and add it to queue for futher searching.
                    vis[x] = true;
                    q.add(x);
                }
            }
        }

        // return the traversed array
        return bfs;
    }

}
```

## C++

```cpp


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>>& adj, int V, int startIndex) {
    vector<int> traversal;  // To store the BFS traversal result

    // Creating a visited array to keep track of visited vertices
    vector<bool> visited(V + 1, false);

    // Creating a queue for BFS
    queue<int> q;

    // Mark the startIndex as visited and enqueue it
    visited[startIndex] = true;
    q.push(startIndex);

    while (!q.empty()) {
        // Dequeue a vertex from the queue and add it to the traversal result
        int vertex = q.front();
        q.pop();
        traversal.push_back(vertex);

        // Get all adjacent vertices of the dequeued vertex
        for (int neighbor : adj[vertex]) {
            // If the adjacent vertex has not been visited, mark it as visited and enqueue it
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return traversal;
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

    int startIndex = 1;

    vector<int> traversal = bfs(adj, V, startIndex);

    for (int vertex : traversal) {
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

O(n)[Visited Array Space] + O(n)[For Queue Space] --> O(n)[Final Complexity]
