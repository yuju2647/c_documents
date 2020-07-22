/* ======================================== */
/*    程序实例: 3-12.c                       */
/*    多项式相加                             */
/* ======================================== */
#include <stdio.h>
#include <malloc.h>
typedef struct Pnode
{
	float  coef;		/*系数域*/
	int  exp;    		/*指数域*/
	struct pnode  *next;
} Pnode,*Ploytp;

void polycreate(Ploytp head)
{
	Pnode *rear, *s;
	int c,e;
	rear=head;	                  	/* rear 始终指向单链表的尾，便于尾插法建表*/
	scanf("%d,%d",&c,&e);       	/*输入多项式的系数和指数项*/
	while(c!=0)	              /*若c=0，则代表多项式的输入结束*/
	{
		s=(Pnode*)malloc(sizeof(Pnode));	/*申请新的节点*/
		s->coef=c;
		s->exp=e;
		rear->next=s;			/*在当前表尾做插入*/
		rear=s;
		scanf("%d,%d",&c,&e); 
	}
	rear->next=NULL;	/*将表的最后一个节点的next置NULL，以示表结束*/
}

void  polyadd(Ploytp polya, Ploytp polyb)
/*此函数用于将两个多项式相加，然后将和多项式存放在多项式polya中，并删除多项式ployb */
{
	Pnode  *p, *q, *pre, *temp;
	int sum;
	p=polya->next;   /*令 p和q分别指向polya和polyb多项式链表中的第一个节点*/
	q=polyb->next;        
	pre=polya;      /* r指向和多项式的尾节点*/
	while (p!=NULL && q!=NULL)  /*当两个多项式均未扫描结束时*/
	{
		if(p->exp < q->exp)
			/*如果p指向的多项式项的指数小于q的指数，将p节点加入到和多项式中*/
		{
			pre->next=p;
			pre=p;
			p=p->next;
		}
		else
			if(p->exp==q->exp)  /*若指数相等，则相应的系数相加*/
			{
				sum=p->coef + q->coef;
				if(sum!=0)	
				{
					p->coef=sum;
					pre->next=p;
					pre=p;
					p=p->next;
					temp=q;
					q=q->next;
					free(temp);
				}
				else /*若系数和为零，则删除节点p与q，并将指针指向下一个节点*/
				{
					temp=p;
					p=p->next;
					free(temp);
					temp=q;
					q=q->next;
					free(temp);
				}
			}
			else/*将q节点加入到和多项式中*/
			{
				pre->next=q;
				pre=q;
				q=q->next;
			}
	}
	if(p!=NULL)  /*多项式A中还有剩余，则将剩余的节点加入到和多项式中*/
		pre->next=p;
	else      /*否则，将B中的节点加入到和多项式中*/
		pre->next=q;
}

void print(Pnode *H)                          /* 输出结果 */
{  
	Pnode *p=H->next;
	while(p->next)
	{
		printf("%dx^%d+",p->coef,p->exp);
		p=p->next;
	}
	if(p->exp) 
		printf("%dx^%d\n",p->coef,p->exp);
	else 
		printf("%d\n",p->coef);
}/* print */

void main()
{
	Ploytp polya,polyb;
	printf("输入数据建立多项式A(X) （以0,0结束!）：\n"); 
	polya=(Pnode *)malloc(sizeof(Pnode));
	polycreate(polya);
	printf("A(x)=");
	print(polya); 
	printf("输入数据建立多项式B(X) （以0,0结束!）：\n"); 
	polyb=(Pnode *)malloc(sizeof(Pnode));
	polycreate(polyb);
	printf("B(x)=");
	print(polyb); 
	polyadd(polya,polyb);
	printf("多项式相加结果：\nA(X)+B(X)=");
	print(polya); 
}
//程序运行结果（以本例中两多项式为例进行输入）： 
//输入数据建立多项式A(X) （以0,0结束!）： 
//15,0  6,1  9,7  3,18  0,0
//A(x)=15x^0+6x^1+9x^7+3x^18
//输入数据建立多项式B(X) （以0,0结束!）： 
//4,1  5,6   16,7  0,0
//B(x)=4x^1+5x^6+16x^7
//多项式相加结果：
//A(X)+B(X)=15x^0+10x^1+5x^6+25x^7+3x^18
