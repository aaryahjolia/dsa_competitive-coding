## Question Link :

https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem?isFullScreen=true

## Code solution :

```cpp
// C++14 Language
bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* fast=head;
    SinglyLinkedListNode* slow=head;
    while(slow && fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            return 1;
        }
    }
    return 0;
}

```