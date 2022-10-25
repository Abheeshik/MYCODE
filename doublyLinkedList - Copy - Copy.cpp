#include<iostream>
using namespace std;

class Node
{
    public:
      int data;
      Node* prev;
      Node* next;

      Node(int d)
      {
        this-> data = d;
        this -> prev = NULL;
        this -> next = NULL; 
      }

};

void insertAtHead(Node* &head, int d)
{
    Node* temp = new Node(d);

    temp ->next = head;

    head ->prev = temp;

    head = temp;
}

void insertAtEnd( Node* &end, int d)
{
    Node* temp = new Node(d);

    end -> next = temp;

    temp -> prev = end;

    end = temp;

}

void print(Node* head)
{
    Node* temp = head;

    while (temp!= NULL)
    {
        cout << temp ->data << " ";
        temp = temp ->next;
    }
    cout << endl;
    
}
int getLength(Node* head)
{
     int len=0;
     Node* temp = head;

    while (temp!= NULL)
    {
        len++;
        temp = temp ->next;
    }
    return len;
}

int main()
{
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* end  = node1;

    print(head);

    //cout << getLength(head) << endl;

    insertAtHead(head , 11);
    print(head);

    insertAtHead(head , 22);
    print(head);

    insertAtEnd(end , 44);
    print(head);

    insertAtEnd(end , 77);
    print(head);

    insertAtEnd(end , 55);
    print(head);

}