#include"2_head.h"
int main(int argc, char const *argv[])
{
    queue_t * queue = createQueue();
    if (queue == NULL)
    {
        printf("创建队列失败\n");
        return 0;
    }
    printf("对列创建成功\n");
    //printf("queue:%p %p\n" , queue , queue->datas);
    judgetQueue(queue);
    printf("------------------入队函数测试------------------\n");
    stu_t stu[5] = {{"jack", 20}, {"marry", 21}, {"pitter", 22}, {"smith", 20}, {"join", 21}};
    for (int i = 0; i < 5; i++)
    {
         pushQueue(queue , stu+i , sizeof(stu_t));
    }
    printf("姓名= %s - 年龄= %d\n",((stu_t *)queue->datas->next->data)->name , ((stu_t *)queue->datas->next->data)->age);
    printf("--------------------------出队函数测试------------------\n");
    stu_t s = {0};
    outputQueue(queue , &s , sizeof(stu_t));
    printf("出队的元素: name = %s  age = %d\n" , s.name , s.age);
    judgetQueue(queue);
    printf("--------------------------输出队列里面的元素--------------------\n");
    queueprintf(queue);
    printf("----------------销毁队列-----------------\n");
    destoryQueue(&queue);
    queueprintf(queue);
    return 0;
}
