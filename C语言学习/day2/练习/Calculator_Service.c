#include "Calculator_Impl.h"

/**
 * 页面表示
*/
void menu(){
    printf("----------------------\n");
    printf("|   欢迎使用计算机   |\n");
    printf("----------------------\n");
}

/**
 * 用户输入账户与密码，并且判断用户账户密码是否正确
*/
int scanf_user(int user_name , int user_passwd ){
    int flag = 0;
    printf("请输入账号：");
    scanf("%d" , &user_name);
    getchar();
    printf("请输入密码：");
    scanf("%d" , &user_passwd);
    getchar();
    flag = login(user_name , user_passwd);
    return flag;
}


/**
 * 登录业务，判断账号密码是否正确
*/
int login(int user_name , int passwd){
    if (user_name == NAME)
    {
        if (passwd == PASSWD)
        {
            printf("登录成功\n");
            return -1;
        }
        printf("密码错误请重新登录\n");
        return 1;
    }
    printf("账号错误请重新输入\n");
    return 1;
}


/**
 * 计算
*/
double compute( int num1 , int num2 , char str){
    int sum = 0;
    if (str == '+'){
        sum = num1 + num2;
    }

    if (str == '-'){
        sum = num1 - num2;
    }

    if (str == '*'){
        sum = num1 * num2;
    }

    if (str == '/'){
        sum = num1 / num2;
    }
    
    if (str == '%'){
        sum = num1 % num2;
    }

    return sum;
}

/**
 * 判断是否继续计算
*/
int judgment_calculation(int flag_str , int temp_ , char flag_){
     while (flag_str){
        printf("是否继续计算？(y/n): ");
        scanf("%c" , &flag_);
        char ch = gets();
        if (flag_ == 'y')
        {
            break;
        }
        if (flag_ == 'n'){
            temp_ = 0;
            printf("谢谢用户使用，欢迎下次光临\n");
            break;
        }else{
            printf("别瞎几把乱搞\n");
        }
    }
    return temp_;
}
