# Graph Representation in C++

### Input: n, m, m lines representing edges

n: No. of vertices  
m: No. of edges  
The next m lines will have 2 vertex inputs.

### Input Example:

```
5 4

1 2
1 3
1 4
1 5

Here, it means the graph has 5 vertices, 4 edge and First vertex is connected with every other vertex.
```

## There are 2 ways to store the graph inputs.

## 1. Adjacency matrix

-> Here, We'll create a (n+1)\*(n+1) matrix and we will mark 1 if there is an edge between both the index of that matrix, else 0.  
-> For Directed/Weighted graph, Add weight instead of 1 in the matrix.

Code:

```cpp
int n,m;
cin>>n>>m;
int adj[n+1][n+1];
for(int i=0;i<m;i++){
     int u,v;
     cin>>u>>v;
     adj[u][v]=1;
     adj[v][u]=1;
}
```

### Time Complexity: O(M)  
### Space Complexity: O(N^2)

## 2. Adjacency List  
  
We have 3 possibilities in this, Directed, Undirected and Weighted Graph.

## A. Undirected Graph

-> Here, We'll create a vector list of n+1 nodes and we'll add the nodes connected with that node in that node's individual list.    
-> Compared to adjacency matrix, We can easily say neighbours of a particular node in this method.

Code:

```cpp
int n,m;
cin>>n>>m;
vector<int> adj[n+1];
for(int i=0;i<m;i++){
     int u,v;
     cin>>u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);
}
```

Time Complexity: O(M)  
Space Complexity: O(2*Edges) (As we are storing edges twice)

## B. Directed Graph (edge u->v)

-> We will store only one edge as it's directed graph.

Code:
```cpp
for(int i=0;i<m;i++){
  int u,v;
  // u --> v
  cin>>u>>v;
  adj[u].push_back(v);
}
```

Space Complexity: O(Edges) (As we are storing edges only once)

## C. Weighted Graph  

-> We will also add weight when storing the sibling node.  
-> We will use ```pair<int,int>``` insted of only ```int``` in vector to store weight and sibling node in the pair of vector.

Code (Weight with undirected graph):
```cpp
for(int i=0;i<m;i++){
  int u,v,weight;
  cin>>u>>v>>weight;
  adj[u].push_back({v, weight});
  adj[v].push_back({u, weight});
}
```

## In General, Space complexity is better in Adjacency list method.
