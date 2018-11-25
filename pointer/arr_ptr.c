// 指针和数组

#include<stdio.h>

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	// printf("%d\n", *arr);
	// for (int i = 0; i < 5; ++i)
	// {
	// 	printf("%d ", *(arr+i)); //*(arr+i) == arr[i]
	// }
	// printf("\n");

	int *p_arr;
	p_arr = arr;

	printf("%d\n", *p_arr);
	for (int i = 0; i < 5; ++i)
	{
		printf("%x = ", p_arr);
		printf("%d \n", *p_arr);
		p_arr ++;
	}




	return 0;
}