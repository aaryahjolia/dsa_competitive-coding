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

// end
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


// reverse list

void reverse_list(){
    Node *prev,*temp,*next;
    temp = head;
    prev = NULL;
    while (temp!=NULL)
    {
        next = temp->link;
        temp->link = prev;
        prev = temp;
        temp = next;
    }

    head = prev;  
}

// print linked list

void print(){
    Node *temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->link;
    }
}

// main

int main(){
    int list_size;
    cin>>list_size;
    head = NULL;

    while (list_size--)
    {
        int num;
        cin>>num;
        insert_end(num);
    }

    reverse_list();

    print();
}
