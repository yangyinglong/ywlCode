//计算一个字符串中a的个数

#include<stdio.h>
#include<string.h>


int main()
{
	int i, len;
	int num = 0;
	char c[5];        //定义一个有5个字符的字符串，可以手动改变 ？怎样可以随机输入
	scanf("%s",&c);
	/* 函数名()，中间不要有空格*/
	len = strlen (c);    //计算该字符串的长度
	for(i=0; i<=len; i++)
	{
		if(c[i] == 'a')    //将各个字符与'a'进行比较
		num = num + 1; 
	}	
	printf("count = %d\n",num);
	//printf("%d\n",len);

	//printf("the number of a = %d\n",s );

	return 0;
}