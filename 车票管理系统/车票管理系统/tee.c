#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>      
#include <time.h>      
#include<stdlib.h>
#include<string.h>
#define OK 1
#define error 0
int flag = error;                   //函数结束标志
int count = 0;
struct time                       //时间结构体
{
	int hour;
	int min;
};
typedef struct                    //车票结构体
{
	int carnum;               //车次
	struct time starttime;   //起始时间
	char startsta[30];       //起点站
	char endsta[30];         //终点站
	struct time endtime;     //到站时间
	int ratednum;            //额定载量
	int booknum;             //已订票人数
	int ticketnum;           //你的购票数量
}stuType;
typedef stuType elemType;     //定义链表存储节点的数据类型为自定义类型
typedef struct node
{
	elemType data;           //数据域，保存节点值
	struct node* next;        //指针域
}linknode, * linklist;
linklist l;                         //定义头指针
void Init(linklist* l)
{
	*l = (linklist)malloc(sizeof(linknode));
	(*l)->next = NULL;
}
int main()
{
	void mainmenu();                //主菜单函数
	void Init(linklist * l);             //初始化带头结点的单链表
	void Input(linklist l);               //输入信息函数
	void Output(linklist l);               //显示信息函数
	void Search();                 //查询信息函数
	void Searchbynum(linklist l);              //根据班次号查询函数
	void Searchbyadd(linklist l);             //根据终点站查询的函数
	void TicketManagement();       //选择订票/退票的函数
	int TicketOrder(linklist l, int* count);               //订票实现函数
	int TicketDelete(linklist l, int* count);              //退票实现函数
	void Modify(linklist l);                         //修改班次信息函数
	int Insertnum(linklist l);                         //加入新的车次
	int Deletenum(linklist l);                        //删除停运列车班次
	Init(&l);
	do
	{
		mainmenu();
	} while (flag == error);
	return 0;
}

void mainmenu()
{
	int i;
	printf(" 车票管理系统\n\n");
	printf("=============================================================\n");
	printf(" 1.录入班次信息\t\n");
	printf(" 2.浏览班次信息\t\n");
	printf(" 3.查询行车路线\t\n");
	printf(" 4.售票与退票系统\t\n");
	printf(" 5.修改班次信息函数\t\n");
	printf(" 6.退出该系统\t\n");
	printf("=============================================================\n");
	printf("请选择你所需要的功能：");
	scanf("%d", &i);
	switch (i)
	{
	case 1:
	{
		system("cls");
		Input(l);
		getchar();
		printf("\n按任意键返回主菜单\n");
		getchar();
		mainmenu();
	}; break;
	case 2:
	{
		system("cls");
		Output(l);
		getchar();
		printf("\n按任意键返回主菜单\n");
		getchar();
		mainmenu();
	}; break;
	case 3:
	{
		system("cls");
		Search();
		getchar();
		printf("\n按任意键返回主菜单\n");
		getchar();
		mainmenu();
	}; break;
	case 4:
	{
		system("cls");
		TicketManagement();
		getchar();
		printf("\n按任意键返回主菜单\n");
		getchar();
		mainmenu();
	}; break;
	case 5:
	{
		system("cls");
		Modify(l);
		getchar;
		printf("\n按任意键返回主菜单\n");
		getchar();
		mainmenu();
	}; break;
	case 6:
	{
		flag = OK;
		printf("***********************************感谢使用本系统********************************************\n");
		exit(0);
	}; break;
	default:
	{
		printf("对不起你的输入有误，请确保你的输入为1-6.\n");
		getchar();
		printf("按任意键返回主菜单\n");
		getchar();
		mainmenu();
	}; break;
	}
	flag = error;
}
void Input(linklist l)
{
	linknode* r, * s;
	r = l;                     //尾指针指向当前表尾
	char temp = 'Y';           //建表结束标志，初始值设为"Y"
	printf("开始创建链表：\n");
	while (temp == 'Y' || temp == 'y')
	{
		s = (linknode*)malloc(sizeof(linknode));
		printf("请输入班次信息：\n");
		scanf("%d", &s->data.carnum);
		printf("请输入发车起始时间(中间请用空格隔开)：\n");
		scanf("%d %d", &s->data.starttime.hour, &s->data.starttime.min);
		if ((s->data.starttime.hour < 0 || s->data.starttime.hour>23) || (s->data.starttime.min < 0 || s->data.starttime.min>59))
		{
			printf("您输入的时间不合法，请正确输入时间\n");
			getchar();
			printf("按任意键返回子菜单。");
			getchar();
			Input(l);
		}
		printf("请输入起点站：\n");
		scanf("%s", s->data.startsta);
		printf("请输入终点站：\n");
		scanf("%s", s->data.endsta);
		printf("请输入此站到站时间(中间请用空格隔开)：\n");
		scanf("%d %d", &s->data.endtime.hour, &s->data.endtime.min);
		if ((s->data.endtime.hour < 0 || s->data.endtime.hour>23) || (s->data.endtime.min < 0 || s->data.endtime.min>59))
		{
			printf("您输入的时间不合法，请正确输入时间\n");
			getchar();
			printf("按任意键返回子菜单。");
			getchar();
			Input(l);
		}
		printf("请输入该车次额定载量：\n");
		scanf("%d", &s->data.ratednum);
		printf("请输入该车次已购票人数：\n");
		scanf("%d", &s->data.booknum);
		printf("请输入本趟列车你的购票数(没买票输入:0)：");
		scanf("%d", &s->data.ticketnum);
		printf("本趟车次剩余票数：%d\n", s->data.ratednum - s->data.booknum);
		r->next = s;                        //新节点链接在尾结点之后
		r = s;                              //尾结点指向新的表位
		getchar();                           //读入回车键
		printf("要继续输入下一趟车次吗？（Y/N）：");
		scanf("%c", &temp);                 //读入标志数据
	}
	r->next = NULL;
}

