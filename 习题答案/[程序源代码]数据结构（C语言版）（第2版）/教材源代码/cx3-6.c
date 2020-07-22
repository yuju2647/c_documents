/* ======================================== */
/*    程序实例: 3-6.c                       */
/*    在链表的头部插入节点建立单链表         */
/* ======================================== */
#include<malloc.h>
#include<stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *create()		/*此函数采用头插法建立单链表，并返回一个指向链表表头的指针*/
{
	NODE *head,*q,*p;                 		/*定义指针变量*/
	char ch;
	int a;
	head=(NODE*)malloc(sizeof(NODE)); 		/*申请新的存储空间，建立头节点*/
	head->next=NULL;
	q=head->next;
	ch='*';
	printf("\n用头插法建立单链表，请输入链表数据，以?结束!\n");
	while(ch!='?')   /*"ch"为是否建立新节点的标志，若"ch"为"?"则输入结束*/
	{
		scanf("%d",&a);                		/*输入新元素*/
		p=(NODE*)malloc(sizeof(NODE)); 		/*对应图3.6中的①*/
		p->data=a;                          	/*对应图3.6中的②*/
		head->next=p;                      	/*对应图3.6中的③*/
		p->next=q;                          	/*对应图3.6中的④*/
		q=p;                                 	/*对应图3.6中的⑤*/
		ch=getchar();               			/*读入输入与否的标志*/
	}
	return(head);           				/*返回表头指针head*/
}

main()
{
	NODE *a;
	a=create();
	printf("输出单链表元素：");
	a=a->next;
	while(a!=NULL)
	{
		printf("%d ",a->data);     				/*输出链表各元素*/
		a=a->next;
	}
}
//程序运行结果：
//用头插法建立单链表，请输入链表数据，以?结束!
//9 8 7 6?（回车）
//输出单链表元素：6 7 8 9
