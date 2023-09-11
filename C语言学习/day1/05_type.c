#include<stdio.h>
//浮点型包括：float、double、long double。
int main(int argc, char const *argv[])
{
    //单精度浮点型
    float f1 = 3.14;
    int in = 3.14;
    printf("%ld\n",sizeof(f1));
    printf("%ld\n",sizeof(double));
    printf("%ld\n",sizeof(long double));
    return 0;
}
