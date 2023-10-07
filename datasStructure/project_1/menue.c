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


// 用户票券中心
void userTicketControllerMenue()
{
    printf("-----------------用户票券中心---------------\n");
    printf("|              1:用户票券                 | \n");
    printf("|              2:退票                     |\n");
    printf("|              3:改签                     |\n");
    printf("|              4:返回上一级               |\n");
    printf("--------------------------------------------\n");
}

// 管理员功能选择界面
void adminControllerMenue()
{
    printf("---------------欢迎来到管理员中心--------------\n");
    printf("|              1:用户信息管理中心             | \n");
    printf("|              2:航班信息管理中心             |\n");
    printf("|              3:删库跑路                     |\n");
    printf("|              4:返回上一级                   |\n");
    printf("-----------------------------------------------\n");
}

//管理员用户信息管理界面
void adminManageControllerMeaue(){
    printf("---------------用户信息管理中心---------\n");
    printf("|              1:修改用户             | \n");
    printf("|              2:删除用户             |\n");
    printf("|              3:返回上一级           |\n");
    printf("--------------------------------------\n");
}

//修改用户选项
void changeFunMenue(){
    printf("-----------------修改选项---------------\n");
    printf("|              1:修改名字             | \n");
    printf("|              2:修改电话             | \n");
    printf("|              3:修改权限             | \n");
    printf("|              4:修改密码             | \n");
    printf("|              5:修改身份证号         | \n");
    printf("|              6:返回上一级           |\n");
    printf("--------------------------------------\n");
}

// 管理员航班信息管理界面
void adminFlightControllerMeaue()
{
    printf("---------------航班信息管理中心---------\n");
    printf("|              1:修改航班             | \n");
    printf("|              2:删除航班             |\n");
    printf("|              3:增加航班             |\n");
    printf("|              4:返回上一级           |\n");
    printf("--------------------------------------\n");
}

// 修改航班信息选项
void changeFlightFunMenue()
{
    printf("-----------------修改选项---------------\n");
    printf("|              1:修改目的地           | \n");
    printf("|              2:修改价格             | \n");
    printf("|              3:修改票量             | \n");
    printf("|              4:修改出发时间         | \n");
    printf("|              5:返回上一级           |\n");
    printf("--------------------------------------\n");
}