void Output(linklist l)
{
	time_t timep;
	struct tm* now;
	timep = time(NULL);
	now = localtime(&timep);
	linknode* p;
	p = l->next;
	printf("班次\t发车时间\t起点站\t终点站\t到站时间\t额定载量\t已订票人数\t你的购票数\t剩余票数\n");
	while (p)
	{
		if (now->tm_hour == p->data.starttime.hour && now->tm_min < p->data.starttime.min || now->tm_hour < p->data.starttime.hour)
		{
			printf("%d\t%d:%d\t\t%s\t%s\t", p->data.carnum, p->data.starttime.hour, p->data.starttime.min, p->data.startsta, p->data.endsta);
			printf("%d:%d\t\t%d\t\t%d\t\t%d\t%d\n", p->data.endtime.hour, p->data.endtime.min, p->data.ratednum, p->data.booknum, p->data.ticketnum, p->data.ratednum - p->data.booknum);
		}
		else
		{
			printf("%d\t%d:%d\t\t%s\t%s\t", p->data.carnum, p->data.starttime.hour, p->data.starttime.min, p->data.startsta, p->data.endsta);
			printf("%d:%d\t\t%d\t\t%d\t\t%d\t%d\t", p->data.endtime.hour, p->data.endtime.min, p->data.ratednum, p->data.booknum, p->data.ticketnum, p->data.ratednum - p->data.booknum);
			printf("此班已发出，请选择下趟列车。\n");
		}
		p = p->next;
	}
}
void Search()
{
	int i;
	printf("查询子菜单:\n");
	printf("=========================================================================\n");
	printf(" 1.按班次号查询\n");
	printf(" 2.按终点站查询\n");
	printf(" 3.返回主菜单\n");
	printf("=========================================================================\n");
	printf("请选择你需要的功能:");
	scanf("%d", &i);
	switch (i)
	{
	case 1:system("cls"); Searchbynum(l);  break;
	case 2:system("cls"); Searchbyadd(l);  break;
	case 3:system("cls"); mainmenu(l); break;
	default:
	{
		printf("输入错误，请确保你的输入为1-3.\n");
		getchar();
		printf("请按任意键返回查询子菜单\n");
		getchar();
		Search();
	}; break;
	}
}
void Searchbynum(linklist l)
{
	linknode* p;
	p = l->next;
	int i;
	printf("请输入你需要查询的班次：");
	scanf("%d", &i);
	while (p && p->data.carnum != i)
		p = p->next;
	if (p != NULL && p->data.carnum == i)
	{
		printf("本趟班次信息为：\n");
		printf("班次\t发车时间\t起点站\t终点站\t到站时间\t额定载量\t已订票人数\t你的购票数\t剩余票数\n");
		printf("%d\t%d:%d\t\t%s\t%s\t", p->data.carnum, p->data.starttime.hour, p->data.starttime.min, p->data.startsta, p->data.endsta);
		printf("%d:%d\t\t%d\t\t%d\t\t%d\t%d\n", p->data.endtime.hour, p->data.endtime.min, p->data.ratednum, p->data.booknum, p->data.ticketnum, p->data.ratednum - p->data.booknum);
	}
	else
		printf("对不起，没有这趟车。");
}

