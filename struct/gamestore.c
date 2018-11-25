//模拟游戏中商品的购买（只支持一种）

//显示所有商品
//玩家选择要买的商品
//1--玩家的金钱 - 商品价格
//   商品库存 - 1
//   玩家背包中新增该商品或该商品数量 + 1

/*所需结构体：
             商品：名称、单价、库存量、属性
             背包：玩家编号、商品[10]、道具数量、最大道具数
             玩家：编号、名称、密码、金钱、[背包]
             */

#include<stdio.h>
#include<stdlib.h>
//定义结构

//商品结构
typedef struct _prop
{
	int id;         //道具的唯一编号
	char name[50];  //道具名称
	double price;   //道具单价
	int stock;      //库存量：如果在背包中，表示此道具的叠加数量
	char desc[200]; //道具的功能描述
}Prop;

//背包结构
typedef struct _bag
{
	int playerId;   //背包所属玩家编号
	int count;      //当前背包中道具的数量
	int max;        //当前背包插槽的总数--玩家可用rmb购买插槽
	Prop props;     //当前背包中的道具数组	
}Bag;

//玩家结构
typedef struct _player
{
	int id;          //玩家编号
	char name[50];   //玩家用户名
	char pass[50];   //玩家密码
	Bag bag;         //玩家背包
	double gold;     //玩家金币--显示100000铜币，可转换成银币、金币
	double sysee;    //元宝数量
}Player;
Prop *props;
Player *players;
int propsCount = 0;
int playersCount = 0;
void Init();  //用来初始化游戏数据
//函数声明
void ShowProps();
void ShowPlayers();

int main()
{
	//初始化游戏数据
	Init();
	//2、打印这些初始化数据
	ShowProps;
	return 0;	
}
void Init()
{
	//1、初始化数据
	static Prop propArray[] = {
		{1, "double card", 3000, 10, "very 666"},
		{2,"old clothes", 5000, 8, "you can just look it"},
		{3,"Rusty Iron Sword", 8000, 10, "just for freshman"},     //生锈的铁剑，新手专用
		{4,"Artillery", 130000, 5, "very very 666"},
		{5,"move up  medicinal", 83000, 10, "if you eat it, you will want again"}
	};
	propsCount = sizeof(propArray) / sizeof(prop);        //自己计算商城中商品数量
	props = propArray;      //设定指针的指向

	static Player playerArray[] = {
		{1, "super caterpillar", "123456", .gold = 50000},
		{2, "Tarlow Altman", "123456", .gold = 150000},
		{3, "The God of heaven", "123456", .gold = 1150000},
		{4, "Galaxie", "123456", .gold = 500000},
	};
	playersCount = 5;
	player = playerArray;
}
void ShowProps()
{
	int i;
	if(props == NULL) return;
	printf("number:\tname:\tprice:\tstock:\tintroduction:\n");           //编号，名称，价格，库存，商品介绍
	for (int i = 0; i < propsCount; i++)
	{
		printf("%d\t%s\t%.2lf\t%d\t%s\n", props[i].id, props[i].name, props[i].price, props[i].stock, props[i].desc);
	}
}
void ShowPlayers()
{

}



