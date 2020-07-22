#include <stdio.h>
#include<malloc.h>
typedef struct node         //二叉树结点类型的定义
{	
char data;
	 struct node *lchild;	//定义结点的左孩子指针
	 struct node	*rchild;	//定义结点的右孩子指针
} BinTNode;				

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
		t->data=ch;                                  //将结点数据ch放入跟结点的数据域
		t->lchild=CreateBinTree();			    //建左子树
		t->rchild=CreateBinTree();			    //建右子树
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

void preorder(BinTNode *t)   //对二叉树进行先序遍历
{
  if(t!=NULL)
	 {
   printf("%3c",t->data);
	   preorder(t->lchild);
   preorder(t->rchild); 
 }
} 

void inorder(BinTNode *t) //对二叉树进行中序遍历
{
  if(t!=NULL)
	  {
    inorder(t->lchild);
	    printf("%3c",t->data);
    inorder(t->rchild); 
  }
} 

void postorder(BinTNode *t) //对二叉树进行后序遍历
{
  if(t!=NULL)
	 {
   postorder(t->lchild);
	   postorder(t->rchild); 
	   printf("%3c",t->data);    
  }
} 

void main()
{
	 BinTNode *t=NULL;
	 printf("请输入先序序列,虚结点用0表示(以图6.14二叉树为例)：\n");
	 t=CreateBinTree();
	 printf("广义表表示的二叉树的输出：\n");
	 ListBinTree(t);                          //调用二叉树的广义表表示函数
	 printf("\n二叉树的前序遍历结果为:\n");
	 preorder(t);                             //调用二叉树先序遍历函数
	 printf("\n二叉树的中序遍历结果为:\n");
	 inorder(t);                              //调用二叉树中序遍历函数
	 printf("\n二叉树的后序遍历结果为:\n");
	 postorder(t);                            //调用二叉树后序遍历函数
 printf("\n"); 	
}

程序运行结果：
请输入先序序列,虚结点用0表示(以图6.14二叉树为例)：
ABD00E00CFG0000（回车）
广义表表示的二叉树的输出： 
A ( B ( D，E)，C ( F (G) ) )
二叉树的前序遍历结果为:
A B D E C F G
二叉树的中序遍历结果为:
D B E A G F C
二叉树的后序遍历结果为:
D E B G F C A
