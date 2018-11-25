//利用指针访问数组2

#include<stdio.h>

int main()
{
	int array[] = {15, 20, 25, 30, 35};
	int i;
	int * ptr_array = array;  //把数组array中的值赋给指针*ptr_array
	for(i = 0; i < 5; i++)
	{
		//printf("the number %d is %d\t the adress of it is %p\n", i+1, ptr_array[i], &ptr_array[i]);      //方法一，最普通
		printf("the number %d is %d\t the adress of it is %p\n", i+1, *(ptr_array + i), ptr_array + i);    //方法二， 1
		// printf("the number %d is %d\t the adress of it is %p\n", i+1, *ptr_array, ptr_array);
		// ptr_array++;
	}







	return 0;
}