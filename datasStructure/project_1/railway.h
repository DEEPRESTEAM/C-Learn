#ifndef __RAILWAY_
#define __RAILWAY_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 255

// 用户航班票
typedef struct ticket
{
    char seatNumber[MAX]; // 座位号
    char entrance[MAX];   // 入口
    // char flight[MAX];        // 航班号
    char date[MAX];          // 出发日期
    char originalPlace[MAX]; // 起始地
    char destination[MAX];   // 目的地
    int id;                  // 序号
    double price;            // 价格
} ticket_t;

// 航班集成
typedef struct stateFilght
{
    char entrance[MAX]; // 入口
    // char flight[MAX];        // 航班
    char date[MAX];          // 始发日期
    char originalPlace[MAX]; // 起始地
    char destination[MAX];   // 目的地
    int id;                  // 序号
    int tickets;             // 票量
    double price;            // 价格
} flight_t;

// 用户
typedef struct user
{
    ticket_t tick[MAX];
    flight_t flight[MAX];   // 航班显示
    int id;                 // id自增
    int uid;                // 账户id自增
    long int accountNumber; // 账户号
    char passwd[MAX];       // 密码
    long int phone;         // 电话号码
    int jurisdiction;       // 账号权限
    long long int idNumber; // 身份证号
    char name[MAX];         // 姓名
} user_t;

typedef struct note_s
{
    struct note_s *pre;  // 直接前置
    struct note_s *next; // 直接后驱
    user_t *user;        // 普通用户
    // admins admin;//管理员
} linklist_t;

//判断链表创建，用户信息读取，用户航班读取
int prependants(linklist_t * head , FILE * file , int size);

// 登陆界面
void showMenu();

// 登录验证
linklist_t *login (linklist_t *head, user_t *user);

// 用户忘记密码
void userChangePsaawd(linklist_t *head, user_t *user);

// 登录注册忘记密码集成
linklist_t * loginIntegration(linklist_t *head, user_t *user, int size);

// 头节点的创立
linklist_t *creatHeadNode();

// 双向链表根据内容查询相关信息
linklist_t *loginCheck(linklist_t *head, user_t *data);

// 判断头节点创建是否为空
int judgetHeadIsNull(linklist_t *head);

// 链表插入数据
int insertTailNewNode(linklist_t *head, user_t *user, int size);

// 用户注册
int regist(linklist_t *head, user_t *user, int size);

// 双向循环链表的遍历
void linkListPrintf(linklist_t *head);

// 从文件中读取文件到链表中
int getgetFileToLinklist(linklist_t *head, FILE *file, int size);

// 打开文件
FILE *file_open(char *file_name, char *modes);

int readFlightToUserNode(linklist_t *head, FILE *file);


//打印航班信息
void userFlightPrintf(linklist_t *head, int count);
//中央控制器
int centerController(linklist_t *head, user_t *user, int size , int count );

// 用户功能选择页面
void userFunctionMenue(linklist_t *head, int count);

//用户控制器
int userController(linklist_t * head , linklist_t *user_t, int count);

// 购票方法，根据前面的序号，来进行购票
int purchaseTickets(int id, linklist_t *user1, int count , linklist_t * head);

// 打印用户飞机票
void userPrintfTicket(linklist_t *temp, int num);

//用户个人中心界面
void userCentreControllerMenue();
//用户中心控制器
int userCentreController(linklist_t *user, linklist_t *head);

/// @brief 查看和修改个人信息
/// @param user
void userMessage(linklist_t *user);

// 修改用户密码
void changeUserPasswd(linklist_t *user, linklist_t *head);

// 注销用户（注销后会直接回到登录页面）
int bannedUser(linklist_t *head, linklist_t *users);

//管理员控制器
int adminController(linklist_t *head);

// 删除双向循环链表中的所有节点
int deletelib(linklist_t *head);

// 用户票券选择界面
void userTicketControllerMenue();


//用户票券选择控制器
int userTicketController(linklist_t * head , linklist_t * user_t , int ticketNums);


//用户退票
void userReturnTicket(linklist_t *head, linklist_t *temp, int num);
#endif