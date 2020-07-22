#include<stdio.h>    // 线性表子系统实验
typedef struct linknode
{
char data;
struct linknode *next;
}node;
node *head;
int n=0;									// 线性表长度

void CreateList()							// 建立线性表
{
		node *p,*s;
		char x;
		int z=1;
		head=new node;
		p=head;
		printf("\n\t\t建立一个线性表");
		printf("\n\t\t说明：请逐个输入字符，结束标记为“x”！\n");
		while(z)
		{
			printf("\t\t输入：");
			scanf("%c",&x);
			getchar();
			if(x!='x')
			{
				s=new node;
				n++;
				s->data=x;
				p->next=s;
				s->next=NULL;
				p=s;
			}
			else z=0;
		}
}

void InsList(int i,char x)					// 插入结点元素
{
		node *s,*p;
		int j;
		s=new node;
		n++;
		s->data=x;
		if(i==0)
		{
			s->next=head;
			head=s;
		}
		else
		{
			p=head;j=1;
			while(p!=NULL&&j<i)
			{
				j++;
				p=p->next;
			}
			if(p!=NULL)
			{
				s->next=p->next;
				p->next=s;
			}
			else 
				printf("\t\t未找到！\n");
		}
}

void DelList(char x)						// 删除结点元素
{
		node *p,*q;
		if(head==NULL) 
		{
			printf("\t\t链表下溢！\n");
			return;
		}
		if(head->next==NULL) 
		{	printf("\t\t线性表已经为空！");
			return;
		}
		q=head;
		p=head->next;
		while(p!=NULL&&p->data!=x)
		{	q=p;
			p=p->next;
		}
		if(p!=NULL)
		{	q->next=p->next;
			delete p;
			n--;
			printf("\t\t %c已经被删除！",x);
		}
		else
			printf("\t\t未找到！\n");
}

void ShowList()								// 显示线性表
{	node *p=head;
		printf("\n\t\t显示线性表的所有元素：");
		if(head->next==NULL||p==NULL)
			printf("\n\t\t链表为空！\n");
		else
		{
			printf("\n\t\t");
			while(p->next!=NULL)
			{	printf("%5c",p->next->data);
				p=p->next;
			}
		}
}

void SearchList(char x)						// 查找线性表元素
{	node *p;
		int i=1;
		if(head==NULL) 
		{	printf("\t\t链表下溢！\n");
			return;
		}
		if(head->next==NULL) 
		{	printf("\t\t线性表为空！没有任何内容！");
			return;
		}
		p=head->next;
		while(p!=NULL&&p->data!=x)
		{	p=p->next;
			i++;
		}
		if(p!=NULL)
			printf("\t\t 在第%d位上找到值为%c的结点！",i,x);
		else
			printf("\t\t未找到值为%c的结点！\n",x);
}

void main()
{	head=NULL;
		int choice,i,j=1;
		char x;
		while(j)
		{	printf("\n\n\n\n");
			printf("\t\t\t   线 性 表 子 系 统\n");
			printf("\n\t\t**********************************");
			printf("\n\t\t*          1----------建     表            *");
			printf("\n\t\t*          2----------插     入            *");
			printf("\n\t\t*          3----------删     除            *");
			printf("\n\t\t*          4----------显     示            *");
			printf("\n\t\t*          5----------查     找            *");
			printf("\n\t\t*          6----------求 表 长            *");
			printf("\n\t\t*          0----------返     回            *");
			printf("\n\t\t**********************************\n");
			printf("\t\t请选择菜单号(0--6)：");
			scanf("%d",&choice);getchar();
			if(choice==1)
				CreateList();
			else if (choice==2)
			{	printf("\n\t\t请输入的位置i和数值x(输入格式：i，x):");
				scanf("%d,%c",&i,&x);
				InsList(i,x);
			}
			else if (choice==3)
			{	printf("\n\t\t请输入要删除的数值：");
				scanf("%c",&x);
				DelList(x);
			}
			else if (choice==4)
				if(head==NULL)
					printf("\n\t\t请先建立线性表！");
				else
				    ShowList();
			else if (choice==5)
			{	printf("\n\t\t请输入要查找的元素：");
				scanf("%c",&x);
				SearchList(x);
			}
			else if (choice==6)
			{	printf("\n\t\t表长为%d",n);
			}
			else if (choice==0)
				j=0;
			else 
				printf("\n\t\t输入错误！请重新输入！\n");
		}
}
