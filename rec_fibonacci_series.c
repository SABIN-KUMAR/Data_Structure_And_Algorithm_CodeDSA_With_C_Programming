#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int fibo(int x)
{
    if(x==1||x==2)
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
    int num,i;
    printf("Enter a number: ");
    scanf("%d",&num);
    printf("The Fibonacci series of %d.",num);
    for(i=1;i<=num;i++)
    {
        printf("%d \t",fibo(i));
    }
    getch();
    return 0;

}