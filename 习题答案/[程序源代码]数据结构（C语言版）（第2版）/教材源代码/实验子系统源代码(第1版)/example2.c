#include<stdio.h>    // ���Ա���ϵͳʵ��
typedef struct linknode
{
char data;
struct linknode *next;
}node;
node *head;
int n=0;									// ���Ա���

void CreateList()							// �������Ա�
{
		node *p,*s;
		char x;
		int z=1;
		head=new node;
		p=head;
		printf("\n\t\t����һ�����Ա�");
		printf("\n\t\t˵��������������ַ����������Ϊ��x����\n");
		while(z)
		{
			printf("\t\t���룺");
			scanf("%c",&x);
			getchar();
			if(x!='x')
			{
				s=new node;
				n++;
				s->data=x;
				p->next=s;
				s->next=NULL;
				p=s;
			}
			else z=0;
		}
}

void InsList(int i,char x)					// ������Ԫ��
{
		node *s,*p;
		int j;
		s=new node;
		n++;
		s->data=x;
		if(i==0)
		{
			s->next=head;
			head=s;
		}
		else
		{
			p=head;j=1;
			while(p!=NULL&&j<i)
			{
				j++;
				p=p->next;
			}
			if(p!=NULL)
			{
				s->next=p->next;
				p->next=s;
			}
			else 
				printf("\t\tδ�ҵ���\n");
		}
}

void DelList(char x)						// ɾ�����Ԫ��
{
		node *p,*q;
		if(head==NULL) 
		{
			printf("\t\t�������磡\n");
			return;
		}
		if(head->next==NULL) 
		{	printf("\t\t���Ա��Ѿ�Ϊ�գ�");
			return;
		}
		q=head;
		p=head->next;
		while(p!=NULL&&p->data!=x)
		{	q=p;
			p=p->next;
		}
		if(p!=NULL)
		{	q->next=p->next;
			delete p;
			n--;
			printf("\t\t %c�Ѿ���ɾ����",x);
		}
		else
			printf("\t\tδ�ҵ���\n");
}

void ShowList()								// ��ʾ���Ա�
{	node *p=head;
		printf("\n\t\t��ʾ���Ա������Ԫ�أ�");
		if(head->next==NULL||p==NULL)
			printf("\n\t\t����Ϊ�գ�\n");
		else
		{
			printf("\n\t\t");
			while(p->next!=NULL)
			{	printf("%5c",p->next->data);
				p=p->next;
			}
		}
}

void SearchList(char x)						// �������Ա�Ԫ��
{	node *p;
		int i=1;
		if(head==NULL) 
		{	printf("\t\t�������磡\n");
			return;
		}
		if(head->next==NULL) 
		{	printf("\t\t���Ա�Ϊ�գ�û���κ����ݣ�");
			return;
		}
		p=head->next;
		while(p!=NULL&&p->data!=x)
		{	p=p->next;
			i++;
		}
		if(p!=NULL)
			printf("\t\t �ڵ�%dλ���ҵ�ֵΪ%c�Ľ�㣡",i,x);
		else
			printf("\t\tδ�ҵ�ֵΪ%c�Ľ�㣡\n",x);
}

void main()
{	head=NULL;
		int choice,i,j=1;
		char x;
		while(j)
		{	printf("\n\n\n\n");
			printf("\t\t\t   �� �� �� �� ϵ ͳ\n");
			printf("\n\t\t**********************************");
			printf("\n\t\t*          1----------��     ��            *");
			printf("\n\t\t*          2----------��     ��            *");
			printf("\n\t\t*          3----------ɾ     ��            *");
			printf("\n\t\t*          4----------��     ʾ            *");
			printf("\n\t\t*          5----------��     ��            *");
			printf("\n\t\t*          6----------�� �� ��            *");
			printf("\n\t\t*          0----------��     ��            *");
			printf("\n\t\t**********************************\n");
			printf("\t\t��ѡ��˵���(0--6)��");
			scanf("%d",&choice);getchar();
			if(choice==1)
				CreateList();
			else if (choice==2)
			{	printf("\n\t\t�������λ��i����ֵx(�����ʽ��i��x):");
				scanf("%d,%c",&i,&x);
				InsList(i,x);
			}
			else if (choice==3)
			{	printf("\n\t\t������Ҫɾ������ֵ��");
				scanf("%c",&x);
				DelList(x);
			}
			else if (choice==4)
				if(head==NULL)
					printf("\n\t\t���Ƚ������Ա�");
				else
				    ShowList();
			else if (choice==5)
			{	printf("\n\t\t������Ҫ���ҵ�Ԫ�أ�");
				scanf("%c",&x);
				SearchList(x);
			}
			else if (choice==6)
			{	printf("\n\t\t��Ϊ%d",n);
			}
			else if (choice==0)
				j=0;
			else 
				printf("\n\t\t����������������룡\n");
		}
}
