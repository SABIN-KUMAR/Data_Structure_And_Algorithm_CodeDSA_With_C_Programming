#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

//let,source=A,Auxiliary=B,Destination=C
int TOH(int n,char A,char B,char C)
{
    if(n==1)
    {
        printf("Move %d disk from %c to %c:\n",n,A,B);
        return 1;
    }
    else
    {
        TOH(n-1,A,B,C);
        printf("Move %d disk form %c to %c:\n",n,A,C);
        TOH(n-1,B,C,A);
    }
}

int main()
{
    //char source=S,Destination=D,Axiliary=A
    int n;
    printf("Enter the  numbers of disks:");
    scanf("%d",&n);
    printf("Te sequence of solving the Tower of Hanoi problem is as follows:\n");
    TOH(n,'S','D','A');
    getch();
    return 0;
}