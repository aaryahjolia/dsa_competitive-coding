## Question Link :

https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem?isFullScreen=true

## Code solution :

```cpp
// C++14 Language
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* q=llist;
    SinglyLinkedListNode* p=q->next;
    while(p!=nullptr){
        if(q->data==p->data){
            p=p->next;
            q->next=p;
        }
        else{
            p=p->next;
            q=q->next;
        }
    }
    return llist;
}

```