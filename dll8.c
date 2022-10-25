#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct node 
{
    char ssn[40];
    char name[40];
    char dept[40];
    char desg[40];
    float sal;
    char phno[40];

    struct node* rlink;
    struct node* llink;
};
typedef struct node* NODE;

NODE insert_front(char ssn[40],char name[40],char dept[40],char desg[40],float sal,char phno[40],NODE first)
{
    NODE temp;

    temp = (NODE)malloc(sizeof(struct node));

    strcpy(temp->ssn,ssn);
    strcpy(temp->name,name);
    strcpy(temp->dept,dept);
    strcpy(temp->desg,desg);
    temp->sal=sal;
    strcpy(temp->phno,phno);

    temp->llink=NULL;
    temp->rlink=NULL;

    if (first==NULL)
    {
        return temp;
    }
    temp->llink=NULL;
    temp->rlink=first;
    first->llink=temp;
    return temp;
    
}
NODE insert_rear(char ssn[40],char name[40],char dept[40],char desg[40],float sal,char phno[40],NODE first)
{
    NODE temp,cur;

    temp=(NODE)malloc(sizeof(struct node));

    strcpy(temp->ssn,ssn);
    strcpy(temp->name,name);
    strcpy(temp->dept,dept);
    strcpy(temp->desg,desg);
    temp->sal=sal;
    strcpy(temp->phno,phno);

    temp->llink=NULL;
    temp->rlink=NULL;

    if (first==NULL)
    {
        return temp;
    }
    
    cur=first;
    while (cur->rlink!=NULL)
    {
        cur=cur->rlink;
    }
    cur->rlink=temp;
    temp->llink=cur;
    
    return first;
    
}

NODE delete_front(NODE first)
{
    NODE cur;

    if (first==NULL)
    {
        printf("LIST IS EMPTY\n");
        return first;
    }
    if (first->rlink==NULL)
    {
        printf("Employee with following details is deleted\n");
        printf("ssn : %s\n",first->ssn);
        printf("name : %s\n",first->name);
        printf("dept : %s\n",first->dept);
        printf("desg : %s\n",first->desg);
        printf("sal : %f\n",first->sal);
        printf("phone no : %s\n\n",first->phno);

        free(cur);
        return NULL;
    }

    cur=first;
    first=first->rlink;

     printf("Employee with following details is deleted\n");
     printf("ssn : %s\n",cur->ssn);
     printf("name : %s\n",cur->name);
     printf("dept : %s\n",cur->dept);
     printf("desg : %s\n",cur->desg);
     printf("sal : %f\n",cur->sal);
     printf("phone no : %s\n\n",cur->phno);

     free(cur);
     first->llink=NULL;
     return first;


}

NODE delete_rear(NODE first)
{
    NODE prev,cur;

    if (first==NULL)
    {
        printf("LIST IS EMPTY\n");
        return first;
    }
     if (first->rlink==NULL)
    {
        printf("Employee with following details is deleted\n");
        printf("ssn : %s\n",first->ssn);
        printf("name : %s\n",first->name);
        printf("dept : %s\n",first->dept);
        printf("desg : %s\n",first->desg);
        printf("sal : %f\n",first->sal);
        printf("phone no : %s\n\n",first->phno);

        free(first);
        return NULL;
    }

    cur=first;
    while (cur->rlink!=NULL)
    {
        cur=cur->rlink;
    }
    prev=cur->llink;

     printf("Employee with following details is deleted\n");
     printf("ssn : %s\n",cur->ssn);
     printf("name : %s\n",cur->name);
     printf("dept : %s\n",cur->dept);
     printf("desg : %s\n",cur->desg);
     printf("sal : %f\n",cur->sal);
     printf("phone no : %s\n\n",cur->phno);

     free(cur);
     prev->rlink=NULL;
     return first;
    
}

void display(NODE first)
{
    NODE cur;
    int count=0;

    if (first==NULL)
    {
        printf("List is empty\n");
        printf("The no of nodes in the list is %d\n\n",count);
        return;
    }
    cur=first;
    printf("\nThe contents of list are\n");
    printf("\nssn\tname\tdept\tdesg\tsal\tphone no\n\n");

    while (cur!=NULL)
    {
        count++;

        printf("ssn : %s\n",cur->ssn);
        printf("name : %s\n",cur->name);
        printf("dept : %s\n",cur->dept);
        printf("desg : %s\n",cur->desg);
        printf("sal : %f\n",cur->sal);
        printf("phone no : %s\n\n",cur->phno);
       

        cur=cur->rlink;
    }
    printf("The no of nodes in the list is %d\n\n",count);
    
    
}

void main()
{
    int choice,n,i;
    char ssn[40],name[40],dept[40],desg[40],phno[40];
    float sal;

    NODE first = NULL;

    printf("Enter the number of employees\n");
    scanf("%d",&n);

    for ( i = 0; i < n; i++)
    {
        printf("Enter ssn\n");
        scanf(" %[^\n]", ssn);
        printf("Enter name\n");
        scanf(" %[^\n]", name);
        printf("Enter dept\n");
        scanf(" %[^\n]", dept);
        printf("Enter desg\n");
        scanf(" %[^\n]", desg);
        printf("Enter salary\n");
        scanf("%f", &sal);
        printf("Enter phone no\n");
        scanf(" %[^\n]", phno);

        first=insert_rear(ssn,name,dept,desg,sal,phno,first);
        printf("\n\n");
        
    }

    
    for(;;)
    {
        printf("1.Insert front\n2.Insert rear\n3.Delete front\n4.Delete rear\n5.Display\n6.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        printf("\n");

        switch(choice)
        {
            case 1: printf("Enter ssn\n");
                    scanf(" %[^\n]", ssn);
                    printf("Enter name\n");
                    scanf(" %[^\n]", name);
                    printf("Enter dept\n");
                    scanf(" %[^\n]", dept);
                    printf("Enter desg\n");
                    scanf(" %[^\n]", desg);
                    printf("Enter salary\n");
                    scanf("%f", &sal);
                    printf("Enter phone no\n");
                    scanf(" %[^\n]", phno);
                    first=insert_front(ssn,name,dept,desg,sal,phno,first);
                    printf("\n");
                    break;

            case 2: printf("Enter ssn\n");
                    scanf(" %[^\n]", ssn);
                    printf("Enter name\n");
                    scanf(" %[^\n]", name);
                    printf("Enter dept\n");
                    scanf(" %[^\n]", dept);
                    printf("Enter desg\n");
                    scanf(" %[^\n]", desg);
                    printf("Enter salary\n");
                    scanf("%f", &sal);
                    printf("Enter phone no\n");
                    scanf(" %[^\n]", phno);
                    first=insert_rear(ssn,name,dept,desg,sal,phno,first);
                    printf("\n");
                    break;

            case 3: first=delete_front(first);
                    printf("\n");
                    break;

            case 4: first=delete_rear(first);
                    printf("\n");
                    break;

            case 5: display(first);
                    printf("\n");
                    break;


            default:exit(0);


            
        
        }
        
    }
    
}