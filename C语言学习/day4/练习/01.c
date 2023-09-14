#include<stdio.h>


int strlen_u(char * buf){
    char * str = buf;
    int num = 0;
    while (*str != '\0')
    {
        num++;  
        str++;  //移动指针
    }
    return num;
    
}
//实现字符串的对比(相同为1，不同为0)
int my_strcmp(char str1[] , char str2[]){
    for (int i = 0; i < sizeof(str1); i++)
    {
        if (str1[i] == str2[i])
        {
            return 1;        
        }
    }
    return 0;
    
}

/**
 * 实现字符串复制会覆盖复制的那份
*/
void my_strcpy(char str1[] , char str2[]){
    while (*str2)
    {
        *str1++ = *str2++;
    }
    
}

    /**
     * strcat把字符串数组2的值追加到字符串一中
    */
   void my_strcat(char str1[] , char str2[]){
        while (*str1)
        {
            str1++;
        }
        while (*str2)
        {
            *str1++ = *str2++;
        } 
   }
    
    
    /**
     * */ 
    char *my_strchr(char str[] , int a){
        while (*str)
        { 
            if ((int)*str == a)
            {
                    return (char*) str;
            }
            str++; 
        }
        return  NULL;
    } 

    int main(int argc, char const *argv[])
    {
        return 0;
    }
    