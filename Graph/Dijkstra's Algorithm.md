# Dijkstra's Algorithm for Shortest Distance

## Example Problem Statement 

Given a weighted, undirected, and connected graph of V vertices and E edges, Find the shortest distance of all the vertex’s from the source vertex S.

**NOTE** : Graph doesn't contain any negative weighted cycle.

## Approach

-> We can implement this algorithm using the following steps:

1) We will be using a min-heap and a distance array of size N initialized with infinity (indicating that at present  none of the nodes are reachable from the source node) and initialize the distance to source node as 0.

2) We will push the source node into the queue.

3) For every node at the top of the queue we pop that element out and look for its adjacent nodes. If the current reachable distance is better than the previous distance indicated by the distance array, we update the distance and push it in the queue.

4) A node with a lesser distance will be at the top of the priority queue as opposed to a node with a higher distance. 

By following the steps 3, until our queue becomes empty, we would get the minimum distance from the source node to all other nodes.

## Code

```cpp
// assuming 1 based indexing of graph and input are taken in graph.
vector<pair<int,int> > g[n+1];

// Dijkstra's algorithm begins from here
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
// 1-indexed array for calculating shortest paths
vector<int> distTo(n+1,INT_MAX);
distTo[source] = 0;
// (dist,source)
pq.push(make_pair(0,source));
while( !pq.empty() ){
   int dist = pq.top().first;
   int prev = pq.top().second;
   pq.pop();
   vector<pair<int,int> >::iterator it;
   for( it = g[prev].begin(); it != g[prev].end(); it++ ){
      int next = it->first;
      int nextDist = it->second;
      if( distTo[next] > distTo[prev] + nextDist){
         distTo[next] = distTo[prev] + nextDist;
         pq.push(make_pair(distTo[next], next));
      }
   }
}
```
## Complexities

-> Time Complexity: O( (N + E) * logN). 

Going through N nodes and E edges and log N for priority queue

-> Space Complexity: O(N). 

Distance array and priority queue