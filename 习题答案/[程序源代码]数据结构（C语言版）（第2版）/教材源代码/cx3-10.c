/* ======================================== */
/*    ����ʵ��: 3-10.c                       */
/*    �ڴ�ͷ�ڵ�ĵ�����head�в���Ԫ��        */
/* ======================================== */
#include<stdio.h>
#include<malloc.h>
typedef struct node                   	/*����ڵ�Ĵ洢�ṹ*/
{
	int data;
	struct node *next;
}NODE;

NODE *create()  /*����β�巨����������������һ��ָ�������ͷ��ָ��*/
{
	NODE *head,*q,*p;                	/*����ָ�����*/
	int a,n;
	head=(NODE*)malloc(sizeof(NODE)); 	/*�����µĴ洢�ռ䣬����ͷ�ڵ�*/
	q=head;
	printf("\n���뵥����ĳ���ֵn��");
	scanf("%d",&n);                   	/*���뵥������ڵ����*/
	if(n>0)                           	/*��n<=0����������ͷ�ڵ�Ŀձ�*/
	{
		printf("���뵥�����%d��Ԫ�أ�",n);
		while(n>0)
		{
			scanf("%d",&a);      		/*������Ԫ��*/
			p=(NODE*)malloc(sizeof(NODE));
			p->data=a;
			q->next=p;
			q=p;
			n--;
		}
	}
	q->next=NULL;
	return(head);                    	/*���ر�ͷָ��head*/
}

void insert(NODE *p,int x)             	/*�������p�ڵ�λ�ú�������Ԫ��x*/
{
	NODE *q;
	q=(NODE*)malloc(sizeof(NODE)); 	/*��Ӧͼ3.8�еĢ�*/
	q->data=x;                       	/*��Ӧͼ3.8�еĢ�*/
	q->next=p->next;                  	/*��Ӧͼ3.8�еĢ�*/
	p->next=q;                       	/*��Ӧͼ3.8�еĢ�*/
}

main()                  				/*������*/
{
	int x,position;    		         /*xΪ�������Ԫ�أ�positionΪ����λ�õ����*/
	int i=0,j=0;
	NODE *c,*d;
	c=create();          				/*������������*/
	d=c->next;
	while(d!=NULL)       			/*ͳ�Ƶ��������нڵ�������j��*/
	{
		d=d->next;
		j++;
	}
	d=c;
	do
	{
		printf("�������Ԫ�ص�λ�ã�");
		scanf("%d",&position);        	/*position��Ϊ0����ʾͷ�ڵ�*/
	}
	while((position>j)||position<0);    		/*positionֵ������������ڵ�������������*/
	printf("�������Ԫ�ص�ֵ��");
	scanf("%d",&x);
	while(i!=position)                   	/*��positionֵȷ�����ڵ��������е�λ��d*/
	{
		d=d->next;
		i++;
	}
	insert(d,x);
	printf("�������Ԫ�غ�ĵ�����");
	while(c->next!=NULL)                	/*�������x��ĵ��������Ԫ��*/
	{
		c=c->next;
		printf("%5d",c->data);
	}
}
//�������н����
//���뵥����ĳ���ֵn��5���س���
//���뵥�����5��Ԫ�أ�5 6 7 8 9���س���
//�������Ԫ�ص�λ�ã�3���س���
//�������Ԫ�ص�ֵ��33���س���
//�������Ԫ�غ�ĵ�����5  6  7  33  8  9 
