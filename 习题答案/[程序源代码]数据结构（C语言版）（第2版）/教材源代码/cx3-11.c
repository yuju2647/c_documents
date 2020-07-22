/* ======================================== */
/*    程序实例: 3-11.c                       */
/*    在带头节点的单链表head中删除元素        */
/* ======================================== */
#include<stdio.h>
#include<malloc.h>
typedef struct node                   	/*定义节点的存储结构*/
{
	int data;
	struct node *next;
}NODE;

NODE *create()      /*采用尾插法建立单链表，并返回一个指向链表表头的指针*/
{
	NODE *head,*q,*p;                 	/*定义指针变量*/
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
			scanf("%d",&a);     		/*输入新元素*/
			p=(NODE*)malloc(sizeof(NODE)); 
			p->data=a;
			q->next=p;
			q=p;
			n--;
		}
	}
	q->next=NULL;
	return(head);                       	/*返回表头指针head*/
}

void delete(NODE *head,int x)       		/*删除链表中的给定元素x*/
{
	NODE *p,*q;
	q=head;
	p=q->next;
	while((p!=NULL)&&(p->data!=x))   	/*查找要删除的元素*/
	{
		q=p;
		p=p->next;
	}
	if(p==NULL)
		printf("%d 不存在.\n",x); /*x节点未找到*/
	else
	{
		q->next=p->next;           			/*链接x直接后继节点*/
		free(p);                     	/*删除x节点，释放x节点存储空间*/
	}
}
main()                              	/*主程序*/
{
	int x;
	NODE *a,*b;
	a=create();
	printf("输入要删除的元素：");
	scanf("%5d",&x);
	delete(a,x);
	b=a;
	b=b->next;
	printf("输出删除元素后的单链表：");
	while(b!=NULL)
	{
		printf("%5d",b->data);      	/*输出删除x后的单向链表*/
		b=b->next;
	}
}
//程序第一次运行结果（删除成功）：
//输入单链表的长度值n：5（回车）
//输入单链表的5个元素：1 2 3 4 5（回车）
//输入要删除的元素：4（回车）
//输出删除元素后的单链表：1  2  3  5
//程序第二次运行结果（删除元素未找到）：
//输入单链表的长度值n：5（回车）
//输入单链表的5个元素：1 2 3 4 5（回车）
//输入要删除的元素：6（回车）
//6 不存在！
//输出删除元素后的单链表：1  2  3  4  5
