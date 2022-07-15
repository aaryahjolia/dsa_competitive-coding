#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    struct ListNode *next;
};

struct ListNode *insertAtBeginning(struct ListNode *head, int data){

    struct ListNode *temp;

    temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp ->data = data;
    temp ->next = NULL;

    if (head == NULL){
        head = temp;
        head->next = NULL;
    }

    else{
        temp -> next = head;
        head = temp;
    }

    return head;
}

struct ListNode *insertAtEnd(struct ListNode *head, int data){
    struct ListNode *temp, *curr;

    temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp -> data = data;
    temp -> next = NULL;

    curr = head;
    if (curr == NULL)  
        head = temp;
    
    else{

        while (curr -> next != NULL)
            curr = curr -> next;
        
        curr -> next = temp;
    }

    return head;
}

struct ListNode *insertAtGivenPosition(struct ListNode *head, struct ListNode *newNode, int n){

    struct ListNode *pred = head;

    if (n <= 1){
        newNode -> next = head;
        return newNode;
    }

    while (--n && pred != NULL)
        pred = pred -> next;

    if (pred == NULL)
        return NULL;

    newNode -> next = pred -> next;
    pred -> next = newNode;
    return head;
}

void printList(ListNode* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

int main()
{
    ListNode* head = NULL;
    ListNode* second = NULL;
    ListNode* third = NULL;
    ListNode* newNode = NULL;
  
    //allocate 3 nodes in the heap
    head = new ListNode();
    second = new ListNode();
    third = new ListNode();
  
    head->data = 1; // assign data in first node
    head->next = second; // Link first node with second
  
    second->data = 2; // assign data to second node
    second->next = third;
  
    third->data = 3; // assign data to third node
    third->next = NULL;

    head = insertAtBeginning(head, 4);

    newNode = new ListNode();
    newNode->data = 5;
    newNode->next = NULL;

    head = insertAtGivenPosition(head, newNode, 5);

    head = insertAtEnd(head, 6);
  
    printList(head);
  
    return 0;
}