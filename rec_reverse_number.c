#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int sum =0,rem;
int reverse_num(int num)
{
    if(num)
    {
        rem=num%10;
        sum=(sum*10)+rem;
        reverse_num(num/10);
    }
    else
    {
        return sum;
    }
}

int main()
{
    int num_1;
    printf("Enter a number: ");
    scanf("%d",&num_1);
    printf("The reverse of %d is %d",num_1,reverse_num(num_1));
    getch();
    return 0;
}