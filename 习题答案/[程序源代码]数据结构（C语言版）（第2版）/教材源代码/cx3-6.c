/* ======================================== */
/*    ����ʵ��: 3-6.c                       */
/*    �������ͷ������ڵ㽨��������         */
/* ======================================== */
#include<malloc.h>
#include<stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *create()		/*�˺�������ͷ�巨����������������һ��ָ�������ͷ��ָ��*/
{
	NODE *head,*q,*p;                 		/*����ָ�����*/
	char ch;
	int a;
	head=(NODE*)malloc(sizeof(NODE)); 		/*�����µĴ洢�ռ䣬����ͷ�ڵ�*/
	head->next=NULL;
	q=head->next;
	ch='*';
	printf("\n��ͷ�巨�����������������������ݣ���?����!\n");
	while(ch!='?')   /*"ch"Ϊ�Ƿ����½ڵ�ı�־����"ch"Ϊ"?"���������*/
	{
		scanf("%d",&a);                		/*������Ԫ��*/
		p=(NODE*)malloc(sizeof(NODE)); 		/*��Ӧͼ3.6�еĢ�*/
		p->data=a;                          	/*��Ӧͼ3.6�еĢ�*/
		head->next=p;                      	/*��Ӧͼ3.6�еĢ�*/
		p->next=q;                          	/*��Ӧͼ3.6�еĢ�*/
		q=p;                                 	/*��Ӧͼ3.6�еĢ�*/
		ch=getchar();               			/*�����������ı�־*/
	}
	return(head);           				/*���ر�ͷָ��head*/
}

main()
{
	NODE *a;
	a=create();
	printf("���������Ԫ�أ�");
	a=a->next;
	while(a!=NULL)
	{
		printf("%d ",a->data);     				/*��������Ԫ��*/
		a=a->next;
	}
}
//�������н����
//��ͷ�巨�����������������������ݣ���?����!
//9 8 7 6?���س���
//���������Ԫ�أ�6 7 8 9
