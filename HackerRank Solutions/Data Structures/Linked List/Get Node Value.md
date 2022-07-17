## Question Link :

https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem?isFullScreen=true

## Code solution :

```cpp
// C++14 Language
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    int index=0;
    SinglyLinkedListNode* current=llist;
    while(llist!=nullptr){
        if(index++>positionFromTail){
            current=current->next;
        }
        llist=llist->next;
    }
    return current->data;
}

```