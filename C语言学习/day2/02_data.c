#include<stdio.h>
int main(int argc, char const *argv[])
{
    int i = 10;
    int j = 10;
    int k = 0;
    //算术运算      +-*/%（取余）
    //i     为变量
    //j+i   表达式
    printf("%d + %d = %d\n" , i , j , i + j);
    printf("%d - %d = %d\n" , i , j , i - j);
    printf("%d * %d = %d\n" , i , j , i * j);
    printf("%d / %d = %d\n" , i , j , i / j);
    printf("%d %% %d = %d\n" , i , j , i % j);
    printf("=================================\n");

    //赋值运算符    = += -= *= /= %=
    //  = ->  赋值      右值      赋值给    左值
    //      赋初值      int * p = NULL;
    //      当指针变量没有赋初值的时候，此时这个指针很有可能变成野指针
    i = 10;
    j = 5;
    k = i;
    printf("%d += %d\n" , i , i += j);
    //  i += j      ->      i = i + j
    printf("%d -= %d\n" , i , i -= j);
    //  i -= j      ->      i = i - j
    printf("%d *= %d\n" , i , i *= j);
    //  i *= j      ->      i = i * j
    printf("%d /= %d\n" , i , i /= j);
    //  i /= j      ->      i = i / j
    printf("%d %%= %d\n" , i , i %= j);
    //  i %%= j      ->      i = i % j
    printf("=================================\n");

    i = 10;
    j = 5;
    k = i;

    //关系运算符    == , != , > , < , >= , <=
    //判断真假
    //例如  i == j  就是判断 i 与 j 的值是否相等
    //如果相等      i == j      ->  1(或非0)
    //如果不相等    i == j      ->  0
    //if([表达式])      if判断内部表达式是否为0
    if (i == j){

        printf("进入到了if(i == j)\n");
        printf("%d == %d = %d\n" , i , j , i == j);

    }else
    {
        printf("没有进入到了if(i == j)\n");
        
    }

    if (i > j)
    {
        printf("进入到了if(i > j)\n");
    }

    if (i >= j)
    {
        printf("进入到了if(i >= j)\n");
    }
    if (i <= j)
    {
         printf("条件为进入\n");
    }else 
    {
        printf("进入到了if(i <= j)\n");
    }
    printf("=================================\n");

    //逻辑运算符    &&、||、!
    /*与逻辑    全一得一（双目运算符）
        逻辑        &&      &&      &&
        数据1       1       1       0
        数据2       1       0       0
        结果        1       0       0
    */

    /*或逻辑    有一得一（双目运算符）
        逻辑        ||      ||      ||
        数据1       1       1       0
        数据2       1       0       0
        结果        1       1       0
    */

    /*非逻辑    是一得零    是零得一（单目运算符）
        逻辑        !       !      
        数据       1       0       
        结果        0       1      
    */
    i = 10;
    j = 10;
    k = 5;
    if (i == j && i > k)
    {
        printf("这里是 if (i == j && i > k)\n");
    }
    if (!(i == j) && i < k)
    {
        printf("这里是 if (!(i == j) && i < k)\n");
    }
    if (!(i == j) || i > k)
    {
        printf("这里是 if (!(i == j) || i < k)\n");
    }
        
        printf("=================================\n");

    //自增自减运算符        ++  --
    i = 10;
    j = 10;
    k = 5;
    //用法
    //[变量名]++
    //[变量名]--
    //++[变量名]
    //--[变量名]
    //++后置，先执行后++
    //++前置，先++后执行
    //--同理

    //等效于    i++     ->      i = i + 1;
    printf("%d\n" , i++);
    //  i = 11
    printf("%d\n" , ++i);
    //  i = 12

    //等效于    i--     ->      i = i - 1;
    printf("%d\n" , i--);
    //  i = 12
    printf("%d\n" , --i);
    //  i = 10
    return 0;
}
