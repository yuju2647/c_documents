/* ======================================== */
/*    ����ʵ��: 3-7.c                       */
/*    �������β������ڵ㽨��������         */
/* ======================================== */
#include<malloc.h>
#include<stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *create()		/*�˺�������β���뷽ʽ����������������һ��ָ�������ͷ��ָ��*/
{
	NODE *head,*q,*p;                	/*����ָ�����*/
	char ch;
	int a;
	head=(NODE*)malloc(sizeof(NODE)); 	/*�����µĴ洢�ռ䣬����ͷ�ڵ�*/
	q=head;
	ch='*';
	printf("\n��β�巨�����������������������ݣ���?����!\n");
	while(ch!='?')              /*"ch"Ϊ�Ƿ����½ڵ�ı�־����"ch"Ϊ"?"���������*/
	{
		scanf("%d",&a);           			/*������Ԫ��*/
		p=(NODE*)malloc(sizeof(NODE));		/*��Ӧͼ3.7�еĢ�*/
		p->data=a;                         	/*��Ӧͼ3.7�еĢ�*/
		q->next=p;                         	/*��Ӧͼ3.7�еĢ�*/
		q=p;                                	/*��Ӧͼ3.7�еĢ�*/
		ch=getchar();               			/*�����������ı�־*/
	}
	q->next=NULL;
	return(head);           					/*���ر�ͷָ��head*/
}
main()
{
	int i;
	NODE *a;
	a=create();
	printf("���������Ԫ�أ�");
	a=a->next;
	while(a!=NULL)
	{
		printf("%d ",a->data);     /*��������Ԫ��*/
		a=a->next;
	}
}
//�������н����
//��β�巨�����������������������ݣ��ԣ�����!
//6 7 8 9?���س���
//���������Ԫ�أ�6 7 8 9
