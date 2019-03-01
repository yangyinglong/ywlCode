#include<stdio.h>


int a[100];


void dfs(int cur, int n)
{

	if (cur == n)
	{
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}

	for (int i = 1; i <= n; ++i)
	{
		int ok = 1;
		for (int j = 0; j < cur; ++j)
		{
			if (a[j] == i)
			{
				ok = 0;
			}
		}
		if (ok)
		{
			a[cur] = i;
			dfs(cur+1, n);
		}
	}
}

int main()
{
	dfs(0, 3);
    return 0;
}