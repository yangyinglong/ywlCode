//do - while 示例2:人机石头剪刀布

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int GetUserInput();
char GetIsAgain();
int main()
{
	int u = -1;      //用于存放用户的输入
	int p = -1;      //用于存放系统的输入（随机产生）
	char isagain = '\0';

	srand(time(NULL));        //以时间变化为基点，是每次产生的随机数都有所变化

	do
	{
		u = GetUserInput();
		p = rand() % 3;       //使电脑每次的输入为0或1或2；
		if (u < 0 || u > 2)
		{
			printf("You lost\n");
		}
		else
		{
			if (p == u)
			{
				printf("Pease!\n");
			}
			else
			{
				if ((u + 1) % 3 == p)
				{
					printf("You win!\n");
				}
				else
				{
					printf("You lost!\n");
				}
			}
		}
		isagain = GetIsAgain();
	}while(isagain == 'Y' || isagain == 'y');
	return 0;
}

int GetUserInput()
{
	int x = -1;
	printf("Please input your select: \n");
	printf("0: Rock\n");     //0代表石头
	printf("1: Scissor\n");  //1代表剪刀
	printf("2: Paper\n");    //2代表布
	scanf("%d", &x);
	while(getchar() != '\n')
	{

	}
	return x;
}

char GetIsAgain()
{
	char ch = '\0';       //变量ch的初值赋为0
	printf("Please input Y or y continue the game\n");
	ch = getchar();
	while(getchar() != '\n')
	{

	}
	return ch;

}