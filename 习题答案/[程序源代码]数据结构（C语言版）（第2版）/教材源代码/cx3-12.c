/* ======================================== */
/*    ����ʵ��: 3-12.c                       */
/*    ����ʽ���                             */
/* ======================================== */
#include <stdio.h>
#include <malloc.h>
typedef struct Pnode
{
	float  coef;		/*ϵ����*/
	int  exp;    		/*ָ����*/
	struct pnode  *next;
} Pnode,*Ploytp;

void polycreate(Ploytp head)
{
	Pnode *rear, *s;
	int c,e;
	rear=head;	                  	/* rear ʼ��ָ�������β������β�巨����*/
	scanf("%d,%d",&c,&e);       	/*�������ʽ��ϵ����ָ����*/
	while(c!=0)	              /*��c=0����������ʽ���������*/
	{
		s=(Pnode*)malloc(sizeof(Pnode));	/*�����µĽڵ�*/
		s->coef=c;
		s->exp=e;
		rear->next=s;			/*�ڵ�ǰ��β������*/
		rear=s;
		scanf("%d,%d",&c,&e); 
	}
	rear->next=NULL;	/*��������һ���ڵ��next��NULL����ʾ�����*/
}

void  polyadd(Ploytp polya, Ploytp polyb)
/*�˺������ڽ���������ʽ��ӣ�Ȼ�󽫺Ͷ���ʽ����ڶ���ʽpolya�У���ɾ������ʽployb */
{
	Pnode  *p, *q, *pre, *temp;
	int sum;
	p=polya->next;   /*�� p��q�ֱ�ָ��polya��polyb����ʽ�����еĵ�һ���ڵ�*/
	q=polyb->next;        
	pre=polya;      /* rָ��Ͷ���ʽ��β�ڵ�*/
	while (p!=NULL && q!=NULL)  /*����������ʽ��δɨ�����ʱ*/
	{
		if(p->exp < q->exp)
			/*���pָ��Ķ���ʽ���ָ��С��q��ָ������p�ڵ���뵽�Ͷ���ʽ��*/
		{
			pre->next=p;
			pre=p;
			p=p->next;
		}
		else
			if(p->exp==q->exp)  /*��ָ����ȣ�����Ӧ��ϵ�����*/
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
				else /*��ϵ����Ϊ�㣬��ɾ���ڵ�p��q������ָ��ָ����һ���ڵ�*/
				{
					temp=p;
					p=p->next;
					free(temp);
					temp=q;
					q=q->next;
					free(temp);
				}
			}
			else/*��q�ڵ���뵽�Ͷ���ʽ��*/
			{
				pre->next=q;
				pre=q;
				q=q->next;
			}
	}
	if(p!=NULL)  /*����ʽA�л���ʣ�࣬��ʣ��Ľڵ���뵽�Ͷ���ʽ��*/
		pre->next=p;
	else      /*���򣬽�B�еĽڵ���뵽�Ͷ���ʽ��*/
		pre->next=q;
}

void print(Pnode *H)                          /* ������ */
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
	printf("�������ݽ�������ʽA(X) ����0,0����!����\n"); 
	polya=(Pnode *)malloc(sizeof(Pnode));
	polycreate(polya);
	printf("A(x)=");
	print(polya); 
	printf("�������ݽ�������ʽB(X) ����0,0����!����\n"); 
	polyb=(Pnode *)malloc(sizeof(Pnode));
	polycreate(polyb);
	printf("B(x)=");
	print(polyb); 
	polyadd(polya,polyb);
	printf("����ʽ��ӽ����\nA(X)+B(X)=");
	print(polya); 
}
//�������н�����Ա�����������ʽΪ���������룩�� 
//�������ݽ�������ʽA(X) ����0,0����!���� 
//15,0  6,1  9,7  3,18  0,0
//A(x)=15x^0+6x^1+9x^7+3x^18
//�������ݽ�������ʽB(X) ����0,0����!���� 
//4,1  5,6   16,7  0,0
//B(x)=4x^1+5x^6+16x^7
//����ʽ��ӽ����
//A(X)+B(X)=15x^0+10x^1+5x^6+25x^7+3x^18
