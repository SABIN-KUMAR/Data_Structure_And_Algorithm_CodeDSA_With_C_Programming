#include<stdio.h>
#include<math.h>
#include<stdlib.h>

static int MAXSIZE=5,front=-1,rear=-1,que[10],i;

void enqueue()
{
    if ((rear+1)%MAXSIZE == front)  //Queue is full
    {
        printf("Queue is full..\n");
    }

    else
    {
        rear=(rear+1)%MAXSIZE;     //For proper wrap around of queue index
        printf("Enter the input value for insertion:\n");
        scanf("%d",&que[rear]);

        printf("The value is inserted is %d.\n",que[rear]);
    }
}

void dequeue()
{
    if(front==rear)   //Queue is empty
    {
        printf("The queue is empty..\n");

    }
    else
    {
        printf("The value delected from queue is %d \n",que[front]);
        front =(front +1 )%MAXSIZE ;//For proper wrap around of queue index
        printf("The next value is %d.\n",que[front]);
    }
}
void display()
{
    if(front == rear)
    {
        printf("The queue is empty..\n");
    }
    else
    {
        printf("The values in queue are:\n");
        for(i=front;i!=rear;i=(i+1)%MAXSIZE)
        {
            printf("%d \n",que[i]);
        }
    }
}

int main()
{
    do
    {
        printf("1.Enqueue \n2.Dequeue \n3.Display \n4.Exit \n");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("The code terminated to close.\n");
            exit(0);
            
            default:
            break;
        }
    

    }
    while(1);
    return 0;
}