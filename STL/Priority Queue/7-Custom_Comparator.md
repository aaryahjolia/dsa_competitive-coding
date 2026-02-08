## Description

Custom comparators allow you to control the ordering of elements in a priority queue. You can create min heaps, custom sorting logic, or sort complex objects.

## Method 1 - Min Heap using greater<int>

```cpp
// Min heap: smallest element at top
priority_queue<int, vector<int>, greater<int>> pq;

pq.push(30);
pq.push(10);
pq.push(20);
pq.push(5);

while(!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
}
```

### Output

```cpp
5 10 20 30
```

## Method 2 - Custom comparator for pairs (sort by second element)

```cpp
// Custom comparator: sort by second element
struct ComparePair {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second; // Max heap by second element
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePair> pq;

pq.push({1, 30});
pq.push({2, 10});
pq.push({3, 50});

while(!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    cout << "(" << p.first << ", " << p.second << ") ";
}
```

### Output

```cpp
(3, 50) (1, 30) (2, 10)
```

## Method 3 - Custom comparator using lambda (C++11)

```cpp
// Lambda comparator for min heap
auto cmp = [](int a, int b) { return a > b; };
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

pq.push(30);
pq.push(10);
pq.push(20);

while(!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
}
```

### Output

```cpp
10 20 30
```

## Method 4 - Custom class with comparator

```cpp
struct Student {
    string name;
    int marks;
};

// Comparator: sort by marks (descending)
struct CompareMarks {
    bool operator()(Student a, Student b) {
        return a.marks < b.marks; // Max heap
    }
};

priority_queue<Student, vector<Student>, CompareMarks> pq;

pq.push({"Alice", 95});
pq.push({"Bob", 85});
pq.push({"Charlie", 90});

while(!pq.empty()) {
    Student s = pq.top();
    pq.pop();
    cout << s.name << ": " << s.marks << endl;
}
```

### Output

```cpp
Alice: 95
Charlie: 90
Bob: 85
```

## Method 5 - Sort pairs by second element (min heap)

```cpp
// Min heap by second element
auto cmp = [](pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
};

priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

pq.push({1, 30});
pq.push({2, 10});
pq.push({3, 20});

while(!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    cout << "(" << p.first << ", " << p.second << ") ";
}
```

### Output

```cpp
(2, 10) (3, 20) (1, 30)
```

## Important Notes

### Comparator Logic

- For **max heap**: return `a < b` (or use `less<T>`)
- For **min heap**: return `a > b` (or use `greater<T>`)
- The comparator returns `true` if first argument has **lower priority** than second

### Common Use Cases

- **Min heap**: `greater<int>` for smallest element at top
- **Custom sorting**: Lambda or struct comparator
- **Complex objects**: Custom comparator based on specific fields
- **Reverse order**: Flip the comparison logic
