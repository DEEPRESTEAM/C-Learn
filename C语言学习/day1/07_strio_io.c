#include<stdio.h>

int main(int argc, char const *argv[])
{
    //%u以十进制机制输出无符号整数
    unsigned int num = -10;
    printf("%d\n",num);

    //%f 以小数形式输出单、双精度浮点型
    float p = 3.1415926;
    printf("%f\n" , p);
    //加上 .4 显示小数点后四位
    printf("%.10f\n" , p);


    double P = 3.1415926;
    printf("%f\n" , P);
    printf("%.10f\n" , P);

    //双精度与单精度的区别（都保留小数点后十位）
    //   float  3.1415925026
    //   double 3.1415926000
    //   %e %E 以指数形式输出单，双精度浮点数
    printf("%e,%E\n" , P , P);

    //   %g %G 根据值得不同，自动选择%f或%e，%E格式输出单，双精度浮点数
    printf("%e,%E\n" , P , P);


    char ch = 'A';
    // %c---输出单个字符
    printf("%c %d\n" , ch , ch);

    // %s---输出字符串
    char str[128] = "hello world";
    printf("%s\n" , str);

    return 0;

}
