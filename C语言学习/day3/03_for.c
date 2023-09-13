#include<stdio.h>
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("hello\n");
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("*");
        }
        printf("\n");
        
    }

    for (int i = 0; i < 5; i++)
    {
        for (int a = 5; a > i; a--)
        {
            printf(" ");
        }
        
        for (int j = 0; j < i*2+1 ; j++)
        {
                printf("*");          
        }
        printf("\n");
        
    }

    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d * %d = %-5d" , i , j , i * j);
        }
        printf("\n");
    }
    
    
    
    
    return 0;
}
