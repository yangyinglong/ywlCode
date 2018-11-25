//自定义一个数组，求该数组中素数的个数

#include<stdio.h>
#include<math.h>

int main()
{
	int a[10], i, b, c;	    
	int flog = 0;      //用flog作为标记
	printf("input ten numbers:\n");
	/* 代码块 要对齐 */
	for(i=0; i<=9; i++)                                     
		{
			scanf("%d",&a[i]);
		for(b=2; b<=sqrt(a[i])+1; b++)
			{
				if(a[i] % b == 0 & a[i] != 2)    //and语句要怎么写啊
				{
					flog = 1;  //a[i]不是素数
					break;
				}
				else
				{
					flog = 0;
				}
		 	}
			 	if(flog == 0)
			 	{
			 		c = c + 1;
			 	}
		}
	 	printf("the number of sushu = %d\n",c);
	return 0;
}