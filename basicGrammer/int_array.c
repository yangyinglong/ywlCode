// Int 类型的 数组

#include <stdio.h>

#define ARRAY_LENGTH 10

int main()
{
	int arr[ARRAY_LENGTH] = {2};

	// for (int i = 0; i < ARRAY_LENGTH; ++i)
	// {
	// 	scanf("%d", &arr[i]);
	// }

	for (int i = 0; i < ARRAY_LENGTH; ++i)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}