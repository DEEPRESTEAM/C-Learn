#include "file.h"

//打开文件
FILE * file_open(char * file_name , char * modes){
    FILE * fp = fopen(file_name , modes);
    if (fp == NULL)
    {
        printf("打开文件失败\n");
        fclose(fp);
        return NULL;
    }
    return fp;
}

// /**
//  * 将结构体的内容写入文件
// */
void inFile(student * stu , FILE * file , int length){
    int temp = 0;
    while (temp <= (length -1))
    {
        fprintf(file , " %d %s %s %s %d %d\n " , stu[temp].class , stu[temp].user , stu[temp].passwd , stu[temp].name , stu[temp].grade , stu[temp].stuId);
        temp++;
    }
    printf("写入完成\n");
    
} 

// //求出结构体的长度
// int length(student * stu){
//     int temp = sizeof(student)/sizeof(stu);
//     return temp;
// }

void menueFather(int temp){
    printf("-------------------------------------\n");
    printf("|       欢迎来到学生管理系统        |\n");
    printf("-------------------------------------\n");
    if (temp == 2)
    {
        printf("欢迎你管理员\n");
    }
    if (temp == 1)
    {
        printf("你好学生\n");
    }
    printf("选择你需要的功能\n");
}

/**
 * 学生功能页面
*/
void menueStudent(){
    printf("-------------------------------------\n");
    printf("|       0:退出学生管理系统          |\n");
    printf("|       1:查询成绩                  |\n");
    printf("|       2:工作人员正在开发中...     |\n");
    printf("-------------------------------------\n");
}

/**
 * 老师功能页面
*/
void menueTeacher(){
    printf("-------------------------------------\n");
    printf("|       0:退出学生管理系统          |\n");
    printf("|       1:查看学生                  |\n");
    printf("|       2:增加学生信息              |\n");
    printf("|       3:删除学生信息              |\n");
    printf("|       4:修改学生信息              |\n");
    printf("|       5:工作人员正在开发中...     |\n");
    printf("-------------------------------------\n");
}
//实现登陆功能
//三个返回值，返回 1 普通人员即学生
//           返回 2 管理人员即老师
//           返回 0 无关人员或者笨逼，账号密码都记不住
int login( student * stu , int length){
    int count = 0;
    char user[MAX] = "0";
    char passwd[MAX] = "0";
    while (1)
    {
        int flag = 1;
        printf("输入你的账户:");
        scanf("%s" , user);
        getchar();
        printf("输入你的密码:");
        scanf("%s" , passwd);
        getchar();
        for (int i = 0; i < length; i++)
        {
            if (!strcmp( stu[i].user , user )) 
            {
                if (!strcmp(user , "1000")){
                    if(!strcmp(stu[i].passwd , passwd  ))
                    {
                        return 2;
                    }else if (count == 5)
                    {
                        printf("错太多了\n");
                        return 0;
                    }else{
                        printf("密码输入错误，请重新输入\n");
                        count++;
                        flag = 0;
                        break;
                    } 
                }else{
                    if(!strcmp(stu[i].passwd , passwd  ))
                    {
                        return 1;
                    }else if (count == 5)
                    {
                        printf("错太多了\n");
                        return 0;
                    }else{
                        printf("密码输入错误，请重新输入\n");
                        count++;
                        flag = 0;
                        break;
                    } 
                }
            }
            if (count == 5)
            {
                printf("错太多了\n");
                return 0;
            }
        }
        while (flag)
        {
            printf("账号错误\n");
            count++;
            break;
        }
        
    }
    
}
    

//将文件内容读取到结构体中
void readFileToStruct(student * stu , FILE * file , int length){
    int temp = 0;
    while (temp <= (length -1))
    {
        fscanf(file , " %d %s %s %s %d %d\n " , &stu[temp].class , stu[temp].user , stu[temp].passwd , stu[temp].name , &stu[temp].grade , &stu[temp].stuId);
        temp++;
    }
    
}

//打所以有学生信息
void prinfStruct(student * stu , int length){
    for (int i = 1; i < length; i++)
    {
        printf("班级：%d 账号：%s 密码：%-8s 姓名：%-8s \t成绩：%02d id：%d\n" , stu[i].class , stu[i].user , stu[i].passwd , stu[i].name , stu[i].grade , stu[i].stuId);
    }
    
}


