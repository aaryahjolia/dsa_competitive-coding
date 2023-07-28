## Singly Linked List

Linked List is a linear Data structure.  
It'structure is like as follows:

![Linked List Image](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/12/screen-shot-2018-04-12-at-152754.png)  
  
Linked List is made up of nodes wher each node contains a data field and a reference field (pointer), this is true for singly linked list.   
There are 2 reference field and 1 data field in doubly linked list.  

Node Structure:
```cpp
struct SinglyListNode {
    int val;
    SinglyListNode *next;
    SinglyListNode(int x){
        val = x;
        next = NULL;
    } 
};
```

The first node or the starting node is generally referred to as head.  

### Operations
We can't access random elements like an array, so if I have to access the last element of linekd list, I'll have to traverse till the last of linked list and the effective TC becomes ```O(N)``` where N is the size of linked list.  