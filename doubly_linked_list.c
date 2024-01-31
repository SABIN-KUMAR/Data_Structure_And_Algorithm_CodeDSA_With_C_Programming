#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

//Define the structure for node in the doubly linked
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

//Function to create a new node
struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

//Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node* Head, int data)
{
    struct Node* newNode=createNode(data);
    if(Head==NULL)
    {
        return newNode;
    }
    newNode->next=Head;
    Head->prev=newNode;
    return newNode;
}

//Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data)
{
    struct Node* newNode=createNode (data);
    if(head==NULL)
    {
        return newNode;
    }
    struct Node*current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newNode;
    newNode->prev=current;
    return head;
}

//Function to insert a node before a given position
struct Node* insertbeforePosition(struct Node* head,int data,int position)
{
    struct Node* newNode=createNode(data);
    if(head==NULL ||position<=1)
    {
        newNode->next=head;
        if(head != NULL)
        {
            head->prev=newNode;
        }
        return newNode;
    }
    struct Node* current =head;
    int currentPosition=1;

    while(currentPosition<position-1 &&current!=NULL)
    {
        current=current->next;
        currentPosition++;
    }
    newNode->next=current->next;
    newNode->prev=current;
    if(current->next!=NULL)
    {
        current->next->prev=newNode ;
    }
    current->next=newNode;
    return head;
}

//Function to insert a node after the a given position
struct Node *insertAfterPosition(struct Node* head ,int data,int position)
{
    struct Node*newNode=createNode(data);
    if(head==NULL ||position<1)
    {
        return newNode;
    }
    struct Node*current=head;
    int currentPosition=1;
    while(current!=NULL && currentPosition<position)
    {
        current=current->next;
        currentPosition++;
    }
    newNode->next=current->next;
    newNode->prev=current;
    if(current->next!=NULL)
    {
        current->next->prev=newNode;
    }
    current->next=newNode;
    return head;
}

//Function to delete the first or beginning node in the list
struct Node*deleteAtBeginning (struct Node* head)
{
    if (head==NULL)
    {
        printf("The list is Empty.. || Cannot able to delete...");
        return NULL;
    }
    struct Node*newHead=head->next;
    if(newHead!=NULL)
    {
        newHead->prev=NULL;
    }
    free(head);
    printf("\nDeleted the first node..\n");
    return newHead;
}

//Function to delete the last node in the last
struct Node*deleteAtEnd(struct Node *head)
{
    if(head==NULL)
    {
        printf("\nThe list is Empty.... || cannot able to delete..");
        return NULL;
    }
    struct Node*current=head;
    while(current->next != NULL)
    {
        current=current->next;
    }
    if(current->prev!=NULL)
    {
        current->prev->next=NULL;
    }
    else
    {
        //only one node in the list
        head = NULL;
    }
    free(current);
    printf("\n Deleted the Last node.. \n");
    return head;
}

//Function to delete a node at a given position
struct Node* deleteAtPosition(struct Node *head,int position)
{
    if(head==NULL)
    {
        printf("The list is Empty...|| cannot able to delete..");
        return NULL;
    }
    if(position<=1)
    {
        return deleteAtBeginning(head);
    }
    struct Node*current=head;
    int currentPosition=1;
    while(current!=NULL && currentPosition<position)
    {
        current=current->next;
        currentPosition++;
    }
    if(current==NULL)
    {
        printf("\nPosition not found..||Cannot able to delete..");
        return head;
    }
    if(current->prev!=NULL)
    {
        current->prev->next=current->next;
    }
    else
    {
        head=current->next;
    }
    if(current->next!=NULL)
    {
        current->next->prev=current->prev;
    }
    free(current);
    printf("\nDeleted node at a positin:%d.\n",position);
    return head;
}

//Function to display the doubly linked list
void displayList(struct Node*head)
{
    printf("The Doubly linked list:");
    while(head!=NULL)
    {
        printf("%d <-> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

//Main function of the code of the doubly linked list

int main()
{
    struct Node*head=NULL;
    int choice,data,position;

    do
    {
        printf("\nDoubly Linked List Operations");
        printf("\n1.Insert at the beginning:");
        printf("\n2.Insert at the end:");
        printf("\n3.Insert before the position:");
        printf("\n4.Insert after the position:");
        printf("\n5.Delete form the beginning:");
        printf("\n6.Delete from the end:");
        printf("\n7.Delete from any specific position:");
        printf("\n8.Display the list:");
        printf("\n9.Exit:");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
            printf("\nEnter the data to insert at the beginning:\n");
            scanf("%d",&data);
            head=insertAtBeginning(head,data);
            break;

            case 2:
            printf("\nEnter the data to insert at the end:\n");
            scanf("%d",&data);
            head=insertAtEnd(head,data);
            break;

            case 3:
            printf("\nEnter the data to insert:\n");
            scanf("%d",&data);
            printf("\nEnter the position before where you want to insert:\n");
            scanf("%d",&position);
            head=insertbeforePosition(head,data,position);
            break;

            case 4:
            printf("\nEnter the data to insert:\n");
            scanf("%d",&data);
            printf("\nEnter the position after which you want to insert:\n");
            scanf("%d",&position);
            head=insertAfterPosition(head,data,position);
            break;

            case 5:
            head=deleteAtBeginning(head);
            break;

            case 6:
            head=deleteAtEnd(head);
            break;

            case 7:
            printf("\nEnter the specific position to delete:\n");
            scanf("%d",&position);
            head = deleteAtPosition(head,position);
            break;

            case 8:
            displayList(head);
            break;

            case 9:
            printf("\nExiting the program:\n");
            break;

            default:
            printf("\nInvalid choice.Please Enter A Valid Option:\n");
        }

    } while (choice!=9);

    //Free allocated memory before exiting
    struct Node* current=head;
    while(current != NULL)
    {
        struct Node *nextNode=current->next;
        free(current);
        current=nextNode;
    }
    return 0;
    
}