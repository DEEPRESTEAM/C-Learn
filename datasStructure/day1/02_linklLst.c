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
int insertDeleteNode(node_t * head , int position ){
    int i = 0;
    if (head == NULL || position <= 0)
    {
        perror("this LinkList is illage\n");
        return -1;
    }
    node_t * temp  = head;
    //找到要删除节点的前一个位置
    while (temp != NULL && i < position -1 )
    {
        i++;
        temp = temp->next;
    }
    //将上一个节点赋值给p
    node_t * p = temp;
    
    //说明要删除的节点在最后面
    if (temp->next == NULL)
    { 
        printf("没找到\n");
        return 1;
    }else{
        //查找的节点不在最后一个元素
        //移动到要查找的位置
         temp = temp->next;
    }
    //传出数据
    //* data = temp->num;
    //如果要删除的节点不在最后面
    p->next = temp->next;
    //temp->next = NULL;
    free(temp);    
}

//删除头节点（数据头节点）
void  deleteHeadLinkList(node_t * head , int * outdata){
    if (head == NULL || head->next == NULL )
    {
        perror("Linklist is illage || Linklist is empty\n");
        return;
    }
    node_t * temps = head->next;
    *outdata = temps->num;
    //修改指针
    head->next = temps->next;
    free(temps);
}

//删除尾节点
void deleteTailLinkList(node_t * head  , int * output){
    if (head == NULL || head->next == NULL )
    {
        perror("Linklist is illage || Linklist is empty\n");
        return;
    }
    node_t * temp = head;
    while (temp->next->next != NULL)
    {  
        temp = temp->next;
    }
    *output = temp->next->num;
    free(temp->next);
    temp->next = NULL;
    
}


//递归删除数据
void deletLinklist(node_t * head){
    if (head == NULL || head->next == NULL )
    {
        perror("this LinkList is illage\n");
        return;
    }
    node_t * temp  = head;
    node_t * p = NULL;
    //找到要删除节点的前一个位置
    while (temp->next != NULL)
    {
        if(temp->next->next == NULL){
            p = temp;
        }
        temp = temp->next;
    }
    p->next = NULL;
    free(temp);
    deletLinklist(head);
}

//按内容查找并删除节点
void deleteLinklistByContent(node_t * head , int num , int * number ){
    int count = 0;
    if (head == NULL || head->next == NULL)
    {
        perror("this LinkList is illage || this LinkList is empty\n");
        return;
    }
    node_t * temp = head;
    while (temp != NULL && temp->next->num != num)
    {
        if (temp->next->next == NULL && temp->next->num != num)
        {
            printf("查无此数据\n");
            return;
        } 
        temp = temp->next;
        
    }
    free(temp->next);
    temp->next = temp->next->next;
    node_t * temp1 = head;
    while (temp1 != NULL)
    {
        if (temp1->num == num)
        {
            *number++ = count;
            deleteLinklistByContent(head , num , number);
        }
        count++;
        temp1 = temp1->next;
    }
    return;

}
// void deleteLinklistByContentFather(node_t * head , int num , int * number){
//     int count = 0;
//     node_t * temp = head;
//     while (temp != NULL)
//     {
//         if (temp->num == num)
//         {
//             *number++ = count;
//             deleteLinklistByContent(head , num);
//         }
//         count++;
//         temp = temp->next;
//     }
//     if (temp == NULL)
//     {
//          printf("查无此数据\n");
//     }
// }





//查找某个节点的位置
void find(node_t * head , int position){
     //参数判断
     int i = 0;
    if (head == NULL || position < 0)
    {
        perror("this Lin{kList is illage\n");
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


//按内容查找当前节点的位置
int findByContent(node_t * head , int data , int * i){
    int flag = 0;
    if (head == NULL || head->next == NULL)
    {
        perror("this LinkList is illage || this LinkList is empty\n");
        return -1;
    }
    node_t * temp = head;
    while (temp != NULL)
    {
        if (temp->num == data)
        {
            *i++ = flag;
        }
        flag++;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        perror("this Linklist is not element\n");
        return -1;
    }
    
    return 1;    
}

//修改任意节点的值
int changeData(node_t * head , int index , int newdata){
    if (head == NULL || head->next == NULL || index <= 0)
    {
        perror("this LinkList is illage || this LinkList is empty\n");
        return -1;;
    }
    int i = 0;
    node_t * temp = head;
    while (temp != NULL && i < index)
    {
        i++;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("index is out of range\n");
        return -1;
    }
    temp->num = newdata;
    return 0;
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
    int arr[10] = {1,9,9,4,5,9,7,8,9,10};
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
    // printf("------------------------------\n");
    // // head->next->name = "非空";
    // // printf("%d , %s\n" , head->next->num , head->next->name);
    // //insetData(head , 78);
    // optionalPositionInsert(head , 11 , 100);
     
    // putchar('\n');
    // find(head , 1);
    // OutputLinklistNodes(head);
    //删除某个节点
    //insertDeleteNode(head , 2);
    //int a;
    //deleteHeadLinkList(head ,&a );
    //printf("%d\n" , a);
    //deleteTailLinkList(head , &a);
    // printf("%d\n" , a);
    //print(head);
    int arr1[10]={0};
    deleteLinklistByContent(head , 9 ,arr);// printf("%d" , head->next->num);
    //changeData(head , -1 , 100);
    
    //deletLinklist(head);
    
    // findByContent(head , 11 , arr1);
    int * p = arr1;

    while (*p)
    {
        printf("%d  " , *p++);
    }
    printf("\n");
    //printf("改内容节点个数%d\n" , findByContent(head , 1));
    //printf("------------------------------------------\n");
    print(head);
    //printf("%d\n" , head->num);
    return 0;
}
