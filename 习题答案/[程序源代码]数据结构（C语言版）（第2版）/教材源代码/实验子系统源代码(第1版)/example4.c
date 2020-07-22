#include<stdio.h>
#include<malloc.h>
typedef struct queuenode
{	
int data;
	 struct queuenode *next;
}queuenode;
typedef struct
{
queuenode *front,*rear;
}linkqueue;
void InQueue(linkqueue *q)					// 入队函数 
{	int x;	
	     queuenode *p;
  	p=(queuenode *)malloc(sizeof(queuenode));
		printf("\n\t\t请键入一个整数：");
		scanf("%d",&x);getchar();
		p->data=x;
		p->next=NULL;
		if(q->front==NULL)
			q->front=p;
		else
			q->rear->next=p;
		q->rear=p;
		if(p)
			printf("\n\t\t%d入队成功！",x);
}
int OutQueue(linkqueue *q,int *v)			// 出队函数
{	queuenode *p;
		if(q->front==NULL)
			return 0;
		else
		{	p=q->front;
			*v=p->data;
			q->front=p->next;
			if(q->front==NULL)
			q->rear=NULL;
		    free(p);
			return 1;
		}
}
void ShowQueue(linkqueue *q)					// 显示队列函数
{	queuenode *p=q->front;
		if(p==NULL)
			printf("\t\t队列为空!\n");
		else
 	{	printf("\t\t队列为：");
			while(p!=NULL)
			{	printf("%6d",p->data);
				p=p->next;
			}
			printf("\n");
		}
}
void ReadFront(linkqueue *q)					// 读队首元素函数
{	if(q==NULL||q->front==NULL)
			printf("\t\t队列为空!没有队顶元素!\n");
		else
			printf("\n\t\t队首元素是：%4d。\n",q->front->data);
}

void main()                              			// 队列子系统主函数
{		
int val,i=1;
	    char w,choice;
	    queuenode *ptr,*t;
	    linkqueue *q;
  	    q=(linkqueue *)malloc(sizeof(linkqueue));
		q->front=q->rear=NULL;
		while (i)
		{	printf("\n\n\n\n");
			printf("\n\t\t\t\t  队 列 子 系 统\n");
			printf("\n\t\t******************************************");
			printf("\n\t\t*           1---------------进          队          *");
			printf("\n\t\t*           2---------------出          队          *");
			printf("\n\t\t*           3---------------队  顶  元  素          *");
			printf("\n\t\t*           4---------------显          示          *");
			printf("\n\t\t*           0---------------返          回          *");
			printf("\n\t\t******************************************");
			printf("\n\t\t请选择菜单号(0--5):");
			scanf("%c",&choice);
			getchar();
			switch(choice)
			{
			case '1':
				InQueue(q);break;
			case '2':
				if(OutQueue(q,&val)==0)
					printf("\n\t\t队列为空!\n");
				else
					printf("\n\t\t出队元素为：%d",val); break;
			case '3':
				ReadFront(q); break;
			case '4':
				ShowQueue(q); break;
			case '0':
				i=0; break;
			default:;
			}
			if(choice=='1'||choice=='2'||choice=='3'||choice=='4')
			{	printf("\n\t\t按回车键继续,按任意键返回主菜单.\n");
				w=getchar();
				if(w!='\xA')
				{getchar();i=0;
				}
			}
		}
		ptr=q->front;
     while(ptr!=NULL)
	 {	
		t=ptr->next;
		free(ptr);
		ptr=t;
	 }
 	q->front=q->rear=NULL;
}
