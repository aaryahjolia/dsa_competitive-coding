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

// reverse function
void reverse(Node* pointer){
    if(pointer->link==NULL) {
        head = pointer;
        return;
    }
    reverse(pointer->link);
    Node* temp = pointer->link;
    temp->link = pointer;
    pointer->link = NULL;
}

// print list
void print(Node* pointer){
    if(pointer==NULL) return;
    cout<<pointer->data<<" ";
    print(pointer->link);
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
    reverse(head);
    print(head); 
}
