## Question Link :

https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem?isFullScreen=true

## Code solution :

```cpp
// C++14 Language
void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}


```

