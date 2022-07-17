## Question Link :

https://www.hackerrank.com/challenges/compare-two-linked-lists/problem?isFullScreen=true

## Code solution :

```cpp
// C++14 Language
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    while(head1!=nullptr && head2!=nullptr &&head1->data==head2->data){
        head1=head1->next;
        head2=head2->next;
    }
    if(head1!=head2){
        return false;
    }
    return true;
}

```