void Searchbyadd(linklist l)
{
	linknode* p;
	p = l->next;
	char add[30];
	int i = 0;
	printf("请输入终点站名：");
	scanf("%s", add);
	while (p)
	{
		if ((strcmp(add, p->data.endsta) == 0))
		{
			printf("本趟班次信息为：\n");
			printf("班次\t发车时间\t起点站\t终点站\t到站时间\t额定载量\t已订票人数\t你的购票数\t剩余票数\n");
			printf("%d\t%d:%d\t\t%s\t%s\t", p->data.carnum, p->data.starttime.hour, p->data.starttime.min, p->data.startsta, p->data.endsta);
			printf("%d:%d\t\t%d\t\t%d\t\t%d\t%d\n", p->data.endtime.hour, p->data.endtime.min, p->data.ratednum, p->data.booknum, p->data.ticketnum, p->data.ratednum - p->data.booknum);
			i++;
		}
		p = p->next;
	}
	if(i==0)
		printf("对不起，没有这趟车。");
}
void TicketManagement()
{
	int i;
	printf("==========================================================================\n");
	printf(" 1.订票.\n");
	printf(" 2.退票.\n");
	printf(" 3.返回主菜单.\n");
	printf("==========================================================================\n");
	printf("请选择你需要的功能:\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1:system("cls");
		count = TicketOrder(l, &count); break;
	case 2:system("cls");
		count = TicketDelete(l, &count); break;
	case 3:system("cls");
		mainmenu(); break;
	default:
	{
		printf("输入错误，请确保你的输入为1--3.\n");
		getchar();
		printf("按任意键返回子菜单.\n");
		getchar();
		TicketManagement();
	}; break;
	}
}
int TicketOrder(linklist l, int* count)
{
	linknode* p;
	p = l->next;
	char i = 'Y';
	int m;
	int j;
	j = *count;
	while (i == 'Y' || i == 'y')
	{
		printf("请输入您需要购买列车的班次：");
		scanf("%d", &m);
		while (p != NULL && p->data.carnum != m)
			p = p->next;
		if (p == NULL || p->data.carnum != m)
		{
			printf("对不起，没有这趟车，请查询后再订票。");
			getchar();
			printf("按任意键返回订票菜单。");
			getchar();
			TicketOrder(l, &count);
		}
		else
		{
			int t;
			time_t timep;
			struct tm* now;
			timep = time(NULL);
			now = localtime(&timep);
			t = p->data.starttime.min - now->tm_min;          //t为当前时间差
			if ((now->tm_hour == p->data.starttime.hour && t >= 10) || now->tm_hour < p->data.starttime.hour)
			{
				if (p->data.booknum < p->data.ratednum)
				{
					printf("恭喜您购票成功！");
					j++;
					p->data.booknum++;
					p->data.ticketnum++;
					printf("\n\t\t%d\n", j);
				}
				else
					printf("对不起，本趟列车已售完，请明天再来，谢谢合作。");
			}
			else
				printf("购票失败，本次列车即将出发，请购买下一趟列车。\n");
			Output(l);

		}
		p = l->next;            //每次购票成功或失败后将p重新链接在头结点后，防止继续购票时p=NULL。
		getchar();
		printf("请问您是否需要继续购票(Y/N)：");
		scanf("%c", &i);
	}
	return j;
}

