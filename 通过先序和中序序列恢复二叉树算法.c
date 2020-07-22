#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//�ṹ���������Ͷ���//
typedef char chelemtype;
typedef struct node
{
	chelemtype data;
	struct node *next;
}qnode;
typedef struct que
{
	qnode *front;
	qnode *rear;
}linkqueue;
typedef struct tree
{
	chelemtype data;
	struct tree *lchild,*rchild;
}Bitree;
//ȫ�ֱ�������//
FILE *fp;
Bitree *T;
//��������//
int recovery(linkqueue *preorderqueue,linkqueue *inorderqueue,Bitree *rootnode);
int inqueue(linkqueue *q,chelemtype ch);
int ifexist(linkqueue *q,chelemtype ch);

int main()
{
	//input_treeorder();
	linkqueue preorderqueue,inorderqueue;
	init(&preorderqueue);
	init(&inorderqueue);
	initqueue(&preorderqueue,&inorderqueue);
//	printf("��������\n");
//	printqueue(&preorderqueue);
//	printf("\n��������\n");
//	printqueue(&inorderqueue);
	chelemtype temp;
	outqueue(preorderqueue,&temp);
	//printf("\n���ӽ��\n");
	//putchar(temp);
	T=(Bitree *)malloc(sizeof(Bitree));
	T->data=temp;
	recovery(&preorderqueue,&inorderqueue,T);
	printf("\n\n\n\n\n\n                                    �������ָ����,��������Ϊ��");
	print_behind(T);
	getch();
}
int input_treeorder()
{
	printf("�ֱ�����������������У�������һ�����а��س������У��������ж������꣬����'#'�ż������س�����\n\n");
	if((fp=fopen("�ָ�����������.txt","w+"))==NULL)
	{
		printf("�ļ���ʧ��\n\n");
		getch();
		exit(1);
	}
	chelemtype ch;
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	} 
	fclose(fp);
}
int initqueue(linkqueue *pre,linkqueue *in)
{
	if((fp=fopen("�ָ�����������.txt","r+"))==NULL)
	{
		printf("���ļ�ʧ��\n");
		getch();
		exit(1);
	}
	chelemtype ch;
	qnode *s;
	ch=fgetc(fp);
	while(ch!='\n')
	{
		//printf("ch=%c\n",ch);
		s=(qnode *)malloc(sizeof(qnode));
		s->data=ch;
		s->next=pre->rear->next;
		pre->rear->next=s;
		pre->rear=s;
		ch=fgetc(fp);
	}
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		//printf("ch2=%c\n",ch);
		s=(qnode *)malloc(sizeof(qnode));
		s->data=ch;
		s->next=in->rear->next;
		in->rear->next=s;
		in->rear=s;
		ch=fgetc(fp);
	}
	fclose(fp);
	return 0;
}
int printqueue(linkqueue *q)
{
	qnode *p;
	p=q->front->next;
	if(p==NULL)
	printf("����Ϊ��\n");
	while(p)
	{
		putchar(p->data);
		p=p->next;
	}
	return 0;
}
int recovery(linkqueue *preorderqueue,linkqueue *inorderqueue,Bitree *rootnode)
{
	/*printf("\n\n������\n");
	printf("����"); 
	printqueue(preorderqueue); 
	printf("\n\n����");
	printqueue(inorderqueue);
	printf("\n\n���ڵ㣺%c",rootnode->data); 
	printf("\n\n���� in_temp1,in_temp2��������\n\n");*/ 
	linkqueue in_temp1,in_temp2;
	//printf("\n��ʼ�� in_temp1,in_temp2 ����\n");
	init(&in_temp1);
	init(&in_temp2);
	/*printf("��ӡin_temp1 ����(��ʱӦΪ��)\n");
	printqueue(&in_temp1);*/ 
	chelemtype ch;
	qnode *p;////////////////////�м�ָ��  p
	p=inorderqueue->front->next;
	while(p->data!=rootnode->data)
	{
		//printf("\n\nѭ����ʼ\n\n");
		inqueue(&in_temp1,p->data);
	/*	printf("��Ӳ����� in_temp1������Ԫ�أ�");
		printqueue(&in_temp1); */ 
		p=p->next;
	//	printf("\n\n����ѭ������\n");
	}
	/*printf("\n\np �Ƶ� ���ڵ�Ԫ��\n");
	printf("in_temp1 �� ������\n ����Ԫ��Ϊ��");
	printqueue(&in_temp1); */ 
	p=p->next;
	while(p)
	{
		//printf("\n\nѭ����ʼ\n\n");
		inqueue(&in_temp2,p->data);
		/*printf("��Ӳ����� in_temp2�����е�Ԫ��Ϊ��");
		printqueue(&in_temp2); */ 
		p=p->next;
		//printf("\n\n����ѭ������\n");
	}
	/*printf("in_temp2�� ������\n ����Ԫ��Ϊ��");
	printqueue(&in_temp2);
	printf("\n\n\nin_temp1��in_temp2����������ӽ�����");
	printf("\n   in_temp1��");
	printqueue(&in_temp1);
	printf("\n   in_temp2��");
	printqueue(&in_temp2); 
	printf("\n\n���� pre_temp1,pre_temp2 ��������\n\n");*/ 
	linkqueue pre_temp1,pre_temp2;
	//printf("\n\n��ʼ�� ����������\n\n");
	init(&pre_temp1);
	init(&pre_temp2);
	//printf("\n�� ָ��p ָ�� ������еĶ�ͷ\n");
	p=preorderqueue->front->next;
	//printf("���� �ڶ����м�ָ�� q\n");
	qnode *q;
	//printf("��q ָ�� p ��ǰһ�����\n");
	q=preorderqueue->front;
	if(ifempty(&in_temp1)==0)
	{
		//printf("\n���� in_temp1 ��Ϊ��\n\n");
		while(p)
		{
			if(ifexist(&in_temp1,p->data)==1)
			{
				inqueue(&pre_temp1,p->data);
				q->next=p->next;
				free(p);
				p=q->next;
			}
			else
			{
				inqueue(&pre_temp2,p->data);
				q->next=p->next;
				free(p);
				p=q->next;
			}
		}
		
	}
	else
	{
		//printf("\n���� in_temp1 Ϊ��\n\n");
		//printf("������ֵ���� ���� pre_temp2 ��\n");
		while(p)
		{
			inqueue(&pre_temp2,p->data);
			p=p->next;
		}
		//printf("\n\n�� ������ֵ���� ���� pre_temp2 �� ���\n\n");
	}
	/*printf("\n\n�� pre_temp ��ֵ���������飺\n\n  pre_temp1��");
	printqueue(&pre_temp1);
	printf("\n  pre_temp2��");
	printqueue(&pre_temp2); 
	printf("\n\n��һ����ȡ pre_temp1 �� pre_temp2 �Ķ�ͷ��㵱������� rootnode �����Һ���\n\n");
	printf("\n�� ���� ���ӷ����ڴ�\n");*/ 
	chelemtype temp1,temp2;
	if(ifempty(&pre_temp1)==0)
	{
		//printf("\npre_temp1 ��Ϊ�գ�Ϊ���ӷ����ڴ沢ȡ�� ���� pre_temp1 �ж���ֵ��Ϊ ��������� ֵ\n\n");
		rootnode->lchild=(Bitree *)malloc(sizeof(Bitree));
	    if(rootnode->lchild==NULL)
	    {
		    printf("���� �ڴ����ʧ��\n");
		    getch();
		    exit(1);
	    }
	    outqueue(&pre_temp1,&temp1);
	    //printf("\n����ȡ��ֵ\n");
	    //printf("temp1= %c\n",temp1);
	    rootnode->lchild->data=temp1;
	    //printf("���亢����Ϊ ��ֵ\n");
	    rootnode->lchild->lchild=NULL;
	    rootnode->lchild->rchild=NULL;
	}
	else
	{
		//printf("\npre_temp1 Ϊ��,������ ��Ϊ NULL ֵ\n");
		rootnode->lchild=NULL;
	}
	if(ifempty(&pre_temp2)==0)
	{
		//printf("\npre_temp2 ��Ϊ�գ�Ϊ���ӷ����ڴ沢ȡ�� ���� pre_temp2 �ж���ֵ��Ϊ ��������� ֵ\n\n");
		rootnode->rchild=(Bitree *)malloc(sizeof(Bitree));
	    if(rootnode->rchild==NULL)
	    {
		    printf("���� �ڴ����ʧ��\n");
		    getch();
		    exit(1);
	    }
	    outqueue(&pre_temp2,&temp2);
	    //printf("\n����ȡ��ֵ\n");
	    //printf("temp2= %c\n",temp2);
	    rootnode->rchild->data=temp2;
	    //printf("���亢����Ϊ ��ֵ\n");
	    rootnode->rchild->lchild=NULL;
	    rootnode->rchild->rchild=NULL;
	}
	else
	{
		//printf("\npre_temp2 Ϊ��,���Һ��� ��Ϊ NULL ֵ\n");
		rootnode->rchild=NULL;
	}
//	printf("\n���鸳ֵ���\n��ӡ�����ĵ�ǰ�������У�");
//	print_tree(T);
//	printf("\n\n\n׼������ݹ�\n\n");
	//printf("\n�ж� pre_temp1 �Ƿ�Ϊ��\n");
	if(ifempty(&pre_temp1)==0)
	{
	//	printf("  ���� pre_temp1����Ϊ��\n ");
		//printf("                 ����ݹ�\n\n\n");
		recovery(&pre_temp1,&in_temp1,rootnode->lchild);
		//printf("\n\n\n                 �˳��ݹ�\n\n");
	}
	else
	{
		//printf("  ���� pre_temp1 Ϊ��\n\n  ������ݹ�\n");
	}
	if(ifempty(&pre_temp2)==0)
	{
		//printf("  ���� pre_temp2����Ϊ��\n ");
	//	printf("                 ����ݹ�\n\n\n");
		recovery(&pre_temp2,&in_temp2,rootnode->rchild);
	//	printf("\n\n\n                 �˳��ݹ�\n\n");
	}
	else
	{
	//	printf("  ���� pre_temp2 Ϊ��\n\n  ������ݹ�\n");
	}
	//printf("\n\n��������\n\n");
	return 0;
}
int outqueue(linkqueue *q,chelemtype *temp)
{
	qnode *p;
	p=q->front->next;
	if(p==NULL)
	{
	//	printf("����Ϊ��\n");
		return 0;
	}
	*temp=p->data;
	q->front->next=p->next;
	free(p);
	return 0;
}
int init(linkqueue *q)
{
	q->front=(qnode *)malloc(sizeof(qnode));
	q->front->next=NULL; 
	q->rear=q->front;
	return 0;
}
int inqueue(linkqueue *q,chelemtype ch)
{
	//printf("\n   ��Ӻ�����\n");
	qnode *s;
	s=(qnode *)malloc(sizeof(qnode));
	s->data=ch;
	s->next=q->rear->next;
	q->rear->next=s;
	q->rear=s;
//	printf("\n   ��Ӻ���ִ�н���\n\n");
	return 0;
}
int ifexist(linkqueue *q,chelemtype ch)
{
	qnode *p;
	p=q->front->next;
	if(p==NULL)
	{
	//	printf("����Ϊ��\n");
		getch();
		exit(1);
	}
	while(p)
	{
		if(p->data==ch)
		return 1;
		else
		p=p->next;
	}
	return 0;
} 
int get(linkqueue *q,chelemtype *ch)
{
	*ch=q->front->next->data;
	return 0;
}
int print_tree(Bitree *T)
{
	putchar(T->data);
	if(T->lchild!=NULL)
	{
		print_tree(T->lchild);
	}
	if(T->rchild!=NULL)
	{
		print_tree(T->rchild);
	}
}
int ifempty(linkqueue *q)
{
	if(q->front->next==NULL)
	{
		//printf("\n����Ϊ��\n");
		return 1;
	}
	return 0;
}
int print_behind(Bitree *t)
{
	if(t->lchild!=NULL)
	print_behind(t->lchild);
	if(t->rchild!=NULL)
	print_behind(t->rchild);
	putchar(t->data);
	return 0; 
}
