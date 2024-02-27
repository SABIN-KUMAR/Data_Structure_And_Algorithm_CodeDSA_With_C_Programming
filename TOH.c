#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

//let,source=A,Auxiliary=B,Destination=C
int TOH(int n,char a,char b,char c)
{
    if(n==1)
    {
        printf("Move %d disk from %c to %c:\n",n,a,c);
        return 1;
    }
    else
    {
        TOH(n-1,a,c,b);
        printf("Move %d disk form %c to %c:\n",n,a,c);
        TOH(n-1,b,a,c);
    }
}

int main()
{
    
    int n;
    printf("Enter the  numbers of disks:");
    scanf("%d",&n);
    printf("Te sequence of solving the Tower of Hanoi problem is as follows:\n");
    TOH(n,'A','B','C');
    getch();
    return 0;
}
