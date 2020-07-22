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
//函数声明//
int recovery(linkqueue *preorderqueue,linkqueue *inorderqueue,Bitree *rootnode);
int inqueue(linkqueue *q,chelemtype ch);
int ifexist(linkqueue *q,chelemtype ch);

int main()
{
	//input_treeorder();
	linkqueue preorderqueue,inorderqueue;
	init(&preorderqueue);
	init(&inorderqueue);
	initqueue(&preorderqueue,&inorderqueue);
//	printf("先序序列\n");
//	printqueue(&preorderqueue);
//	printf("\n中序序列\n");
//	printqueue(&inorderqueue);
	chelemtype temp;
	outqueue(preorderqueue,&temp);
	//printf("\n出队结果\n");
	//putchar(temp);
	T=(Bitree *)malloc(sizeof(Bitree));
	T->data=temp;
	recovery(&preorderqueue,&inorderqueue,T);
	printf("\n\n\n\n\n\n                                    二叉树恢复完毕,后序序列为：");
	print_behind(T);
	getch();
}
int input_treeorder()
{
	printf("分别输入先序和中序序列，输入完一个序列按回车键换行，两个序列都输入完，输入'#'号键并按回车结束\n\n");
	if((fp=fopen("恢复二叉树数据.txt","w+"))==NULL)
	{
		printf("文件打开失败\n\n");
		getch();
		exit(1);
	}
	chelemtype ch;
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	} 
	fclose(fp);
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
		//printf("ch=%c\n",ch);
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
		//printf("ch2=%c\n",ch);
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
	/*printf("\n\n函数内\n");
	printf("先序："); 
	printqueue(preorderqueue); 
	printf("\n\n中序：");
	printqueue(inorderqueue);
	printf("\n\n根节点：%c",rootnode->data); 
	printf("\n\n建立 in_temp1,in_temp2两个队列\n\n");*/ 
	linkqueue in_temp1,in_temp2;
	//printf("\n初始化 in_temp1,in_temp2 队列\n");
	init(&in_temp1);
	init(&in_temp2);
	/*printf("打印in_temp1 队列(此时应为空)\n");
	printqueue(&in_temp1);*/ 
	chelemtype ch;
	qnode *p;////////////////////中间指针  p
	p=inorderqueue->front->next;
	while(p->data!=rootnode->data)
	{
		//printf("\n\n循环开始\n\n");
		inqueue(&in_temp1,p->data);
	/*	printf("入队操作后 in_temp1队列中元素：");
		printqueue(&in_temp1); */ 
		p=p->next;
	//	printf("\n\n单次循环结束\n");
	}
	/*printf("\n\np 移到 根节点元素\n");
	printf("in_temp1 队 入队完毕\n 队列元素为：");
	printqueue(&in_temp1); */ 
	p=p->next;
	while(p)
	{
		//printf("\n\n循环开始\n\n");
		inqueue(&in_temp2,p->data);
		/*printf("入队操作后 in_temp2队列中的元素为：");
		printqueue(&in_temp2); */ 
		p=p->next;
		//printf("\n\n单次循环结束\n");
	}
	/*printf("in_temp2队 入队完毕\n 队列元素为：");
	printqueue(&in_temp2);
	printf("\n\n\nin_temp1、in_temp2两个队列入队结束：");
	printf("\n   in_temp1：");
	printqueue(&in_temp1);
	printf("\n   in_temp2：");
	printqueue(&in_temp2); 
	printf("\n\n建立 pre_temp1,pre_temp2 两个队列\n\n");*/ 
	linkqueue pre_temp1,pre_temp2;
	//printf("\n\n初始化 这两个队列\n\n");
	init(&pre_temp1);
	init(&pre_temp2);
	//printf("\n将 指针p 指向 先序队列的对头\n");
	p=preorderqueue->front->next;
	//printf("设置 第二个中间指针 q\n");
	qnode *q;
	//printf("将q 指向 p 的前一个结点\n");
	q=preorderqueue->front;
	if(ifempty(&in_temp1)==0)
	{
		//printf("\n队列 in_temp1 不为空\n\n");
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
		//printf("\n队列 in_temp1 为空\n\n");
		//printf("将所有值存入 队列 pre_temp2 中\n");
		while(p)
		{
			inqueue(&pre_temp2,p->data);
			p=p->next;
		}
		//printf("\n\n已 将所有值存入 队列 pre_temp2 中 完毕\n\n");
	}
	/*printf("\n\n给 pre_temp 赋值结束，检验：\n\n  pre_temp1：");
	printqueue(&pre_temp1);
	printf("\n  pre_temp2：");
	printqueue(&pre_temp2); 
	printf("\n\n下一步，取 pre_temp1 和 pre_temp2 的队头结点当作根结点 rootnode 的左、右孩子\n\n");
	printf("\n给 左、右 孩子分配内存\n");*/ 
	chelemtype temp1,temp2;
	if(ifempty(&pre_temp1)==0)
	{
		//printf("\npre_temp1 不为空，为左孩子分配内存并取出 队列 pre_temp1 中队首值作为 左孩子树结点 值\n\n");
		rootnode->lchild=(Bitree *)malloc(sizeof(Bitree));
	    if(rootnode->lchild==NULL)
	    {
		    printf("左孩子 内存分配失败\n");
		    getch();
		    exit(1);
	    }
	    outqueue(&pre_temp1,&temp1);
	    //printf("\n检验取出值\n");
	    //printf("temp1= %c\n",temp1);
	    rootnode->lchild->data=temp1;
	    //printf("将其孩子设为 空值\n");
	    rootnode->lchild->lchild=NULL;
	    rootnode->lchild->rchild=NULL;
	}
	else
	{
		//printf("\npre_temp1 为空,将左孩子 设为 NULL 值\n");
		rootnode->lchild=NULL;
	}
	if(ifempty(&pre_temp2)==0)
	{
		//printf("\npre_temp2 不为空，为左孩子分配内存并取出 队列 pre_temp2 中队首值作为 左孩子树结点 值\n\n");
		rootnode->rchild=(Bitree *)malloc(sizeof(Bitree));
	    if(rootnode->rchild==NULL)
	    {
		    printf("左孩子 内存分配失败\n");
		    getch();
		    exit(1);
	    }
	    outqueue(&pre_temp2,&temp2);
	    //printf("\n检验取出值\n");
	    //printf("temp2= %c\n",temp2);
	    rootnode->rchild->data=temp2;
	    //printf("将其孩子设为 空值\n");
	    rootnode->rchild->lchild=NULL;
	    rootnode->rchild->rchild=NULL;
	}
	else
	{
		//printf("\npre_temp2 为空,将右孩子 设为 NULL 值\n");
		rootnode->rchild=NULL;
	}
