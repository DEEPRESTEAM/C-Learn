#include<stdio.h>
//在建立字符串时最好要定义下标(数组长度)
//  数组定义    char str[50] = {"hello"};

//在单片机中    字符函数的用途  ->  通讯    串口通讯
int main(int argc, char const *argv[])
{
    char str[50] = {0};
    scanf("%s" , str);
    printf("%s" , str);
    return 0;
}
