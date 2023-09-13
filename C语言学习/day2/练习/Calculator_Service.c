#include "Calculator_Impl.h"

/**
 * 页面表示
*/
void menu(){
    printf("-------------------------------\n");
    printf("|   欢迎你！来到<大杂烩系统>   |\n");
    printf("-------------------------------\n");
}

void select_fuction_menu(){
    printf("----------------------\n");
    printf("|   0.退出程序      |\n");
    printf("|   1.基本计算器    |\n");
    printf("|   2.九九乘法表    |\n");
    printf("|   3.学生管理系统  |\n");
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
            return 0;
        }
        printf("密码错误请重新登录\n");
        return 1;
    }
    printf("账号错误请重新输入\n");
    return 1;
}


/**
 * 延时启动
*/
void lay_start(){
    printf("正在启动");
    for (int i = 0; i < 5; i++)
    {
        printf(".");
        fflush(stdout);
        usleep(500000);
    }
    printf("\n");
    
}

/**
 * 选择功能
*/
int select_fuction(int flag){
    flag = 1;
    select_fuction_menu();
    while (flag)
    {
        printf("请选择功能：");
        int scanf_flag = scanf("%d" , &flag);
        gets();
        if (scanf_flag == 1 && flag >= 0 && flag <= 3)
        {
            return flag;
        }else {
            printf("请输入相对应的数字\n");
        }
    }
}

/**
 * 基本计算器
*/
double compute( int num1 , int num2 , char str){
    int sum = 0;
    if (str == '+' || str == '-' || str == '*' || str == '/' || str == '%')
    {
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
    }else{
        printf("请输入正确的基本运算符\n");
    }
    return 0;
}

/**
 * 九九乘法表
*/
void multiplication_table(int num1 , int num2){
    for (int i = 1 ; i <= num1 ; i++)
    {
        for (int j = 1 ; j <= num2; j++)
        {
            printf("%d * %d = %-5d" , i , j , i * j);
        }
        printf("\n");
    }
}

/**
 * 判断是否继续计算
*/
int judgment_calculation(int flag_str , int temp_ , char flag_){
     while (flag_str){
        printf("是否继续执行？(y/n): ");
        scanf("%c" , &flag_);
        char ch = gets();
        if (flag_ == 'y')
        {
            break;
        }
        if (flag_ == 'n'){
            temp_ = 1;
            printf("谢谢用户使用，欢迎下次光临\n");
            break;
        }else{
            printf("别瞎几把乱搞\n");
        }
    }
    return temp_; 
   
}

/**
 * 判断是否继续计算
*/
int judgment_calculation_m(int flag_str , int temp_ , char flag_){
     while (flag_str){
        printf("是否继续执行？(y/n): ");
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

void manageCheckIdAndScore(int studentId[] , int studentScore[]){
    for (int i = 0; i < MAX; i++)
    {
        printf("学号：%d    成绩：%d \n" , studentId[i] , studentScore[i]);
    }
    
}

void peopleCheckStudentScore(int studentId , int studentScore[]){
   printf("学号：%d    成绩：%d \n" , studentId , studentScore[studentId-1]);
}


/**
 * 管理员更改学生成绩
*/
void manageChangeStudentScore(int studentId , int studentScore[]){
    int flag = 1;
    while (flag)
    {
        int studentNewScore = 0;
        if (studentId > 0 && studentId <= MAX )
        {
            printf("当前学生成绩为%d，请问你需要将该同学的成绩改为多少：" , studentScore[studentId -1]);
            int scanf_temp = scanf("%d" , &studentNewScore);
            gets();
            if (scanf_temp == 0 || studentNewScore >100)
            {
                printf("别瞎几把乱输\n");
                continue;
            }else{
                studentScore[studentId -1] = studentNewScore;
                flag = judgment_calculation_m(1,1,'0');
            }
            
        }
    }
    
}