//	printf("\n检验赋值情况\n打印出树的当前先序序列：");
//	print_tree(T);
//	printf("\n\n\n准备进入递归\n\n");
	//printf("\n判断 pre_temp1 是否为空\n");
	if(ifempty(&pre_temp1)==0)
	{
	//	printf("  队列 pre_temp1：不为空\n ");
		//printf("                 进入递归\n\n\n");
		recovery(&pre_temp1,&in_temp1,rootnode->lchild);
		//printf("\n\n\n                 退出递归\n\n");
	}
	else
	{
		//printf("  队列 pre_temp1 为空\n\n  不进入递归\n");
	}
	if(ifempty(&pre_temp2)==0)
	{
		//printf("  队列 pre_temp2：不为空\n ");
	//	printf("                 进入递归\n\n\n");
		recovery(&pre_temp2,&in_temp2,rootnode->rchild);
	//	printf("\n\n\n                 退出递归\n\n");
	}
	else
	{
	//	printf("  队列 pre_temp2 为空\n\n  不进入递归\n");
	}
	//printf("\n\n函数结束\n\n");
	return 0;
}
int outqueue(linkqueue *q,chelemtype *temp)
{
	qnode *p;
	p=q->front->next;
	if(p==NULL)
	{
	//	printf("队列为空\n");
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
	//printf("\n   入队函数内\n");
	qnode *s;
	s=(qnode *)malloc(sizeof(qnode));
	s->data=ch;
	s->next=q->rear->next;
	q->rear->next=s;
	q->rear=s;
//	printf("\n   入队函数执行结束\n\n");
	return 0;
}
int ifexist(linkqueue *q,chelemtype ch)
{
	qnode *p;
	p=q->front->next;
	if(p==NULL)
	{
	//	printf("队列为空\n");
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
		//printf("\n队列为空\n");
		return 1;
	}
	return 0;
}
int print_behind(Bitree *t)
{
	if(t->lchild!=NULL)
	print_behind(t->lchild);
	if(t->rchild!=NULL)
	print_behind(t->rchild);
	putchar(t->data);
	return 0; 
}
