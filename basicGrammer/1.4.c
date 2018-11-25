#include <stdio.h>

int main()
{
	int a;
	int temp;
	temp = 1;
	

	while(1 == temp)
	{
		printf("please enter a number from 1 to 7:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				printf("Today is Monday!\n");
				break;
			case 2:
				printf("Today is Tuesday!\n");
				break;
			case 3:
				printf("Today is Wednesday!\n");
				break;
			case 4:
				printf("Today is Thursday!\n");
				break;
			case 5:
				printf("Today is Friday!\n");			
				break;
			case 6:
				printf("Today is Saturday!\n");
				break;
			case 7:
				printf("Today is Sunday!\n");
				break;
			default:
				printf("please enter 1-7\n");
				temp = 0;
				break;
		}
	}
	
	return 0;
}