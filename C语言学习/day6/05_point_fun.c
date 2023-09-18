#include<stdio.h>
//定义一个结构体
typedef struct student
{
    char name[20];
    int age;
    float score;
}Student;
 
//比较两个学生的年龄
int compareByAge(Student stu1, Student stu2)
 {
    return stu1.age > stu2.age ? 1 : 0;
}
 
//比较两个学生的成绩
int compareByScore(Student stu1, Student stu2) 
{
    return stu1.score > stu2.score ? 1 : 0;
}
 
void sortStudents(Student *array, int n, int(*p)(Student, Student)) 
{
    Student temp;
    int flag = 0;
    for (int i = 0; i < n - 1 && flag == 0; i++) 
    {
        flag = 1;
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (p(array[j], array[j + 1])) 
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 0;
            }
        }
    }
}
 
int main() {
 
    Student stu1 = {"小明", 19, 98};
    Student stu2 = {"小红", 20, 78};
    Student stu3 = {"小白", 21, 88};
    Student stuArray[3] = {stu1, stu2, stu3};
    sortStudents(stuArray, 3, compareByScore);
    
    return 0;
}