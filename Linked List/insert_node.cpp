#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* link;

    Node(int num){
        data = num;
        link = NULL;
    } 
};

Node* head; //pointer to head node

// insert node at the end of linked list
void insert_end(int num){
    Node* temp = new Node(num);

    if(head == NULL){
        head = temp;
        return;
    }

    Node* temp1 = head;
    while (temp1->link != NULL)
    {
        temp1 = temp1->link;
    }

    temp1->link = temp;   
}

// insert a node at the front of linked list
void insert_head(int num){
    Node* temp = new Node(num);
    if(head==NULL){
        head = temp;
        return;
    }
    temp->link = head;
    head = temp;
} 

// insert a node at given position
void insert_nth(int num, int loc){
    Node* temp = new Node(num);

    if(loc==1){
        temp->link = head;
        head = temp;
        return;
    }
    loc -= 2;
    Node* temp1 = head;
    while (loc--)
    {
        temp1 = temp1->link;
    }

    temp->link = temp1->link;
    temp1->link = temp;
    
}

// print linked list
void print(){
    Node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->link;
    }
}

int main(){
    int size;
    cin>>size;
    head = NULL;
    while (size--)
    {
        int num;
        cin>>num;
        insert_end(num);
    }
    print(); 
}
