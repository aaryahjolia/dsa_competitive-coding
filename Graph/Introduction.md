# **Graphs**

## Some Common Terms
1. **Node/Vertex**: A node (or vertex) of a graph is one of the objects that are connected together.
2. **Edges**: It is one of the connections between the nodes (or vertices) of the network.
3. **Path**: A sequence of node of vertex such that none of the node is repeated or visited twice in the graph.
4. **Cyclic**: If the graph contains a cycle (We can come back to same node after traversing the graph is called a cyclic graph). The opposite of a cyclic graph is an acyclic graph.
5. **Weight / Cost**: If the edge is assigned a numerical value, The value is called the edge's weight or cost.

There are primarily 2 types of graph:  
## 1. Undirected Graph  

Example:
![Undirected](https://user-images.githubusercontent.com/82600388/193063117-753b42ab-0695-44db-9f3e-d569b049b87f.png)  
  
  
Here, We can say that there is an edge between 2 and 3 & between 3 and 2 as undirected graph can be traversed through both the sides.  
  
**Degree**: The number of edges connected with the node or vertex.  
Ex: Degree(2) = 2  
    Degree(1) = 2

**Relation between Degree and Edges**  
Total Degrees = 2 * Edges  

**Path**: 1 2 3 4 (One possibility)

**Cyclic property**: It is an undirected cyclic graph (1->2->3->1 is a cycle)

## 2. Directed Graph  
  
Example:
![Directed](https://user-images.githubusercontent.com/82600388/193063186-c7141c2b-e2e4-45b3-94a6-9bb542d53ad9.png)  
  
Here, We can say that there is an edge between 1 and 2 but there is not edge between 2 and 1 as directed graph only traverse in the direction of edge.  
  
**Indegree**: The number of edges incoming to that node or vertex.  
Ex: Indegree(2) = 2  
**Outdegree**: The number of edges outgoing to that node or vertex.  
Ex: Outdegree(2) = 0

**Path**: 1 3 4 (One possibility)

**Cyclic**: It's a directed cyclic graph (3->4->3 is a cycle).