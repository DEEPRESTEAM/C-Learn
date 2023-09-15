#include<stdio.h>


int add(int num1 , int num2);

void prin_hello(){
    printf("hello,world\n");
}


int main(int argc, char const *argv[])
{
    int num1 = 1 ; int num2 = 2;
    prin_hello();
    int sum = add(num1 , num2);
    printf("数值相加:%d\n" , sum);
    return 0;

}


int add(int num1 , int num2){
    int sum = num1 + num2;
    return sum;
}
