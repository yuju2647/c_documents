#include<stdio.h>
#include<malloc.h> 
#include<windows.h>
#define N 60000000
typedef struct SNAKE
{
	int x;
	int y;
	struct SNAKE *next;
}snake,*address;
address createsnake();//函数声明 
address activesnake2(address head,address S);
address snaketurnright(address head,address S);
address snakegoup(address head,address S);
address snaketurnleft(address head,address S);
address snakegodown(address head,address S);
address food(int i);
address HEAD,temp;//定义全局变量 
char direction;
int SX=4,SY=12,J=1;
int main()//主函数 
{
	temp=(address)malloc(sizeof(snake));
    temp->x=0;
    temp->y=0;
	int i=0,score=0;
	address S;
do
{
buildplatform();
HEAD=createsnake();
printsnake(HEAD);
S=food(score);
i=rightcircle(HEAD,S);
while(i==2)//吃到食物 循环 
{
at(120,16);
printf("得分=%d\n",++score);
J++;
S=food(score);
if(direction=='R')
{
	if(GetAsyncKeyState(VK_DOWN))
	i=downcircle(HEAD,S);
	else if(GetAsyncKeyState(VK_UP))
	i=upcircle(HEAD,S);
	else
	i=rightcircle(HEAD,S);

}
else if(direction=='L')
{
	if(GetAsyncKeyState(VK_DOWN))
    i=downcircle(HEAD,S);
	else if(GetAsyncKeyState(VK_UP))
	i=upcircle(HEAD,S);
	else
	i=leftcircle(HEAD,S);
}
else if(direction=='U')
{
	if(GetAsyncKeyState(VK_LEFT))
	i=leftcircle(HEAD,S);
	else if(GetAsyncKeyState(VK_RIGHT))
	i=rightcircle(HEAD,S);
	else
	i=upcircle(HEAD,S);
}
else if(direction=='D')
{
    if(GetAsyncKeyState(VK_LEFT))
	i=leftcircle(HEAD,S);
	else if(GetAsyncKeyState(VK_RIGHT))
	i=rightcircle(HEAD,S);
	else 
    i=downcircle(HEAD,S);
}
}
if(i==0)
{
	at(120,15);
	printf("游戏结束"); 
}
at(0,34);
system("pause");
freesnake(HEAD);
system("cls");
score=0;	
}
while(1);
} /////////////////////////////////////主函数结束 
int at(int x,int y)//光标位置移动 
{
	COORD pos;
	HANDLE hOutput;
    pos.X=x;
    pos.Y=y;
    hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput,pos);
    return 0;
}
int buildplatform()//建立界面 
{          
	int i,j;
	for(i=0;i<=100;i+=100)//打印左右边框 
	{
		for(j=1;j<=29;j++)
		{
			printnode(i,j);
		}
	}
	for(j=0;j<=30;j+=30)//打印上下边框 
	{
		for(i=0;i<=100;i+=2)
		{
		 printnode(i,j);
		}
	}
	return 0;
}
address createsnake()//建立一条蛇 
{
	int x=24,y=15;
	address head,s;
	head=(address)malloc(sizeof(snake));
	head->next=NULL;
	for(x=24;x>=14;x-=2)
	{
		s=(address)malloc(sizeof(snake));
		s->x=x;
		s->y=y;
		s->next=head->next;
		head->next=s;
	}
	return head;
}
int printnode(int x,int y)//打印结点 
{
	at(x,y);
	printf("■");
	return 0;
}
int printsnake(address p)//打印蛇身 
{
	int i;
	p=p->next;
	while(p)
	{
		printnode(p->x,p->y);
		p=p->next;
	}
	return 0;
}
address snaketurnright(address head,address S)//激活蛇 
{
	int i=0;
	address p,r,s;
	p=head->next;
	r=head;
	while(r->next!=NULL)
	r=r->next;
	s=(address)malloc(sizeof(snake));
		s->x=r->x+2;
		s->y=r->y;
		s->next=NULL;
		r->next=s;
	for(i=1;i<=N;i++)
	{}
	if(s->x==100)
	{
		at(0,31);
		printf("傻逼，撞上啦！");
		return NULL;
	} 
	if(biteitself(head)==3)
	{
		at(0,31);
		printf("傻逼，咬到自己了！");
		return NULL; 
	}
	if(s->x!=S->x||s->y!=S->y)
	{
	head->next=p->next;
	freesnakenode(p);
	}
	else
	return temp;
	printsnake(head);
	
	return head;
}
int freesnake(address head)//清除整条蛇链 
{
	address r=head,q;
	while(r->next!=NULL)
	{
	while(r->next!=NULL)
	{
		q=r;
		r=r->next;
	}
	q->next=r->next;
	int i;
	freesnakenode(r);
	r=head;
	}
	freesnakenode(r);
	return 0;
}
int freesnakenode(address p)//清除尾点 
{
	at(p->x,p->y);
	printf("  ");
	free(p);
}
address snakegoup(address head,address S)//向上走 单链表实现  
{
	address r,p,s;
	r=head->next;
	p=head;
	while(p->next!=NULL)
	p=p->next;
	s=(address)malloc(sizeof(snake));
	s->x=p->x;
	s->y=p->y-1;
	s->next=NULL;
	p->next=s;
	int i;
	for(i=1;i<=N;i++)
	{}
	if(s->y==0)
	{
		at(0,31);
		printf("傻逼，撞墙啦！");
		return NULL;
	}
	if(biteitself(head)==3)
	{
		at(0,31);
		printf("傻逼，咬到自己了！");
		return NULL; 
	}
	if(s->x!=S->x||s->y!=S->y)
	{
	head->next=r->next;
	freesnakenode(r);
	}
	else
	return temp;
	printsnake(head);
	return head;
}
address snaketurnleft(address head,address S)//向左转 单链表实现  
{
	address r,p,s;
	r=head->next;
	p=head;
	while(p->next!=NULL)
	p=p->next;
	s=(address)malloc(sizeof(snake));
	s->x=p->x-2;
	s->y=p->y;
	s->next=NULL;
	p->next=s;
	int i;
	for(i=1;i<=N;i++)
	{}
	if(s->x==0)
	{
		at(0,31);
		printf("傻逼，撞墙啦！");
		return NULL;
	}
	if(biteitself(head)==3)
	{
		at(0,31);
		printf("傻逼，咬到自己了！");
		return NULL; 
	}
	if(s->x!=S->x||s->y!=S->y)
	{
	head->next=r->next;
	freesnakenode(r);
	}
	else
	return temp;
	printsnake(head);
	return head;
}
address snakegodown(address head,address S)//向下走 单链表实现 
{
	address r,p,s;
	r=head->next;
	p=head;
	while(p->next!=NULL)
	p=p->next;
	s=(address)malloc(sizeof(snake));
	s->x=p->x;
	s->y=p->y+1;
	s->next=NULL;
	p->next=s;
	int i;
	for(i=1;i<=N;i++)
	{}
	
	if(s->y==30)
	{
		at(0,31);
		printf("傻逼，撞墙啦！");
		return NULL; 
	}
	if(biteitself(head)==3)
	{
		at(0,31);
		printf("傻逼，咬到自己了！");
		return NULL; 
	}
	if(s->x!=S->x||s->y!=S->y)
	{
	head->next=r->next;
	freesnakenode(r);
	}
	else
	return temp;
	printsnake(head);
	return head;
}
int rightcircle(address head,address S)//向右转 循环 
{
	int i,a=1,b=1;
	for(i=0;i<=50;i++)
	{
		head=snaketurnright(head,S);
		if(head==temp)
		{
		direction='R';
		return 2;
		}
		if(head==NULL)
		return 0; 
		if(GetAsyncKeyState(VK_DOWN))
		b=downcircle(head,S);
		else if(GetAsyncKeyState(VK_UP))
		a=upcircle(head,S);
		if(a==0||b==0)
		return 0;
		else if(a==2||b==2)
		return 2;	
	}
	return 0;
}
int upcircle(address head,address S)//向上转 循环 
{
	int i,a=1,b=1;
	for(i=0;i<=50;i++)
	{
		head=snakegoup(head,S);
		if(head==temp)
		{
		direction='U';
		return 2;
		}
		if(head==NULL)
		return 0;
		if(GetAsyncKeyState(VK_RIGHT))
		a=rightcircle(head,S);
		else if(GetAsyncKeyState(VK_LEFT))
		b=leftcircle(head,S);
	
		if(a==0||b==0)
		return 0;
		else if(a==2||b==2)
		return 2;
	}
	return 0;
}
int downcircle(address head,address S)//向下转 循环 
{
	int i,a=1,b=1;
	for(i=0;i<=50;i++)
	{
		head=snakegodown(head,S);
		if(head==temp)
		{
		direction='D';
		return 2;
		}
		if(head==NULL)
		return 0;
		if(GetAsyncKeyState(VK_RIGHT))
		a=rightcircle(head,S);
		else if(GetAsyncKeyState(VK_LEFT))
		b=leftcircle(head,S);
		if(a==0||b==0)
		return 0;
		else if(a==2||b==2)
		return 2;
	}
	return 0;
}
int leftcircle(address head,address S)//向左转 循环 
{
	int i,a=1,b=1;
	for(i=0;i<=50;i++)
	{
		head=snaketurnleft(head,S);
		if(head==temp)
		{
		direction='L';
		return 2;	
		}
		if(head==NULL)
		return 0;
		if(GetAsyncKeyState(VK_UP))
		a=upcircle(head,S);
		else if(GetAsyncKeyState(VK_DOWN))
		b=downcircle(head,S);	
		if(a==0||b==0)
		return 0; 
		else if(a==2||b==2)
		return 2;
	}
	return 0;
}
address food(int i)//出现食物 
{
	address s;
	s=(address)malloc(sizeof(snake));
	if(i==0)
	{
	s->x=30;
	s->y=10;
	}
	else
	{
	if(J>=15)
	J=1;
	SX+=2*J;
	SY+=J;
	if(SX>=98)
	SX=4;
	if(SY>=28)
	SY=9;
	s->x=SX;
	s->y=SY;	
	}
	printnode(s->x,s->y);
	return s;
}
int biteitself(address head)
{
	address s=head,r=head;
	while(s->next!=NULL)
	s=s->next;
	while(r!=NULL&&r!=s)
	{
		if(r->x==s->x&&r->y==s->y)
		return 3;
		r=r->next;
	}
	return 0;
}

