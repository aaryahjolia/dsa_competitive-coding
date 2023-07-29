# Description: For a given Singly LinkedList, insert a node at the beginning of the linked list.

//Input: List = 10->20->30->40->null, Node = 0
//Output: 0->10->20->30->40->null
//Explanation: Inserted the given node at the beginning of the linked list.

//Example 2:
//Input: List = 100->200->300->null, Node =700
//Output: 700->100->200->300->null
//Explanation: Inserted the given node at the beginning of the linked list.

```cpp
#include <bits/stdc++.h>

using namespace std;

class ListNode {
  public:
    int val;
  ListNode * next;
  ListNode(int x) {
    val = x;
    next = NULL;
  }
};

void PrintList(ListNode * head) // Function to print the LinkedList
{
  ListNode * curr = head;
  for (; curr != NULL; curr = curr -> next)
    cout << curr -> val << "-->";
  cout << "null" << endl;
}

ListNode * InsertatFirst(int value, ListNode * head) {

  // Step1 : creating a new Node with the given val
  ListNode * newnode = new ListNode(value);

  // Step2 : Making next of newly created Node to point the head of LinkedList
  newnode -> next = head;

  // Making the newly created Node as head
  head = newnode;
  return head;
}

int main() {
  ListNode * head = NULL; // head of the LinkedList
  head = InsertatFirst(40, head);
  head = InsertatFirst(30, head);
  head = InsertatFirst(20, head);
  head = InsertatFirst(10, head);
  cout << "LinkedList before inserting 0 at beginning : " << endl;
  PrintList(head);
  head = InsertatFirst(0, head);
  cout << "LinkedList after inserting 0 at beginning : " << endl;
  PrintList(head);
  return 0;
}

#Time Complexity:  O(1) Because we are just Manipulating the links, which is a constant operation.

#Space Complexity: O(1) We are not using any extra space.