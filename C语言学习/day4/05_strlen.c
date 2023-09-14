#include<stdio.h>
#include<string.h>


//小项目一个    实现一个strlen
//返回一个长度

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
    char str2[6] = {"world"};
    char str1[5] = {"hello"};

    printf( "%p\n",my_strchr(str1 , 'h'));
    printf( "%p\n",strchr(str1 , 'h'));

    //num = strlen_u(str1);
    //printf("字符串长度为：%d\n" , num);
    //printf("%s\n" , str1);
    // printf("str1数组下标5的地址为：%p\n" , &str1[5]);
    // printf("str2数组下标0的地址为：%p\n" , &str2[0]);
    // printf("%s\n" , str1);
    // printf("%s\n" , str2);
    

    return 0;
}
