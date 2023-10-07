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
    int id;                  // 航班序号
    int uid;                 // 序号
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

typedef struct note_ticket
{
    ticket_t *ticket;
    struct note_ticket *next;
    struct note_ticket *pre;
} linklist_ticket;
// 用户
typedef struct user
{
    linklist_ticket *ticketHead;
    ticket_t tick[MAX];
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
    int flag;
    // admins admin;//管理员
} linklist_t;

typedef struct note_flight
{
    struct note_flight *pre;
    struct note_flight *next;
    flight_t *flights;
} linklist_flight;

// 判断链表创建，用户信息读取，用户航班读取
int prependants(linklist_flight *flightHead, linklist_t *head, FILE *file, int size);

// 登陆界面
void showMenu();

// 登录验证
linklist_t *login(linklist_t *head, user_t *user);

// 用户忘记密码
void userChangePsaawd(linklist_t *head, user_t *user);

// 登录注册忘记密码集成
linklist_t *loginIntegration(linklist_t *head, user_t *user, int size);

// 头节点的创立
linklist_t *creatHeadNode();

// 航班存储双向循环链表的创建
linklist_flight *creatHeadFlightNode();

void creatHeadTicketNode(user_t *user);

// 双向链表根据内容查询相关信息
linklist_t *loginCheck(linklist_t *head, user_t *data);

// 判断头节点创建是否为空
int judgetHeadIsNull(linklist_t *head, linklist_flight *flightHead);

// 链表插入数据
int insertTailNewNode(linklist_t *head, user_t *user, int size);

// 用户注册
int regist(linklist_t *head, user_t *user, int size);

// 双向循环链表的遍历
void linkListPrintf(linklist_t *head);

// 从文件中读取文件到链表中
int getgetFileToLinklist(linklist_t *head, FILE *file, int size);

//读取航班文件到航班双向循环链表中
int getFlightFileToLinklist(linklist_flight *flightHead, FILE *file);

// 打开文件
FILE *file_open(char *file_name, char *modes);

// 打印航班信息
void userFlightPrintf(linklist_flight *flghtHead);

// 中央控制器
int centerController(linklist_flight *flightHead, linklist_t *head, user_t *user, int size);

// 用户功能选择页面
void userFunctionMenue(linklist_flight *flightHead);

// 用户控制器
int userController(linklist_t *head, linklist_t *user_t, linklist_flight *flightHead);

// 购票方法，根据前面的序号，来进行购票
int purchaseTickets(int id, linklist_t *user1, linklist_flight *flightHead);

// 打印用户飞机票
void userPrintfTicket(linklist_t *temp);

// 用户个人中心界面
void userCentreControllerMenue();

// 用户中心控制器
int userCentreController(linklist_t *user, linklist_t *head);

// 查看和修改个人信息
void userMessage(linklist_t *user);

// 修改用户密码
void changeUserPasswd(linklist_t *user, linklist_t *head);

// 注销用户（注销后会直接回到登录页面）
int bannedUser(linklist_t *head, linklist_t *users);

// 管理员控制器
int adminController(linklist_t *head , linklist_flight * flightHead);

// 删除双向循环链表中的所有节点
int deletelib(linklist_t *head);

// 用户票券选择界面
void userTicketControllerMenue();

// 用户票券选择控制器
int userTicketController(linklist_t *head, linklist_t *user_t, linklist_flight *flightHead);

// 用户退票
void userReturnTicket(linklist_t *userNode, linklist_flight *flightHead);

// 将航班双向循环链表删除
void deleteFilght(linklist_flight **head);

// 主链表删除头节点
void deleteMainLinklist(linklist_t **head);

// 将用户票券双向循环链表删除
void deleteTicketLinklist(linklist_ticket **ticketHead);

// 用户改签
void userChangeTicket(linklist_flight *flightHead, linklist_t *userNode);

// 修改用户信息函数指针
typedef linklist_t *(*changeMes)(linklist_t *node, void *data);

// 修改电话
linklist_t *changeMesPhone(linklist_t *node, void *data);

// 修改权限
linklist_t *changeMesJudege(linklist_t *node, void *data);

// 修改密码
linklist_t *changeMesPasswad(linklist_t *node, void *data);

// 修改身份证号码
linklist_t *changeMesIdNumber(linklist_t *node, void *data);

// 修改姓名
linklist_t *changeMesName(linklist_t *node, void *data);

//修改函数
void changeFun(linklist_t *head, int num, changeMes changeMesFun, void *data);

// 通过选择修改用户信息
void changeUserMessage(linklist_t *head, int id);

// 修改用户信息
void adminChangeUserMessage(linklist_t *head);

// 用户信息管理集成
void userManageController(linklist_t *head);

// 管理员功能选择界面
void adminControllerMenue();

// 管理员用户信息管理界面
void adminManageControllerMeaue();

// 修改用户选项
void changeFunMenue();

// 删除用户
void deleteUserMessage(linklist_t *head);

// 管理员航班信息管理界面
void adminFlightControllerMeaue();

//修改票券对应属性的函数指针
typedef linklist_flight *(*changeFlightMes)(linklist_flight *node , void * data);

// 修改票券数量
linklist_flight *changeFlightTicket(linklist_flight *node, void *data);

// 修改票券价格
linklist_flight *changeFlightPrice(linklist_flight *node, void *data);

// 修改票券出发时间
linklist_flight *changeFlightDate(linklist_flight *node, void *data);

// 修改票券目的地
linklist_flight *changeFlightDestination(linklist_flight *node, void *data);

// 修改航班信息
void changeFlightFun(linklist_flight *head, int num, changeFlightMes changeFlight, void *data);

// 修改航班信息选项
void changeFlightFunMenue();

// 修改航班信息集成
void changeFlightMessage(linklist_flight *head, int id);

// 删除航班信息

void deleteFlightMes(linklist_flight *head);

// 航班信息管理集成
void flightManageController(linklist_flight *head);

// 读取用户链表文件
void readUserStructMesToFile(FILE *fp, linklist_t *head);

// 读取航班链表到文件中
void readFlightStructToFile(linklist_flight *head, FILE *fp);

// 求出航班链表节点个数
int FlightLinklistNodeCounts(linklist_flight *head);

// 航班增加
void addFlightMes(linklist_flight *head, int index);

#endif