//输入一个3*3的矩形阵，求矩形阵中元素之和，并找出最小的元素的位置

#include<stdio.h>

int main()
{
	int i, j, sum, min;
	int a[3][3];
	int s, t;           //存放最小元素的位置
	for(i=0; i<=2; i++)
	{
		for(j=0; j<=2; j++)
		{
			scanf("%d",&a[i][j]);
			sum = sum + a[i][j];
			 
			if(a[i][j] < min)           //找出矩形阵中的最小元素及其位置
			{
				min = a[i][j];         
				s = i;
				t = j;
			}
			printf(" %d",a[i][j] );     //打印3*3的矩形阵
			if(j==2)printf("\n");
		}		
	}
	printf("sum = %d\n",sum );
	printf("min = %d\n",min );
	/* 下面中的空格问题
	   printf("i = %d j = %d\n", s, t);
	*/
	printf("i = %d j = %d\n",s,t );
	return 0;
}