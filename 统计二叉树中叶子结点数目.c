#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//结构体数据类型定义//
typedef char chelemtype;
typedef struct node
{
	chelemtype data;
	struct node *next;
}qnode;
typedef struct que
{
	qnode *front;
	qnode *rear;
}linkqueue;
typedef struct tree
{
	chelemtype data;
	struct tree *lchild,*rchild;
}Bitree;
//全局变量定义//
FILE *fp;
Bitree *T;
int I=0;//叶子结点数量 
//函数声明//
int recovery(linkqueue *preorderqueue,linkqueue *inorderqueue,Bitree *rootnode);
int inqueue(linkqueue *q,chelemtype ch);
int ifexist(linkqueue *q,chelemtype ch);
Bitree *search(Bitree *t,chelemtype ch);
int main()
{
	linkqueue preorderqueue,inorderqueue;
	init(&preorderqueue);
	init(&inorderqueue);
	initqueue(&preorderqueue,&inorderqueue);
	chelemtype temp;
	outqueue(preorderqueue,&temp);
	T=(Bitree *)malloc(sizeof(Bitree));
	T->data=temp;
	recovery(&preorderqueue,&inorderqueue,T);
	printf("二叉树恢复完毕：");
	print_tree(T);
	//getch();
	////////////////////////////////////
	Bitree *q;
	q=search(T,'J');
	if(q!=NULL)
	{
		printf("\n\nq 不为空\n\n\n");
		putchar(q->data);
	}
	else
	{
		printf("\n\nq 为空\n");
		
	}
	///////////////////////////
	leaf(T);
	printf("叶子结点个数为：%d 个\n\n",I);
}
int leaf(Bitree *t)
{
	if(t->lchild!=NULL)
	leaf(t->lchild);
	else if(t->rchild==NULL)
	   I++; 
	if(t->rchild!=NULL)
	leaf(t->rchild);
	return 0;
}
Bitree *search(Bitree *t,chelemtype ch)
{
	Bitree *q;
	if(t->data==ch)
	return t;
	if(t->lchild!=NULL)
	{
		q=search(t->lchild,ch);
		if(q!=NULL)
		return q;
	}
	if(t->rchild!=NULL)
	{
		q=search(t->rchild,ch);
		if(q!=NULL)
		return q;
	}
	return NULL;
}
int initqueue(linkqueue *pre,linkqueue *in)
{
	if((fp=fopen("恢复二叉树数据.txt","r+"))==NULL)
	{
		printf("打开文件失败\n");
		getch();
		exit(1);
	}
	chelemtype ch;
	qnode *s;
	ch=fgetc(fp);
	while(ch!='\n')
	{
		s=(qnode *)malloc(sizeof(qnode));
		s->data=ch;
		s->next=pre->rear->next;
		pre->rear->next=s;
		pre->rear=s;
		ch=fgetc(fp);
	}
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		s=(qnode *)malloc(sizeof(qnode));
		s->data=ch;
		s->next=in->rear->next;
		in->rear->next=s;
		in->rear=s;
		ch=fgetc(fp);
	}
	fclose(fp);
	return 0;
}
int printqueue(linkqueue *q)
{
	qnode *p;
	p=q->front->next;
	if(p==NULL)
	printf("队列为空\n");
	while(p)
	{
		putchar(p->data);
		p=p->next;
	}
	return 0;
}
int recovery(linkqueue *preorderqueue,linkqueue *inorderqueue,Bitree *rootnode)
{
	linkqueue in_temp1,in_temp2;
	init(&in_temp1);
	init(&in_temp2);
	chelemtype ch;
	qnode *p;////////////////////中间指针  p
	p=inorderqueue->front->next;
	while(p->data!=rootnode->data)
	{
		inqueue(&in_temp1,p->data);
		p=p->next;
	}
	p=p->next;
	while(p)
	{
		inqueue(&in_temp2,p->data);
		p=p->next;
	} 
	linkqueue pre_temp1,pre_temp2;
	init(&pre_temp1);
	init(&pre_temp2);
	p=preorderqueue->front->next;
	qnode *q;
	q=preorderqueue->front;
	if(ifempty(&in_temp1)==0)
	{
		while(p)
		{
			if(ifexist(&in_temp1,p->data)==1)
			{
				inqueue(&pre_temp1,p->data);
				q->next=p->next;
				free(p);
				p=q->next;
			}
			else
			{
				inqueue(&pre_temp2,p->data);
				q->next=p->next;
				free(p);
				p=q->next;
			}
		}
		
	}
	else
	{
		while(p)
		{
			inqueue(&pre_temp2,p->data);
			p=p->next;
		}
	}
	chelemtype temp1,temp2;
	if(ifempty(&pre_temp1)==0)
	{
		rootnode->lchild=(Bitree *)malloc(sizeof(Bitree));
	    if(rootnode->lchild==NULL)
	    {
		    printf("左孩子 内存分配失败\n");
		    getch();
		    exit(1);
	    }
	    outqueue(&pre_temp1,&temp1);
	    rootnode->lchild->data=temp1;
	    rootnode->lchild->lchild=NULL;
	    rootnode->lchild->rchild=NULL;
	}
	else
	{
		rootnode->lchild=NULL;
	}
	if(ifempty(&pre_temp2)==0)
	{
		rootnode->rchild=(Bitree *)malloc(sizeof(Bitree));
	    if(rootnode->rchild==NULL)
	    {
		    printf("左孩子 内存分配失败\n");
		    getch();
		    exit(1);
	    }
	    outqueue(&pre_temp2,&temp2);
	    rootnode->rchild->data=temp2;
	    rootnode->rchild->lchild=NULL;
	    rootnode->rchild->rchild=NULL;
	}
	else
	{
		rootnode->rchild=NULL;
	}
	if(ifempty(&pre_temp1)==0)
	{
		recovery(&pre_temp1,&in_temp1,rootnode->lchild);
	}
	if(ifempty(&pre_temp2)==0)
	{
		recovery(&pre_temp2,&in_temp2,rootnode->rchild);
	}
	return 0;
}
int outqueue(linkqueue *q,chelemtype *temp)
{
	qnode *p;
	p=q->front->next;
	if(p==NULL)
	{
		return 0;
	}
	*temp=p->data;
	q->front->next=p->next;
	free(p);
	return 0;
}
int init(linkqueue *q)
{
	q->front=(qnode *)malloc(sizeof(qnode));
	q->front->next=NULL; 
	q->rear=q->front;
	return 0;
}
int inqueue(linkqueue *q,chelemtype ch)
{
	qnode *s;
	s=(qnode *)malloc(sizeof(qnode));
	s->data=ch;
	s->next=q->rear->next;
	q->rear->next=s;
	q->rear=s;
	return 0;
}
int ifexist(linkqueue *q,chelemtype ch)
{
	qnode *p;
	p=q->front->next;
	if(p==NULL)
	{
		getch();
		exit(1);
	}
	while(p)
	{
		if(p->data==ch)
		return 1;
		else
		p=p->next;
	}
	return 0;
} 
int get(linkqueue *q,chelemtype *ch)
{
	*ch=q->front->next->data;
	return 0;
}
int print_tree(Bitree *T)
{
	putchar(T->data);
	if(T->lchild!=NULL)
	{
		print_tree(T->lchild);
	}
	if(T->rchild!=NULL)
	{
		print_tree(T->rchild);
	}
}
int ifempty(linkqueue *q)
{
	if(q->front->next==NULL)
	{
		return 1;
	}
	return 0;
}
