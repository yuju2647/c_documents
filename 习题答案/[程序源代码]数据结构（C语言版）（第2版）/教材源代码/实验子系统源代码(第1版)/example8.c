#define MAXLEN 100
#define N 10
#include<stdio.h>
#include<malloc.h>

void SeqSearch()			               // ˳�����
{	int a[N],i,x,y;
		char ch;
	     printf("\n\t\t����һ��������˳���(�Իس�Ϊ������ԣ�1����)��\n");
		for(i=0;i<MAXLEN;i++)
	     {	printf("\t\t");
	 		scanf("%d",&a[i]);
			getchar();
		    if(a[i]==-1)
			{	
y=i;break;	
			}
	     }
	    printf("\n\t\t��Ҫ����������Y����������N��\n\t\t");
	    scanf("%c",&ch);//getchar();
		while(ch=='y'||ch=='Y')
		{	printf("\n\t\t������Ҫ���ҵ�����\n\t\t");
			scanf("%d",&x);getchar();
			i=y-1;
		    while(i>=0&&a[i]!=x)		
				i--;
		    if(i==-1) 
				printf("\t\tû���ҵ�\n");
			else
				printf("\t\t���ҵ����ڵ�%d��λ����\n",i+1);
		    printf("\t\t������������Y����������N��\n\t\t");
			scanf("%c",&ch);
		}
}

void BinSearch()					      // ���ֲ���
{	int R[MAXLEN],i,k,low,mid,high,m,nn;
		char ch;
	     printf("\t\t������������Ĳ���˳���(�Իس�������ԣ�1����)��\n");
	     for(i=0;i<MAXLEN;i++)
	    {	printf("\t\t");
			scanf("%d",&R[i]);
			getchar();
		     if(R[i]==-1)
		     { 
nn=i;break;	
		     }
	}
	printf("\t\t����������Y���˳�����N�� \n\t\t");
	scanf("%c",&ch);getchar();
		while(ch=='y'||ch=='Y')
		{	printf("\n\t\t������Ҫ���ҵ�����:\n\t\t");
			scanf("%d",&k);getchar();
			low=0;high=nn-1;m=0;
		    while(low<=high)
			{	mid=(low+high)/2;
			     m++;
				if(R[mid]>k) high=mid-1;
				else if(R[mid]<k) low=mid+1;
				else break;
			}
			if(low>high)
			{	printf("\t\tû���ҵ�\n");
			     printf("\t\t������%d�αȽϡ�\n",m);
				if(R[mid]<k) 
					mid++;
				printf("\t\t�ɽ��������뵽%d��λ���ϡ� \n",mid+1);
			}
			else
			{
			  printf("\t\tҪ�ҵ�����%d�ڵ�%d��λ���ϡ�\n",k,mid+1);
			  printf("\t\t������%d�αȽϡ�\n",m);
			}
			printf("\t\t������������Y����������N��\n\t\t");
		     scanf("%c",&ch);getchar();
		}
}

typedef int KeyType;
typedef struct node			               // �������������ṹ
{	
KeyType key;
	     struct node *lchild,*rchild;
}BSTNode;
typedef BSTNode *BSTree;

BSTree CreateBST(void);
void SearchBST(BSTree T,KeyType Key);
void InsBST(BSTree *Tptr,KeyType Key);
void DelBSTNode(BSTree *Tptr,KeyType Key);
void InorderBST(BSTree T);

