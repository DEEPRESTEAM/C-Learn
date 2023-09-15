#include<stdio.h>

/**
 * 体温判断
*/

void judgmentTemperature(float temperature){
    if (temperature > 37.5 || temperature < 36)
    {
        printf("体温不正常\n");
    }else { 
        printf("体温正常\n");
    }
}


int main(int argc, char const *argv[])
{
    float temperature = 0;
    printf("请输入你当前的体温\n");
    scanf("%f" , &temperature);
    getchar();
    printf("当前温度为:%.2f\n" , temperature);
    judgmentTemperature(temperature);
    return 0;
}
