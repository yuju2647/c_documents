/* ======================================== */
/*    程序实例: 4-3.c                       */
/*    顺序队列的相关操作                      */
/* ======================================== */
#include <stdio.h>
#define MAXLEN 10
typedef struct                   	/*队列的顺序存储结构定义*/
{
	int data[MAXLEN];          	/*存放队列元素的数组*/
	int front,rear;                	/*队列头、尾指针*/
}SeQueue;

SeQueue InitSeQueue()            	/*建立一个空队列q*/
{   
	SeQueue q;
	q.front=-1;
	q.rear=-1;
	return(q);
}

int Getfront_seq(SeQueue *q,int *x) 	/*取队头元素，若队列q非空，用*x返回其元素*/
{
	if(q->front==q->rear)
		return(0);              	/*队列空返回0*/
	else
	{
		*x=q->data[(q->front)+1];
		return(1);
	}
}

int enterSeqQueue(SeQueue *q,int x) 	/*入队列操作，若队列q未满，将元素x入队*/
{
	if(q->rear==MAXLEN-1)
		return(0);               	/*队列满返回0*/
	q->rear++;
	q->data[q->rear]=x;
	return(1);
}

int Empty_seq(SeQueue *q)        	/*判断队列q是否为空，空则返回1，非空返回0*/
{
	return(q->front==q->rear);
}

int DelSeqQueue(SeQueue *q,int *x) 	/*出队列操作，若队列q非空，将出队元素送*x*/
{
	if(q->front==q->rear)
		return(0);                	/*队列空返回0*/
	else
	{
		q->front++;
		*x=q->data[q->front];
		return(1);
	}
}

void print(SeQueue q)              	/*输出队列q元素*/
{
	int n;
	if(q.front!=q.rear)             	/*队列非空，输出队列元素*/
	{
		printf("队列的元素输出：");
		for(n=q.front+1;n<=q.rear;n++)
			printf("%d ",q.data[n]);
	}
	else
		printf("队列为空!!!");
	printf("\n");
}

main()                          		/*主程序*/
{
	SeQueue queue;
	int n,y,z,i,j;
	queue=InitSeQueue();          		/*建立空队列queue*/
	if(Empty_seq(&queue)!=0)      		/*判断队列queue是否为空*/
		printf("\n队列为空!");
	else
		printf("\n队列非空!");
	printf("\n输入入队元素的数目n：");
	scanf("%d",&n);
	printf("输入%d个待入队的元素：\n",n);
	for(i=1;i<=n;i++)               		/*入队列n个元素*/
	{
		scanf("%d",&y);
		enterSeqQueue(&queue,y);
	}
	print(queue);                 		/*入队列n个元素后输出队列元素*/
	Getfront_seq(&queue,&z);       		/*取队列头部元素，送z*/
	printf("当前队头元素：%d \n",z);  	/*输出队列头部元素z*/
	print(queue);                   	/*再输出队列元素*/
	printf("输入出队元素的数目j（j要小于n）：");
	scanf("%d",&j);
	printf("出队的%d个元素为：",j);
	for(i=1;i<=j;i++)                    	/*出队列j个元素*/
	{
		DelSeqQueue(&queue,&z);
		printf("%d ",z);               	/*按出队列次序输出队列元素*/
	}
	printf("\n");    
	print(queue);                      	/*再输出队列元素*/
	if(Empty_seq(&queue)!=0)          	/*判断队列queue是否为空*/
		printf("队列为空!\n");
	else
		printf("队列非空!\n");
}
//程序运行结果：
//队列为空！
//输入入队元素的数目n：6（回车）
//输入6个待入队的元素：8  7  6  2  5  4（回车）
//队列的元素输出：8  7  6  2  5  4
//当前队头元素：8
//队列的元素输出：8  7  6  2  5  4
//输入出队元素的数目j（j要小于n）：3（回车）
//队列的元素输出：2  5  4
//队列非空！
