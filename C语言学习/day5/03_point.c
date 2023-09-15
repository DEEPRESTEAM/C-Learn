#include<stdio.h>

int main(int argc, char const *argv[])
{
    int num = 50;
    int * p;
    p = &num;
    printf("%d\n" , *p);
    printf("%p\n" , &p);
    printf("%p\n" , &num);
    return 0;
}
