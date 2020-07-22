/* ======================================== */
/*    程序实例: 3-10.c                       */
/*    在带头节点的单链表head中插入元素        */
/* ======================================== */
#include<stdio.h>
#include<malloc.h>
typedef struct node                   	/*定义节点的存储结构*/
{
	int data;
	struct node *next;
}NODE;

NODE *create()  /*采用尾插法建立单链表，并返回一个指向链表表头的指针*/
{
	NODE *head,*q,*p;                	/*定义指针变量*/
	int a,n;
	head=(NODE*)malloc(sizeof(NODE)); 	/*申请新的存储空间，建立头节点*/
	q=head;
	printf("\n输入单链表的长度值n：");
	scanf("%d",&n);                   	/*输入单向链表节点个数*/
	if(n>0)                           	/*若n<=0，建立仅含头节点的空表*/
	{
		printf("输入单链表的%d个元素：",n);
		while(n>0)
		{
			scanf("%d",&a);      		/*输入新元素*/
			p=(NODE*)malloc(sizeof(NODE));
			p->data=a;
			q->next=p;
			q=p;
			n--;
		}
	}
	q->next=NULL;
	return(head);                    	/*返回表头指针head*/
}

void insert(NODE *p,int x)             	/*在链表的p节点位置后插入给定元素x*/
{
	NODE *q;
	q=(NODE*)malloc(sizeof(NODE)); 	/*对应图3.8中的①*/
	q->data=x;                       	/*对应图3.8中的②*/
	q->next=p->next;                  	/*对应图3.8中的③*/
	p->next=q;                       	/*对应图3.8中的④*/
}

main()                  				/*主程序*/
{
	int x,position;    		         /*x为将插入的元素，position为插入位置的序号*/
	int i=0,j=0;
	NODE *c,*d;
	c=create();          				/*建立单向链表*/
	d=c->next;
	while(d!=NULL)       			/*统计单向链表中节点数，置j中*/
	{
		d=d->next;
		j++;
	}
	d=c;
	do
	{
		printf("输入插入元素的位置：");
		scanf("%d",&position);        	/*position可为0，表示头节点*/
	}
	while((position>j)||position<0);    		/*position值超过单向链表节点数，重新输入*/
	printf("输入插入元素的值：");
	scanf("%d",&x);
	while(i!=position)                   	/*由position值确定其在单向链表中的位置d*/
	{
		d=d->next;
		i++;
	}
	insert(d,x);
	printf("输出插入元素后的单链表：");
	while(c->next!=NULL)                	/*输出插入x后的单向链表各元素*/
	{
		c=c->next;
		printf("%5d",c->data);
	}
}
//程序运行结果：
//输入单链表的长度值n：5（回车）
//输入单链表的5个元素：5 6 7 8 9（回车）
//输入插入元素的位置：3（回车）
//输入插入元素的值：33（回车）
//输出插入元素后的单链表：5  6  7  33  8  9 
