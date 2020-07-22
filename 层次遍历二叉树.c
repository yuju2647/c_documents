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

//全局变量定义
FILE *fp;
sequeue *q;

//函数声明
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
	printf("层次遍历树\n");
	level_order();
	//outqueue(q,&test);
//	printf("\n出队后,检验队中第一个值\n");
//	printf("%c  \n",test.data);
//	print_tree(&test);
	///printf("队列长度为：%d\n",len(q));
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
		printf("队列已满\n");
		return 0;
	}
	q->queue[++q->rear]=node;
	return 0;
}
int outqueue(sequeue *q,Bitreenode *temp)
{
	if((ifempty(q))==1)
	{
		//printf("队列为空\n");
		return 1;
	}
	int i=++q->front;
	temp->data=q->queue[i]->data;
	temp->lchild=q->queue[i]->lchild;
	temp->rchild=q->queue[i]->rchild;
	//printf("出队函数中，检测出队赋值情况\n");
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
	fp=fopen("二叉树先序序列数据.txt","r");
	if(fp==NULL)
	{
		printf("打开文件失败\n\n");
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
