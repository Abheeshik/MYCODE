#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;

        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "memory is free for node with data " << value << endl;
        
    }
};

void inseretAtHead(Node* &head,int d)
{
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtEnd(Node* &end,int d)
{
    Node* temp = new Node(d);

    end ->next = temp;
    end = temp;
}

void insertAtPosition(Node* &end,Node* &head, int position , int d)
{

    if (position == 1)
    {
       inseretAtHead(head , d);
       return;
    }
    
    Node* temp = head;

    int cnt = 1;

    while (cnt < position-1)
    {
        temp = temp ->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtEnd(end , d);
        return;
    }
    

    Node* nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;

    temp ->next = nodeToInsert;
    
}

void deleteNode(Node* &head,int position)
{
    if (position == 1)
    {
        Node* temp = head;
        head = head -> next;
        temp ->next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt ++;
        }
        prev -> next = curr ->next;
        curr -> next = NULL;
        delete curr;
    }
    

}

void deleteNodeValue(Node* &head,int value)
{
    Node* curr = head;
    Node* prev = NULL;

    if (curr != NULL && curr -> data == value)
    {
        Node* curr = head;
        head = head -> next;
        curr -> next = NULL;
        delete curr;
    }
    
    else
    {
        while (curr != NULL && curr -> data != value)
    {
           prev = curr;
           curr = curr -> next;
    }
    
    
    if (curr == NULL)
    {
        cout << "node does not exist" << endl;
        return;
    }
    
             prev -> next = curr ->next;
             curr -> next = NULL;
             delete curr;
    }
       
       
    
}

void print(Node* &head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp -> next;
    }

    cout << endl;
    
}

int main()
{
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* end = node1;

    print(head);

    inseretAtHead(head, 12);

    print(head);

    inseretAtHead(head, 19);

    print(head);

    insertAtEnd(end,17);

    print(head);

    insertAtPosition(end,head, 5 , 111);

    print(head);

    cout << "end-> " << end->data << endl;
    cout << "head-> " << head->data << endl;

   // deleteNode(head , 5);
    //print(head);

   deleteNodeValue(head , 111);
   print(head);

   cout << "end-> " << end->data << endl;
    cout << "head-> " << head->data << endl;


    

    
}