## Question Link :

https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem?isFullScreen=true

## Code solution :

```cpp
// C++14 Language
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2){
    SinglyLinkedListNode* p1=head1;
    SinglyLinkedListNode* p2=head2;
    while(p1!=p2){
        p1 = p1==NULL ? head2 : p1->next;
        p2 = p2==NULL ? head1 : p2->next;
    }
    return p1->data;
}

```