// swich case 语句

#include <stdio.h>

int main()
{
	int source;
	scanf("%d", &source);

	switch(source)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			printf("A\n");
			break;
		case 7:
			printf("B\n");
			break;
		case 8:
			printf("C\n");
			break;
		default:       //default 语句不一定必须要
		
			break;
	}
	return 0;
}