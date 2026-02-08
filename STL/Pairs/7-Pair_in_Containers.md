## Description

Pairs are commonly used with STL containers like vectors, maps, sets, and priority queues for storing associated data.

## Pairs with Containers

### Method 1 - Vector of pairs

```cpp
// Store (id, name) pairs
vector<pair<int, string>> students;

students.push_back(make_pair(1, "Alice"));
students.push_back({2, "Bob"});
students.push_back({3, "Charlie"});

// Print all students
for(auto student : students) {
    cout << "ID: " << student.first << ", Name: " << student.second << endl;
}
```

### Output

```cpp
ID: 1, Name: Alice
ID: 2, Name: Bob
ID: 3, Name: Charlie
```

### Method 2 - Map (already uses pairs internally)

```cpp
// Map stores data as pair<key, value>
map<string, int> scores;
scores["Alice"] = 95;
scores["Bob"] = 87;
scores["Charlie"] = 92;

// Iterate over map (each element is a pair)
for(auto p : scores) {
    cout << p.first << ": " << p.second << endl;
}
```

### Output

```cpp
Alice: 95
Bob: 87
Charlie: 92
```

### Method 3 - Set of pairs

```cpp
// Store and auto-sort coordinate pairs
set<pair<int, int>> coordinates;

coordinates.insert({3, 4});
coordinates.insert({1, 2});
coordinates.insert({5, 6});
coordinates.insert({1, 2}); // Duplicate, won't be inserted

// Print sorted coordinates
for(auto p : coordinates) {
    cout << "(" << p.first << ", " << p.second << ")" << endl;
}
```

### Output

```cpp
(1, 2)
(3, 4)
(5, 6)
```

### Method 4 - Priority queue with pairs

```cpp
// Max heap based on first element
priority_queue<pair<int, string>> pq;

pq.push({85, "Bob"});
pq.push({95, "Alice"});
pq.push({75, "Charlie"});

// Print in priority order (highest first)
while(!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    cout << p.second << ": " << p.first << endl;
}
```

### Output

```cpp
Alice: 95
Bob: 85
Charlie: 75
```

### Method 5 - Sorting vector of pairs

```cpp
// Store (score, name) and sort by score
vector<pair<int, string>> students = {
    {75, "Charlie"},
    {95, "Alice"},
    {85, "Bob"}
};

// Sort by score (ascending)
sort(students.begin(), students.end());

cout << "Ascending order:" << endl;
for(auto s : students) {
    cout << s.second << ": " << s.first << endl;
}
```

### Output

```cpp
Ascending order:
Charlie: 75
Bob: 85
Alice: 95
```

### Method 6 - Graph representation using pairs

```cpp
// Adjacency list: vector of vectors of pairs (node, weight)
vector<vector<pair<int, int>>> graph(4);

// Add edges: (from, to, weight)
graph[0].push_back({1, 10});
graph[0].push_back({2, 5});
graph[1].push_back({3, 2});
graph[2].push_back({3, 7});

// Print adjacency list
for(int i = 0; i < 4; i++) {
    cout << "Node " << i << ": ";
    for(auto edge : graph[i]) {
        cout << "(" << edge.first << ", w=" << edge.second << ") ";
    }
    cout << endl;
}
```

### Output

```cpp
Node 0: (1, w=10) (2, w=5)
Node 1: (3, w=2)
Node 2: (3, w=7)
Node 3:
```
