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
  
    //delete a node
    public void delete(int loc){
        Node temp = head;
        if(loc==1){
            head = temp.link;
            return;
        }
        loc -=2;
        while (loc>0){
            temp = temp.link;
            loc--;
        }

        Node temp1 = temp.link;
        temp.link = temp1.link;
    }
  
    //print linked list
    public void print(){
        Node temp = head;
        while (temp!=null){
            System.out.print(temp.data + " ");
            temp = temp.link;
        }
    }
  public static void main(String[] args){
        //Scanner scan = new Scanner(System.in);
        Linkedlist list = new Linkedlist();
        list.append(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.append(5);
    
        list.delete(3);

        list.print();
    }
}
