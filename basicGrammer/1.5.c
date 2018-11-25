//输入密码，输出对应的用户类型

#include <stdio.h>

int main()
{
	int a;
	printf("please enter a password of four numbers:\n");
	scanf("%d",&a);
	// if(a == 0000)
	// {
	// 	printf("This is an authorized user\n");
	// }
	// else if(a == 1111)
	// {
	// 	printf("This is a shouquan user\n");
	// }

	// else if(a == 1234)
	// {
	// 	printf("This is a Normal user\n");
	// }

	// else
	// {
	// 	printf("This is a illegal user\n");
	// }


	switch(a)
	{
		case 0000:
			printf("This is an authorized user\n");break;
		case 1111:
			printf("This is a shouquan user\n");break;
		case 1234:
			printf("This is a Normal user\n");break;
		default:
			printf("This is a illegal user\n");break;

	}

	return 0;



}