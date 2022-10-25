#include<iostream>
#include<queue>
using namespace std;

class Node{

   public:
   int data;
   Node* left;
   Node* right;

   Node(int d)
   {
    this -> data = d;
    this -> left = NULL;
    this -> right = NULL;
   }
};

void LevelOrder(Node* root)
{
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

   while(!q.empty())
   {
    Node* temp = q.front();
    q.pop();

    if(temp == NULL)
    {
        cout << endl;
        if(!q.empty())
        {
            q.push(NULL);
        }
    }
    else
    {
        cout << temp -> data << " ";
        if(temp ->left)
        {
            q.push(temp->left);

        }
        if(temp -> right)
        {
            q.push(temp->right);

        }
    }
   }
}

Node* MinVal(Node* root)
{
    Node* temp = root;

    while (temp -> left != NULL)
    {
        temp = temp -> left;
    }

    return temp;
}

Node* MaxVal(Node* root)
{
    Node* temp = root;

    while (temp -> right != NULL)
    {
        temp = temp -> right;
    }

    return temp;
}

void inorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root ->data << " ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root ->data << " ";
    preorder(root->left);
    preorder(root->right);
}


void postorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root ->data << " ";
}

Node* deleteFromBST(Node* root , int key)
{
    
    if(root == NULL)
    {
        return root;
    }

    if(root -> data == key)
    {
        if(root -> left == NULL && root -> right == NULL)
        {
            delete(root);
            return NULL;
        }

        if(root -> left != NULL && root -> right == NULL)
        {
            Node* next = root -> left;
            delete(root);
            return next;
        }
        if(root -> left == NULL && root -> right != NULL)
        {
            Node* next = root -> right;
            delete(root);
            return next;
        }

        if(root -> left != NULL && root -> right != NULL)
        {
            int mini = MinVal(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root->right,mini);
            return root;

        }
    }

    else if(root -> data > key )
    {
        root -> left = deleteFromBST(root -> left,key);
        return root;
    }

    else
    {
        root -> right = deleteFromBST(root -> right,key);
        return root;
    }
}


Node* insertIntoBST(Node* root,int d)
{

    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if(d > root -> data)
    {
        root -> right = insertIntoBST(root->right,d);

    }
    else
    {
        root -> left = insertIntoBST(root->left,d);
    }

    return root;
}
void takeInput(Node* &root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = insertIntoBST(root,data);
        cin >> data;
    }
}

int main()
{
    Node* root = NULL;

    cout << "enter data to create BST " << endl;

    takeInput(root);

    cout << "printing bst" << endl;
    LevelOrder(root);

    cout <<"printing inorder traversal" << endl;
    inorder(root);

    cout << endl << "printing preorder traversal" << endl;
    preorder(root);

    cout << endl <<"printing postorder traversal" << endl;
    postorder(root);

    root = deleteFromBST(root,50);

    cout << endl << "bst after deletion" << endl;

    cout << "printing bst" << endl;
    LevelOrder(root);

    cout <<"printing inorder traversal" << endl;
    inorder(root);

    cout << endl << "printing preorder traversal" << endl;
    preorder(root);

    cout << endl <<"printing postorder traversal" << endl;
    postorder(root);

    

    return 0;
}