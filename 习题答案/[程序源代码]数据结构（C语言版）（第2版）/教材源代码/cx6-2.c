#include <stdio.h>
#include<malloc.h>
typedef struct node         //������������͵Ķ���
{	
char data;
	 struct node *lchild;	//�����������ָ��
	 struct node	*rchild;	//��������Һ���ָ��
} BinTNode;				

BinTNode *CreateBinTree()  //���������������������У�������������
{   
	 BinTNode *t;
	 char ch;
	 ch=getchar();
	 if (ch=='0')             //�������0����������            
		t=NULL;
	 else
	 {	
		t=(BinTNode *)malloc(sizeof(BinTNode));	//��������*t�ռ�
		t->data=ch;                                  //���������ch���������������
		t->lchild=CreateBinTree();			    //��������
		t->rchild=CreateBinTree();			    //��������
	 } 
    return t;
}

void ListBinTree(BinTNode *t)                  //�ù�����ʾ������
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

void preorder(BinTNode *t)   //�Զ����������������
{
  if(t!=NULL)
	 {
   printf("%3c",t->data);
	   preorder(t->lchild);
   preorder(t->rchild); 
 }
} 

void inorder(BinTNode *t) //�Զ����������������
{
  if(t!=NULL)
	  {
    inorder(t->lchild);
	    printf("%3c",t->data);
    inorder(t->rchild); 
  }
} 

void postorder(BinTNode *t) //�Զ��������к������
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
	 printf("��������������,������0��ʾ(��ͼ6.14������Ϊ��)��\n");
	 t=CreateBinTree();
	 printf("������ʾ�Ķ������������\n");
	 ListBinTree(t);                          //���ö������Ĺ�����ʾ����
	 printf("\n��������ǰ��������Ϊ:\n");
	 preorder(t);                             //���ö����������������
	 printf("\n������������������Ϊ:\n");
	 inorder(t);                              //���ö����������������
	 printf("\n�������ĺ���������Ϊ:\n");
	 postorder(t);                            //���ö����������������
 printf("\n"); 	
}

�������н����
��������������,������0��ʾ(��ͼ6.14������Ϊ��)��
ABD00E00CFG0000���س���
������ʾ�Ķ������������ 
A ( B ( D��E)��C ( F (G) ) )
��������ǰ��������Ϊ:
A B D E C F G
������������������Ϊ:
D B E A G F C
�������ĺ���������Ϊ:
D E B G F C A
