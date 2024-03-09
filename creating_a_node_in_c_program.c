#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *list;
};

int main()
{
    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    printf("Address:-%d\n",head);
    printf("Size of data types:-%d\n", sizeof(struct node)); 
    head->data = 10;
    head->list = NULL;
    printf("%d",head->data);
    return 0;

}