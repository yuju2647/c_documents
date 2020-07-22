#include <stdio.h>
#include<malloc.h>
typedef struct node         //二叉树结点类型的定义
{	
char data;
struct node *lchild;	       //定义结点的左孩子指针
struct node	*rchild;	   //定义结点的右孩子指针
}BinTNode;				

BinTNode *CreateBinTree()  //输入二叉树的先序遍历序列，创建二叉链表
{   
	BinTNode *t;
	char ch;
	ch=getchar();
	if (ch=='0')             //如果读入0，创建空树            
		t=NULL;
	else
	{	
		t=(BinTNode *)malloc(sizeof(BinTNode));	//申请根结点*t空间
		t->data=ch;                           //将结点数据ch放入跟结点的数据域
		t->lchild=CreateBinTree();		  //建左子树
		t->rchild=CreateBinTree();		  //建右子树
	} 
    return t;
}

void ListBinTree(BinTNode *t)                  //用广义表表示二叉树
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
	printf("请输入先序序列,虚结点用0表示(以图6.12(a)二叉树为例)：\n");
	t=CreateBinTree();
	printf("广义表表示的二叉树的输出：\n");
	ListBinTree(t);
	printf("\n");
}

程序运行结果：
请输入先序序列,虚结点用0表示(以图6.12(a)二叉树为例)：
ABC00DE00F000（回车）
广义表表示的二叉树的输出： 
A ( B ( C，D (E ，F)))
