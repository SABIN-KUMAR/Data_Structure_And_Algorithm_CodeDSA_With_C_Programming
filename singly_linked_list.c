#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

struct node
{
    int info;
    struct node *link;

};
struct node*start =NULL;

//creating the singly linked list..
void createlist()
{
    if(start==NULL)
    {
        int n;
        printf("\nEnter the number of nodes:");
        scanf("%d",&n);
        if(n!=0)
        {
            int data,i;
            struct node *newnode;
            struct node *temp;
            newnode=malloc(sizeof(struct node));
            start=newnode;
            temp=start;
            printf("\nEnter the number to be inserted:\n");
            scanf("%d",&data);
            start->info=data;
            for(i=2;i<=n;i++)
            {
                newnode=malloc(sizeof(struct node));
                temp->link=newnode;
                printf("\nEnter the number to be inserted:\n");
                scanf("%d",&data);
                newnode->info=data;
                temp=temp->link;
            }
            
        }
        printf("\nThe list is created:\n");
        
        
    }
    else
    
        printf("\nThe list is already created:\n");
    
}

//function for the traversing in the singly linked list
void traverse()
{
    struct node*temp;
    if(start==NULL)
    {
        printf("\nThe list is Empty..");
    }
    else
    {
        temp=start;
        while(temp!=NULL)
        {
            printf("%d\t",temp->info);
            temp=temp->link;
        }
    }
}

//funtion to inserted the data at the beginning or front
void insertAtFront()
{
    int data;
    struct node*temp;
    temp=malloc(sizeof(struct node));
    printf("Enter the number to be inserted:\n");
    scanf("%d",&data);
    temp->info=data;
    temp->link=start;
    start=temp;
}

//function to inserted the data at the end or last
void insertAtEnd()
{
    int data;
    struct node*temp,*head;
    temp=malloc(sizeof(struct node));
    printf("Enter the number to be inserted:\n");
    scanf("%d",&data);
    temp->link=0;
    temp->info=data;
    head=start;
    while(head->link!=NULL)
    {
        head=head->link;
    }
    head->link=temp;
}

//function to inserted the data at the specific position
void insertAtPosition()
{
    struct node*temp,*newnode;
    int pos,data,i=1;
    newnode=malloc(sizeof(struct node));
    printf("\nEnter the position and data:\n");
    scanf("%d %d",&pos,&data);
    temp=start;
    newnode->info=data;
    newnode->link=0;
    while(i<pos-1)
    {
        temp=temp->link;
        i++;
    }
    newnode->link=temp->link;
    temp->link=newnode;
}

//function to deleted the data from the beginning or first
void deleteFirst()
{
    struct node*temp;
    if(start==NULL)
    {
        printf("\nThe list is Empty..\n");
    }
    else
    {
        temp=start;
        start=start->link;
        free(temp);
    }
}

//function to deleted the data from  the End or last
void deleteEnd()
{
    struct node*temp,*prevnode;
    if(start==NULL)
    {
        printf("\nThe list is Empty..\n");

    }
    else
    {
        temp=start;
        while(temp->link!=0)
        {
            prevnode=temp;
            temp=temp->link;
        }
        free(temp);
        prevnode->link=0;
    }
}

//function to deleted the data from the specific position
void deletePosition()
{
    struct node*temp,*position;
    int pos,i=1;
    if(start==NULL)
    {
        printf("\nThe list is Empty..\n");

    }
    else
    {
        printf("Enter the Index:");
        scanf("%d",&pos);
        temp=start;
        while(i<pos-1)
        {
            temp=temp->link;
            i++;
        }
        position=temp->link;
        temp->link=position->link;
        free(position);
    }
}

//the main function of the singly linked list program
int main()
{
    int choice;
    while(1)
    {

        printf("\n1.To see the list:");
        printf("\n2.For insertion at starting:");
        printf("\n3.For insertion at End");
        printf("\n4.For insertion at any position:");
        printf("\n5.For deletion of first element:");
        printf("\n6.For Deletion of last element:");
        printf("\n7.For Deletion of element of any Position:");
        printf("\n8.To Exit the program:");
        printf("\n\nEnter the choice:\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            traverse();
            break;

            case 2:
            insertAtFront();
            break;

            case 3:
            insertAtEnd();
            break;

            case 4:
            insertAtPosition();
            break;

            case 5:
            deleteFirst();
            break;

            case 6:
            deleteEnd();
            break;

            case 7:
            deletePosition();
            break;

            case 8:
            exit(1);
            default:
            printf("\nIncorrect choice.....");
            getch();
        }
    }
    return 0;
}