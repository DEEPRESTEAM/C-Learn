#include"railway.h"


//界面集成



// 登陆界面
void showMenu()
{
    printf("------------------------------\n");
    printf("|   登陆航班系统              |\n");
    printf("------------------------------\n");
    printf("|    1：注册                 |\n");
    printf("|    2：登录                 |\n");
    printf("|    3：忘记密码             |\n");
    printf("|    4：退出系统             |\n");
    printf("------------------------------\n");
}

// 用户功能选择页面
void userFunctionMenue(linklist_flight * flightHead)
{
    printf("--------------------主界面--------------------\n");
    printf("航班信息\n");
    userFlightPrintf(flightHead);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("------------------用户功能界面-----------------\n");
    printf("|                 1:购票窗口                  |\n");
    printf("|                 2:查询航班                  |\n");
    printf("|                 3:本人票券                  |\n");
    printf("|                 4:用户中心                  |\n");
    printf("|                 5:返回上一级                |\n");
    printf("----------------------------------------------\n");
}

// 用户中心共能选择界面
void userCentreControllerMenue()
{
    printf("---------------欢迎来到用户中心--------------\n");
    printf("|              1:个人信息管理                 | \n");
    printf("|              2:修改密码                     |\n");
    printf("|              3:注销用户                     |\n");
    printf("|              4:返回上一级                   |\n");
    printf("-----------------------------------------------\n");
}

// 管理员功能选择界面
void adminControllerMenue()
{
    printf("---------------欢迎来到管理员中心--------------\n");
    printf("|              1:个人信息管理                 | \n");
    printf("|              2:修改密码                     |\n");
    printf("|              3:注销用户                     |\n");
    printf("|              4:返回上一级                   |\n");
    printf("-----------------------------------------------\n");
}

// 管理员功能选择界面
void userTicketControllerMenue()
{
    printf("-----------------用户票券中心---------------\n");
    printf("|              1:用户票券                 | \n");
    printf("|              2:退票                     |\n");
    printf("|              3:改签                     |\n");
    printf("|              4:返回上一级                |\n");
    printf("--------------------------------------------\n");
}