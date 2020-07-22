/* ======================================== */
/*    ����ʵ��: 4-2.c                       */
/*    ��ʽջ����ز���                      */
/* ======================================== */
#include<stdio.h>
#include<malloc.h>
typedef struct node              	/*������ջ�ڵ�*/
{
	int data;                     	/*��������������Ϊ��*/
	struct node*next;            	/*ָ�����ͣ������һ���ڵ��ַ*/
}NODE;

NODE *crea_linkstack()           	/*������ջ*/
{
	NODE *top,*p;               	/*����ջ��ָ��top*/
	int a,n;
	top=NULL;
	printf("\n������ջ��Ԫ����Ŀ��");
	scanf("%d",&n);              	/*����ջ��Ԫ�ظ���*/
	if(n>0)                      	/*��n<=0��������ջ*/
	{
		printf("����%d����ջ��Ԫ�أ�",n);
		while(n>0)
		{
			scanf("%d",&a);  		/*������Ԫ��*/
			p=(NODE*)malloc(sizeof(NODE));
			p->data=a;
			p->next=top;
			top=p;
			n--;
		}
	}
	return(top);                  	/*����ջ��ָ��*/
}    

NODE *pushstack(NODE *top,int x)  	/*��ջ����*/
{
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE));
	p->data=x;                   	/*��Ҫ���������x�洢���ڵ�p����������*/ 
	p->next=top;                 	/*��p��������ͷ��������ջ����*/ 
	top=p;
	return(top);
}

NODE *popstack(NODE *top,int *p)
{
	NODE *q;                	/*����q�ڵ�*/
	if(top!=NULL)               	/*���ջ����*/
	{
		q=top;
		*p=top->data;            	/*��ջ��Ԫ�ط���*p��*/
		top=top->next;           	/*�޸�topָ��*/
		free(q);                 	/*�ͷ�ԭջ���ռ�*/
	}  
	return(top);                  	/*����ջ��ָ��*/
}

void print(NODE *top)             	/*�����ջ�и�Ԫ��*/
{
	NODE *p;
	p=top;
	if(p!=NULL)
	{
		printf("�����ջ: ");
		while(p!=NULL)
		{
			printf("%3d",p->data);
			p=p->next;
		}
	}
	else
		printf("\nջΪ��!!!");
}

main()                      		/*������*/
{
	int y=0;                  		/*����ջ��Ԫ��*/
	NODE *a,*b; 
	a=crea_linkstack();     		/*������ջ*/
	print(a);                     	/*�����������ջ*/
	printf("\n\n*****The operation of pushstack*****");
	printf("\n����һ����ջԪ�أ�");
	scanf("%d",&y);             	/*������ջԪ��y*/
	a=pushstack(a,y);             	/*y��ջ*/
	print(a);                        	/*�����ջ���������ջ*/
	b=popstack(a,&y);            		/*��ջһ��Ԫ�ص�y*/
	printf("\n\n*****The operation of popstack*****\n");
	printf("�����ջջ��Ԫ�أ�%d\n",y);
	print(b);                         	/*�����ջ���������ջ*/
}
//�������н����
//������ջ��Ԫ����Ŀ��5���س���
//����5����ջ��Ԫ�أ�1 2 3 4 5���س���
//�����ջ��5 4 3 2 1

//*****The operation of pushstack*****
//����һ����ջԪ�أ�6���س���
//�����ջ��6 5 4 3 2 1

//*****The operation of popstack*****
//��ջ��ջջ��Ԫ�أ�6
//�����ջ��5 4 3 2 1
