#include<stdio.h>

int main()
{
	int N, i, j;
	char a[10][3];
	scanf("%d", &N);
	for(i = 0; i < N; i ++)
	{
		for(j = 0; j < 3; j ++)
		{
			scanf("%c", &a[i][j]);
			
		}
		if((a[i][2] < 15 || a[i][2] > 20) || (a[i][3] < 50 || a[i][3] > 75))
		{
			printf("%c\n", a[i][1]);
		}	
	}


	return 0;
}