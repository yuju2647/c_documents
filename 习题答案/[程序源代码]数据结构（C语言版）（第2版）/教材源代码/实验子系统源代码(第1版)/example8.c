#define MAXLEN 100
#define N 10
#include<stdio.h>
#include<malloc.h>

void SeqSearch()			               // 顺序查找
{	int a[N],i,x,y;
		char ch;
	     printf("\n\t\t建立一个整数的顺序表(以回车为间隔，以－1结束)：\n");
		for(i=0;i<MAXLEN;i++)
	     {	printf("\t\t");
	 		scanf("%d",&a[i]);
			getchar();
		    if(a[i]==-1)
			{	
y=i;break;	
			}
	     }
	    printf("\n\t\t需要查找请输入Y，否则输入N：\n\t\t");
	    scanf("%c",&ch);//getchar();
		while(ch=='y'||ch=='Y')
		{	printf("\n\t\t请输入要查找的数据\n\t\t");
			scanf("%d",&x);getchar();
			i=y-1;
		    while(i>=0&&a[i]!=x)		
				i--;
		    if(i==-1) 
				printf("\t\t没有找到\n");
			else
				printf("\t\t已找到，在第%d的位置上\n",i+1);
		    printf("\t\t继续查找输入Y，否则输入N：\n\t\t");
			scanf("%c",&ch);
		}
}

void BinSearch()					      // 二分查找
{	int R[MAXLEN],i,k,low,mid,high,m,nn;
		char ch;
	     printf("\t\t建立递增有序的查找顺序表(以回车间隔，以－1结束)：\n");
	     for(i=0;i<MAXLEN;i++)
	    {	printf("\t\t");
			scanf("%d",&R[i]);
			getchar();
		     if(R[i]==-1)
		     { 
nn=i;break;	
		     }
	}
	printf("\t\t查找请输入Y，退出输入N： \n\t\t");
	scanf("%c",&ch);getchar();
		while(ch=='y'||ch=='Y')
		{	printf("\n\t\t请输入要查找的数据:\n\t\t");
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
			{	printf("\t\t没有找到\n");
			     printf("\t\t共进行%d次比较。\n",m);
				if(R[mid]<k) 
					mid++;
				printf("\t\t可将此数插入到%d的位置上。 \n",mid+1);
			}
			else
			{
			  printf("\t\t要找的数据%d在第%d的位置上。\n",k,mid+1);
			  printf("\t\t共进行%d次比较。\n",m);
			}
			printf("\t\t继续查找输入Y，否则输入N：\n\t\t");
		     scanf("%c",&ch);getchar();
		}
}

typedef int KeyType;
typedef struct node			               // 二叉排序树结点结构
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
		printf("\n\t\t建立一棵二叉树的二叉链表存储\n");
	     T=CreateBST();ch1='y';
		getchar();
	     while(ch1=='y'||ch1=='Y')
		{
			printf("\n\n\n\n\t\t\t\t--二叉排序树--");
	 	        printf("\n\t\t*******************************************");
			printf("\n\t\t*           1------更新二叉排序树                *");
			printf("\n\t\t*           2------查  找  结  点                *");
		        printf("\n\t\t*           3------插  入  结  点                *");
			printf("\n\t\t*           4------删  除  结  点                *");
			printf("\n\t\t*           5------中序输出排序树                *");
		        printf("\n\t\t*           0------返          回                *");
			printf("\n\t\t*******************************************");
			printf("\n\t\t请选择菜单号(0--5): ");
		        scanf("%c",&ch2);
			getchar();
			switch(ch2)
			{
			case '1':T=CreateBST();break;
			case '2':printf("\n\t\t请输入要查找的数据：");
			     scanf("%d",&Key);getchar();
				SearchBST(T,Key);
				printf("\t\t查找操作完毕。\n");break;
		    case '3':printf("\n\t\t请输入要插入的数据：");
				scanf("%d",&Key);getchar();
				InsBST(&T,Key);
				printf("\t\t插入操作完毕。\n");break;
		    case '4':printf("\n\t\t请输入要删除的数据：");
				scanf("%d",&Key);getchar();
				DelBSTNode(&T,Key);
				printf("\t\t删除操作完毕。\n");break;
		    case '5':printf("\t\t");InorderBST(T);
				printf("\n\t\t二叉排序树输出完毕。 \n");break;
			case '0':ch1='n';return;
		    default:printf("\t\t输入错误！请重新输入！\n\t\t");
			}
	}
}

BSTree CreateBST(void)
{	BSTree T;
		KeyType Key;
	     T=NULL;
		printf("\n\t\t请输入一个整数关键字(输入0时结束输入)：");
	     scanf("%d",&Key);
		while(Key)
		{	InsBST(&T,Key);
			printf("\n\t\t请输入下一个整数关键字(输入0时结束输入)：");
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
			printf("\t\t已经找到\n");return;
			}
			p=(Key<p->key)?p->lchild:p->rchild;
		}
		printf("\t\t没有找到\n");
}
void InsBST(BSTree *T,KeyType Key)
{	BSTNode *f,*p;
		p=(*T);
	    while(p)
		{	
			if(p->key==Key)
			{
				printf("\t\t树中已有%d，不需插入\n",Key);
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
	     printf("\t\t没有找到要删除的结点\n");return;
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
		      printf("\t\t\t查 找 子 系 统");
		 	 printf("\n\t\t************************************");
			 printf("\n\t\t*           1------顺 序 查 找           *");
		         printf("\n\t\t*           2------二 分 查 找           *");
			 printf("\n\t\t*           3------二叉排序树            *");
			 printf("\n\t\t*           0------返       回           *");
		         printf("\n\t\t************************************");
			 printf("\n\t\t请选择菜单号(0--3):");
			 scanf("%d",&choice);
		     switch(choice)
			{
			 case 1:SeqSearch();break;
		      case 2:BinSearch();break;
			 case 3:BTSearch();break;
			 case 0:ch='n';break;
		      default:printf("\n\t\t菜单选择错误！请重输");
			}
		}
}
