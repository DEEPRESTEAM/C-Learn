#include"2_head.h"

//创建对列函数
queue_t * createQueue(){
    queue_t * queue = malloc(sizeof(queue_t));
    if (queue == NULL)
    {
        printf("申请空间失败\n");
        return NULL;
    }
    //队列节点的指针跟双向循环链表的创建函数有关
    queue->datas = creat_linklistHeadNode();
    if (queue->datas == NULL)
    {
        printf("创建双向循环链表失败\n");
        return NULL;
    }
    return queue;
    
    
}

//入队函数
int pushQueue(queue_t * queue , void * data , int size){
    insertlinklistToTail(queue->datas , data , size);
    return 1;
}

//打印队列
int queueprintf(queue_t * queue){
    if (queue == NULL || queue->datas == NULL)
    {
        printf("队列为空或队列不存在\n");
        return 0;
    }
    linklistPrintf(queue->datas , showAll);
    return 0;
}

//出队函数
int outputQueue(queue_t * queue , void * data , int size){
    deleteLinklistHeadNode(queue->datas , data , size);
    return 0;
}

//判断对列为空
int judgetQueue(queue_t * queue){
    if (queue->datas->next == queue->datas)
    {
        printf("队列为空\n");
        return 0;
    }else{
        printf("队列不为空\n");
        return 0;
    }
}

//判断队列是否满
int judgetSize(queue_t * queue){
    if(findLinklistNodeCount(queue->datas) <= QUEUESIZE){
        printf("队列未满\n");
        return QUEUESIZE - findLinklistNodeCount(queue->datas);
    }else{
        printf("队列已满\n");
        return 0;
    }
}

//获取对头成员
int getQueueHead(){
    return 0;
}

//销毁队列
int destoryQueue(queue_t **queue){
    if (queue == NULL)
    {
        printf("队列不存在\n");
        return 0;
    }
    
    deleteAllLinklistNode(&((*queue)->datas));
    free(*queue);
    *queue = NULL;
}