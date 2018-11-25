//用穷举法列出pow(x,2) + pow(y,2) == 1000的所有整数

#include<stdio.h>
#include<math.h>

int main()
{
	int x, y;
	for(x = 1; x <= 100; x ++)
	{
		for(y = 1; y <= 100; y ++)
		{
			if(pow(x,2) + pow(y,2) == 1000)
			{
				printf("(x,y) = (%d,%d)\n",x,y);
			}
		}
	}
		









	return 0;
}