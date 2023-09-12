#include "Calculator_Impl.h"
#define MAX 100

int main(int argc, char const *argv[])
{
    /**
     * 用户输入的账户与密码
    */
    int user_name = 0;
    int user_passwd = 0;

    /**
     * 用户登录判断的返回值，1为登陆失败账号或密码错误，-1登录成功
    */
    int flag = -1;

    /**
     * num1 , num2 , str ，result 分别是用户输入的 数字 运算符号 以及 运算结果
    */
    int num1 = 0;
    int num2 = 0;
    char str = '0';
    double result = 0;

    /**
     * 判断是否继续计算标记符号
    */
    char flag_ = '0';
    
    /**
     * 主要循环标志符号
    */
    int temp_ = 1;
    menu();
    while (1)
    {
        int flag = scanf_user(user_name , user_passwd );
        if (flag == -1)
            break;
        
    }
    
    
    while (temp_)
    {
        
        switch (flag){
            case 1:
                printf("笑死死循环了吧");
                temp_ = 0;
                break;
            case -1:
                printf("输入计算公式（中间没有空格，别瞎搞）:");
                scanf("%d%c%d" , &num1 , &str , &num2);
                getchar();
                result = compute(num1 , num2 , str);
                printf("结果为：%lf\n",result);
                int flag_str = 1;
                temp_ = judgment_calculation(flag_str , temp_ , flag_);
                break; 
            }
                  
        
    }
    return 0;
}