void BTSearch()
{	BSTree T;
		char ch1,ch2;
	     KeyType Key;
		printf("\n\t\t����һ�ö������Ķ�������洢\n");
	     T=CreateBST();ch1='y';
		getchar();
	     while(ch1=='y'||ch1=='Y')
		{
			printf("\n\n\n\n\t\t\t\t--����������--");
	 	        printf("\n\t\t*******************************************");
			printf("\n\t\t*           1------���¶���������                *");
			printf("\n\t\t*           2------��  ��  ��  ��                *");
		        printf("\n\t\t*           3------��  ��  ��  ��                *");
			printf("\n\t\t*           4------ɾ  ��  ��  ��                *");
			printf("\n\t\t*           5------�������������                *");
		        printf("\n\t\t*           0------��          ��                *");
			printf("\n\t\t*******************************************");
			printf("\n\t\t��ѡ��˵���(0--5): ");
		        scanf("%c",&ch2);
			getchar();
			switch(ch2)
			{
			case '1':T=CreateBST();break;
			case '2':printf("\n\t\t������Ҫ���ҵ����ݣ�");
			     scanf("%d",&Key);getchar();
				SearchBST(T,Key);
				printf("\t\t���Ҳ�����ϡ�\n");break;
		    case '3':printf("\n\t\t������Ҫ��������ݣ�");
				scanf("%d",&Key);getchar();
				InsBST(&T,Key);
				printf("\t\t���������ϡ�\n");break;
		    case '4':printf("\n\t\t������Ҫɾ�������ݣ�");
				scanf("%d",&Key);getchar();
				DelBSTNode(&T,Key);
				printf("\t\tɾ��������ϡ�\n");break;
		    case '5':printf("\t\t");InorderBST(T);
				printf("\n\t\t���������������ϡ� \n");break;
			case '0':ch1='n';return;
		    default:printf("\t\t����������������룡\n\t\t");
			}
	}
}

BSTree CreateBST(void)
{	BSTree T;
		KeyType Key;
	     T=NULL;
		printf("\n\t\t������һ�������ؼ���(����0ʱ��������)��");
	     scanf("%d",&Key);
		while(Key)
		{	InsBST(&T,Key);
			printf("\n\t\t��������һ�������ؼ���(����0ʱ��������)��");
			scanf("%d",&Key);
		}
		return T;
}

void SearchBST(BSTree T,KeyType Key)
{	BSTNode *p=T;
		while(p)
		{	
			if(p->key==Key)
			{
			printf("\t\t�Ѿ��ҵ�\n");return;
			}
			p=(Key<p->key)?p->lchild:p->rchild;
		}
		printf("\t\tû���ҵ�\n");
}
void InsBST(BSTree *T,KeyType Key)
{	BSTNode *f,*p;
		p=(*T);
	    while(p)
		{	
			if(p->key==Key)
			{
				printf("\t\t��������%d���������\n",Key);
				return;
			}
		    f=p;
			p=(Key<p->key)?p->lchild:p->rchild;
	     }
		p=(BSTNode*)malloc(sizeof(BSTNode));
		p->key=Key;
	     p->lchild=p->rchild=NULL;
	     if((*T)==NULL) (*T)=p;
		 else if(Key<f->key) f->lchild=p;
	     else f->rchild=p;
}

void DelBSTNode(BSTree *T,KeyType Key)
{	BSTNode *parent=NULL,*p,*q,*child;
		p=*T;
	    while(p)
	    {	if(p->key==Key) break;
			parent=p;
			p=(Key<p->key)?p->lchild:p->rchild;
	    }
	   if(!p) 
	   {
	     printf("\t\tû���ҵ�Ҫɾ���Ľ��\n");return;
	   }
	   q=p;
	   if(q->lchild&&q->rchild)
		for(parent=q,p=q->rchild;p->lchild;parent=p,p=p->lchild);
		child=(p->lchild)?p->lchild:p->rchild;
	     if(!parent) *T=child;
	     else
	     {	if(p==parent->lchild)
			  parent->lchild=child;
		     else parent->rchild=child;
			  if(p!=q)
			  q->key=p->key;
	     }
		free(p);
}

void InorderBST(BSTree T)
{
		if (T!=NULL)
		{	InorderBST(T->lchild);
			printf("\t%d",T->key);
			InorderBST(T->rchild);
		}
}

void main()
{
	     int choice;
		char ch;
		ch='y';
	     while(ch=='y'||ch=='Y')
		 {	 printf("\n\n\n\n");
		      printf("\t\t\t�� �� �� ϵ ͳ");
		 	 printf("\n\t\t************************************");
			 printf("\n\t\t*           1------˳ �� �� ��           *");
		         printf("\n\t\t*           2------�� �� �� ��           *");
			 printf("\n\t\t*           3------����������            *");
			 printf("\n\t\t*           0------��       ��           *");
		         printf("\n\t\t************************************");
			 printf("\n\t\t��ѡ��˵���(0--3):");
			 scanf("%d",&choice);
		     switch(choice)
			{
			 case 1:SeqSearch();break;
		      case 2:BinSearch();break;
			 case 3:BTSearch();break;
			 case 0:ch='n';break;
		      default:printf("\n\t\t�˵�ѡ�����������");
			}
		}
}
