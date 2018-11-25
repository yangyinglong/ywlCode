//输入一个数字a，判断是否为3的倍数

#include<stdio.h>

int main()
{
 	int a, sum;
 	a = 1;
 	while(a)
 	{
	 	printf("please enter a numbers:");
	 	scanf("%d",&a);

	 	if(a%3 == 0)
	 	{
	 		sum = sum + a;
	 	}

	    // if(0 == a)
	    // {
	    // 	break;
	    // }


	    //printf("sum = %d\n",sum);

 	}


 	printf("sum = %d\n",sum);

	return 0;
}