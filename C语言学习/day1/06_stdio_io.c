#include<stdio.h>
//将变量等于0是为了赋初值

//scanf

int main(int argc, char const *argv[])
{
    int i = 0;
    int j = 0;
    //格式化输入
    printf("请输入");
    scanf("%d %d" , &i , &j);
    getchar();
    //格式化输出
    printf("你好，计算出的数值为：%d + %d = %d\n" , i , j , i + j);

    //getchar
    //putchar
    char ch = 'A';
    char ch_n = '\n';
    putchar(ch);
    putchar(ch_n);
    printf("请输入一个字符: \n");
    ch = getchar();
    putchar(ch);             
    putchar('\n');

    return 0;
}