int TicketDelete(linklist l, int* count)
{
	linknode* p;
	p = l->next;
	char i = 'Y';
	int m;
	int j = *count;
	if (j <= 0)
	{
		printf("对不起，您还没有买票，无法进行退票操作。");
		return 0;
	}
	else
	{
		while (i == 'Y' || i == 'y')
		{
			printf("请输入您需要退票列车的班次：");
			scanf("%d", &m);
			while (p != NULL && p->data.carnum != m)
				p = p->next;
			if (p == NULL || p->data.carnum != m)
			{
				printf("对不起，没有这趟车，请查询后再退票。");
				getchar();
				printf("按任意键返回退票菜单。");
				getchar();
				TicketDelete(l, &count);
			}
			else
			{
				if (p->data.ticketnum == 0)
				{
					printf("对不起，您尚未购买本趟列车，请查询后再退票");
					return j;
				}
				int t2;
				time_t timep2;
				struct tm* now;
				timep2 = time(NULL);
				now = localtime(&timep2);
				t2 = p->data.starttime.min - now->tm_min;          //t为当前时间差
				if ((now->tm_hour == p->data.starttime.hour && t2 >= 20) || now->tm_hour < p->data.starttime.hour)
				{
					printf("恭喜您退票成功！");
					j--;
					p->data.booknum--;
					p->data.ticketnum--;
				}
				else
					printf("退票失败，本趟列车即将出发，无法退票。\n");
				Output(l);

			}
			p = l->next;            //每次购票成功或失败后将p重新链接在头结点后，防止继续购票时p=NULL。
			getchar();
			printf("请问您是否需要继续退票(Y/N)：");
			scanf("%c", &i);
		}
	}
	return j;
}
void Modify(linklist l)
{
	int i;
	printf("==========================================================================\n");
	printf(" 1.加入新的班次.\n");
	printf(" 2.删除停运班次.\n");
	printf(" 3.返回主菜单.\n");
	printf("==========================================================================\n");
	printf("请选择你需要的功能:\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1:system("cls");
		l = Insertnum(l); break;
	case 2:system("cls");
		l = Deletenum(l); break;
	case 3:system("cls");
		mainmenu(); break;
	default:
	{
		printf("输入错误，请确保你的输入为1--4.\n");
		getchar();
		printf("按任意键返回子菜单.\n");
		getchar();
		Modify(l);
	}; break;
	}
}
int Insertnum(linklist l)
{
	Output(l);
	linknode* p = l, * newNode;
	//int m;
	char temp = 'Y';           //建表结束标志，初始值设为"Y"
	printf("开始插入新的班次：\n");
	while (p->next != NULL)
		p = p->next;
	if (p == NULL)
	{
		printf("输入错误，按任意键返回主菜单");
		getchar();
		Modify(l);
	}
	else
	{
		while (temp == 'Y' || temp == 'y')
		{
			newNode = (linknode*)malloc(sizeof(linknode));
			printf("请输入班次信息：\n");
			scanf("%d", &newNode->data.carnum);
			printf("请输入发车起始时间(中间请用空格隔开)：\n");
			scanf("%d %d", &newNode->data.starttime.hour, &newNode->data.starttime.min);
			if ((newNode->data.starttime.hour < 0 || newNode->data.starttime.hour>23) || (newNode->data.starttime.min < 0 || newNode->data.starttime.min>59))
			{
				printf("您输入的时间不合法，请正确输入时间\n");
				getchar();
				printf("按任意键返回子菜单。");
				getchar();
				Input(l);
			}
			printf("请输入起点站：\n");
			scanf("%s", newNode->data.startsta);
			printf("请输入终点站：\n");
			scanf("%s", newNode->data.endsta);
			printf("请输入此站到站时间(中间请用空格隔开)：\n");
			scanf("%d %d", &newNode->data.endtime.hour, &newNode->data.endtime.min);
			if ((newNode->data.endtime.hour < 0 || newNode->data.endtime.hour>23) || (newNode->data.endtime.min < 0 || newNode->data.endtime.min>59))
			{
				printf("您输入的时间不合法，请正确输入时间\n");
				getchar();
				printf("按任意键返回子菜单。");
				getchar();
				Input(l);
			}
			printf("请输入该车次额定载量：\n");
			scanf("%d", &newNode->data.ratednum);
			printf("请输入该车次已购票人数：\n");
			scanf("%d", &newNode->data.booknum);
			printf("请输入本趟列车你的购票数(没买票输入:0)：");
			scanf("%d", &newNode->data.ticketnum);
			printf("本趟车次剩余票数：%d\n", newNode->data.ratednum - newNode->data.booknum);
			newNode->next = p->next;
			p->next = newNode;
			Output(l);
			getchar();                           //读入回车键
			printf("要继续输入下一趟车次吗？（Y/N）：");
			scanf("%c", &temp);                 //读入标志数据
		}
	}

	return l;
}
int Deletenum(linklist l)
{
	int num;
	printf("请输入你要删除的班次：");
	scanf("%d", &num);
	linknode* pre = l, * p = l->next, * newNode;
	if (p == NULL)
		return 0;
	while (p != NULL && p->data.carnum != num) {
		pre = p;
		p = p->next;
	}
	if (p != NULL) {
		newNode = pre->next;
		pre->next = pre->next->next;
		free(newNode);
		Output(l);
		return 1;
	}
	else
	{
		printf("没有这趟车次，请查询后再删除");
		return 0;

	}
}