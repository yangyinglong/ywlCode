#include<stdio.h>
#include<math.h>

int main()
{
	int i;
	char a[31];
	int IP1 = 0, IP2 = 0, IP3 = 0, IP4 = 0;
	// IP1 = IP2 = IP3 = IP4 = 0;
	for(i = 0; i <= 7; i ++)
	scanf("%c", &a[i]);

	for(i = 0; i <= 7; i ++)
	{
		IP1 = IP1 + (a[i] - '0') * pow(2,(7 - i));
	}
	for(i = 8; i <= 15; i ++)
	{
		IP2 = IP2 + (a[i] - '0') * pow(2,(15 - i));
	}
	for(i = 16; i <= 23; i ++)
	{
		IP3 = IP3 + (a[i] - '0') * pow(2,(23 - i));
	}
	for(i = 24; i <= 31; i ++)
	{
		IP1 = IP1 + (a[i] - '0') * pow(2,(31 - i));
	}
	printf("%d.%d.%d.%d\n", IP1, IP2, IP3, IP4);
	return 0;
}