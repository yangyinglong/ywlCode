// 

#include <stdio.h>

int main()
{
	char s[10], c[10], d[10], e[10];
	int a, b;
	FILE * stream = fopen("fp.txt", "w+");
	if (stream == NULL)
	{
		printf("file open fail\n");
		return -1;
	}
	// 文件格式化写入
	fprintf(stream, "%s\t%s\n", "aaaa", "10100101");
	fprintf(stream, "%s\t%s", "bbbb", "20202020");
	// 移动文件光标到开头
	fseek(stream, 0L, SEEK_SET);
	// 判断光标是否到结尾
	while (!feof(stream))
	{
		fscanf(stream, "%s%s", s, d);
		printf("%s\t%s\n", s, d);
	}
	fclose(stream);
	return 0;
}