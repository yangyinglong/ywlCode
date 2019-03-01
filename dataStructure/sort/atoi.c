// 字符串转整型 array to int
#include <stdio.h>
#include <assert.h>

int atoi(char * str)
{
	assert(str);
	int total = 0;
	int sign = 1;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+')
	{
		str++;
	}
	while(*str)
	{
		int tmp = *str - '0';
		if (tmp < 0 || tmp > 9)
		{
			break;
		}
		total = total * 10 + tmp;
		str++;
	}
	return total*sign;
}

int main()
{
	char str[10] = "-23412PP0";
	int total = atoi(str);
	printf("%d\n", total);
	return 0;
}