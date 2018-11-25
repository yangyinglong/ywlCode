//求j个人i门课的平均分、最高分及最低分

#include<stdio.h>

int main()
{
	/* 还是代码块对齐的问题*/
	int a[2][2];         //a[i][j]i门课，j个人
	int i, j, sum, max, min;
	for(i=0; i<=1; i++)
	{
		sum = 0;
		for(j=0; j<=1; j++)
		{
			scanf("%d",&a[i][j]);
			sum = sum + a[i][j];      //求各科的总分

			max = a[i][0];           //求各科的最高分
			if(max < a[i][j])
			{
				max = a[i][j];
			}

			min = a[i][0];          //求各科的最低分
			if(min > a[i][j])
			{
				min = a[i][j];
			}
		}
		printf("vag = %d\n",sum/j);   //sum/j求各科的平均分
		printf("max = %d\n",max);
		printf("min = %d\n",min);



	}

	return 0;
}