/* ======================================== */
/*    ����ʵ��: 4-4.c                       */
/*    ��ʽ���е���ز���                      */
/* ======================================== */
#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int data;     				/*��������Ϊ����*/
	struct Node *next;     		/*ָ����*/
}QNode;
typedef struct 
{
	QNode *front;
	QNode *rear;
}LinkQueue;

int InitLinkQueue(LinkQueue *Q) 
	/*��ʼ����������Q��ʼ��Ϊһ����ͷ�ڵ�Ŀ������� */
{ 
	Q->front=(QNode *)malloc(sizeof(QNode));
	if(Q->front!=NULL)
	{
		Q->rear=Q->front;     	/*βָ��ָ��ͷ�ڵ�*/
		Q->front->next=NULL;  	/*��ͷ�ڵ��ָ����Ϊ��*/
		return(1);
	}
	else return(0);    /* �����*/
}

int EnterLinkQueue(LinkQueue *Q,int x)  /*��Ӳ�����������Ԫ��x���뵽����Q�� */
{  
	QNode *NewNode;
	NewNode=(QNode *)malloc(sizeof(QNode));
	if(NewNode!=NULL)
	{
		NewNode->data=x;
		NewNode->next=NULL;
		Q->rear->next=NewNode;
		Q->rear=NewNode;
		return(1);
	}
	else  return(0);    /* �����*/
}

int DelLinkQueue(LinkQueue *Q,int *x) 
	/*���Ӳ�����������Q�Ķ�ͷԪ�س��ӣ�����ŵ�x��ָ�Ĵ洢�ռ��� */
{  
	QNode *q;
	if(Q->front==Q->rear)
		return(0);
	q=Q->front->next;
	Q->front->next=q->next;  		/* ��ͷԪ��q���� */
	if(Q->rear==q)      			/* �������ֻ��һ��Ԫ��q����q���Ӻ��Ϊ�ն� */
		Q->rear=Q->front;  
	*x=q->data;
	free(q);   /*�ͷŴ洢�ռ� */
	return(1);	
}

int GetHead(LinkQueue Q, int *x) 	/*��ȡ���еĶ�ͷԪ�أ���x������ֵ*/
{ 
	if(Q.front==Q.rear)  			/*����Ϊ��*/
		return(0);
	*x=Q.front->next->data;
	return(1);  				/*�����ɹ�*/
}

void ShowQueue(LinkQueue *Q)		// ��ʾ����Ԫ�غ���				
{	QNode *p=Q->front->next;
if(p==NULL)
	printf("����Ϊ��!\n");
else
{
	printf("����Ԫ��Ϊ:\n");
	while(p!=NULL)
	{	
		printf("%3d",p->data);
		p=p->next;
	}
	printf("\n");
}
}

void main()   //������
{	
	int v,n=0,i,record,j,x;
	LinkQueue queue;
	InitLinkQueue(&queue);
	printf("\n�������Ԫ�ص���Ŀn��");
	scanf("%d",&n);
	printf("�������ӵ�%d��Ԫ�أ�\n",n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&record);	
		EnterLinkQueue(&queue,record);
	}
	ShowQueue(&queue);
	if(GetHead(queue,&v)==0)
		printf("����Ϊ��!\n");
	else
		printf("��ͷԪ��Ϊ��%d",v);
	printf("\n�������Ԫ�ص���Ŀj��Ҫ��j<=n����"); 
	scanf("%d",&j);
	printf("���ӵ�Ԫ��Ϊ��\n");
	for(i=1;i<=j;i++)
	{
		DelLinkQueue(&queue,&x);
		printf("%3d",x);
	}
	printf("\n");
	ShowQueue(&queue);
}
//�������н����
//�������Ԫ�ص���Ŀn��6���س��� 
//�������ӵ�6��Ԫ�أ�
//5 3 2 1 8 10
//����Ԫ��Ϊ��
//5 3 2 1 8 10
//��ͷԪ��Ϊ��5
//�������Ԫ�ص���Ŀj��Ҫ��j<=n����3���س��� 
//���ӵ�Ԫ��Ϊ��
//5  3  2
//����Ԫ��Ϊ��
//1  8  10
//���������Ԫ�صĸ���Ϊ6������ʾ��
//���ӵ�Ԫ��Ϊ��
//5 3 2 1 8 10
//����Ϊ�գ�
