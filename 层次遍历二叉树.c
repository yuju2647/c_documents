#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define Maxnode 10 
typedef char celemtype;
typedef struct node
{
	celemtype data;
	struct node *lchild,*rchild;
}Bitreenode;
typedef struct que
{
	Bitreenode *queue[Maxnode];
	int front,rear;
}sequeue;

//ȫ�ֱ�������
FILE *fp;
sequeue *q;

//��������
Bitreenode *create_tree(); 
int main()
{
	sequeue temp;
	q=(sequeue *)malloc(sizeof(sequeue));
	initqueue(q);
	openfile(fp);
	Bitreenode *T,test;
	T=create_tree();
	//print_tree(T);
	inqueue(q,T);
	printf("��α�����\n");
	level_order();
	//outqueue(q,&test);
//	printf("\n���Ӻ�,������е�һ��ֵ\n");
//	printf("%c  \n",test.data);
//	print_tree(&test);
	///printf("���г���Ϊ��%d\n",len(q));
	closefile(fp);
}
int initqueue(sequeue *q)
{
	q->front=-1;
	q->rear=-1;
	return 0;
}
int ifempty(sequeue *q)
{
	if(q->front==q->rear)
	return 1;
	return 0;
}
int inqueue(sequeue *q,Bitreenode *node)
{
	if(q->rear==Maxnode-1)
	{
		printf("��������\n");
		return 0;
	}
	q->queue[++q->rear]=node;
	return 0;
}
int outqueue(sequeue *q,Bitreenode *temp)
{
	if((ifempty(q))==1)
	{
		//printf("����Ϊ��\n");
		return 1;
	}
	int i=++q->front;
	temp->data=q->queue[i]->data;
	temp->lchild=q->queue[i]->lchild;
	temp->rchild=q->queue[i]->rchild;
	//printf("���Ӻ����У������Ӹ�ֵ���\n");
	//printf("temp->data=%c \n",temp->data);
	return 0;
}
int printqueue(sequeue *q)
{
	int i;
	for(i=q->front+1;i<=q->rear;i++)
	{
		printf("%c  ",q->queue[i]->data);
	}
	return 0;
}
int len(sequeue *q)
{
	return (q->rear-q->front);
}
int openfile()
{
	fp=fopen("������������������.txt","r");
	if(fp==NULL)
	{
		printf("���ļ�ʧ��\n\n");
		exit(1);
	}
	return 0;
}
int closefile()
{
	fclose(fp);
	return 0;
}
Bitreenode *create_tree()
{
	Bitreenode *T;
	celemtype ch;
	ch=fgetc(fp);
	if(ch=='#')
	{
		T=NULL;
		return T;
	}
	T=(Bitreenode *)malloc(sizeof(Bitreenode));
	T->data=ch;
	T->lchild=create_tree();
	T->rchild=create_tree();
	return T;
}
int print_tree(Bitreenode *t)
{
	printf("%c ",t->data);
	if(t->lchild!=NULL)
	{
		print_tree(t->lchild);
	}
	if(t->rchild!=NULL)
	{
		print_tree(t->rchild);
	}
	return 0;
}
int level_order()
{
	Bitreenode *temp;
	temp=(Bitreenode *)malloc(sizeof(Bitreenode));
	if((outqueue(q,temp))==1)
	return 0;
	printf("%c  ",temp->data);
	if(temp->lchild!=NULL)
	inqueue(q,temp->lchild);
	if(temp->rchild!=NULL)
	inqueue(q,temp->rchild);
	level_order();
	return 0;
}
