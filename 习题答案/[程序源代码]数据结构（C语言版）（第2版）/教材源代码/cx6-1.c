#include <stdio.h>
#include<malloc.h>
typedef struct node         //������������͵Ķ���
{	
char data;
struct node *lchild;	       //�����������ָ��
struct node	*rchild;	   //��������Һ���ָ��
}BinTNode;				

BinTNode *CreateBinTree()  //���������������������У�������������
{   
	BinTNode *t;
	char ch;
	ch=getchar();
	if (ch=='0')             //�������0����������            
		t=NULL;
	else
	{	
		t=(BinTNode *)malloc(sizeof(BinTNode));	//��������*t�ռ�
		t->data=ch;                           //���������ch���������������
		t->lchild=CreateBinTree();		  //��������
		t->rchild=CreateBinTree();		  //��������
	} 
    return t;
}

void ListBinTree(BinTNode *t)                  //�ù�����ʾ������
{
	if (t!=NULL)
	{
		printf("%c",t->data);
		if (t->lchild!=NULL||t->rchild!=NULL)
		{
			printf("(");
			ListBinTree(t->lchild);
			if (t->rchild!=NULL)
			printf(",");
			ListBinTree(t->rchild);
			printf(")");
		}
	}
}

void main()
{
	BinTNode *t=NULL;
	printf("��������������,������0��ʾ(��ͼ6.12(a)������Ϊ��)��\n");
	t=CreateBinTree();
	printf("������ʾ�Ķ������������\n");
	ListBinTree(t);
	printf("\n");
}

�������н����
��������������,������0��ʾ(��ͼ6.12(a)������Ϊ��)��
ABC00DE00F000���س���
������ʾ�Ķ������������ 
A ( B ( C��D (E ��F)))
