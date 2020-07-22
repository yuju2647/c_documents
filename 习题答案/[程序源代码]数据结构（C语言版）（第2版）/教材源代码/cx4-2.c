/* ======================================== */
/*    程序实例: 4-2.c                       */
/*    链式栈的相关操作                      */
/* ======================================== */
#include<stdio.h>
#include<malloc.h>
typedef struct node              	/*定义链栈节点*/
{
	int data;                     	/*这里以整型数据为例*/
	struct node*next;            	/*指针类型，存放下一个节点地址*/
}NODE;

NODE *crea_linkstack()           	/*建立链栈*/
{
	NODE *top,*p;               	/*定义栈顶指针top*/
	int a,n;
	top=NULL;
	printf("\n输入链栈的元素数目：");
	scanf("%d",&n);              	/*入链栈的元素个数*/
	if(n>0)                      	/*若n<=0，建立空栈*/
	{
		printf("输入%d个链栈的元素：",n);
		while(n>0)
		{
			scanf("%d",&a);  		/*输入新元素*/
			p=(NODE*)malloc(sizeof(NODE));
			p->data=a;
			p->next=top;
			top=p;
			n--;
		}
	}
	return(top);                  	/*返回栈顶指针*/
}    

NODE *pushstack(NODE *top,int x)  	/*进栈操作*/
{
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE));
	p->data=x;                   	/*将要插入的数据x存储到节点p的数据域中*/ 
	p->next=top;                 	/*将p插入链表头部，即链栈顶部*/ 
	top=p;
	return(top);
}

NODE *popstack(NODE *top,int *p)
{
	NODE *q;                	/*定义q节点*/
	if(top!=NULL)               	/*如果栈不空*/
	{
		q=top;
		*p=top->data;            	/*将栈顶元素放入*p中*/
		top=top->next;           	/*修改top指针*/
		free(q);                 	/*释放原栈顶空间*/
	}  
	return(top);                  	/*返回栈顶指针*/
}

void print(NODE *top)             	/*输出链栈中各元素*/
{
	NODE *p;
	p=top;
	if(p!=NULL)
	{
		printf("输出链栈: ");
		while(p!=NULL)
		{
			printf("%3d",p->data);
			p=p->next;
		}
	}
	else
		printf("\n栈为空!!!");
}

main()                      		/*主程序*/
{
	int y=0;                  		/*将入栈的元素*/
	NODE *a,*b; 
	a=crea_linkstack();     		/*建立链栈*/
	print(a);                     	/*输出建立的链栈*/
	printf("\n\n*****The operation of pushstack*****");
	printf("\n输入一个入栈元素：");
	scanf("%d",&y);             	/*输入入栈元素y*/
	a=pushstack(a,y);             	/*y进栈*/
	print(a);                        	/*输出入栈后的整个链栈*/
	b=popstack(a,&y);            		/*出栈一个元素到y*/
	printf("\n\n*****The operation of popstack*****\n");
	printf("输出链栈栈顶元素：%d\n",y);
	print(b);                         	/*输出出栈后的整个链栈*/
}
//程序运行结果：
//输入链栈的元素数目：5（回车）
//输入5个链栈的元素：1 2 3 4 5（回车）
//输出链栈：5 4 3 2 1

//*****The operation of pushstack*****
//输入一个入栈元素：6（回车）
//输出链栈：6 5 4 3 2 1

//*****The operation of popstack*****
//出栈链栈栈顶元素：6
//输出链栈：5 4 3 2 1
