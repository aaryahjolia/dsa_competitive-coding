## Question Link :

https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem?isFullScreen=true

## Code solution :

```cpp
// C++14 Language
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* ptr=head;
    if(ptr==nullptr){
        head=new SinglyLinkedListNode(data);
        ptr=head;
        return head;
    }
    else{
        while(ptr->next!=nullptr){
            ptr=ptr->next;
        }
        ptr->next=new SinglyLinkedListNode(data); 
    }
    return head;
}

```