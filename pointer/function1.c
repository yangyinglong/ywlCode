//一些简单的内置函数的使用

#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	//常用内置函数-0表示真，非0表示假

	//调用<ctype.h>头文件中的内置函数
	//如果输入的是单纯的数字，则表示ascii码
	printf("%d\n",isupper('a'));   //判断字母是否为大写字母
    printf("%d\n",islower('a'));   //判断字母是否为小写字母
    printf("%d\n",isalpha(97));    //判断返回的字符是否为字母
    printf("%d\n",isdigit('a'));   //判断返回的字符是否为数字
    printf("%c\n",toupper(65));    //将输入的数字(ascii码中的字母所对应的数字)或小写字母转换成大写字母
    
    //调用<math.h>头文件中的内置函数
    //ceil(天花板)-进一法    floor(地板)-去尾法
    //ceil 和 floor 的返回值均为double类型
    printf("%.2lf\n", ceil(98.1));         //小数点后数除0(.0)外，其他数(.1)均进一
    printf("%.2lf\n", floor(98.9));        //小数点后的数均被舍去
	printf("%.2lf\n", ceil(-98.1));        //如果是负数，则先去掉负号，然后将ceil变成floor进行运算后再加上负号
    printf("%.2lf\n", floor(-98.9)); 
    printf("%.2lf\n", sqrt(9));            //求平方根
    printf("%.2lf\n", pow(3,4));           //求x的y次方
    printf("%d\n", abs(-11));              //求绝对值

    //调用<stdlib.h>和<time.h>头文件中的随机数
    //1.设置随机种子-一般与时间联用（因为时间每时每刻都是在变化的）
    srand(time(NULL));      //也可以直接stand(随机输入某一个数)，但这样就无法随机输出一个数
  	//2.取随机数                   //将time中的值定义为NULL,即表示默认时间
  	int num = rand();
  	printf("%d\n", num);

  	//exit(0);   //0表示正常退出程序，非0表示非正常退出程序


  	printf("You are a pig!\n");
  	system("color 4E");      //颜色属性由两个十六进制数字指定，第一个为背景色，第二个为前景色


	return 0;
}