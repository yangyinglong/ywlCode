gitHub的使用
```
git 是一个代码管理工具，github 是一个远程仓库，使用 git 可以在本地创建一个代码仓库来存储代码，然后使用 git 可以连接到 github 上的远程仓库，这样本地修改的代码就可以通过 git 提交到 github 上，达到多人合作编写代码的目的

git 常用命令：
	git config --global user.name "vmCentos"
	git config --global user.email yangyl96@foxmail.com
	ssh-keygen -t rsa -C yangyl96@foxmail.com
	git init	#初始化仓库
	git add .	#提交到仓库
	git commit -m "****"	#提交文件并增加描述信息
	git remote add origin url(仓库url)	#增加关联仓库
	git pull    #同步远程仓库到本地仓库				
	git push -u origin master	#提交到远程仓库
	git remote rm origin	#取消关联仓库
	.gitignore	#这个文件中配置不提交到仓库中的文件
	git status	#查看文件修改情况
	git diff +　地址	#查看具体文件的更改情况
	git checkout + 地址	#撤销修改
	git log #查看提交记录
```

结构体的使用
```
结构体的定义
结构体变量的初始化
结构体指针
	指向结构体的指针
		struct Student * pStu;
结构体函数
	返回类型为结构体
		struct Student init(char * idNumber, char * name, int sex)；
	参数类型为结构体
		void printStu(struct Student * stu)；


```