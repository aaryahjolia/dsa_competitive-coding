## Question Link :

https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem?isFullScreen=true

## Code solution :

```cpp
// C++14 Language
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* llist;
    if(head1==NULL){
        return head2; 
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data<=head2->data){
        llist=head1;
        head1=head1->next;
    }
    else{
        llist=head2;
        head2=head2->next;
    }
    SinglyLinkedListNode* p=llist;
    while(head1 && head2){
        if(head1->data<=head2->data){
            p->next=head1;
            head1=head1->next;
            p=p->next;
        }
        else{
            p->next=head2;
            head2=head2->next;
            p=p->next;
        }
    }
    while(head1){
        p->next=head1;
        head1=head1->next;
        p=p->next;
    }
    while(head2){
        p->next=head2;
        head2=head2->next;
        p=p->next;
    }
    p->next=nullptr;
    return llist;
}

```