#include <stdio.h>
#include<malloc.h>
#define MAXLEN 100
typedef struct BINTNODE			           		// 定义二叉树结构体
{	
char data;
struct BINTNODE *lchild,*rchild;
}BINTNODE;
BINTNODE *CreateBT();                
void ShowTree(BINTNODE *t);
void Preorder(BINTNODE *t);
void Postorder(BINTNODE *t);
void Levelorder(BINTNODE *t);
void Inorder(BINTNODE *t);
void Leafnum(BINTNODE *t);
void Nodenum(BINTNODE *t);
int TreeDepth(BINTNODE *t);
int count=0;					         		// 定义计算结点个数数的变量
void main()                             			// 树子系统住函数
{	BINTNODE *t=NULL;
		char ch1,ch2,a;
		ch1='y';
		while(ch1=='y'||ch1=='Y')
		{	printf("\n\n\n\n");
			printf("\n\n\t\t\t二 叉 树 子 系 统\n");
			printf("\n\t\t***************************************");
			printf("\n\t\t*           1---------建 二 叉 树           *");
			printf("\n\t\t*           2---------凹 入 显 示           *");
			printf("\n\t\t*           3---------先 序 遍 历           *");
			printf("\n\t\t*           4---------中 序 遍 历           *");
			printf("\n\t\t*           5---------后 序 遍 历           *");
			printf("\n\t\t*           6---------层 次 遍 历           *");
			printf("\n\t\t*           7---------求 叶 子 数           *");
			printf("\n\t\t*           8---------求 结 点 数           *");
			printf("\n\t\t*           9---------求 树 深 度           *");
			printf("\n\t\t*           0---------返       回           *");
			printf("\n\t\t***************************************");
			printf("\n\t\t请选择菜单号(0--9):");
			scanf("%c",&ch2);
			getchar();
			printf("\n");
			switch(ch2)
			{
			case '1':
			printf("\n\t\t请输入按先序建立二叉树的结点序列：");
			printf("\n\t\t说明：'0'代表后继结点为空,请逐个输入,按回车输入下一结点。");
			printf("\n\t\t请输入根结点：");
			t=CreateBT();
			printf("\n\t\t二叉树成功建立!\n");break;
			case '2':
			ShowTree(t);break;
			case '3':
			printf("\n\t\t该二叉树的先序遍历序列为：");
			Preorder(t);break;
			case '4':
			printf("\n\t\t该二叉树的中序遍历序列为：");
			Inorder(t);break;
			case '5':
			printf("\n\t\t该二叉树的后序遍历序列为：");
			Postorder(t);break;
			case '6':
			printf("\n\t\t该二叉树的层次遍历序列为：");
			Levelorder(t);break;
			case '7':
			count=0;Leafnum(t);
			printf("\n\t\t该二叉树有%d个叶子。\n",count);break;
			case '8':
			count=0;Nodenum(t);
			printf("\n\t\t该二叉树总共有%d个结点。\n",count);break;
			case '9':
			printf("\n\t\t该树的深度是：%d",TreeDepth(t));break;
			case '0':
			ch1='n';break;
			default:
			printf("\n\t\t***请注意：输入有误!***");
			}
			if(ch2!='0')
			{	printf("\n\n\t\t按回车键继续，按任意键返回主菜单!\n");
				a=getchar();
				if(a!='\xA')
				{getchar();ch1='n';}
			}
		}
}

BINTNODE *CreateBT()		     	       				// 建立二叉树
{   BINTNODE *t;
		char x;
		scanf("%c",&x);
		getchar();
		if(x=='0')
			t=NULL;
		else
		{	t=(BINTNODE *)malloc(sizeof(BINTNODE));
			t->data=x;
			printf("\n\t\t请输入%c结点的左子结点：",t->data);
			t->lchild=CreateBT();
			printf("\n\t\t请输入%c结点的右子结点：",t->data);
			t->rchild=CreateBT();
}
		return t;
}

void Preorder(BINTNODE *t)         	// 先序遍历
{	if(t)
{	printf("%3c",t->data);
			Preorder(t->lchild);
			Preorder(t->rchild);
}
}
void Inorder(BINTNODE *t)		// 中序遍历
{	if(t)
		{	Inorder(t->lchild);
			printf("%3c",t->data);
			Inorder(t->rchild);
		}
}

void Postorder(BINTNODE *t)		// 后序遍历
{	if(t)
{	Postorder(t->lchild);
			Postorder(t->rchild);
			printf("%3c",t->data);
}
}

void Levelorder(BINTNODE *t)		// 层次遍历
{
		int i,j;
		BINTNODE *q[100],*p;
		p=t;
		if(p!=NULL)
{
			i=1;q[i]=p;j=2;
		}
		while(i!=j)
{
			p=q[i];printf("%3c",p->data);
			if(p->lchild!=NULL)
			{
				q[j]=p->lchild;j++;}
				if(p->rchild!=NULL)
				{
					q[j]=p->rchild;j++;
				}
				i++;
		}
}

void Leafnum(BINTNODE *t)  		// 求叶结点数
{
		if(t)
{
			if(t->lchild==NULL&&t->rchild==NULL)
				count++;
			Leafnum(t->lchild);
			Leafnum(t->rchild);
}
}

void Nodenum(BINTNODE *t)       	// 求二叉树总结点数
{
		if(t)
{
			count++;
			Nodenum(t->lchild);
			Nodenum(t->rchild);
}
}

int TreeDepth(BINTNODE *t)		// 求树深度
{
		int ldep,rdep;
		if(t==NULL)
			return 0;
		else
		{	ldep=TreeDepth(t->lchild);
			rdep=TreeDepth(t->rchild);
			if(ldep>rdep)
				return ldep+1;
			else
				return rdep+1;
		}
}
void ShowTree(BINTNODE *t)   	             			// 凹入法显示二叉树
{
		BINTNODE *stack[MAXLEN],*p;
		int level[MAXLEN][2],top,n,i,width=4;
		if(t!=NULL)
		{
			printf("\n\t\t二叉树的凹入表示法：\n\t\t");
			top=1;
			stack[top]=t;                 			// 根结点入栈
			level[top][0]=width;
			while(top>0)
			{
				p=stack[top];              		// 退栈并显示结点的值
				n=level[top][0];
				for(i=1;i<=n;i++)         		// n为显示宽度，字符以右对齐显示
					printf(" ");
				printf("%c",p->data);
				for(i=n+1;i<50;i+=2)
					printf("▃");
				printf("\n\t\t");
				top--;
				if(p->rchild!=NULL)
				{                          			// 右子树根结点入栈
					top++;
					stack[top]=p->rchild;
					level[top][0]=n+width; 		// 显示宽度增加width
					level[top][1]=2;       		// 左子树根结点入栈
				}
				if(p->lchild!=NULL)
				{
					top++;
					stack[top]=p->lchild;
					level[top][0]=n+width;  	// 显示宽度增加width
					level[top][1]=1;
				}
			}
		}
}
