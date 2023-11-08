#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>      
#include <time.h>      
#include<stdlib.h>
#include<string.h>
#define OK 1
#define error 0
int flag = error;                   //����������־
int count = 0;
struct time                       //ʱ��ṹ��
{
	int hour;
	int min;
};
typedef struct                    //��Ʊ�ṹ��
{
	int carnum;               //����
	struct time starttime;   //��ʼʱ��
	char startsta[30];       //���վ
	char endsta[30];         //�յ�վ
	struct time endtime;     //��վʱ��
	int ratednum;            //�����
	int booknum;             //�Ѷ�Ʊ����
	int ticketnum;           //��Ĺ�Ʊ����
}stuType;
typedef stuType elemType;     //��������洢�ڵ����������Ϊ�Զ�������
typedef struct node
{
	elemType data;           //�����򣬱���ڵ�ֵ
	struct node* next;        //ָ����
}linknode, * linklist;
linklist l;                         //����ͷָ��
void Init(linklist* l)
{
	*l = (linklist)malloc(sizeof(linknode));
	(*l)->next = NULL;
}
int main()
{
	void mainmenu();                //���˵�����
	void Init(linklist * l);             //��ʼ����ͷ���ĵ�����
	void Input(linklist l);               //������Ϣ����
	void Output(linklist l);               //��ʾ��Ϣ����
	void Search();                 //��ѯ��Ϣ����
	void Searchbynum(linklist l);              //���ݰ�κŲ�ѯ����
	void Searchbyadd(linklist l);             //�����յ�վ��ѯ�ĺ���
	void TicketManagement();       //ѡ��Ʊ/��Ʊ�ĺ���
	int TicketOrder(linklist l, int* count);               //��Ʊʵ�ֺ���
	int TicketDelete(linklist l, int* count);              //��Ʊʵ�ֺ���
	void Modify(linklist l);                         //�޸İ����Ϣ����
	int Insertnum(linklist l);                         //�����µĳ���
	int Deletenum(linklist l);                        //ɾ��ͣ���г����
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
	printf(" ��Ʊ����ϵͳ\n\n");
	printf("=============================================================\n");
	printf(" 1.¼������Ϣ\t\n");
	printf(" 2.��������Ϣ\t\n");
	printf(" 3.��ѯ�г�·��\t\n");
	printf(" 4.��Ʊ����Ʊϵͳ\t\n");
	printf(" 5.�޸İ����Ϣ����\t\n");
	printf(" 6.�˳���ϵͳ\t\n");
	printf("=============================================================\n");
	printf("��ѡ��������Ҫ�Ĺ��ܣ�");
	scanf("%d", &i);
	switch (i)
	{
	case 1:
	{
		system("cls");
		Input(l);
		getchar();
		printf("\n��������������˵�\n");
		getchar();
		mainmenu();
	}; break;
	case 2:
	{
		system("cls");
		Output(l);
		getchar();
		printf("\n��������������˵�\n");
		getchar();
		mainmenu();
	}; break;
	case 3:
	{
		system("cls");
		Search();
		getchar();
		printf("\n��������������˵�\n");
		getchar();
		mainmenu();
	}; break;
	case 4:
	{
		system("cls");
		TicketManagement();
		getchar();
		printf("\n��������������˵�\n");
		getchar();
		mainmenu();
	}; break;
	case 5:
	{
		system("cls");
		Modify(l);
		getchar;
		printf("\n��������������˵�\n");
		getchar();
		mainmenu();
	}; break;
	case 6:
	{
		flag = OK;
		printf("***********************************��лʹ�ñ�ϵͳ********************************************\n");
		exit(0);
	}; break;
	default:
	{
		printf("�Բ����������������ȷ���������Ϊ1-6.\n");
		getchar();
		printf("��������������˵�\n");
		getchar();
		mainmenu();
	}; break;
	}
	flag = error;
}
void Input(linklist l)
{
	linknode* r, * s;
	r = l;                     //βָ��ָ��ǰ��β
	char temp = 'Y';           //���������־����ʼֵ��Ϊ"Y"
	printf("��ʼ��������\n");
	while (temp == 'Y' || temp == 'y')
	{
		s = (linknode*)malloc(sizeof(linknode));
		printf("����������Ϣ��\n");
		scanf("%d", &s->data.carnum);
		printf("�����뷢����ʼʱ��(�м����ÿո����)��\n");
		scanf("%d %d", &s->data.starttime.hour, &s->data.starttime.min);
		if ((s->data.starttime.hour < 0 || s->data.starttime.hour>23) || (s->data.starttime.min < 0 || s->data.starttime.min>59))
		{
			printf("�������ʱ�䲻�Ϸ�������ȷ����ʱ��\n");
			getchar();
			printf("������������Ӳ˵���");
			getchar();
			Input(l);
		}
		printf("���������վ��\n");
		scanf("%s", s->data.startsta);
		printf("�������յ�վ��\n");
		scanf("%s", s->data.endsta);
		printf("�������վ��վʱ��(�м����ÿո����)��\n");
		scanf("%d %d", &s->data.endtime.hour, &s->data.endtime.min);
		if ((s->data.endtime.hour < 0 || s->data.endtime.hour>23) || (s->data.endtime.min < 0 || s->data.endtime.min>59))
		{
			printf("�������ʱ�䲻�Ϸ�������ȷ����ʱ��\n");
			getchar();
			printf("������������Ӳ˵���");
			getchar();
			Input(l);
		}
		printf("������ó��ζ������\n");
		scanf("%d", &s->data.ratednum);
		printf("������ó����ѹ�Ʊ������\n");
		scanf("%d", &s->data.booknum);
		printf("�����뱾���г���Ĺ�Ʊ��(û��Ʊ����:0)��");
		scanf("%d", &s->data.ticketnum);
		printf("���˳���ʣ��Ʊ����%d\n", s->data.ratednum - s->data.booknum);
		r->next = s;                        //�½ڵ�������β���֮��
		r = s;                              //β���ָ���µı�λ
		getchar();                           //����س���
		printf("Ҫ����������һ�˳����𣿣�Y/N����");
		scanf("%c", &temp);                 //�����־����
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
	printf("���\t����ʱ��\t���վ\t�յ�վ\t��վʱ��\t�����\t�Ѷ�Ʊ����\t��Ĺ�Ʊ��\tʣ��Ʊ��\n");
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
			printf("�˰��ѷ�������ѡ�������г���\n");
		}
		p = p->next;
	}
}
void Search()
{
	int i;
	printf("��ѯ�Ӳ˵�:\n");
	printf("=========================================================================\n");
	printf(" 1.����κŲ�ѯ\n");
	printf(" 2.���յ�վ��ѯ\n");
	printf(" 3.�������˵�\n");
	printf("=========================================================================\n");
	printf("��ѡ������Ҫ�Ĺ���:");
	scanf("%d", &i);
	switch (i)
	{
	case 1:system("cls"); Searchbynum(l);  break;
	case 2:system("cls"); Searchbyadd(l);  break;
	case 3:system("cls"); mainmenu(l); break;
	default:
	{
		printf("���������ȷ���������Ϊ1-3.\n");
		getchar();
		printf("�밴��������ز�ѯ�Ӳ˵�\n");
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
	printf("����������Ҫ��ѯ�İ�Σ�");
	scanf("%d", &i);
	while (p && p->data.carnum != i)
		p = p->next;
	if (p != NULL && p->data.carnum == i)
	{
		printf("���˰����ϢΪ��\n");
		printf("���\t����ʱ��\t���վ\t�յ�վ\t��վʱ��\t�����\t�Ѷ�Ʊ����\t��Ĺ�Ʊ��\tʣ��Ʊ��\n");
		printf("%d\t%d:%d\t\t%s\t%s\t", p->data.carnum, p->data.starttime.hour, p->data.starttime.min, p->data.startsta, p->data.endsta);
		printf("%d:%d\t\t%d\t\t%d\t\t%d\t%d\n", p->data.endtime.hour, p->data.endtime.min, p->data.ratednum, p->data.booknum, p->data.ticketnum, p->data.ratednum - p->data.booknum);
	}
	else
		printf("�Բ���û�����˳���");
}

void Searchbyadd(linklist l)
{
	linknode* p;
	p = l->next;
	char add[30];
	int i = 0;
	printf("�������յ�վ����");
	scanf("%s", add);
	while (p)
	{
		if ((strcmp(add, p->data.endsta) == 0))
		{
			printf("���˰����ϢΪ��\n");
			printf("���\t����ʱ��\t���վ\t�յ�վ\t��վʱ��\t�����\t�Ѷ�Ʊ����\t��Ĺ�Ʊ��\tʣ��Ʊ��\n");
			printf("%d\t%d:%d\t\t%s\t%s\t", p->data.carnum, p->data.starttime.hour, p->data.starttime.min, p->data.startsta, p->data.endsta);
			printf("%d:%d\t\t%d\t\t%d\t\t%d\t%d\n", p->data.endtime.hour, p->data.endtime.min, p->data.ratednum, p->data.booknum, p->data.ticketnum, p->data.ratednum - p->data.booknum);
			i++;
		}
		p = p->next;
	}
	if(i==0)
		printf("�Բ���û�����˳���");
}
void TicketManagement()
{
	int i;
	printf("==========================================================================\n");
	printf(" 1.��Ʊ.\n");
	printf(" 2.��Ʊ.\n");
	printf(" 3.�������˵�.\n");
	printf("==========================================================================\n");
	printf("��ѡ������Ҫ�Ĺ���:\n");
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
		printf("���������ȷ���������Ϊ1--3.\n");
		getchar();
		printf("������������Ӳ˵�.\n");
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
		printf("����������Ҫ�����г��İ�Σ�");
		scanf("%d", &m);
		while (p != NULL && p->data.carnum != m)
			p = p->next;
		if (p == NULL || p->data.carnum != m)
		{
			printf("�Բ���û�����˳������ѯ���ٶ�Ʊ��");
			getchar();
			printf("����������ض�Ʊ�˵���");
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
			t = p->data.starttime.min - now->tm_min;          //tΪ��ǰʱ���
			if ((now->tm_hour == p->data.starttime.hour && t >= 10) || now->tm_hour < p->data.starttime.hour)
			{
				if (p->data.booknum < p->data.ratednum)
				{
					printf("��ϲ����Ʊ�ɹ���");
					j++;
					p->data.booknum++;
					p->data.ticketnum++;
					printf("\n\t\t%d\n", j);
				}
				else
					printf("�Բ��𣬱����г������꣬������������лл������");
			}
			else
				printf("��Ʊʧ�ܣ������г������������빺����һ���г���\n");
			Output(l);

		}
		p = l->next;            //ÿ�ι�Ʊ�ɹ���ʧ�ܺ�p����������ͷ���󣬷�ֹ������Ʊʱp=NULL��
		getchar();
		printf("�������Ƿ���Ҫ������Ʊ(Y/N)��");
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
		printf("�Բ�������û����Ʊ���޷�������Ʊ������");
		return 0;
	}
	else
	{
		while (i == 'Y' || i == 'y')
		{
			printf("����������Ҫ��Ʊ�г��İ�Σ�");
			scanf("%d", &m);
			while (p != NULL && p->data.carnum != m)
				p = p->next;
			if (p == NULL || p->data.carnum != m)
			{
				printf("�Բ���û�����˳������ѯ������Ʊ��");
				getchar();
				printf("�������������Ʊ�˵���");
				getchar();
				TicketDelete(l, &count);
			}
			else
			{
				if (p->data.ticketnum == 0)
				{
					printf("�Բ�������δ�������г������ѯ������Ʊ");
					return j;
				}
				int t2;
				time_t timep2;
				struct tm* now;
				timep2 = time(NULL);
				now = localtime(&timep2);
				t2 = p->data.starttime.min - now->tm_min;          //tΪ��ǰʱ���
				if ((now->tm_hour == p->data.starttime.hour && t2 >= 20) || now->tm_hour < p->data.starttime.hour)
				{
					printf("��ϲ����Ʊ�ɹ���");
					j--;
					p->data.booknum--;
					p->data.ticketnum--;
				}
				else
					printf("��Ʊʧ�ܣ������г������������޷���Ʊ��\n");
				Output(l);

			}
			p = l->next;            //ÿ�ι�Ʊ�ɹ���ʧ�ܺ�p����������ͷ���󣬷�ֹ������Ʊʱp=NULL��
			getchar();
			printf("�������Ƿ���Ҫ������Ʊ(Y/N)��");
			scanf("%c", &i);
		}
	}
	return j;
}
void Modify(linklist l)
{
	int i;
	printf("==========================================================================\n");
	printf(" 1.�����µİ��.\n");
	printf(" 2.ɾ��ͣ�˰��.\n");
	printf(" 3.�������˵�.\n");
	printf("==========================================================================\n");
	printf("��ѡ������Ҫ�Ĺ���:\n");
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
		printf("���������ȷ���������Ϊ1--4.\n");
		getchar();
		printf("������������Ӳ˵�.\n");
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
	char temp = 'Y';           //���������־����ʼֵ��Ϊ"Y"
	printf("��ʼ�����µİ�Σ�\n");
	while (p->next != NULL)
		p = p->next;
	if (p == NULL)
	{
		printf("������󣬰�������������˵�");
		getchar();
		Modify(l);
	}
	else
	{
		while (temp == 'Y' || temp == 'y')
		{
			newNode = (linknode*)malloc(sizeof(linknode));
			printf("����������Ϣ��\n");
			scanf("%d", &newNode->data.carnum);
			printf("�����뷢����ʼʱ��(�м����ÿո����)��\n");
			scanf("%d %d", &newNode->data.starttime.hour, &newNode->data.starttime.min);
			if ((newNode->data.starttime.hour < 0 || newNode->data.starttime.hour>23) || (newNode->data.starttime.min < 0 || newNode->data.starttime.min>59))
			{
				printf("�������ʱ�䲻�Ϸ�������ȷ����ʱ��\n");
				getchar();
				printf("������������Ӳ˵���");
				getchar();
				Input(l);
			}
			printf("���������վ��\n");
			scanf("%s", newNode->data.startsta);
			printf("�������յ�վ��\n");
			scanf("%s", newNode->data.endsta);
			printf("�������վ��վʱ��(�м����ÿո����)��\n");
			scanf("%d %d", &newNode->data.endtime.hour, &newNode->data.endtime.min);
			if ((newNode->data.endtime.hour < 0 || newNode->data.endtime.hour>23) || (newNode->data.endtime.min < 0 || newNode->data.endtime.min>59))
			{
				printf("�������ʱ�䲻�Ϸ�������ȷ����ʱ��\n");
				getchar();
				printf("������������Ӳ˵���");
				getchar();
				Input(l);
			}
			printf("������ó��ζ������\n");
			scanf("%d", &newNode->data.ratednum);
			printf("������ó����ѹ�Ʊ������\n");
			scanf("%d", &newNode->data.booknum);
			printf("�����뱾���г���Ĺ�Ʊ��(û��Ʊ����:0)��");
			scanf("%d", &newNode->data.ticketnum);
			printf("���˳���ʣ��Ʊ����%d\n", newNode->data.ratednum - newNode->data.booknum);
			newNode->next = p->next;
			p->next = newNode;
			Output(l);
			getchar();                           //����س���
			printf("Ҫ����������һ�˳����𣿣�Y/N����");
			scanf("%c", &temp);                 //�����־����
		}
	}

	return l;
}
int Deletenum(linklist l)
{
	int num;
	printf("��������Ҫɾ���İ�Σ�");
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
		printf("û�����˳��Σ����ѯ����ɾ��");
		return 0;

	}
}