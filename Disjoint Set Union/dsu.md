Disjoin Set Union is an important data structure also known as dsu. It is helful in finding connected componets or similar tasks. This task can also be done by graphs also but using DSU in those places is time complexity efficient.

In this data structure there can be any number of connected component and each component is called set, so all different sets combining together is called disjoint set.

It has mainly 3 operations

- make_set : to create a new node
- find_set : this function return parent of the given node, parent is the node by which other nodes connected in tree format
- union_sets : It combines two sets together, to combine together It attach parent of the one node[have less size] to the parent of another node [have more size]

Here is the implementation of DSU with an example of finding number of connected components
```cpp

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+2;

int parent[N];
int set_size[N];

// Initially all nodes will be independent so they will be parent of themselves
void make_set(int v){
	parent[v] = v;
	set_size[v] = 1;
}

// At each iteration, set parent of all nodes in path directly to parent so that whenever it is asked to find parent it will not have to go through all path. This process is also known as path compression
int find_set(int v){
	if(parent[v] == v) return v;
	return parent[v] = find_set(parent[v]);
}

// union by size
void union_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);

	if(a != b){
		if(set_size[a] < set_size[b]){
			swap(a,b);
		}
		parent[b] = a;
		set_size[a] += set_size[b];
	}
}

int main() {
	int n,k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		make_set(i);
	}
	for(int i = 1; i <= k; i++){
		int u,v;
		cin >> u >> v;
		union_sets(u, v);
	}

	int connected_cnt = 0;
	for(int i = 1; i <= n; i++){
		if(parent[i] == i)connected_cnt++;
	}
	cout << connected_cnt << endl;
}
```

Time Complexity : O(alpha(n)) where alpha(n) is the Inverse Ackermann function.