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
    while (*str1)
    {
        if (*str1 != *str2)
        {
            return 0;
        }
        str1++;
        str2++;
    }
    return 1;
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
        char arr1[5]={"hello"};
        char arr2[5]={"hello"};
        int as = my_strcmp(arr1 , arr2);
        if (as)
        {
            printf("字符串相同\n");
        }else{
            printf("字符串不同\n");
        }
        
        return 0;
    }
    