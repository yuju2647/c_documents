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
void InQueue(linkqueue *q)					// ��Ӻ��� 
{	int x;	
	     queuenode *p;
  	p=(queuenode *)malloc(sizeof(queuenode));
		printf("\n\t\t�����һ��������");
		scanf("%d",&x);getchar();
		p->data=x;
		p->next=NULL;
		if(q->front==NULL)
			q->front=p;
		else
			q->rear->next=p;
		q->rear=p;
		if(p)
			printf("\n\t\t%d��ӳɹ���",x);
}
int OutQueue(linkqueue *q,int *v)			// ���Ӻ���
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
void ShowQueue(linkqueue *q)					// ��ʾ���к���
{	queuenode *p=q->front;
		if(p==NULL)
			printf("\t\t����Ϊ��!\n");
		else
 	{	printf("\t\t����Ϊ��");
			while(p!=NULL)
			{	printf("%6d",p->data);
				p=p->next;
			}
			printf("\n");
		}
}
void ReadFront(linkqueue *q)					// ������Ԫ�غ���
{	if(q==NULL||q->front==NULL)
			printf("\t\t����Ϊ��!û�жӶ�Ԫ��!\n");
		else
			printf("\n\t\t����Ԫ���ǣ�%4d��\n",q->front->data);
}

void main()                              			// ������ϵͳ������
{		
int val,i=1;
	    char w,choice;
	    queuenode *ptr,*t;
	    linkqueue *q;
  	    q=(linkqueue *)malloc(sizeof(linkqueue));
		q->front=q->rear=NULL;
		while (i)
		{	printf("\n\n\n\n");
			printf("\n\t\t\t\t  �� �� �� ϵ ͳ\n");
			printf("\n\t\t******************************************");
			printf("\n\t\t*           1---------------��          ��          *");
			printf("\n\t\t*           2---------------��          ��          *");
			printf("\n\t\t*           3---------------��  ��  Ԫ  ��          *");
			printf("\n\t\t*           4---------------��          ʾ          *");
			printf("\n\t\t*           0---------------��          ��          *");
			printf("\n\t\t******************************************");
			printf("\n\t\t��ѡ��˵���(0--5):");
			scanf("%c",&choice);
			getchar();
			switch(choice)
			{
			case '1':
				InQueue(q);break;
			case '2':
				if(OutQueue(q,&val)==0)
					printf("\n\t\t����Ϊ��!\n");
				else
					printf("\n\t\t����Ԫ��Ϊ��%d",val); break;
			case '3':
				ReadFront(q); break;
			case '4':
				ShowQueue(q); break;
			case '0':
				i=0; break;
			default:;
			}
			if(choice=='1'||choice=='2'||choice=='3'||choice=='4')
			{	printf("\n\t\t���س�������,��������������˵�.\n");
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
