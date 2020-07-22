/* ======================================== */
/*    程序实例: 3-13.c                       */
/*    合并两个循环单链表                     */
/* ======================================== */
#include <stdio.h>
#include <malloc.h>
typedef int elementtype;
typedef struct CNode    /*节点类型定义*/ 
{ 
	elementtype data;
	struct CNode  * next;
}CNode, *CLinkList;  /* CLinkList为结构指针类型*/

CLinkList crt_linklist()/*创建尾指针表示的循环链表*/
{
	CLinkList list;
	int num;
	CNode *p;
	list=(CNode*)malloc(sizeof(struct CNode));
	list->data=-1;
	list->next=list;
	printf("请输入循环链表的元素（以-1结束）：\n"); 
	scanf("%d",&num);
	while(num != -1)
	{
		p=(CNode*)malloc(sizeof(struct CNode));
		p->data=num;
		p->next=list->next;
		list->next=p;
		scanf("%d",&num);
	}
	p=list;
	while(p->next!=list)
	{
		p=p->next;
	}
	return p;
}

CLinkList  merge_rear(CLinkList reara,CLinkList rearb)
{        /*此算法将两个采用尾指针的循环链表首尾连接起来*/
	CNode *p;
	p=reara->next; /*保存链表reara的头节点地址*/
	reara->next=rearb->next->next;  /*链表rearb的开始节点链到链表reara的终端节点之后*/
	free(rearb->next);	        /*释放链表rearb的头节点*/
	rearb->next=p;  	             /*链表reara的头节点链到链表rearb的终端节点之后*/
	return  rearb;		        /*返回新循环链表的尾指针*/
}
void print(CLinkList cl)
{  
	CNode *p;
	p=cl->next->next;
	while(p!=cl->next)
	{
		printf("%d  ",p->data);
		p=p->next;
	}
	printf("\n");
}

void main()
{
	CLinkList clista,clistb,clistc;
	printf("建立循环链表A，请输入数据!\n");
	clista=crt_linklist();
	printf("建立的循环单链表A为：\n");
	print(clista);
	printf("\n建立循环链表B，请输入数据!\n");
	clistb=crt_linklist();
	printf("建立的循环单链表B为：\n");
	print(clistb);
	clistc=merge_rear(clista,clistb);
	printf("\n合并后的循环链表为：\n");
	print(clistc);
}
//程序运行结果：
//建立循环链表A，请输入数据!
//请输入循环链表的元素（以-1结束）：
//6  5  4  3  2  -1（回车） 
//建立的循环单链表A为：
//2  3  4  5  6
//建立循环链表B，请输入数据!
//请输入循环链表的元素（以-1结束）： 
//8  9  4  6  3  -1（回车） 
//建立的循环单链表B为：
//3  6  4  9  8
//合并后的循环单链表为：
//2  3  4  5  6  3  6  4  9  8
