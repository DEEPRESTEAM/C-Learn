#include "Calculator_Impl.h"

int main(int argc, char const *argv[])
{

    int studentId[MAX] = {1,2,3,4,5,6,7,8,9,10};
    int studentScore[MAX] = {78,98,45,67,78,45,43,89,100,88};
    int studentId_ = 0;

    int a =0;
    int a_admin = 0;
    /**
     * 用户输入的账户与密码
    */
    int user_name = 0;
    int user_passwd = 0;

    /**
     * 用户登录判断的返回值，1为登陆失败账号或密码错误，-1登录成功
    */
    int flag = 1;

    /**
     * num1 , num2 , str ，result 分别是用户输入的 数字 运算符号 以及 运算结果
    */
    int num1 = 0;
    int num2 = 0;
    char str = '0';
    double result = 0;


    int count = 0;
    /**
     * 判断是否继续计算标记符号
    */
    char flag_ = '0';
    
    /**
     * 主要循环标志符号
    */
    int temp_ = 1;
    int temp_1 = 1;
    int temp_2 = 1;

    menu();
    
    while (flag)
    {
        flag = scanf_user(user_name , user_passwd );
        count++;
        if (count == 5)
        {
            printf("老铁，不是这么玩的，算了给你点提示\n");
            printf("密码提示：用户所在的班级 \n");
        }
        if (count == 10)
        {
            printf("10次机会都不珍惜,拜拜了你\n");
            return 0;
        }
    }
    
    lay_start();
    


    while (temp_)
    {
        flag = select_fuction(flag);
        switch (flag){

            case 3:
                a = 0;
                printf("欢迎来到学生管理系统\n");
                printf("选择登录人员\n");
                printf("1.管理员\n");
                printf("2.普通人员\n");
                printf("输入你所选择的选项:");
                int scanf_3 = scanf("%d" , &a);
                gets();
                if (scanf_3 == 0 || a >3 || a<0)
                {
                    printf("输入格式有误,请重新输入\n");
                    break;
                }
                while (temp_1)
                {
                    switch (a)
                    {
                        case 1:
                            a_admin = 0;
                            printf("管理员功能选择\n");
                            printf("1、查询成绩\n");
                            printf("2、更改成绩\n");
                            printf("请输入所需要的功能:");
                            int scanf_4 = scanf("%d" , &a_admin);
                            gets();
                            printf("%d" , a_admin);
                            if (a_admin >2 || a_admin < 1 )
                            {
                                printf("输入格式错误\n");
                            }
                            if (a_admin == 1)
                            {
                                manageCheckIdAndScore(studentId , studentScore);
                                int flag_str_4 = 1;
                                temp_1 = judgment_calculation(flag_str_4 , temp_1 , flag_);
                            }
                            if (a_admin == 2)
                            {
                                printf("请输入需要更改成绩学生的学号：");
                                scanf("%d" , &studentId_);
                                manageChangeStudentScore(studentId_ , studentScore);
                                int flag_str_5 = 1;
                                temp_1 = judgment_calculation(flag_str_5 , temp_1 , flag_);
                            }
                            
                            break;
                        
                        case 2:
                            printf("普通人员功能选择\n");
                            printf("1、查询成绩\n");
                            printf("请输入所需要的功能：");
                            int scanf_5 = scanf("%d" , &a_admin);
                            gets();
                            if (a_admin >2 || a_admin < 1 || scanf_5 != 1)
                            {
                                printf("输入格式错误\n");
                            }
                            printf("输入所需查询的学号:");
                            scanf("%d" , &studentId_);
                            gets();
                            peopleCheckStudentScore(studentId_ , studentScore);
                            
                            int flag_str_5 = 1;
                            temp_1 = judgment_calculation(flag_str_5 , temp_1 , flag_);
                            break;
                    }
                }
               
                break;

            case 2:
                printf("输入需要换算乘法表的数字：\n");
                int temp = scanf("%d %d" , &num1 , &num2);
                gets();
                if (num1 > 10 || num2 >10 || num1 < num2 || temp != 2)
                {
                    printf("输入有误请重新输入");
                    break;
                }
                multiplication_table(num1 , num2);
                int flag_str_1 = 1;
                temp_2 = judgment_calculation(flag_str_1 , temp_ , flag_);
                break;

            case 1:
                printf("输入计算公式（中间没有空格，别瞎搞）:");
                scanf("%d%c%d" , &num1 , &str , &num2);
                gets();
                result = compute(num1 , num2 , str);
                if (result == 0)
                {
                    break;
                }else{
                    printf("结果为：%lf\n",result);
                }
                int flag_str = 1;
                temp_2 = judgment_calculation(flag_str , temp_ , flag_);
                break; 
            case 0:
                temp_ = 0;
                break;
        }
                  
    }
    return 0;
}