/* ======================================== */
/*    ����ʵ��: 3-9.c                              */
/*    �ڴ�ͷ�ڵ�ĵ�����head�а�ֵ����Ԫ��      */
/* ======================================== */
#include<stdio.h>
#include<malloc.h>
typedef struct node                   		 /*����ڵ�Ĵ洢�ṹ*/
{
	int data;
	struct node *next;
}NODE;

NODE *create()  /*����β�巨����������������һ��ָ�������ͷ��ָ��*/
{
	NODE *head,*q,*p;               		/*����ָ�����*/
	char ch;
	int a;
	head=(NODE*)malloc(sizeof(NODE)); 		/*�����µĴ洢�ռ䣬����ͷ�ڵ�*/
	q=head;
	ch='*';
	printf("\n��β�巨�����������������������ݣ���?����!\n");
		while(ch!='?')          /*"ch"Ϊ�Ƿ����½ڵ�ı�־����"ch"Ϊ"?"���������*/
		{
			scanf("%d",&a);    				/*������Ԫ��*/
			p=(NODE*)malloc(sizeof(NODE));
			p->data=a;
			q->next=p;
			q=p;
			ch=getchar();             		/*�����������ı�־*/
		}
		q->next=NULL;
		return(head);                 		     /*���ر�ͷָ��head*/
}

NODE *locate(NODE *head,int x)   		         /*����֪�����в��Ҹ�����ֵx*/
{
	NODE *p;
	p=head->next;
	while((p!=NULL)&&(p->data!=x))		    /*δ����β��δ�ҵ���������*/
		p=p->next;                 	         /*ָ����һ��Ԫ��*/
	return(p);
}

main()                           		        /*������*/
{
	int y;
	NODE *a,*b;
	a=create();
	printf("����Ҫ���ҵ�Ԫ�أ�");
	scanf("%d",&y);
	b=locate(a,y);
	if(b!=NULL)
	{   
		printf("�ҵ���Ԫ��Ϊ��");
		printf("%5d",b->data);      		/*���ҳɹ�*/
	}
	else
		printf("���ҵ�Ԫ�ز����ڣ�");     	/*����ʧ��*/
}
//�������н����
//��β�巨�����������������������ݣ���?����!
//1 2 3 4 5?���س���
//����Ҫ���ҵ�Ԫ�أ� 5���س���
//�ҵ���Ԫ��Ϊ��5
