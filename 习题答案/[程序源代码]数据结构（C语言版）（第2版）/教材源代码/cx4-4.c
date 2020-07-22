/* ======================================== */
/*    程序实例: 4-4.c                       */
/*    链式队列的相关操作                      */
/* ======================================== */
#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int data;     				/*数据域，设为整型*/
	struct Node *next;     		/*指针域*/
}QNode;
typedef struct 
{
	QNode *front;
	QNode *rear;
}LinkQueue;

int InitLinkQueue(LinkQueue *Q) 
	/*初始化操作，将Q初始化为一个带头节点的空链队列 */
{ 
	Q->front=(QNode *)malloc(sizeof(QNode));
	if(Q->front!=NULL)
	{
		Q->rear=Q->front;     	/*尾指针指向头节点*/
		Q->front->next=NULL;  	/*置头节点的指针域为空*/
		return(1);
	}
	else return(0);    /* 溢出！*/
}

int EnterLinkQueue(LinkQueue *Q,int x)  /*入队操作，将数据元素x插入到队列Q中 */
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
	else  return(0);    /* 溢出！*/
}

int DelLinkQueue(LinkQueue *Q,int *x) 
	/*出队操作，将队列Q的队头元素出队，并存放到x所指的存储空间中 */
{  
	QNode *q;
	if(Q->front==Q->rear)
		return(0);
	q=Q->front->next;
	Q->front->next=q->next;  		/* 队头元素q出队 */
	if(Q->rear==q)      			/* 如果队中只有一个元素q，则q出队后成为空队 */
		Q->rear=Q->front;  
	*x=q->data;
	free(q);   /*释放存储空间 */
	return(1);	
}

int GetHead(LinkQueue Q, int *x) 	/*提取队列的队头元素，用x返回其值*/
{ 
	if(Q.front==Q.rear)  			/*队列为空*/
		return(0);
	*x=Q.front->next->data;
	return(1);  				/*操作成功*/
}

void ShowQueue(LinkQueue *Q)		// 显示队列元素函数				
{	QNode *p=Q->front->next;
if(p==NULL)
	printf("队列为空!\n");
else
{
	printf("队列元素为:\n");
	while(p!=NULL)
	{	
		printf("%3d",p->data);
		p=p->next;
	}
	printf("\n");
}
}

void main()   //主函数
{	
	int v,n=0,i,record,j,x;
	LinkQueue queue;
	InitLinkQueue(&queue);
	printf("\n输入入队元素的数目n：");
	scanf("%d",&n);
	printf("输入待入队的%d个元素：\n",n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&record);	
		EnterLinkQueue(&queue,record);
	}
	ShowQueue(&queue);
	if(GetHead(queue,&v)==0)
		printf("队列为空!\n");
	else
		printf("队头元素为：%d",v);
	printf("\n输入出队元素的数目j（要求j<=n）："); 
	scanf("%d",&j);
	printf("出队的元素为：\n");
	for(i=1;i<=j;i++)
	{
		DelLinkQueue(&queue,&x);
		printf("%3d",x);
	}
	printf("\n");
	ShowQueue(&queue);
}
//程序运行结果：
//输入入队元素的数目n：6（回车） 
//输入待入队的6个元素：
//5 3 2 1 8 10
//队列元素为：
//5 3 2 1 8 10
//队头元素为：5
//输入出队元素的数目j（要求j<=n）：3（回车） 
//出队的元素为：
//5  3  2
//队列元素为：
//1  8  10
//若输入出队元素的个数为6，将显示：
//出队的元素为：
//5 3 2 1 8 10
//队列为空！
