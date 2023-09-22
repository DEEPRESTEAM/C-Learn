#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 255


//用户航班票
typedef struct ticket
{
    char seatNumber[MAX];       //座位号
    char entrance[MAX];         //入口
    char flight[MAX];           //航班号
    char date[MAX];             //出发日期
    char originalPlace[MAX];    //起始地
    char destination[MAX];      //目的地
    double price;               //价格
}tickets;


//大厅显示
typedef struct stateRoom
{
    char entrance[MAX];         //入口
    char flight[MAX];           //航班
    char date[MAX];             //始发日期
    char originalPlace[MAX];    //起始地
    char destination[MAX];      //目的地
    char seatNumber[MAX];       //座位号
    int  * tickets;               //票量
}room;

//管理员用户
typedef struct Admins
{
    int id;                     //id自增
    int uid;                    //账户id自增
    int accountNumber;          //账户号
    char passwd[MAX];           //密码
    long int phone;             //电话号码
    int jurisdiction;           //账号权限 
    unsigned long long int idNumber;     //身份证号
    char name[MAX];             //姓名
    room rooms[MAX];            //大厅显示内容
    
}admins;

//普通用户
typedef struct user{
    tickets tick[MAX];
    room romms[MAX];         //大厅显示
    int id;                 //id自增
    int uid;                //账户id自增
    int accountNumber;      //账户号
    char passwd[MAX];       //密码
    long int phone;         //电话号码
    int jurisdiction;       //账号权限 
    unsigned long long int idNumber; //身份证号 
    char name[MAX];         //姓名
}users;

typedef struct note_s{
    struct note_s * pre;    //直接前置
    struct note_s * next;   //直接后驱
    users user;//普通用户
    admins admin;//管理员
}linklist;

//登陆界面
void showMenu(){
    printf("------------------------------\n");
    printf("|   登陆系统                 |\n");
    printf("------------------------------\n");
    printf("|    1：注册                 |\n");
    printf("|    2：登录                 |\n");
    printf("|    3：忘记密码             |\n");
    printf("------------------------------\n");

}

//用于显示航班的详细情况
void viewingScreen(){

}

//管理员功能界面
void adminMenue(){

}

//普通用户功能页面
void userMenue(){

}


//账号注册
void registe(linklist * head){
    
}

//账号登录
void numberOfLogon(){

}


//忘记密码(找回密码)
void retrievePassword(){

}


//功能选择
void selectFunction(){

}

//双向链表的头节点的创建
linklist * creatHeadNode(){
    linklist * head = malloc(sizeof(linklist));
    if (head == NULL)
    {
        printf("申请空间失败\n");
        return NULL;
    }
    head->pre = head->next = NULL;
    return head;
}

//双向链表插入新的节点(尾插)
void insertTailNewNode(linklist * head , users user , admins admin){

}

//双向链表插入新的节点(头插)
void insertHeadNewNode(){

}

//双向链表的头部插入(链表的创建)
void insertHeadToLinklist(linklist * head , users user , admins admin){
    if (head == NULL)
    {
        printf("linklist is illage\n");
        return;
    }
    linklist * newNode = malloc(sizeof(linklist));
    linklist * temp = head; 
    
    
    
    
}

//双向链表的遍历
void linkListPrintf(linklist * head){
    if (head == NULL)
    {
        printf("链表为空\n");
        return;
    }
    linklist * temp = head;
    //从前往后进行遍历
    while (temp->next != NULL)
    {
        temp = temp->next;
        printf("%d\n" , temp->user.id);
    }
    //从后往前的进行遍历
    while (temp->pre->pre != NULL)
    {
        temp = temp->pre;
        printf("%d\n" , temp->user.id);
    }
}

//双向链表通过内容查找所在的节点
void findLinklistNodeByContext(){

}


//通过内容删除内容所在的节点
void deleteLinklistNodeByContext(){

}
//删除双向链表的所有的数据节点
void deleteLinklistAllContext(){

}

//结构体读入内容到文件中
void inReadContextToFile(){

}
//从文件读入内容到结构体中
void outContextToStruct(){

}



int main(int argc, char const *argv[])
{   
    //打印菜单
    showMenu();

    while (1)
    {
        /* code */
    }
    
    return 0;
}
