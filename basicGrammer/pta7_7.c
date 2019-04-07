#include<stdio.h>
#include<math.h>

int main()
{
	int a, b; 
	int i = 0;
	for(a = 100; a <= 200; a ++)
	{
		int flog = 0;
		for(b=2; b<=sqrt(a)+1; b++)
		{
			if(a % b == 0)
			{
				flog = 1;
				break;
			}
		}
		if(flog == 0)
		{
			printf("%5d", a);
			i += 1;
			if(i  == 8)
			{
				printf("\n");
				i = 0;
			}
		}	
	} 
	printf("\n");
	return 0;
}