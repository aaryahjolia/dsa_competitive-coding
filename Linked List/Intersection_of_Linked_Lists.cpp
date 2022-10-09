/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

    Notes:
        If the two linked lists have no intersection at all, return null.
        The linked lists must retain their original structure after the function returns.
        You may assume there are no cycles anywhere in the entire linked structure.
        Your code should preferably run in O(n) time and use only O(1) memory.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    //Two pointers to traverse both lists
    ListNode* p=A;
    ListNode* q=B;
    //Here both pointers are not on same distance from intersecting point
    //So first we'll bring both pointers to same distance from intersecting point
    while(p&&q){
        p=p->next;
        q=q->next;
    }
    if(p==NULL){
        p=B;
    }
    else if(q==NULL){
        q=A;
    }    
    while(p&&q){
        p=p->next;
        q=q->next;
    }
    if(p==NULL){
        p=B;
    }
    else if(q==NULL){
        q=A;
    }
    //Now we'll check for intersection
    while(p&&q){
        //If both lists intersect at any point we will return the pointer
        if(p==q)
            return p;
        p=p->next;
        q=q->next;
    }
    //If both lists do not intersect at any point we will return NULl
    return NULL;    
}
