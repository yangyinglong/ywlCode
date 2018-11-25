// 字符数组

#include <stdio.h>

int main()
{
	char carr[10];

	for (int i = 0; i < 10; ++i)
	{
		carr[i] = getchar();
	}

	while(getchar() == '\n');

	for (int i = 0; i < 10; ++i)
	{
		printf("%c\n", carr[i]);
	}

	

	return 0;
}