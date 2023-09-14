#include<stdio.h>

//二维数组的定义
/*  
    int arr[3][3] = {{1 , 2 , 3} , {1 , 2 , 3} , {1 , 2 , 3}};
    索引：   printf("%d\n" , arr[1][2]);
    遍历
*/

int main(int argc, char const *argv[])
{
    int arr[3][3] = {{1 , 2 , 3} , {4 , 5 , 6} , {7 , 8 , 9}};
    //printf("%ld\\n" , sizeof(arr)/sizeof(int));
    for (int i = 0; i < sizeof(arr)/sizeof(arr[i]); i++)
    {
        for (int j = 0; j < sizeof(arr[i])/sizeof(arr[i][j])  ; j++)
        {
            printf("%d " , arr[i][j]);
        }
        printf("\n");
        
    }
     return 0;
}
