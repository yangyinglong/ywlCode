// 结构体的语法学习

#include <stdio.h>
#include <string.h>


// 定义一个结构体
struct Student
{
	char idNumber[6];
	char name[10];
	int sex;	
};

// 声明函数
void printHead();
void printStu(struct Student * stu);
struct Student init(char * idNumber, char * name, int sex);
void inputCharArr(char charArr[], int length);

int main()
{
	// 定义结构体变量
	struct Student bob, alice, mike;
	// 定义结构体指针
	struct Student * pStu;

	// 初始化结构体指针
	pStu = &alice;

	// 对结构体变量bob 中的 idNumber 进行赋值
	strcpy(bob.idNumber, "00001");
	strcpy(bob.name, "Bob");
	bob.sex	= 1;

	// 通过 结构体指针 对 结构体变量 进行初始化
	strcpy(pStu->idNumber, "00002");
	strcpy(pStu->name, "Alice");
	pStu->sex	= 0;

	char idNumber[6], name[10];
	// 用函数 inputCharArr 对 char 数组 idNumber 赋值，这里的 idNumber 不是 Student 中的 idNumber
	printf("Please input idNumber\n");
	inputCharArr(idNumber, 6);
	printf("Please input name\n");
	inputCharArr(name, 10);

	// 用函数初始化一个结构体变量，并将其值返回，赋值给mike
	mike = init(idNumber, name, 1);

	printHead();

	// 将 结构体变量 的 地址 当做 参数 传递给函数 printStu
	printStu(&bob);
	printStu(pStu);
	printStu(&mike);

	return 0;
}

/**
 * 在终端打印出
 * ---------------------------------
 * |IdNumber       |Name   |Sex    |
 */
void printHead()
{
	for (int i = 0; i < 33; ++i)
	{
		printf("-");
	}
	printf("\n");
	printf("|IdNumber\t");
	printf("|");
	printf("Name\t");
	printf("|");
	printf("Sex\t");
	printf("|\n");

}

/**
 * 参数为 结构体 struct Student 类型的 指针
 * 在终端打印出
 * ---------------------------------
 * |00001          |Bob    |1      |
 */
void printStu(struct Student * stu)
{
	for (int i = 0; i < 33; ++i)
	{
		printf("-");
	}
	printf("\n|");
	printf("%s\t\t", stu->idNumber);
	printf("|");
	printf("%s\t", stu->name);
	printf("|");
	printf("%d\t", stu->sex);
	printf("|\n");
}

/**
 * 参数1为 char 类型的指针，参数2为 char 类型的指针，参数3为 int 类型
 * 在函数中定义了一个结构体变量，然后对他进行初始化，并将它的值返回
 * 参数类型为 char 类型的指针，也可以改成char 类型的数组，跟函数 inputCharArr(char charArr[], int length)
 * 我上次讲过，传 数组 当做函数的参数，跟传指针当做函数的参数是一样的，把这个函数中的 idNumber 改成数组传入，
 * 写在下面，内容一样，调用时也一样，只不过在头部申明的时候要保持一致而已
 * 传指针当做参数 和 传数组当做参数 其实本质上在调用的时候，都是把地址传给函数，比如 init(idNumber, name, 1); idNumber 就是 char idNumber[6] 的地址
 */
struct Student init(char * idNumber, char * name, int sex)
{
	struct Student stu;
	strcpy(stu.idNumber, idNumber);
	strcpy(stu.name, name);
	stu.sex = sex;
	return stu;
}

/*
struct Student init(char idNumber[], char * name, int sex)
{
	struct Student stu;
	strcpy(stu.idNumber, idNumber);
	strcpy(stu.name, name);
	stu.sex = sex;
	return stu;
}
*/

/*
 * 参数为 char 类型的数组，和 int 类型，length 是数组charrArr[] 的长度
 * 把数组 或者 指针传入，正如前面所讲的，传入的地址，在函数中对 地址上 的 值 进行修改，在函数外也生效，所以不用返回值
 * 在 main() 函数中对 inputCharArr() 函数进行了调用，传入的参数为 (idNumber, 6)，此时，idNum	ber 即使数组名，也是指向数组 idNumber[6] 的指针，
 * 在调用函数 inputCharArr() 的时候，把idNumber 的值赋值给了 charArr，也代表着 charArr 也指向了数组 idNumber[6]
 *
 * 在这个函数中，用getchar()来获取从终端输入的字符
 */
void inputCharArr(char charArr[], int length)
{
	while(getchar() != '\n');	// 这个 while() 是用来清除终端中残留字符，保证下面的 while() 中获取到的字符都是新输入的有效的字符
	int i = 0;
	char ch;
	printf("Please input charArr end with enter: ");
	while((ch = getchar()) != '\n' && i < length - 1)
	{
		charArr[i++] = ch;
	}
	charArr[i] = 0;
}