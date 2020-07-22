/* ======================================== */
/*    程序实例: 3-7.c                       */
/*    在链表的尾部插入节点建立单链表         */
/* ======================================== */
#include<malloc.h>
#include<stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *create()		/*此函数采用尾插入方式建立单链表，并返回一个指向链表表头的指针*/
{
	NODE *head,*q,*p;                	/*定义指针变量*/
	char ch;
	int a;
	head=(NODE*)malloc(sizeof(NODE)); 	/*申请新的存储空间，建立头节点*/
	q=head;
	ch='*';
	printf("\n用尾插法建立单链表，请输入链表数据，以?结束!\n");
	while(ch!='?')              /*"ch"为是否建立新节点的标志，若"ch"为"?"则输入结束*/
	{
		scanf("%d",&a);           			/*输入新元素*/
		p=(NODE*)malloc(sizeof(NODE));		/*对应图3.7中的①*/
		p->data=a;                         	/*对应图3.7中的②*/
		q->next=p;                         	/*对应图3.7中的③*/
		q=p;                                	/*对应图3.7中的④*/
		ch=getchar();               			/*读入输入与否的标志*/
	}
	q->next=NULL;
	return(head);           					/*返回表头指针head*/
}
main()
{
	int i;
	NODE *a;
	a=create();
	printf("输出单链表元素：");
	a=a->next;
	while(a!=NULL)
	{
		printf("%d ",a->data);     /*输出链表各元素*/
		a=a->next;
	}
}
//程序运行结果：
//用尾插法建立单链表，请输入链表数据，以？结束!
//6 7 8 9?（回车）
//输出单链表元素：6 7 8 9
