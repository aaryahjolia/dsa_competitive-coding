# Description

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Definition for singly-linked list:

```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
```
[Leetcode question link](https://leetcode.com/problems/middle-of-the-linked-list/)

### Examples:

```
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
```

### Constraints:

- The number of nodes in the list is in the range [1, 100].
- 1 <= Node.val <= 100

---

### Approach 1 (Two-pass approach):

#### Intuition

- First, we will find the length of the linked list.
- Then, we will find the middle node of the linked list (length / 2).

```cpp
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        /* Find the length of the linked list */
        int len = 0;
        ListNode *temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }

        /* Find the middle node of the linked list */
        int mid = len / 2;
        temp = head;
        while (mid--) {
            temp = temp->next;
        }

        return temp;
    }
};
```

### Complexity Analysis:

Time Complexity: O(N), where N is the number of nodes in the given list.<br>
Space Complexity: O(1), the space used by temp.<br>

---

### Approach 2 (Slow and Fast pointers approach):

#### Intuition

- This algorithm is based on the [Floyd's Tortoise and Hare Algorithm](https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_tortoise_and_hare) aka Floyd's Cycle Detection Algorithm.
- Initially, we have two pointers called slow and fast. Both of these pointers are initially pointing to the head of the linked list.
- We move the slow pointer one step forward and the fast pointer two steps forward until the fast pointer reaches the end of the linked list.
- By the time the fast pointer reaches the end of the linked list, the slow pointer will be at the middle of the linked list.

```cpp
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        /* Initialize slow and fast pointers pointing to the head of the linked list */
        ListNode *slow = head, *fast = head;

        /* Until the fast pointer reaches the end of the linked list */
        while (fast && fast->next) {
            slow = slow->next;       /* Move the slow pointer one step forward */
            fast = fast->next->next; /* Move the fast pointer two steps forward */
        }

        return slow;
    }
};
```

### Complexity Analysis:

Time Complexity: O(N), where N is the number of nodes in the given list.<br>
Space Complexity: O(1), the space used by slow and fast.<br>
