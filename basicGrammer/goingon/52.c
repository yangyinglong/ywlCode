//用户输入宽高，打印长方形

#include<stdio.h>
int GetWidth();
int GetHigh();
void PrintStars(int n);
void PrintSpaceStar(int m);
int main()
{
    int w = 0;
    int h = 0;
    if (w <= 0 || h <= 0)
    {
        printf("Your input is invalid\n");
        return 1;                   //表示程序未正常退出
    }
    if (1 == h)
    {
        PrintStars(w);
    }
    else 
    {
        PrintStars(w);
        for (i = 1; i <= h - 2; i ++)
        {
            PrintSpaceStar(w);
        }
        PrintStars(w);
    }
    return 0;
}

void PrintStars(int n)
{
    int i = 0;
    for(i = 0; i <= n; i ++)
    {
        putchar('*');
    }
    /*        //方法二：用while循环来打印星号
    i = 1;
    while (i <= n)
    {
        putchar('*');
        i ++;
    }
    */
    putchar('\n');
    return;            //对于void函数加不加return都可以
}
//自定义函数 PrintSpaceStar,打印长方形的宽
void PrintSpaceStar(int m)
{
    if (m < 1)
    {
        return;            //输入错误，直接退出
    }
    if (1 == m)
    {
        printf("*\n");
    }
    else if(2 == m)
    {
        printf("**\n");
    }
    else
    {
        printf("*%*c\n", m - 1, '*');
    }
}
//自定义函数 GetWidth,用来输入长方形的宽
int GetWidth()
{
    int x = 0;
    printf("Please enter a width of rectangle: ");
    scanf("%d", &x);
    while(getchar() != '\n')
    {
    }
    return x;
}
//自定义函数 GetHigh,用来输入长方形的高
int GetHigh()
{
    int x = 0;
    printf("Please enter a high of rectangle: ");
    scanf("%d", &x);
    while(getchar() != '\n')
    {
    }
    return x;
}