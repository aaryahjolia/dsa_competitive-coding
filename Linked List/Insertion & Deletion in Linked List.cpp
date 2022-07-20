#include <iostream>

using namespace std;

class node
{
public:
  int data;
  node *next;
};

class singly_linked_list
{
private:
  node *head;
public:
  int length;
  singly_linked_list();
  ~singly_linked_list();

  void add_first(int);
  void add_last(int);
  void add_particularposition(int,int);
  void delete_first();
  void delete_last();
  void delete_particularposition(int);
  void display_all();
  void display_first();
  void display_last();
  void display_particularposition(int); 
};


singly_linked_list::singly_linked_list()
{
  this->length = 0;
  this->head = NULL;
}

singly_linked_list::~singly_linked_list()
{
  cout << "this object was deleted"  << "\n";
}

void singly_linked_list::add_particularposition(int pos,int n)
{
  node *pre = new node();
  node *cur = new node();
  node *temp = new node();
  
  if(pos==0)
  {
    temp->data = n;
    temp->next = this->head;
    this->head = temp;
  }
  else
  {
    cur=this->head;
    for (int i = 0; i < pos ; i++)
    {
      pre = cur;
      cur = cur->next;
    }
    temp->data = n;
    temp->next = cur;
    pre->next = temp;
  }
  this->length++;
}

void singly_linked_list::add_first(int n)
{
  add_particularposition(0,n);
}

void singly_linked_list::add_last(int n)
{
  add_particularposition(this->length,n);
}

void singly_linked_list::delete_particularposition(int pos)
{
  node *pre = new node();
  node *cur = new node();
  cur = this->head;

  if(pos == 0)
  {
    pre = this->head;
    head = head->next;
  }
  else
  {
    for (int i = 0; i < pos; i++)
      {
	pre = cur;
	cur = cur->next;
      }
    pre->next = cur->next;
  }
  this->length--;
}

void singly_linked_list::delete_first()
{
  delete_particularposition(0);
}

void singly_linked_list::delete_last()
{
  delete_particularposition(this->length-1);
}

void singly_linked_list::display_particularposition(int n)
{
  node *new_node = this->head;
  for (int i = 0; i < n; i++) 
    new_node = new_node->next;
  cout << n <<": "<< new_node->data << "\n";
}

void singly_linked_list::display_first()
{
  display_particularposition(0);
}

void singly_linked_list::display_last()
{
  display_particularposition(this->length-1);
}

void singly_linked_list::display_all()
{
  node *new_node = this->head;
  int i = 1;
  while(new_node)
  {
    cout << i <<": "<< new_node->data << "\n";
    new_node=new_node->next;
    i++;
  }
}


int main(int argc, char *argv[])
{
  singly_linked_list *sll = new singly_linked_list();
  cout << "add first"<<"\n";
  sll->add_first(10);
  sll->add_first(20);
  sll->display_all();
  cout << "\n";

  cout << "add last"<<"\n";
  sll->add_last(30);
  sll->add_last(40);
  sll->display_all();
  cout << "\n";

  cout << "delete first and last node"<<"\n";
  sll->delete_first();
  sll->delete_last();
  sll->display_all();
  cout << "\n";
  
  cout << "display first and last node"<<"\n";
  sll->display_first();
  sll->display_last();
  return 0;
}
