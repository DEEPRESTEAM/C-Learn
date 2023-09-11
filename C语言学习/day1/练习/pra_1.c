#include<stdio.h>


/**
 * 加法
 * 传入两个int类型参数，返回两个数的总和
*/
int add(int num_1 , int num_2){
    int sum = 0;
    sum = num_1 + num_2;
    return sum;
}


/**
 * 减法
 * 传入两个int类型参数，返回两个数相减的值
*/
int subtraction(int num_1 , int num_2){
    int sub = num_1 - num_2;
    return sub;
}

/**
 * 乘法
 * 传入两个int类型参数，返回两个数相乘的值
*/
int multiplication(int num_1 , int num_2){
    int mul = num_1 * num_2;
    return mul;
}

/**
 * 除法
 * 传入两个int类型参数，返回两个数相除的值，返回类型为浮点型
*/
int division(int num_1 , int num_2){
    int div = num_1 / num_2;
    return div;
}

/**
 * 每次计算的结果
*/
void result(int num_1 , int num_2 , int sum , char str){
    printf("************************\n");
    printf("*     %d %c %d = %d     *\n" , num_1 , str ,num_2 , sum); 
    printf("************************\n");
}

void title(){
    printf("******************************\n");
    printf("*         1:加法运算         *\n");
    printf("*         2:减法运算         *\n");
    printf("*         3:乘法运算         *\n");
    printf("*         4:除法运算         *\n");
    printf("*         5:退出运算         *\n");
    printf("******************************\n");
}



int main(int argc, char const *argv[])
{   
    int num_1 = 0; 
    int num_2 = 0;
    int sum , sub , mul ;
    double div;
    printf("输入第一个值：");
    scanf("%d" , &num_1);
    getchar();
    printf("输入第二个值：");
    scanf("%d" , &num_2);

    printf("******************************\n");
    printf("*           num_1 = %d      *\n" , num_1);
    printf("*           num_2 = %d      *\n" , num_2);
    printf("******************************\n");

    int flag = 1;
    while (flag)
    {   
       
        title();
        printf("输入所需要的选项\n");
        scanf("%d" , &flag);
        getchar();
      
        switch (flag){

            case 1:
                sum = add(num_1,num_2);
                result(num_1 , num_2 , sum , '+');
                break;

            case 2:
                sub = subtraction(num_1 , num_2);
                result(num_1 , num_2 , sub , '-');
                break;

            case 3:
                mul = multiplication(num_1 , num_2);
                result(num_1 , num_2 , mul , '*');
                break;

            case 4:
                div = division(num_1 , num_2);
                result(num_1 , num_2 , div , '/');
                break;

            case 5:
                flag = 0;
                break;

            default:
                printf("输入有误，请重新输入\n");
                break;
        }
    }

    
    return 0;
}
