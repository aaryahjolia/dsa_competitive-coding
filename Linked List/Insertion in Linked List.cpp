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

int main()
{
    ListNode* head = new ListNode();
    ListNode* temp1 = new ListNode();
    ListNode* temp2 = new ListNode();
    ListNode* temp3 = new ListNode();
  
      
    head->data = 10; 
    head->next = temp1; 
  
    temp1->data = 20; 
    temp1->next = temp2;
  
    temp2->data = 30; 
    temp2->next = temp3;

    head = insertAtBeginning(head, 40);

    temp3 = new ListNode();
    temp3->data = 5;
    temp3->next = NULL;

    head = insertAtGivenPosition(head, temp3, 50);

    head = insertAtEnd(head, 60);
  
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
  
    return 0;
}
