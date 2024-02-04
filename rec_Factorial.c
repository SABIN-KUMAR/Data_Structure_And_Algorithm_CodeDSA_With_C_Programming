#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int factorial(int num)
{
    if(num==0)
    {
        return 1;
    }
    else
    {
        return(num*factorial(num-1));
    }
}

int main()
{
    int num_1;
    printf("Enter the numbers:");
    scanf("%d",&num_1);
    printf("The factorial of %d is %d",num_1,factorial(num_1));
    getch();
    return 0;
}