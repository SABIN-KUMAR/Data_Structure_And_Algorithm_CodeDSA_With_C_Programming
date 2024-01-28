#include<stdio.h>
#define MAX_SIZE 5

int stack[MAX_SIZE];
int top=-1;

void push(int item)
{
    if(top==MAX_SIZE-1)
    {
        printf("overflow!! and Exit \n");
    }
    else
    {
        stack[++top]=item;
        printf("%d Item Inserted \n ",item);
    }

}

void pop()
{
    if(top==-1)
    {
        printf("Underflow!! and Exit \n");
    }
    else
    {
        int Item=stack[top--];
        printf("%d Item Deleted.\n",Item);
    }
}

void display()
{
    if(top==-1)
    {
        printf("The stack is empty.\n");
    }
    else
    {
        printf("Stack elements.");
        for(int i=0;i<=top;i++)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice,item;
    printf(" 1.push\n 2.pop\n 3.display\n 4.Exit\n");
    while(1)
    {
        printf("Enter your choice.");
        scanf("%d",&choice);
         switch(choice)
         {
            case 1:
            printf("Enter the value to push:");
            scanf("%d",&item);
            push(item);
            break;

            case 2:
            pop();
            break;

            case 3:
            display();
            break;

            case 4:
            return 0;
            default:
            printf("Invalid choice!!!");

         }
   

    }
   return 0;
}