#include<stdio.h>
#include<malloc.h>
#include<windows.h>
typedef char Telemtype;
typedef struct node{
	Telemtype data;
	struct node *lchild,*rchild;
}BiTnode,*Bitree;
Bitree create_tree();
int main()
{
	print_tree(create_tree());
}
Bitree create_tree()
{
	Bitree T;
	Telemtype ch;
	ch=getchar();
	//getchar();
	if(ch=='#')
	{
		T=NULL;
		//printf("输入值为 '#',退出当前函数\n");
		return T;
	}
	else
	if((T=(Bitree)malloc(sizeof(BiTnode)))==NULL)
	{
		printf("空间分配失败\n");
		getch();
		exit(1);
	}
	printf("检测点\n");
	T->data=ch;
	T->lchild=create_tree();
	T->rchild=create_tree();
	printf("create 函数结束出口\n\n");
	return T;
}
int print_tree(Bitree T)
{
	
	visit(T);
	if(T->lchild!=NULL)
	{
		printf("左孩子不为空\n");
		print_tree(T->lchild);
	}
	if(T->rchild!=NULL)
	print_tree(T->rchild);
	return 0;
}
int visit(Bitree t)
{
	printf("\n检测点2\n");
	putchar(t->data);
	return 0;
}
