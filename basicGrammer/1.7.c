//用两种循环输出26大小写字母

#include<stdio.h>

int main()
{
	//int A, a;
	
	for(int i = 'A'; i <= 'Z'; ++i)
	{
		printf("%c\n",i);
	}

	for(int a = 97; a <=122; ++a )
	{
		printf("%c\n",a);
	}


	/* 定义变量要放在最开头 */
	int A = 65;
	int a = 97;
	while(A <= 90)
	{
		printf("%c\n",A);
		A ++;
	}
	while(a <= 122)
	{
		printf("%c\n",a);
		a ++;
	}



	return 0;
}

