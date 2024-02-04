#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int fibo(int x)
{
    if(x==1 ||x==2)
    {
        return 1;
    }
    else
    {
        return(fibo(x-1)+fibo(x-2));
    }
}

int main()
{
    int num;
    printf("Enter the number Fibonacci series: ");
    scanf("%d",&num);
    printf("\n%dth Fibonacci Number is %d\n",num,fibo(num));
    getch();
    return 0;
}