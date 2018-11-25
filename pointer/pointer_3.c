//利用指针访问数组

#include<stdio.h>

int main()
{
	int i;
	double score[] = {98, 87, 65, 43, 76};
	// double*ptr_score = score;        //重新定义一个指针，将score数组的首元素赋给它，用来求double类型的单个数组元素所占字节
    // printf("double %d\n",sizeof(ptr_score));     //sizeof()用来求字符串的长度,打印double类型的单个数组元素所占字节
	printf("the first address of the shuzu is :%p\n",score);       //打印数组的首地址
	printf("the address of the shuzu is :%p\n",&score[0]);         //打印数组的首元素地址
	for(i=0; i<5; i++)
	{
		//printf("%.2lf\n",ptr_score[i]);     //方法一
		printf("%.2lf\n",*(ptr_score+i));     //方法二   //在数组范围内，指针可加减任一整数
		//printf("%.2lf\n",*ptr_score++);     //方法三
	}
	//重新打印一遍数组元素
	//ptr_score = score;        //为方法3 重新定义指针
	for(i=0; i<5; i++)
		{
		//printf("%.2lf\n",ptr_score[i]);
		printf("%.2lf\n",*(ptr_score+i));   //方法1、2可直接使用，
		//printf("%.2lf\n",*ptr_score++);  //在使用方法3前需重新定义指针ptr_score = score
	}




	return 0;
}