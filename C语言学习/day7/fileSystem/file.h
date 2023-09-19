#ifndef __FILE_H_
#define __FILE_H_
#include<stdio.h>
#include<string.h>
#define MAX 255
#define LENGTH 20;
typedef struct student
{
    int class;              //班级
    char user[MAX];         //用户账户
    char passwd[MAX];       //用户密码
    char name[MAX];         //用户姓名
    int grade;              //用户成绩
    int stuId;              //用户Id
}student;


/**
 * 父界面
*/
void menueFather(int temp);


/**
 * 子界面（学生）
*/
void menueStudent();


/**
 * 子界面（老师）
*/
void menueTeacher();


/**
 * 打开文件
*/
FILE * file_open(char * file_name , char * modes);


/**
 * 账号登录
*/
int login( student * stu , int length);


/**
 * 写入文件
*/
void inFile(student * stu , FILE * file , int length);


/**
 * 将文件内容读取到结构体中
*/
void readFileToStruct(student * stu , FILE * file , int length);


/**
 * 将结构体所有的内容打印出来
*/
void prinfStruct(student * stu , int length);


/**
 * 功能选择
*/
void functionSelection(student * stu , FILE * file , int flag , int length);


/**
 * 学生功能
*/
void checkResults(student * stu , int userId);


/**
 * 成绩判断
*/
int gradeJudgment(int grade);


/**
 * 老师增加学员信息
*/
void addStudent(student * stu , int length , FILE * file);


/**
 * 老师删除学员信息
*/
void deleteStudent(student * stu , int length , FILE * file);


/**
 * 老师修改学=员信息
*/
void recomposeStudent(student * stu , int length , FILE * file);


/**
 * 老师查询所有学生
*/
void selectAll(student * stu , int length);

#endif