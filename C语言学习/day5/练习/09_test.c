#include<stdio.h>
#define MAX 255
int page = 99;

int main(int argc, char const *argv[])
{
    printf("始发地：上海    目的地：长春    时间：2018年4月10日16：20出发\n");
    printf("三个城市剩余票为：%d\n" , page);
    printf("上海的12306系统剩余票数为：%d张\n" , page);
    printf("北京的12306系统剩余票数为：%d张\n" , page);
    printf("深圳的12306系统剩余票数为：%d张\n" , page);
    page--;
    printf("我抢到一张票数之后剩余票数：%d\n" , page);
    printf("我抢到一张票后三个城市剩余的票数分别为\n");
    printf("上海的12306系统剩余票数为：%d张\n" , page);
    printf("上海的12306系统剩余票数为：%d张\n" , page);
    printf("上海的12306系统剩余票数为：%d张\n" , page);

    return 0;
}
