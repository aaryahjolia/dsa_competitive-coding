### Input: n, m
n: No. of vertices  
m: No. of egdes  
The next m lines will have 2 vertex inputs.


### There are 2 ways to store the graph inputs.

1. Adjacency matrix
   
   -> Here, We'll create a (n+1)*(n+1) matrix and we will mark 1 if there is an edge between both the index of that matrix, else 0.  
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
Space complexity: O(N^2)

2. Vector List  
   -> Here, We'll create a vector list of n+1 nodes and we'll add the nodes connected with that node in that node's individual list.  
   -> For Directed/Weighted graph, write ``pair<int,int>`` instead of int in vector list datatype and write ``adj[u].push_back({v,weight});`` when adding the input to the list.

   Code:
   ```cpp
   int n,m;
   cin>>n>>m;
   vector<int>adj[n+1];
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
   }
   ```
Space complexity: O(2*Edges)