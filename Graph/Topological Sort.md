# Topological Sort

Definition : The linear ordering of nodes/vertices such that if there exists an edge between 2 nodes u,v then ‘u’ appears before ‘v’.

## Example Problem Statement 

Given a graph, find the topological order for the given graph.

**NOTE** : Topological Sort can only be possible for DAG ( Directed acyclic graph) and if there is a cycle then topological order will not be possible.

## Approach

-> We can implement this algorithm using the following steps:

1) In order to maintain the In-degree of each and every node, we take an array of size v( where v is the number of nodes).

2) Find in-degree of all nodes and fill them in an array

3) Now we will take Queue data structure and add nodes that have in-degree is 0 ( because we have to start this question from a node that doesn’t have any previous edges), and simply apply bfs on queue with some conditions.

4) Take the top/peek node from Queue ( let the popped node be z), add this z to our answer. (If you can observe clearly the above step is nothing but Normal BFS traversal). 

   Now we have to apply some conditions to the BFS :

   1) Take neighbour nodes of popped nodes and reduce their in-degree by 1.
   2) Now check if in-degree of the popped element becomes 0 then add this neighbour element into the queue.

5) Repeat step 4 till the queue becomes empty. 

## Code

```cpp
vector<int> topo(int N, vector<int> adj[]) {
   // Adjacency List will be given in question or you can make your own.
   queue<int> q; 
   vector<int> indegree(N, 0); 
   for( int i = 0; i < N; i++ ) {
      for(auto it: adj[i]) {
         indegree[it]++; 
      }
   }
   
   for( int i = 0; i < N; i++ ) {
      if(indegree[i] == 0) {
         q.push(i); 
      }
   }
   // Made vector topo to store the topological sort order.
   vector<int> topo;
   while( !q.empty() ) {
      int node = q.front(); 
      q.pop(); 
      topo.push_back(node);
      for(auto it : adj[node]) {
         indegree[it]--;
         if( indegree[it] == 0 ) {
            q.push(it); 
         }
      }
   }
   return topo;
}
```
## Complexities

-> Time Complexity: O( N + E ). 

Going through N nodes and E edges.

-> Space Complexity: O(N) + O(N). 

For Queue and Array.