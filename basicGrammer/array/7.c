#include<stdio.h>
#include<math.h>

int main()
{
	int a;
	scanf("%d", &a);
	Kaprekar(a);
	return 0;
}

void Kaprekar(int a)
{
	int x, y, z;
	int b;
	b = a;
	for (i = 0; i < 100; i ++)
	{
		x = b / 100;   			 //x用来存放百位数
		y = (b - x * 100) / 10;  //y用来存放十位数
		z = b % 10;              //z用来存放个位数
		max = x;
		if (max < y)
		{
			max = y;
		}
		if (max < z)
		{
			max = z;
		}
		b = max 
	}
	
	

}