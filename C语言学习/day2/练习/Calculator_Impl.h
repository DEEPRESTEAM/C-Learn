#ifndef _CALCULATOR_IMPL_
#define _CALCULATOR_IMPL_
#include<stdio.h>

#define NAME 2308
#define PASSWD 2308

/**
 * 用户登录前主界面
*/
void menu(void);

/**
 * 用户输入
*/
int scanf_user(int , int );

/**
 * 登录验证，传入账号与密码
*/
int login(int , int);


/**
 * 取出字符串数组前 符号前 的字符串数字 以及 符号后 的字符串数字
*/


/**
 * 计算方法
*/
double compute(int , int , char);

/**
 * 判断是否继续计算
*/
int judgment_calculation(int , int , char);


#endif