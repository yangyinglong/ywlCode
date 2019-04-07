//未完成
/*
	判断E-mail地址是否合法：
 输入一个字符串，判断是否是合法邮箱（格式正确即可，不管是否真的存在）
 输入的只能是字母、数字、下划线、@以及.五种，
 @前后只能是字母或者数字，
 而且.后只能是com， 
 是则输出YES ，否则输出NO
*/

#include<stdio.h>
#include<string.h>

int main()
{
	char a[100];
	int len, i;
	int flag1 = 0;
	int flag2 = 0;
	scanf("%s", a);
	len = strlen(a);
	for (i = 0; i < len; i ++)
	{
		if (a[i] == '@')
		{
			if ((a[i -1] >= '0' && a[i - 1] <= '9') || (a[i -1] >= 'a' && (a[i + 1] <= 'z') && (a[i +1] >= '0' && a[i + 1] <= '9') || (a[i +1] >= 'a' && a[i + 1] <= 'z'))
			{
				flag1 = 1;
				
			}
			

		}
		if (a[i] == '.' && a[i + 1] == 'c' && a[i + 2] == 'o' && a[i + 3] == 'm')
		{
			flag2 = 1;
		}
	} 
	if (flag1 == 1 && flag2 == 1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}