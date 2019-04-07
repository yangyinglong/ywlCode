/*
	输入十六进制数，通过计算输出相应的十进制数
*/
#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	char a[10];
	int i, len;
	long int dec = 0;
	scanf("%s", a);
	len = strlen(a);
	for (i = 0; i < len; i ++)
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			dec += (a[i] - 48) * pow(16, len -i - 1);
		}
		else if(a[i] >= 'A' && a[i] <= 'F')
		{
			// if(a[i] >= 'A' && a[i] <= 'F')
			// {
				dec += (a[i] - 55) * pow(16, len -i - 1);
			// }
		}
	}
	printf("%d\n", dec);
	return 0;
}