#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**
 * 创建头指针
*/

typedef struct node
{
    //数据部分
    int num;
    char * name;
    //下一个节点部分
    struct node * next;
}node_t;


//1创建一个单链表结构
node_t * createLinkList(){
    //申请空间
    //填写节点域
    //填写节点中的指针部分
    node_t * head = (node_t *)malloc(sizeof(node_t));
    if (NULL == head)//NULL 写在左边比卸载右边好 
    {
        printf("mollec error\n");
        return NULL;
    }
    //填写节点中的数据
    head->num = 0;
    head->name = "头节点";
    //填写节点中的指针部分
    head->next = NULL;

    return head;
}


//头插法
//参数一    已经存在的链表
//返回值    成功返回0 失败返回非0
int insertHeadLinkList(node_t * head , int num , char * name  ){

    node_t * T = head;

    //参数判断
    if (head == NULL)
    {
        perror("this LinkList is illage\n");
        return -1;
    }
    //申请空间
    node_t * newNode = (node_t *)malloc(sizeof(node_t));
    if (newNode == NULL)
    {
        perror("newNode malloc error\n");
        return -1;
    }
    //填写数据
    newNode->name = name;
    newNode->num = num;
    //修改指针
    newNode->next = head->next;
    head->next = newNode;
    return 1;
}

//尾插法
int insertTailLinkList(node_t * head , int num){
    node_t * T = head;
    //参数判断
    if (head == NULL)
    {
        perror("this LinkList is illage\n");
        return -1;
    }
    //申请空间
    node_t * newNode = (node_t *)malloc(sizeof(node_t));
    if (newNode == NULL)
    {
        perror("newNode malloc error\n");
        return -1;
    }
    while (T->next != NULL)
    {  
        T = T->next; 
    }


    newNode->num = num;
    newNode->next = T->next;
    T->next = newNode;
   
    return 1;
}


//根据数据大小插入数据
int insetData(node_t * head ,  int newdata){
    //参数判断
    if (head == NULL)
    {
        perror("this LinkList is illage\n");
        return -1;
    }
    node_t * temp  = head;
    while (temp->num <= newdata && temp->next->num <= newdata && temp->next != NULL)
    {
        temp = temp->next;
    }
    //申请空间
    node_t * newNode = (node_t *)malloc(sizeof(node_t));
    if (newNode == NULL)
    {
        perror("newNode malloc error\n");
        return -1;
    }
    //在中间插入数据
    newNode->num = newdata;
    newNode->next = temp->next;
    temp->next = newNode;
    
}

//在任意位置插入节点
int optionalPositionInsert(node_t * head , int position , int newdata){
    //参数判断
    int i = 0;
    if (head == NULL || position < 0)
    {
        perror("this LinkList is illage\n");
        return -1;
    }
    node_t * temp  = head;
    while (temp != NULL && i < position-1)
    {
        i++;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("没找到该位置\n");
        return -1;
    }
    
    //申请空间
    node_t * newNode = (node_t *)malloc(sizeof(node_t));
    if (newNode == NULL)
    {
        perror("newNode malloc error\n");
        return -1;
    }
    //在中间插入数据
    newNode->num = newdata;
    newNode->next = temp->next;
    temp->next = newNode;
}
//输出链表节点个数
void OutputLinklistNodes(node_t * head){
    int count = 0;
    if (head == NULL)
    {
        perror("newNode malloc error\n");
        return;
    }
    if (head->next == NULL)
    {
        printf("this linklist nodes is empty\n");
    }
    node_t * temp = head;
    while(temp->next != NULL){
        count++;
        temp = temp->next;
    }
    printf("节点个数:%d\n" , count);
    
    
    
}

//删除某个节点
// int insertDeleteNode(node_t * head , int position){
//     if (head == NULL || position < 0)
//     {
//         perror("this LinkList is illage\n");
//         return -1;
//     }
//     node_t * temp  = head;
//     while (temp != NULL && temp->num != position)
//     {
//         temp = temp->next;
//     }
//     if (temp == NULL)
//     {
//         printf("没找到该位置\n");
//         return -1;
//     }
//     if (temp->next == NULL)
//     {
//         printf("删除")
//     }
    
    
// }

//查找某个节点的位置
void find(node_t * head , int position){
     //参数判断
     int i = 0;
    if (head == NULL || position < 0)
    {
        perror("this LinkList is illage\n");
        return;
    }
    node_t * temp  = head;
    while (temp != NULL && i < position)
    {
        i++;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("没找到该位置\n");
        return;
    }
    printf("%d\n" , temp->num);
    
}

//非递归打印
void showLinkList(node_t * head){
    if (head == NULL)
    {
        perror("this linklist not exits\n");
        return;
    }
    
    if (head->next == NULL)
    {
        return;
    }
    node_t * T = head->next;
    while (T != NULL)
    {
        printf("%d \n" , T->num);
        T = T->next;
    }
    putchar(10);   
}


//递归打印
void recursivePrinting(node_t * T){
    
    if (T == NULL)
    {
        return;
    }
    printf("%d " , T->num);
    recursivePrinting(T = T->next);
} 

void print(node_t * head){
    node_t * T = head->next;
    if (head == NULL)
    {
        printf("链表为空\n");
    }
    
    recursivePrinting(T);
}



int main(int argc, char const *argv[])
{
    printf("------------------------------\n");
    node_t * head = createLinkList();
    if (head == NULL)
    {
        printf("creatLinkList error \n");
        return -1;
    }
    //printf("%p  %d , %s , %p\n" ,head , head->num , head->name , head->next);
    //free(head);
    //malloc与free一起使用  由于测试代码所以  没有free
    //如果没写free
    //也会被父进程把3G用户内存给释放掉,3G内存包括堆空间和栈空间
    //将数据写入到链表中
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < 10; i++)
    {
        int result = insertTailLinkList(head ,arr[i] );
        if (result == -1)
        {
            printf("insertLinkList error \n");
        }
        //printf("%d \n" , result);
    }
    // printf("%d , %s\n" , head->next->num , head->next->name);
    printf("------------------------------\n");
    // head->next->name = "非空";
    // printf("%d , %s\n" , head->next->num , head->next->name);
    //insetData(head , 78);
    optionalPositionInsert(head , 11 , 100);
    print(head);
    putchar('\n');
    find(head , 1);
    OutputLinklistNodes(head);
    return 0;
}
