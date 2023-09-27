#ifndef __HEAD_H_
#define __HEAD_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define QUEUESIZE 20


/**
 * 双向循环链表
*/

typedef struct stu
{
    char name[21];
    int age;
} stu_t;

typedef struct note_t
{
    void * data;
    struct note_t * pre; 
    struct note_t * next;
}linklist;



/// @brief 头节点的初始化
/// @return 返回创建的头节
linklist * creat_linklistHeadNode();


/// @brief 双向循环链表头插
/// @param head 头节点
/// @param newData 传入数据域
/// @param size 传入数据域大小
void insertLinklistToHead(linklist * head , void * newData , int size);



/// @brief 双向循环链表的尾插
/// @param head 传入链表头节点
/// @param newData 传入数据域 
/// @param size 传入数据域大小
void insertlinklistToTail(linklist * head , void * newData , int size);


//求出链表的节点个数
int findLinklistNodeCount(linklist * head);


//双向循环链表的打印
typedef void ( *showkind)(void * data);
void showName(void * data);
void showAge(void * data);
void showAll(void * data);
void linklistPrintf(linklist * head , showkind show);


/// @brief 删除任意位置的节点
/// @param head //双向链表的头节点
/// @param index //需要删除的位置
void deleteLinklistNodeByIndex(linklist * head , int index);


/// @brief 删除头节点
/// @param head 链表的头节点
/// @param data 需要传出的数据指针
/// @param size 空间大小
void deleteLinklistHeadNode(linklist * head , void * data , int size);


/// @brief 修改某个位置的数据内容
/// @param head 头节点
/// @param index 传入位置
/// @param data 需要修改的数据
/// @param size 修改数据的大小
void changeLinklistNodeContentByIndex(linklist * head , int index , void * data , int size);


/// @brief 在任意位置插入
/// @param head 
/// @param index 
/// @param newDate 
/// @param size 
void insertLinklistNodeByIndex(linklist * head , int index , void * newDate , int size);



//根据内容，查询所有内容
typedef int (* cmpContent) (void * data1 , void * data2);
int cmpName(void * data1 , void * data2);
int cmpAge(void * data1 , void * data2);
void findAllContentBySomeContent(linklist * head , cmpContent cmp , void * data);


/// @brief 删除双向循环链表的所有数据节点(利用头插法的原理)
/// @param head 传入头节点
void deleteAllLinklistNode(linklist ** head);


/// @brief 删除尾节点
/// @param head 传入头节点
void deleteLinklistNodeToTail(linklist * head);


/// @brief 双向循环链表排序
/// @param head 传入链表头节点
void linklistSort(linklist * head);



//------------------------------------------队列函数都在此声明--------------------------------//
//队列类型
typedef struct queue
{
    linklist * datas;
}queue_t;


//创建队列函数
queue_t * createQueue();

//入队函数
int pushQueue(queue_t * queue , void * data , int size);

//输出队列的元素
int queueprintf(queue_t * queue);

//出队
int outputQueue(queue_t * queue , void * data , int size);

//判断对列为空
int judgetQueue(queue_t * queue);

//销毁对列
int destoryQueue(queue_t **queue);
#endif