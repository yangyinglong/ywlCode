#include<stdio.h>

int main()
{
	int N, i;
	int a[10];
	scanf("%d", &N);
	for(i = 0; i < N; i ++)
	{
		scanf("%d", &a[i]);
	}
	// min = a[0];
	//max = a[N-1];
	for(i = 1; i < N; i ++)
	{
		if(a[0] > a[i])
		{
			a[0] = a[i];
		}
	
	}
	for(i = 0; i < N; i ++)
	{
		printf("%d ", a[i]);
	}
	printf("%d\n", a[i]);
	return 0;
}