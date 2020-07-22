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
		//printf("����ֵΪ '#',�˳���ǰ����\n");
		return T;
	}
	else
	if((T=(Bitree)malloc(sizeof(BiTnode)))==NULL)
	{
		printf("�ռ����ʧ��\n");
		getch();
		exit(1);
	}
	printf("����\n");
	T->data=ch;
	T->lchild=create_tree();
	T->rchild=create_tree();
	printf("create ������������\n\n");
	return T;
}
int print_tree(Bitree T)
{
	
	visit(T);
	if(T->lchild!=NULL)
	{
		printf("���Ӳ�Ϊ��\n");
		print_tree(T->lchild);
	}
	if(T->rchild!=NULL)
	print_tree(T->rchild);
	return 0;
}
int visit(Bitree t)
{
	printf("\n����2\n");
	putchar(t->data);
	return 0;
}
