#include <stdio.h>
#include<malloc.h>
#define MAXLEN 100
typedef struct BINTNODE			           		// ����������ṹ��
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
int count=0;					         		// ���������������ı���
void main()                             			// ����ϵͳס����
{	BINTNODE *t=NULL;
		char ch1,ch2,a;
		ch1='y';
		while(ch1=='y'||ch1=='Y')
		{	printf("\n\n\n\n");
			printf("\n\n\t\t\t�� �� �� �� ϵ ͳ\n");
			printf("\n\t\t***************************************");
			printf("\n\t\t*           1---------�� �� �� ��           *");
			printf("\n\t\t*           2---------�� �� �� ʾ           *");
			printf("\n\t\t*           3---------�� �� �� ��           *");
			printf("\n\t\t*           4---------�� �� �� ��           *");
			printf("\n\t\t*           5---------�� �� �� ��           *");
			printf("\n\t\t*           6---------�� �� �� ��           *");
			printf("\n\t\t*           7---------�� Ҷ �� ��           *");
			printf("\n\t\t*           8---------�� �� �� ��           *");
			printf("\n\t\t*           9---------�� �� �� ��           *");
			printf("\n\t\t*           0---------��       ��           *");
			printf("\n\t\t***************************************");
			printf("\n\t\t��ѡ��˵���(0--9):");
			scanf("%c",&ch2);
			getchar();
			printf("\n");
			switch(ch2)
			{
			case '1':
			printf("\n\t\t�����밴�������������Ľ�����У�");
			printf("\n\t\t˵����'0'�����̽��Ϊ��,���������,���س�������һ��㡣");
			printf("\n\t\t���������㣺");
			t=CreateBT();
			printf("\n\t\t�������ɹ�����!\n");break;
			case '2':
			ShowTree(t);break;
			case '3':
			printf("\n\t\t�ö������������������Ϊ��");
			Preorder(t);break;
			case '4':
			printf("\n\t\t�ö������������������Ϊ��");
			Inorder(t);break;
			case '5':
			printf("\n\t\t�ö������ĺ����������Ϊ��");
			Postorder(t);break;
			case '6':
			printf("\n\t\t�ö������Ĳ�α�������Ϊ��");
			Levelorder(t);break;
			case '7':
			count=0;Leafnum(t);
			printf("\n\t\t�ö�������%d��Ҷ�ӡ�\n",count);break;
			case '8':
			count=0;Nodenum(t);
			printf("\n\t\t�ö������ܹ���%d����㡣\n",count);break;
			case '9':
			printf("\n\t\t����������ǣ�%d",TreeDepth(t));break;
			case '0':
			ch1='n';break;
			default:
			printf("\n\t\t***��ע�⣺��������!***");
			}
			if(ch2!='0')
			{	printf("\n\n\t\t���س�����������������������˵�!\n");
				a=getchar();
				if(a!='\xA')
				{getchar();ch1='n';}
			}
		}
}

BINTNODE *CreateBT()		     	       				// ����������
{   BINTNODE *t;
		char x;
		scanf("%c",&x);
		getchar();
		if(x=='0')
			t=NULL;
		else
		{	t=(BINTNODE *)malloc(sizeof(BINTNODE));
			t->data=x;
			printf("\n\t\t������%c�������ӽ�㣺",t->data);
			t->lchild=CreateBT();
			printf("\n\t\t������%c�������ӽ�㣺",t->data);
			t->rchild=CreateBT();
}
		return t;
}

void Preorder(BINTNODE *t)         	// �������
{	if(t)
{	printf("%3c",t->data);
			Preorder(t->lchild);
			Preorder(t->rchild);
}
}
void Inorder(BINTNODE *t)		// �������
{	if(t)
		{	Inorder(t->lchild);
			printf("%3c",t->data);
			Inorder(t->rchild);
		}
}

void Postorder(BINTNODE *t)		// �������
{	if(t)
{	Postorder(t->lchild);
			Postorder(t->rchild);
			printf("%3c",t->data);
}
}

void Levelorder(BINTNODE *t)		// ��α���
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

void Leafnum(BINTNODE *t)  		// ��Ҷ�����
{
		if(t)
{
			if(t->lchild==NULL&&t->rchild==NULL)
				count++;
			Leafnum(t->lchild);
			Leafnum(t->rchild);
}
}

void Nodenum(BINTNODE *t)       	// ��������ܽ����
{
		if(t)
{
			count++;
			Nodenum(t->lchild);
			Nodenum(t->rchild);
}
}

int TreeDepth(BINTNODE *t)		// �������
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
void ShowTree(BINTNODE *t)   	             			// ���뷨��ʾ������
{
		BINTNODE *stack[MAXLEN],*p;
		int level[MAXLEN][2],top,n,i,width=4;
		if(t!=NULL)
		{
			printf("\n\t\t�������İ����ʾ����\n\t\t");
			top=1;
			stack[top]=t;                 			// �������ջ
			level[top][0]=width;
			while(top>0)
			{
				p=stack[top];              		// ��ջ����ʾ����ֵ
				n=level[top][0];
				for(i=1;i<=n;i++)         		// nΪ��ʾ��ȣ��ַ����Ҷ�����ʾ
					printf(" ");
				printf("%c",p->data);
				for(i=n+1;i<50;i+=2)
					printf("�z");
				printf("\n\t\t");
				top--;
				if(p->rchild!=NULL)
				{                          			// �������������ջ
					top++;
					stack[top]=p->rchild;
					level[top][0]=n+width; 		// ��ʾ�������width
					level[top][1]=2;       		// �������������ջ
				}
				if(p->lchild!=NULL)
				{
					top++;
					stack[top]=p->lchild;
					level[top][0]=n+width;  	// ��ʾ�������width
					level[top][1]=1;
				}
			}
		}
}
