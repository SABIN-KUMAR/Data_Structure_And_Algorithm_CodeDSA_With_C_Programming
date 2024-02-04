#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

void reverse_char()
{
    char c;
    scanf("%c", &c);
    if(c!='\n')
    {
        reverse_char();
        printf("%c ", c);
    }
}

int main()
{
    printf("Enter a character: ");
    reverse_char();
    getch();
    return 0;
}