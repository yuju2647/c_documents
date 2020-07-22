/* ======================================== */
/*    ����ʵ��: 4-3.c                       */
/*    ˳����е���ز���                      */
/* ======================================== */
#include <stdio.h>
#define MAXLEN 10
typedef struct                   	/*���е�˳��洢�ṹ����*/
{
	int data[MAXLEN];          	/*��Ŷ���Ԫ�ص�����*/
	int front,rear;                	/*����ͷ��βָ��*/
}SeQueue;

SeQueue InitSeQueue()            	/*����һ���ն���q*/
{   
	SeQueue q;
	q.front=-1;
	q.rear=-1;
	return(q);
}

int Getfront_seq(SeQueue *q,int *x) 	/*ȡ��ͷԪ�أ�������q�ǿգ���*x������Ԫ��*/
{
	if(q->front==q->rear)
		return(0);              	/*���пշ���0*/
	else
	{
		*x=q->data[(q->front)+1];
		return(1);
	}
}

int enterSeqQueue(SeQueue *q,int x) 	/*����в�����������qδ������Ԫ��x���*/
{
	if(q->rear==MAXLEN-1)
		return(0);               	/*����������0*/
	q->rear++;
	q->data[q->rear]=x;
	return(1);
}

int Empty_seq(SeQueue *q)        	/*�ж϶���q�Ƿ�Ϊ�գ����򷵻�1���ǿշ���0*/
{
	return(q->front==q->rear);
}

int DelSeqQueue(SeQueue *q,int *x) 	/*�����в�����������q�ǿգ�������Ԫ����*x*/
{
	if(q->front==q->rear)
		return(0);                	/*���пշ���0*/
	else
	{
		q->front++;
		*x=q->data[q->front];
		return(1);
	}
}

void print(SeQueue q)              	/*�������qԪ��*/
{
	int n;
	if(q.front!=q.rear)             	/*���зǿգ��������Ԫ��*/
	{
		printf("���е�Ԫ�������");
		for(n=q.front+1;n<=q.rear;n++)
			printf("%d ",q.data[n]);
	}
	else
		printf("����Ϊ��!!!");
	printf("\n");
}

main()                          		/*������*/
{
	SeQueue queue;
	int n,y,z,i,j;
	queue=InitSeQueue();          		/*�����ն���queue*/
	if(Empty_seq(&queue)!=0)      		/*�ж϶���queue�Ƿ�Ϊ��*/
		printf("\n����Ϊ��!");
	else
		printf("\n���зǿ�!");
	printf("\n�������Ԫ�ص���Ŀn��");
	scanf("%d",&n);
	printf("����%d������ӵ�Ԫ�أ�\n",n);
	for(i=1;i<=n;i++)               		/*�����n��Ԫ��*/
	{
		scanf("%d",&y);
		enterSeqQueue(&queue,y);
	}
	print(queue);                 		/*�����n��Ԫ�غ��������Ԫ��*/
	Getfront_seq(&queue,&z);       		/*ȡ����ͷ��Ԫ�أ���z*/
	printf("��ǰ��ͷԪ�أ�%d \n",z);  	/*�������ͷ��Ԫ��z*/
	print(queue);                   	/*���������Ԫ��*/
	printf("�������Ԫ�ص���Ŀj��jҪС��n����");
	scanf("%d",&j);
	printf("���ӵ�%d��Ԫ��Ϊ��",j);
	for(i=1;i<=j;i++)                    	/*������j��Ԫ��*/
	{
		DelSeqQueue(&queue,&z);
		printf("%d ",z);               	/*�������д����������Ԫ��*/
	}
	printf("\n");    
	print(queue);                      	/*���������Ԫ��*/
	if(Empty_seq(&queue)!=0)          	/*�ж϶���queue�Ƿ�Ϊ��*/
		printf("����Ϊ��!\n");
	else
		printf("���зǿ�!\n");
}
//�������н����
//����Ϊ�գ�
//�������Ԫ�ص���Ŀn��6���س���
//����6������ӵ�Ԫ�أ�8  7  6  2  5  4���س���
//���е�Ԫ�������8  7  6  2  5  4
//��ǰ��ͷԪ�أ�8
//���е�Ԫ�������8  7  6  2  5  4
//�������Ԫ�ص���Ŀj��jҪС��n����3���س���
//���е�Ԫ�������2  5  4
//���зǿգ�
