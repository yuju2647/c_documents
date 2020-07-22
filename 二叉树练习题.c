#include<stdio.h>
#include<sys/malloc.h>
#include<stdlib.h>
typedef struct BINTNODE
{
	char data;
	struct BINTNODE *lchild;
	struct BINTNODE *rchild;
}BINTNODE;
//声明函数//
char search_max(BINTNODE *t,char max);
int locate_level(BINTNODE *t,char ch,int level);

//定义全局变量//
FILE *fp;
int TWO=0;//统计 度为 2 的结点数目 
char node[20],i=0;//储存 结点的一维数组 
int W=0;//用于统计 叶子节点 或者 树的宽度 
int main()
{
	openfile();
	BINTNODE *T;
	T=(BINTNODE *)malloc(sizeof(BINTNODE));
	recovery(T);
	closefile();
	print_tree(T);
	calculate_two_branch(T);
	printf("\n度为 2 的结点数目为 %d 个\n",TWO);
	printf("\n最大元素为 %c\n\n",search_max(T,0));
	savedata(T);
	node[i]='\0';
	printf("储存至一维数组中后：");
	puts(node);
	level(T,1);
	width(T);
	printf("二叉树的宽度或叶子结点数目为：%d\n\n",W);
	interchange(T);
	printf("交换左右左右子树后，二叉树的先序遍历为：");
	print_tree(T);
	int L;
	char ch='E';
	L=locate_level(T,ch,1);
	if(L)
	{
		printf("字符 %c 所在的层数为：%d");
	} 
	return 0;
}
int openfile()
{
	if((fp=fopen("二叉树先序序列数据.txt","r+"))==NULL)
	{
		printf("\n文件打开失败\n\n");
		getch();
		exit(1);
	}
	return 0;
}
int closefile()
{
	fclose(fp);
	return 0;
}
int recovery(BINTNODE *t)
{
	char ch;
	BINTNODE *child;
	ch=fgetc(fp);
	t->data=ch;
	if((ch=fgetc(fp))!='#')
	{
		t->lchild=(BINTNODE *)malloc(sizeof(BINTNODE));
		fseek(fp,-1,1);
		recovery(t->lchild); 
	}
	else
	{
		t->lchild=NULL;
	}
	if((ch=fgetc(fp))!='#')
	{
		t->rchild=(BINTNODE *)malloc(sizeof(BINTNODE));
		fseek(fp,-1,1);
		recovery(t->rchild);
	}
	else
	{
		t->rchild=NULL;
	}
	return 0;
}
int print_tree(BINTNODE *t)
{
	putchar(t->data);
	if(t->lchild!=NULL)
	print_tree(t->lchild);
	if(t->rchild!=NULL)
	print_tree(t->rchild);
	return 0;
}
int calculate_two_branch(BINTNODE *t)
{
	if(t->lchild!=NULL)
	{
		if(t->rchild!=NULL)
		TWO++;
		calculate_two_branch(t->lchild);
	}
	if(t->rchild!=NULL)
	{
		calculate_two_branch(t->rchild);
	}
	return 0;
} 
char search_max(BINTNODE *t,char max)
{
	if(max<t->data)
	max=t->data;
	if(t->lchild!=NULL)
	max=search_max(t->lchild,max);
	if(t->rchild!=NULL)
	max=search_max(t->rchild,max);
	return max;
}
int savedata(BINTNODE *t)
{
	node[i++]=t->data;
	if(t->lchild!=NULL)
	savedata(t->lchild);
	if(t->rchild!=NULL)
	savedata(t->rchild);
	return 0;
}
int level(BINTNODE *t,int m)//m用于记录当前结点的所在层号 
{
	printf("结点：");
	putchar(t->data);
	printf("  层号：%d\n\n",m);
	if(t->lchild!=NULL)
	level(t->lchild,m+1);
	if(t->rchild!=NULL)
	level(t->rchild,m+1);
	return 0;
}
int width(BINTNODE *t)
{
	if(t->lchild!=NULL)
	{
		width(t->lchild);
	}
	else if(t->rchild==NULL)
	{
		W++;
	}
	if(t->rchild!=NULL)
	width(t->rchild);
	return 0;
}
int interchange(BINTNODE *t)
{
	BINTNODE *temp;
	temp=t->lchild;
	t->lchild=t->rchild;
	t->rchild=temp;
	if(t->lchild!=NULL)
	interchange(t->lchild);
	if(t->rchild!=NULL)
	interchange(t->rchild);
	return 0;
}
int locate_level(BINTNODE *t,char ch,int level)
{
	if(t->data==ch)
	return level;
	int r;
	if(t->lchild!=NULL)
	{
		if(r=locate_level(t->lchild,ch,level+1))
		return r;
	}
	if(t->rchild!=NULL)
	{
		if(r=locate_level(t->rchild,ch,level+1))
		return r;
	}
	return 0;
}
