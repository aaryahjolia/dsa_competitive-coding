public class Linkedlist {
    Node head;

    static class Node
    {
        int data;
        Node link;

        Node(int num){
            data = num;
            link = null;
        }
    }

    //insert a node at the front of linked list
    public void head(int num){
        Node temp = new Node(num);
        if(head==null){
            head = temp;
            return;
        }
        temp.link = head;
        head = temp;
    }

    //insert a node at the end of linked list
    public void append(int num){
        Node temp = new Node(num);
        if(head == null){
            head = temp;
            return;
        }
        Node temp1 = head;
        while (temp1.link!=null){
            temp1 = temp1.link;
        }

        temp1.link = temp;
    }

    //insert a node at given position in linked list
    public void insert(int num, int loc){
        Node temp = new Node(num);
        if(loc==1){
            temp.link = head;
            head = temp;
        }
        loc -= 2;
        Node temp1 = head;
        while (loc>0){
            temp1 = temp1.link;
            loc--;
        }
        temp.link = temp1.link;
        temp1.link = temp;
    }
  
    //print linked list
    public void print(){
        Node temp = head;
        while (temp!=null){
            System.out.print(temp.data + " ");
            temp = temp.link;
        }
    }

    //main
    public static void main(String[] args){
        Linkedlist list = new Linkedlist();
        list.append(2);
        list.append(4);
        list.append(5);
        list.head(1);
        list.insert(3,3);

        list.print();
    }
}
