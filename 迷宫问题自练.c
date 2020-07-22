#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define I 9
#define J 8
struct location
{
	int x;
	int y;
	struct location *next;
};
//全局变量定义
int data[I][J];/*={
	{0,0,1,0,0,0,1,0},
	{0,0,1,0,0,0,1,0},
	{0,0,0,0,1,1,0,1},
	{0,1,1,1,0,0,1,0},
	{0,0,0,1,0,0,0,0},
	{0,1,0,0,0,1,0,1},
	{0,1,1,1,1,0,0,1},
	{1,1,0,0,0,1,0,1},
	{1,1,0,0,0,0,0,0}
	};*/ 
struct location head;
int main()
{
	init(&head);
	assign();
	printstack(&head);
	operate(&head);
}
int assign()//用文件给二维数组赋值 
{
	int i,j;
	FILE *fp;
	char ch;
	if((fp=fopen("迷宫数据","r+"))==NULL)
	{
		printf("文件打开失败\n");
		getch();
		exit(1);
	}
	for(i=0;i<=I-1;i++)
	{
		for(j=0;j<=J-1;j++)
		{
			ch=fgetc(fp);
			while(ch==' '||ch=='\n')
			ch=fgetc(fp);
			data[i][j]=ch-48;
		}
	}
	for(i=0;i<=I-1;i++)
	{
		for(j=0;j<=J-1;j++)
		{
			printf("%d    ",data[i][j]);
		}
		printf("\n\n");
	}
}
int operate(struct location *head)
{
	int i,j;
	gettop(head,&i,&j);//取栈顶元素 
	if(i==0&&j==0)//判断是否到达入口 
	return 1;
	if(i!=0)//判断(i-1,j)中i-1是否可向上走 
	{
		if(ifexist(head,i-1,j)!=1)//确认坐标(i-1,j)在栈中不存在 
		{
			if(data[i-1][j]==0)
			{
				printf("操作(i-1,j)\n");
				push(head,i-1,j);//将坐标(i-1,j)压栈
				printf("压栈操作后\n");
				printstack(head);
				printf("\n\n");
				if(operate(head)==1)//递归实现 
				return 1;
			}
		} 
	}
	if(i!=8)//判断(i+1,j)中i-1是否可向下走 
	{
		if(ifexist(head,i+1,j)!=1)//确认坐标(i-1,j)在栈中不存在 
		{
			if(data[i+1][j]==0)
			{
				printf("操作(i+1,j)\n");
				push(head,i+1,j);// 将坐标(i+1,j)压栈 
				printf("压栈操作后\n");
				printstack(head);
				printf("\n\n");
				if(operate(head)==1)//递归实现 
				return 1;
			}
		} 
	}
	if(j!=0)
	{
		if(ifexist(head,i,j-1)!=1)
		{
			if(data[i][j-1]==0)
			{
				printf("操作(i,j-1)\n");
				push(head,i,j-1);
				printf("压栈操作后\n");
				printstack(head);
				printf("\n\n");
				if(operate(head)==1)
				return 1;
			}
		}
	}
	if(j!=7)
	{
		if(ifexist(head,i,j+1)!=1)
		{
			if(data[i][j+1]==0)
			{
				printf("操作(i,j+1)\n");
				push(head,i,j+1);
				printf("压栈操作后\n");
				printstack(head);
				printf("\n\n");
				if(operate(head)==1)
				return 1;
			}
		}
	}
	pop(head,&i,&j);
	printf("出栈 操作后\n");
	printstack(head);
	return 0;
}
int init(struct location *head)//初始化位置栈 
{
	head->next=NULL;
	struct location *r,*s;
	r=head;
	s=(struct location *)malloc(sizeof(struct location));
	s->next=NULL;
	s->x=8;
	s->y=7;
	r->next=s;
	return 0;
}
int gettop(struct location *head,int *x,int *y)
{
	*x=head->next->x;
	*y=head->next->y;
	return 0;
}
int  ifempty(struct location *head)//判断是否栈空 
{//head 为栈的头指针 
	if(head->next==NULL)
	return 1;
	return 0;
}
int push(struct location *head,int x,int y)//压栈操作 
{
	struct location *s;
	s=(struct location *)malloc(sizeof(struct location));
	s->x=x;
	s->y=y;
	s->next=head->next;
	head->next=s;
	return 0;
}
int pop(struct location *head,int *x,int *y)//出栈操作 
{
	struct location *s;
	s=head->next;
	*x=s->x;
	*y=s->y;
	head->next=s->next;
	free(s);
	return 0;
}
int ifexist(struct location *head,int x,int y)//判断坐标是否已存在栈中 
{
	struct location *p;
	p=head->next;
	while(p)
	{
		if(p->x==x&&p->y==y)
		return 1;
		p=p->next;
	}
	return 0;
}
int printstack(struct location *head)
{
	struct location *s;
	s=head->next;
	while(s)
	{
		printf("(%d,%d)\n",s->x+1,s->y+1);
		s=s->next;
	}
	return 0;
}
int printstack2(struct location *head)
{
	struct location *s;
	s=head->next;
	while(s)
	{
		printf("(%d,%d)\n",s->x+1,s->y+19);
		s=s->next;
	}
	return 0;
}
