#ifndef _CALCULATOR_IMPL_
#define _CALCULATOR_IMPL_
#include<stdio.h>
#include<unistd.h>

#define MAX 10
#define NAME 2308
#define PASSWD 2308

/**
 * 用户登录前主界面
*/
void menu(void);

/**
 * 选择功能页面
*/
void select_fuction_menu();

/**
 * 用户输入
*/
int scanf_user(int , int );

/**
 * 登录验证，传入账号与密码
*/
int login(int , int);


/**
 * 延时启动
*/
void lay_start();


/**
 * 选择功能
*/
int select_function(int);

/**
 * 计算方法
*/
double compute(int , int , char);

/**
 * 九九乘法表
*/
void multiplication_table(int , int);

/**
 * 判断是否继续计算
*/
int judgment_calculation(int , int , char);

int judgment_calculation_m(int flag_str , int temp_ , char flag_);

/**
 * 管理员查询方法，可查询到所有学员，不需要输入学员学号
*/
void manageCheckIdAndScore(int studentId[] , int studentScore[]);

/**
 * 管理员更改学员成绩
*/
void manageChangeStudentScore(int studentId , int studentScore[]);

/**
 * 普通人查询学生成绩
*/
void peopleCheckStudentScore(int studentId , int studentScore[]);
#endif