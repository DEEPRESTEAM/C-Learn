#include<stdio.h>
/**
 * 人民币换算
*/

//换算人民币函数
double conversion(float doller){
    double RMB = doller * 7.2767;
    return RMB;
}


int main(int argc, char const *argv[])
{
    float doller = 0;
    printf("输入你想换算的美元\n");
    scanf("%f" , &doller);
    printf("换算成人名币为:%lf\n" , conversion(doller));
    return 0;
}
