#include <stdio.h>
#include <malloc.h>
typedef struct  node
{
	int  key ;                 /*定义关键字，假定为整型*/
	struct node  *lchild,*rchild;  /*左右指针*/
}BSTNode;

void InsertBST(BSTNode **bst, int key)
/*若在二叉排序树中不存在关键字等于key的记录，插入该记录*/
{ 
	BSTNode * s;
	if (*bst == NULL)/*递归结束条件*/
	{
		s=(BSTNode *)malloc(sizeof(BSTNode)); /*申请新的结点s*/
		s-> key=key;
		s->lchild=NULL; 
		s->rchild=NULL;
		*bst=s;
	}
	else 
		if (key<(*bst)->key)
		  InsertBST(&((*bst)->lchild), key); /*将s插入左子树*/
	   else 
		if (key > (*bst)->key)
		 InsertBST(&((*bst)->rchild), key);  /*将s插入右子树*/
}

void  CreateBST(BSTNode **bst)  /*从键盘输入记录的值，创建相应的二叉排序树*/
{ 
	int key;
	*bst=NULL;
	scanf("%d", &key);
	while (key!=0)   /*输入0时结束*/
	{
		InsertBST(bst, key);
		scanf("%d", &key);
	}
}

void  inOrder(BSTNode *root)  /*中序遍历二叉树, root为指向二叉树根结点的指针*/
{
	if (root!=NULL)
	{
		inOrder(root->lchild);  /*中序遍历左子树*/
		printf("%d  ",root->key);  /*输出结点*/
		inOrder(root->rchild);  /*中序遍历右子树*/
	}
}

BSTNode *SearchBST(BSTNode *bst, int key)
/*在根指针bst所指二叉排序树中，递归查找某关键字等于key的记录，
若查找成功，返回指向该记录结点指针，否则返回空指针*/
{ 
	if (!bst) 
	  return NULL;
	else 
	  if(bst->key==key)
	    return bst;      /*查找成功*/
	  else
		if(bst->key>key)
		  return SearchBST(bst->lchild, key);/*在左子树继续查找*/
		    else 
			  return SearchBST(bst->rchild, key);/*在右子树继续查找*/
}

BSTNode *DelBST(BSTNode *t, int k)  /*在二叉排序树t中删去关键字为k的结点*/
{
	BSTNode  *p, *f,*s ,*q;
	p=t; 
	f=NULL;
	while(p)  /*查找关键字为k的待删结点p*/
	{ 
		if(p->key==k )  break;  /*找到则跳出循环*/
		f=p;                    /*f指向p结点的双亲结点*/
		if(p->key>k)  
			p=p->lchild;
		else 
			p=p->rchild;
	} 
	if(p==NULL)  return t;  /*若找不到，返回原来的二叉排序树*/
	if(p->lchild==NULL)   /*p无左子树*/
	{ 
		 if(f==NULL) 
			t=p->rchild;   /*p是原二叉排序树的根*/
		 else 
			if(f->lchild==p)   /*p是f的左孩子*/
			 f->lchild=p->rchild ;  /*将p的右子树链到f的左链上*/
			else   /*p是f的右孩子*/
				f->rchild=p->rchild ;   /*将p的右子树链到f的右链上*/
			free(p);   /*释放被删除的结点p*/
	}
	else  /*p有左子树*/
	{ 
		q=p; 
		s=p->lchild;
		while(s->rchild)  /*在p的左子树中查找最右下结点*/
		{
			q=s; 
			s=s->rchild;
		}
		if(q==p) 
			q->lchild=s->lchild ;  /*将s的左子树链到q上*/
		else 
			q->rchild=s->lchild;
		p->key=s->key;  /*将s的值赋给p*/
		free(s);
	}
	return t;
} 

void main()
{
	BSTNode *T;
	int k,rec;
	BSTNode *result;
	printf("建立二叉排序树，请输入序列(输入0结束):\n");
    CreateBST(&T);
	printf("二叉排序树中序遍历序列为:\n");
    inOrder(T);
	printf("\n请输入要查找的记录:");
	scanf("%d",&k);
	result=SearchBST(T,k);
	if (result!=NULL)
	{
	printf("要查找的记录存在，值为%d\n",result->key);
	result=DelBST(T,k);
	printf("查找到的记录被删除后的中序序列：\n");
	inOrder(result);
	}		
	else
	printf("该记录不存在!，只能进行插入操作");
	printf("\n输入要插入的记录:");
	scanf("%d",&rec);
    InsertBST(&T,rec);
	printf("插入记录后二叉排序树的中序序列：\n");
	inOrder(T);
}

程序运行结果：
建立二叉排序树，请输入序列(输入0结束): （回车）
17  6  43  12  123  26  34  40  8  90  45  0（回车）
二叉排序树中序遍历序列为：
6  8  12  17  26  34  40  43  45  90  123
输入要查找的记录：123（回车）
要查找的记录存在，值为123
查找到的记录被删除后的中序序列：
6  8  12  17  26  34  40  43  45  90
输入要插入的记录:98（回车）
插入记录后二叉排序树的中序序列：
6  8  12  17  26  34  40  43  45  90  98
