#include<stdio.h>
#include<sys/malloc.h>
#include<stdlib.h>
typedef struct BINTNODE
{
	char data;
	struct BINTNODE *lchild;
	struct BINTNODE *rchild;
}BINTNODE;
//��������//
char search_max(BINTNODE *t,char max);
int locate_level(BINTNODE *t,char ch,int level);

//����ȫ�ֱ���//
FILE *fp;
int TWO=0;//ͳ�� ��Ϊ 2 �Ľ����Ŀ 
char node[20],i=0;//���� ����һά���� 
int W=0;//����ͳ�� Ҷ�ӽڵ� ���� ���Ŀ�� 
int main()
{
	openfile();
	BINTNODE *T;
	T=(BINTNODE *)malloc(sizeof(BINTNODE));
	recovery(T);
	closefile();
	print_tree(T);
	calculate_two_branch(T);
	printf("\n��Ϊ 2 �Ľ����ĿΪ %d ��\n",TWO);
	printf("\n���Ԫ��Ϊ %c\n\n",search_max(T,0));
	savedata(T);
	node[i]='\0';
	printf("������һά�����к�");
	puts(node);
	level(T,1);
	width(T);
	printf("�������Ŀ�Ȼ�Ҷ�ӽ����ĿΪ��%d\n\n",W);
	interchange(T);
	printf("�����������������󣬶��������������Ϊ��");
	print_tree(T);
	int L;
	char ch='E';
	L=locate_level(T,ch,1);
	if(L)
	{
		printf("�ַ� %c ���ڵĲ���Ϊ��%d");
	} 
	return 0;
}
int openfile()
{
	if((fp=fopen("������������������.txt","r+"))==NULL)
	{
		printf("\n�ļ���ʧ��\n\n");
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
int level(BINTNODE *t,int m)//m���ڼ�¼��ǰ�������ڲ�� 
{
	printf("��㣺");
	putchar(t->data);
	printf("  ��ţ�%d\n\n",m);
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
