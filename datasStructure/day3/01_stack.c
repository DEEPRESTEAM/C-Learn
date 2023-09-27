#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
typedef struct car{
    char carname[20];
    int price;
}car_t;

typedef struct stack{
    //栈顶位置以及元素个数
    int top;
    //指针数组
    void * arr[MAX];
}stack_t;

stack_t * creat_stack(){
    //申请空间
    stack_t * stack = malloc(sizeof(stack_t));
    if (stack == NULL)
    {
        printf("stack空间申请失败\n");
        return NULL;
    }
    //填写数据
    stack->top = 0;
    //清空数组
    __bzero(stack->arr , sizeof(stack->arr));
    return stack;   
    
}

//栈的入栈
void intoStack(stack_t * stack , car_t * value){
    if (stack == NULL || stack->top >= MAX || value == NULL)
    {
        printf("栈不存在\n");
        return;
    }
    //申请空间 + 建立练习
    stack->arr[stack->top] = malloc(sizeof(car_t));
    //填写数据
    memcpy(stack->arr[stack->top] , value ,sizeof(car_t));
    stack->top++;
}

//栈的出栈
void outputStack(stack_t * stack , car_t * value){
    if (stack == NULL || stack->top == 0 || value == NULL)
    {
        printf("参数错误\n");
        return;
    }
    stack->top--;
    memcpy(value , stack->arr[stack->top] , sizeof(car_t));
    free(stack->arr[stack->top]); 
    stack->arr[stack->top] = NULL;
    
    
}

//求出栈的元素个数
int stackCount(stack_t * stack){
    int count = stack->top;
    return count;
}
//判断栈满或栈的情况
int judgetStackSize(stack_t * stack){
    if (stack == NULL)
    {
        printf("ERROR!\n");
        return -1;
    }
    if (stack->top == 0)
    {
        return 0;
    }else if (stack->top == MAX) {
        return 1;
    }else{
        return 2;
    }
    
}


typedef int (* showFun_t)(car_t * car);
int showName(car_t * car){
    printf("品牌：%s\n" , car->carname);
    return 0;
}
int showAge(car_t * car){
    printf("价格：%d\n" , car->price);
    return 0;
}
int showAll(car_t * car){
    printf("品牌：%s - 价格：%d\n" , car->carname , car->price);
    return 0;
}
//打印栈中所有元素
void stackPrintf(stack_t * stack  , int count , showFun_t show){
    
    if (stack == NULL)
    {
        printf("栈不存在\n");
        return;
    }
    if (count == 0)
    {
        printf("打印完成\n");
        return;
    }
    count--;
    show(((car_t *)(stack->arr[count])));
    stackPrintf(stack , count ,show);
}
//获取栈顶元素
stack_t * topStack(stack_t * stack){
    if (stack == NULL || stack->top == 0)
    {
        return NULL;
    }
    return stack->arr[stack->top -1];
}
void destroyStack(stack_t **stack){
    if (*stack == NULL)
    {
        printf("栈不存在\n");
    }
    if ((*stack)->top == 0)
    {
        *stack = NULL;
        return;
    }
    (*stack)->top--;
    free((*stack)->arr[(*stack)->top]); 
    (*stack)->arr[(*stack)->top] = NULL;
    destroyStack(stack);
    
}






int main(int argc, char const *argv[])
{
    stack_t * stack = creat_stack();
    if (stack == NULL)
    {
        return 0;
    }
    printf("-------------------入栈测试---------------------\n");
    car_t car[5] = {"宝马",10000 , "奔驰",2000 , "大众",20000 , "比亚迪" , 3000 , "保时捷",5000};
    for (int i = 0; i < 5; i++)
    {
        intoStack(stack , car + i);
    }
    printf("栈顶元素:%s - %d\n" ,((car_t *)(stack->arr[stack->top -1]))->carname , ((car_t *)(stack->arr[stack->top-1]))->price);
    printf("-------------------出栈测试---------------------\n");
    car_t car1 = {0};
    outputStack(stack ,&car1);
    printf("出栈数据:%s - %d\n" , car1.carname , car1.price);
    printf("--------------------打印栈中所有元素-----------------\n");
    stackPrintf(stack , stackCount(stack) ,showAll);
    printf("------------------判断栈的情况------------------\n");
    if (judgetStackSize(stack) == 0)
    {
        printf("stack is empty\n");
    }
    if (judgetStackSize(stack)==1)
    {
        printf("stack is Full\n");
    }
    if (judgetStackSize(stack)==2)
    {
        printf("stack is not Full Abd is not Empty\n");
    }
    printf("--------------------获取栈顶元素------------------\n");
    car_t * car2 = (car_t *)topStack(stack);
    printf("品牌：%s - 价格：%d\n" , car2->carname , car2->price);
    printf("--------------------删除栈里所有元素-----------------\n");
    destroyStack(&stack);
    car2 = (car_t *)topStack(stack);
    if (car2 == NULL)
    {
        printf("栈不存在\n");
    }else{
         printf("品牌：%s - 价格：%d\n" , car2->carname , car2->price);
    }
    
    return 0;
}
