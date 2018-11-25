//输入一段文本，统计a的个数


#include <stdio.h>

int main()
{
	char message[1024];			//定义一个字符数组来存储输入的字符
	int index = 0;				//作为输入的下标
	int num_a = 0;				//统计a的数量
	char test[1024];

	/* 下面这四行代码实现了对一个字符数组的输入，一定要理解和记住
	   应该会经常用到，和 struct_.c 中的 void inputCharArr(char 
	   charArr[], int length) 这个函数相同，但是这个函数中，首
	   先把缓冲中的字符都清理了，可以看看这个函数的实现，*/
	while((message[index] = getchar()) != '\n' && index < 1024)
	{
		index ++;
	}
	message[index] = '\0';

	index = 0;
	while((test[index] = getchar()) != '\n' && index < 1024)
	{
		index ++;
	}
	test[index] = '\0';

	printf("message = %s\n", message);
	printf("test = %s\n", test);

	for (int i = 0; message[i] != '\0'; ++i)
	{
		if (message[i] == 'a')
			num_a ++;
	}
	printf("num_a = %d\n", num_a);

	return 0;
}