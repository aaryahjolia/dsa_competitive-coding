## Question Link :

https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem?isFullScreen=true

## Code solution :

```cpp
// C++14 Language
void reversePrint(SinglyLinkedListNode* llist) {
    if(llist==NULL){
       return; 
    }
    reversePrint(llist->next);
    cout<< llist->data <<endl;
}

```