/* ======================================== */
/*    ����ʵ��: 3-8.c                       */
/*    �ڴ�ͷ�ڵ�ĵ�����head�в��ҵ�i���ڵ�  */
/* ======================================== */
#include<stdio.h>
#include<malloc.h>
typedef struct node                   		/*����ڵ�Ĵ洢�ṹ*/
{
	int data;
	struct node *next;
}NODE;

NODE *create()  /*����β�巨����������������һ��ָ�������ͷ��ָ��*/
{
	NODE *head,*q,*p;        		/*����ָ�����*/
	char ch;
	int a;
	head=(NODE*)malloc(sizeof(NODE)); 	/*�����µĴ洢�ռ䣬����ͷ�ڵ�*/
	q=head;
	ch='*';
	printf("\n��β�巨�����������������������ݣ���?����!");
	while(ch!='?')    /*"ch"Ϊ�Ƿ����½ڵ�ı�־����"ch"Ϊ"?"���������*/
	{
		scanf("%d",&a);            		/*������Ԫ��*/
		p=(NODE*)malloc(sizeof(NODE));
		p->data=a;
		q->next=p;
		q=p;
		ch=getchar();                  	/*�����������ı�־*/
	}
	q->next=NULL;
	return(head);                       	/*���ر�ͷָ��head*/
}

NODE *find(NODE *head,int i)     		    /*����֪�����в��Ҹ�����λ��i*/
{
	int j=1;
	NODE *p;
	p=head->next;
	while((p!=NULL)&&(j<i)) 			    /*δ����β��δ�ҵ���������*/
	{
		p=p->next;                 	    /*ָ����һ��Ԫ��*/
		j++;
	}    
	return(p);
}

main()                             	  /*������*/
{
	int i;
	NODE *a,*b;
	a=create();
	printf("�������λ�ã�");
	scanf("%d",&i);
	b=find(a,i);
	if(b!=NULL)
	{   
		printf("�ҵ���Ԫ��Ϊ��");
		printf("%5d",b->data);      		/*���ҳɹ�*/
	}
	else
		printf("û�и�Ԫ�أ�");           	/*����ʧ��*/
}
//�������н����
//��β�巨�����������������������ݣ���?����!
//5 6 7 8 9?���س���
//�������λ�ã�3���س���
//�ҵ���Ԫ��Ϊ��7
