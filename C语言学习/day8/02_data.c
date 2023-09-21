#include<stdio.h>


int fun(int num){
    if (num == 0 )
    {
       return 1;
    }
    return num * fun(num - 1);
}

int main(int argc, char const *argv[])
{
    int sum = fun(5);
    printf("%d\n" , sum);
    return 0;
}
