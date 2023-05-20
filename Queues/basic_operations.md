# Description
Illustration of basic operations performed on a queue

# Code
```cpp

#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define endl '\n'


// Print the queue
void print_q(queue<int> q)
{
	queue<int> g = q;
	while (!g.empty()) {
		cout << ' ' << g.front();
		g.pop();
	}
	cout << '\n';
}

int main()
{
    // fast IO
    IOS


    // integer queue
	queue<int> q;
    // performing push function on the queue
        q.push(10);
        // current queue - 10

        q.push(20);
        // current queue - 10 20

        q.push(30);
        // current queue - 10 20 30

	cout << "The queue q is : ";
	print_q(q);

	cout << "Current size of the queue : " << q.size() << endl;
	cout << "Current front element of the queue : " << q.front() << endl;
	cout << "Current rear element of the queue : " << q.back() << endl;

    // performing pop function on the queue to add elements to the queue
	cout << "\nq.pop() : ";
    q.pop();
	print_q(q);

	return 0;
}

```

# Output

```
The queue q is :  10 20 30
Current size of the queue : 3
Current front element of the queue : 10
Current rear element of the queue : 30

q.pop() :  20 30

```

# GFG URL CODE
https://ide.geeksforgeeks.org/21afee75-c704-4fe7-a2dc-92c5f20eaa98