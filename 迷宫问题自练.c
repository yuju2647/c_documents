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
//ȫ�ֱ�������
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
int assign()//���ļ�����ά���鸳ֵ 
{
	int i,j;
	FILE *fp;
	char ch;
	if((fp=fopen("�Թ�����","r+"))==NULL)
	{
		printf("�ļ���ʧ��\n");
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
	gettop(head,&i,&j);//ȡջ��Ԫ�� 
	if(i==0&&j==0)//�ж��Ƿ񵽴���� 
	return 1;
	if(i!=0)//�ж�(i-1,j)��i-1�Ƿ�������� 
	{
		if(ifexist(head,i-1,j)!=1)//ȷ������(i-1,j)��ջ�в����� 
		{
			if(data[i-1][j]==0)
			{
				printf("����(i-1,j)\n");
				push(head,i-1,j);//������(i-1,j)ѹջ
				printf("ѹջ������\n");
				printstack(head);
				printf("\n\n");
				if(operate(head)==1)//�ݹ�ʵ�� 
				return 1;
			}
		} 
	}
	if(i!=8)//�ж�(i+1,j)��i-1�Ƿ�������� 
	{
		if(ifexist(head,i+1,j)!=1)//ȷ������(i-1,j)��ջ�в����� 
		{
			if(data[i+1][j]==0)
			{
				printf("����(i+1,j)\n");
				push(head,i+1,j);// ������(i+1,j)ѹջ 
				printf("ѹջ������\n");
				printstack(head);
				printf("\n\n");
				if(operate(head)==1)//�ݹ�ʵ�� 
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
				printf("����(i,j-1)\n");
				push(head,i,j-1);
				printf("ѹջ������\n");
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
				printf("����(i,j+1)\n");
				push(head,i,j+1);
				printf("ѹջ������\n");
				printstack(head);
				printf("\n\n");
				if(operate(head)==1)
				return 1;
			}
		}
	}
	pop(head,&i,&j);
	printf("��ջ ������\n");
	printstack(head);
	return 0;
}
int init(struct location *head)//��ʼ��λ��ջ 
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
int  ifempty(struct location *head)//�ж��Ƿ�ջ�� 
{//head Ϊջ��ͷָ�� 
	if(head->next==NULL)
	return 1;
	return 0;
}
int push(struct location *head,int x,int y)//ѹջ���� 
{
	struct location *s;
	s=(struct location *)malloc(sizeof(struct location));
	s->x=x;
	s->y=y;
	s->next=head->next;
	head->next=s;
	return 0;
}
int pop(struct location *head,int *x,int *y)//��ջ���� 
{
	struct location *s;
	s=head->next;
	*x=s->x;
	*y=s->y;
	head->next=s->next;
	free(s);
	return 0;
}
int ifexist(struct location *head,int x,int y)//�ж������Ƿ��Ѵ���ջ�� 
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
