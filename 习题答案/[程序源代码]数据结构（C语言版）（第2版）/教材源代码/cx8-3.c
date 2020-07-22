#include <stdio.h>
#include <malloc.h>
typedef struct  node
{
	int  key ;                 /*����ؼ��֣��ٶ�Ϊ����*/
	struct node  *lchild,*rchild;  /*����ָ��*/
}BSTNode;

void InsertBST(BSTNode **bst, int key)
/*���ڶ����������в����ڹؼ��ֵ���key�ļ�¼������ü�¼*/
{ 
	BSTNode * s;
	if (*bst == NULL)/*�ݹ��������*/
	{
		s=(BSTNode *)malloc(sizeof(BSTNode)); /*�����µĽ��s*/
		s-> key=key;
		s->lchild=NULL; 
		s->rchild=NULL;
		*bst=s;
	}
	else 
		if (key<(*bst)->key)
		  InsertBST(&((*bst)->lchild), key); /*��s����������*/
	   else 
		if (key > (*bst)->key)
		 InsertBST(&((*bst)->rchild), key);  /*��s����������*/
}

void  CreateBST(BSTNode **bst)  /*�Ӽ��������¼��ֵ��������Ӧ�Ķ���������*/
{ 
	int key;
	*bst=NULL;
	scanf("%d", &key);
	while (key!=0)   /*����0ʱ����*/
	{
		InsertBST(bst, key);
		scanf("%d", &key);
	}
}

void  inOrder(BSTNode *root)  /*�������������, rootΪָ�������������ָ��*/
{
	if (root!=NULL)
	{
		inOrder(root->lchild);  /*�������������*/
		printf("%d  ",root->key);  /*������*/
		inOrder(root->rchild);  /*�������������*/
	}
}

BSTNode *SearchBST(BSTNode *bst, int key)
/*�ڸ�ָ��bst��ָ�����������У��ݹ����ĳ�ؼ��ֵ���key�ļ�¼��
�����ҳɹ�������ָ��ü�¼���ָ�룬���򷵻ؿ�ָ��*/
{ 
	if (!bst) 
	  return NULL;
	else 
	  if(bst->key==key)
	    return bst;      /*���ҳɹ�*/
	  else
		if(bst->key>key)
		  return SearchBST(bst->lchild, key);/*����������������*/
		    else 
			  return SearchBST(bst->rchild, key);/*����������������*/
}

BSTNode *DelBST(BSTNode *t, int k)  /*�ڶ���������t��ɾȥ�ؼ���Ϊk�Ľ��*/
{
	BSTNode  *p, *f,*s ,*q;
	p=t; 
	f=NULL;
	while(p)  /*���ҹؼ���Ϊk�Ĵ�ɾ���p*/
	{ 
		if(p->key==k )  break;  /*�ҵ�������ѭ��*/
		f=p;                    /*fָ��p����˫�׽��*/
		if(p->key>k)  
			p=p->lchild;
		else 
			p=p->rchild;
	} 
	if(p==NULL)  return t;  /*���Ҳ���������ԭ���Ķ���������*/
	if(p->lchild==NULL)   /*p��������*/
	{ 
		 if(f==NULL) 
			t=p->rchild;   /*p��ԭ�����������ĸ�*/
		 else 
			if(f->lchild==p)   /*p��f������*/
			 f->lchild=p->rchild ;  /*��p������������f��������*/
			else   /*p��f���Һ���*/
				f->rchild=p->rchild ;   /*��p������������f��������*/
			free(p);   /*�ͷű�ɾ���Ľ��p*/
	}
	else  /*p��������*/
	{ 
		q=p; 
		s=p->lchild;
		while(s->rchild)  /*��p���������в��������½��*/
		{
			q=s; 
			s=s->rchild;
		}
		if(q==p) 
			q->lchild=s->lchild ;  /*��s������������q��*/
		else 
			q->rchild=s->lchild;
		p->key=s->key;  /*��s��ֵ����p*/
		free(s);
	}
	return t;
} 

void main()
{
	BSTNode *T;
	int k,rec;
	BSTNode *result;
	printf("��������������������������(����0����):\n");
    CreateBST(&T);
	printf("���������������������Ϊ:\n");
    inOrder(T);
	printf("\n������Ҫ���ҵļ�¼:");
	scanf("%d",&k);
	result=SearchBST(T,k);
	if (result!=NULL)
	{
	printf("Ҫ���ҵļ�¼���ڣ�ֵΪ%d\n",result->key);
	result=DelBST(T,k);
	printf("���ҵ��ļ�¼��ɾ������������У�\n");
	inOrder(result);
	}		
	else
	printf("�ü�¼������!��ֻ�ܽ��в������");
	printf("\n����Ҫ����ļ�¼:");
	scanf("%d",&rec);
    InsertBST(&T,rec);
	printf("�����¼��������������������У�\n");
	inOrder(T);
}

�������н����
��������������������������(����0����): ���س���
17  6  43  12  123  26  34  40  8  90  45  0���س���
���������������������Ϊ��
6  8  12  17  26  34  40  43  45  90  123
����Ҫ���ҵļ�¼��123���س���
Ҫ���ҵļ�¼���ڣ�ֵΪ123
���ҵ��ļ�¼��ɾ������������У�
6  8  12  17  26  34  40  43  45  90
����Ҫ����ļ�¼:98���س���
�����¼��������������������У�
6  8  12  17  26  34  40  43  45  90  98
