#include<stdio.h>
#define STUDENT 10
//小型学生管理系统
//改成绩
//查成绩

//如果你的函数定义在main函数的上面，则不用声明
void prin_ui(){
    printf("欢迎你！来到<大杂烩系统>\n");
    printf("输入相应的数字进入不同的功能：\n");
    printf("1.改成绩\n");
    printf("2.查成绩\n");
    int sc = 0;
    printf("请输入：");
    scanf("%d" ,&sc);
}
/**
 * 查成绩
*/
void checkGrades(){

}


/**
 * 改成绩
*/
int changeScore(int arr[]){

    printf("");
}

int main(int argc, char const *argv[])
{
    int num_1[STUDENT] = {10,10,10,10,10,10,10,10,10,10};
    int num_2[STUDENT] = {1,2,3,4,5,6,7,8,9,10};
    ch_score(num_1);
    return 0;
}
