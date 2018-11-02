#include<stdio.h>
void myswap(int &x, int &y)
{
    int t;
    t=x;
    x=y;
    y=t;
}

int main()
{
    int a, b;
    printf("请输入待交换的两个整数：");
    scanf("%d %d", &a, &b);
    myswap(a,b);  //直接以变量a和b作为实参交换
    printf("调用交换函数后的结果是：%d 和 %d\n", a, b);
    return 0;
}