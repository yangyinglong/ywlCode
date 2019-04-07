// 删除字符串两端的空格

#include <stdio.h>
#include <assert.h>
#include <string.h>

char *trim(char *str)
{
	assert(str);
	int index = -1;
	while(*str && (*str == ' ' || *str == '\t' || *str == '\r'))
	{
		index ++;
		str ++;
	}
	// 如果 *str 为空，就意味着str 全部是空格
	if (!*str)
	{
		*str = '\0';
	}
	int i = strlen(str);
	for (; i >= 0; --i)
	{
		if (!(*(str+i) == ' ' || *(str+i) == '\n' || *(str+i) == '\t' || *(str+i) == '\r'))
		{
			break;
		}
	}
	str[i] = '\0';
	return str;
}

int main()
{
	char str[20] = " 90909009 \t";
	char *r = trim(str);
	printf("%s\n", r);
	return 0;
}