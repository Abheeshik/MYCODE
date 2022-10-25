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

    if (head == NULL)
            head = temp;
        else {
            temp->next = head;
            head ->prev = temp;
            head = temp;
            }
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

/*void print(Node* head)
{
    
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }cout << endl;
}*/

Node* reverse(Node* &head)
{
    Node* curr = head;
    Node* temp = NULL;
    
    while(curr != NULL)
    {
        temp = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = temp;
        curr = curr -> prev;
    }

    if (temp != NULL)
    {
        head = temp;
    }
    
    return head;
    
}



int main()
{
   //Node* node1 = new Node(10);
    
    Node* head = NULL;
    Node* end  = NULL;

    

    insertAtHead(head , 11);
    insertAtHead(head , 22);
    insertAtHead(head , 56);
    insertAtHead(head , 12);
    insertAtHead(head , 87);
    print(head);

    reverse(head);
    print(head);

    
}