/**
 * 功能选择
 * 学生只能通过输入学号查询自己的成绩
 * 老师可以 查看所有人列表，能够增加学生列表，能够删除学生列表，能够修改所有学生列表
*/
void functionSelection(student * stu , FILE * file , int flag , int length){
    int mode = 0;
    int userId = 0;
    if (flag ==1)
    {
        while (1)
        {
            menueStudent();
            printf("请选择你所需要的功能：");
            scanf("%d" , &mode);
            getchar();
            switch (mode)
            {
            case 0:
                return;
            case 1:
                while (1)
                {
                    printf("请输入学号\n");
                    scanf("%d" , &userId);
                    getchar();
                    if (userId >=0 && userId < length)
                    {
                        checkResults(stu , userId);
                        break;
                    }else{
                        printf("学号输入错误,请重新输入\n");        
                        continue;
                    }
                }
                break;
            case 2:
                printf("都说了工作人员真正开发中，急什么急\n");
                break;
            }
        }
    }
    if (flag == 2)
    {
        while (1)
        {
            menueTeacher();
            printf("请选择你所需要的功能：");
            scanf("%d" , &mode);
            getchar();
            switch (mode)
            {
            case 0:
                return;
            case 1:
                selectAll(stu , length);
                break;
            case 2:
                addStudent(stu , length , file);
                break;
            case 3:
                deleteStudent(stu , length , file);
                break;
            case 4:
                recomposeStudent(stu , length , file);
                break;
            case 5:
                printf("都说了工作人员真正开发中，急什么急\n");
                break;
            }
        }
    }
}

/**
 * 学生通过学号查询成绩
*/
void checkResults(student * stu , int userId){
    printf("%s 同学的成绩为:%d\n" , stu[userId].name , stu[userId].grade);
    printf("对 %s 同学成绩判断为：" , stu[userId].name);
    gradeJudgment(stu[userId].grade);
}

/**
 * 成绩判断器
*/
int gradeJudgment(int grade){
    int temp = grade / 10;
    switch (temp)
    {
        case 10:
            printf("拉满了真的拉满了\n");
            break;
        case 9:
            printf("十分有九分优秀\n");
            break;
        case 8:
            printf("表现良好，请继续努力\n");
            break;
        case 7:
            printf("表现中等，还得加油\n");
            break;
        case 6:
            printf("刚刚及格，好险好险\n");
            break;
        default:
            printf("不及格，小心父母混和双打，后面努力学习，争取取得好成绩\n");
            break;
    }
}


/**
 * 老师增加学员信息
*/
void addStudent(student * stu , int length , FILE * file){
    int flag = 1;
    while (1)
    {
        int temp = 0;
        for (int i = 0; i < length; i++)
        {
            if (stu[i].class == 0)
            {
                break;
            }
            temp++;
        }
        printf("%d\n" , temp);
        printf("请输入所需添加的学员\n");
        scanf("%d %s %s %s %d %d" , &stu[temp].class , stu[temp].user , stu[temp].passwd , stu[temp].name , &stu[temp].grade , &stu[temp].stuId);
        prinfStruct(stu , length);
        printf("是否继续增加学员:(1:0)\n");
        scanf("%d" , &flag);
        getchar();
        if (flag == 1)
        {
            continue;
        }else{
            break;
        }
        
    }

}


/**
 * 老师删除学员信息
*/
void deleteStudent(student * stu , int length, FILE * file){
    int userId = 0;
    printf("请输入需要删除学生的id:");
    scanf("%d" , &userId);
    getchar();
    stu[userId].class = 0;
    strcpy(stu[userId].user , "0");
    strcpy(stu[userId].passwd , "0");
    strcpy(stu[userId].name , "0");
    stu[userId].grade = 0;
    stu[userId].stuId = 0;
    selectAll(stu , length);
}
/**
 * 老师修改学员成绩
*/
void recomposeStudent(student * stu , int length, FILE * file){
    int class = 0;
    char  user[MAX] = "0";
    char  passwd[MAX] = "0";
    char  name[MAX] = "0";
    int grade = 0;

    int medo = 0;
    int userId = 0;
    printf("请输入你要修改的学员:");
    scanf("%d" , &userId);
    printf("1:班级\n");
    printf("2:账号\n");
    printf("3:密码\n");
    printf("4:姓名\n");
    printf("5:成绩\n");
    printf("请输入修改的选项:");
    scanf("%d" , &medo);
    switch (medo)
    {
    case 1:
        printf("请输入你想修改的值(班级):");
        scanf("%d" , &class);
        getchar();
        stu[userId].class = class;
        break;
    case 2:
        printf("请输入你想修改的值(账户):");
        scanf("%s" , user);
        strcpy(stu[userId].user , user);   
        break;
    case 3:
        printf("请输入你想修改的值(密码):");
        scanf("%s" , passwd);
        strcpy(stu[userId].passwd , passwd);   
        break;
    case 4:
        printf("请输入你想修改的值(姓名):");   
        scanf("%s" , name);
        strcpy(stu[userId].name , name); 
        break;
    case 5:
        printf("请输入你想修改的值(成绩):");
        scanf("%d" , &grade);
        stu[userId].grade = grade;
        break;
    default:
        printf("输入有误\n");
        break;
    }
}
/**
 * 老师查询所有学生
*/
void selectAll(student * stu , int length){
    prinfStruct(stu , length);
}