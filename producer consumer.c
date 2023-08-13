/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int mutex=1;
int full=0;
int empty,x=0;
void producer()
{
    
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\n producer produces item %d",x);
    ++mutex;
}
void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("\n Consumer Consumes item%d",x);
    x--;
    ++mutex;
}
int main()
{
    int n,i;
    printf("enter the buffer size");
    scanf("%d",&empty);
    printf("\n 1.press ! for producer""\n press 2 for consumer""\npress 3 for exit");
    for (i=1;i>0;i++)
    {
        printf("\nenter your choice");
        scanf("%d",&n);
        switch(n)
        {
            case 1:if ((mutex==1)&&(empty!=0))
                    {
                        producer();
                    }
                    else
                    {
                        printf("buffer is full");
                    }
                    break;
            case 2:if ((mutex==1)&&(full!=0))
                     {
                        consumer();
                
                     }
                     else{
                        printf("bufer is empty");
                     }
                     break;
            case 3:exit(0);
            break;
        }
    }
}
