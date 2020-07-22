#include<stdio.h>
#include<malloc.h>
#define Maxsize 20
typedef struct node//ͼ ��ڵ���������
{
	int advertex;
	struct node *next;
}NODE;
typedef struct t//ͼ ͷ�ڵ� �������� 
{
	char data[4];
	NODE *next;
}HEAD_NODE;
typedef struct web//�� ��ڵ� ��������
{
	int advertex;
	int weight;
	struct web *next;
}NETWORK_NODE;
typedef struct w//�� ͷ�ڵ���������
{
	char data[4];
	NETWORK_NODE *next;
}NETWORK_HEAD_NODE;

//��������//


//ȫ�ֱ�������//
int recording_spot[Maxsize];

int main()
{
	int chioce;
	printf("ͼ/�� �����㷨\n\n�Ƚ�����ͼ/����Ҫ��������ͼ--1��������--2��");
	scanf("%d",&chioce);
	getchar();
	HEAD_NODE ver[Maxsize];
	NETWORK_HEAD_NODE net[Maxsize];
	if(chioce==1)
	{
		build_graph(ver);//����ͼ
		printf("���뿪ʼ�����ڵ㣺");
		int start;
		scanf("%d",&start);
		getchar();
		printf("��������������������"); 
		traverse_graph(ver,start);
	}
	else
	build_network(net);//������ 
	
	return 0;
}
int build_graph(HEAD_NODE *p)//���� �ڽӱ���ṹ ��ͼ 
{
	printf("\n�����붥�����ͱ�����������ʽΪ��������,������");
	int size,brim;
	scanf("%d,%d",&size,&brim);
	getchar();//���� ���з� 
	init_recording_spot(size);//��ʼ�� ��¼�� ���� 	
	input_data(p,size);
	printf("���鶥��ֵ�������\n");
	int i;
	for(i=1;i<=size;i++)
	{
		printf("%d.  ",i);
		puts(p[i].data);
		printf("\n\n");
	}
	build_list(p,brim);
	printf("\n�����ڽӱ������\n\n");
	print_list(p,size);
}
int init_recording_spot(int n)//�� ��¼�ڵ� ����״̬ ������ ������ֵ Ϊ 0����ʾ δ������ 
{
	int i;
	for(i=1;i<=n;i++)
	{
		recording_spot[i]=0;
	}
	return 0;
} 
int input_data(HEAD_NODE *p,int size)//���ݶ��������������������Ԫ��ֵ 
{
	int i;
	for(i=1;i<=size;i++)//ѭ�����붥��ֵ����1��ʼ����0 
	{
	   printf("�� %d ����",i);
	   gets(p[i].data);
	   p[i].next=NULL;
	}
	return 0;
}
int build_list(HEAD_NODE *p,int brim)//���ݶ��������������������ڽӱ� 
{
	printf("Ҫ������������ͼ-1����������ͼ-2��");
	int chioce;
	scanf("%d",&chioce); 
	getchar();
	int i;
	if(chioce==1)
	{
		printf("\n��������ͼ\n");
		printf("\\n����ߣ������ʽΪ���������1,�������2 (�磺1,2  ��ʾ����1������2�ı�)\n\n"); 
		for(i=1;i<=brim;i++)
		{
			printf("�� %d ���ߣ�",i);
			int brim1,brim2;
			scanf("%d,%d",&brim1,&brim2);
			getchar();
			directed_set(p,brim1,brim2);
		}
	}
	else
	{
		printf("\n��������ͼ\n"); 
	    printf("\n����ߣ������ʽΪ���������1,�������2 (�磺1,2  ��ʾ����1������2�ı�)\n"); 
	    for(i=1;i<=brim;i++)
		{
			printf("�� %d ���ߣ�",i);
			int brim1,brim2;
			scanf("%d,%d",&brim1,&brim2);
			getchar();
			undirected_set(p,brim1,brim2);
		}

	}
	return 0;
}
int directed_set(HEAD_NODE *p,int brim1,int brim2)//��������ͼʱ ���������� 
{
	NODE *s;//���������µĽڵ�
	s=(NODE *)malloc(sizeof(NODE));
	s->advertex=brim2;
	s->next=p[brim1].next;
	p[brim1].next=s;
	return 0; 
}
int undirected_set(HEAD_NODE *p,int brim1,int brim2)//��������ͼʱ ���������� 
{
	NODE *s;//ͬ�����������µĽڵ�
	s=(NODE *)malloc(sizeof(NODE));//�Զ���p[brim1]Ϊͷ�ڵ�ָ��brim2 
	s->advertex=brim2;
	s->next=p[brim1].next;
	p[brim1].next=s;
	s=(NODE *)malloc(sizeof(NODE));//�Զ���p[brim2]Ϊͷ�ڵ�ָ��brim1 
	s->advertex=brim1;
	s->next=p[brim2].next;
	p[brim2].next=s;
	return 0;
}
int print_list(HEAD_NODE *p,int size)//��ӡ�� �ڽӱ� 
{
	NODE *r;//���ڱ���
	int i;
	for(i=1;i<=size;i++)
	{
		printf("���� %s |",p[i].data);
		r=p[i].next;
		while(r)
		{
			printf("   ---> %s",p[r->advertex].data);
			r=r->next;
		}
		printf("\n\n");
	}
	return 0;
}
////////////////����������////////////////// 
int build_network(NETWORK_HEAD_NODE *p)//�����ڽӱ���ṹ�� �� 
{
	printf("\n�����붥�����ͱ����������ʽΪ��������,������");
	int size,brim;
	scanf("%d,%d",&size,&brim);
	getchar();
	init_HEAD_NODE(p,size);
	printf("\n���鶥���������\n");
	int i;
	for(i=1;i<=size;i++)
	{
		printf("%d.  ",i);
		puts(p[i].data);
		printf("\n");
	}
	build_network_list(p,brim); 
	printf("\n���齨�����\n");
	print_network(p,size);
	return 0;
}
int init_HEAD_NODE(NETWORK_HEAD_NODE *p,int size)//�������и��������ֵ 
{
	int i;
	for(i=1;i<=size;i++)
	{
		printf("�� %d �����㣺",i);
		gets(p[i].data);
		p[i].next=NULL;
	}
	return 0;
}
int build_network_list(NETWORK_HEAD_NODE *p,int brim)//���� �� ���ڽӱ� 
{
	printf("Ҫ��������������--1,����������--2��");
	int chioce;
	scanf("%d",&chioce);
	getchar();//���ɻ��з� 
	int i;
	if(chioce==1)
	{
		printf("\n����������\n");
		printf("\n����ߣ������ʽΪ������1,����2,����1������2��Ȩֵ (�� 1,4,2 ��ʾ����1������4������ߣ���ȨֵΪ2)\n");	
		for(i=1;i<=brim;i++)
		{
			printf("����� %d ���ߣ�",i);
			int brim1,brim2,weight;
			scanf("%d,%d,%d",&brim1,&brim2,&weight);
			getchar();
			network_directed_set(p,brim1,brim2,weight);
		} 
	}
	else
	{
		printf("\n����������\n");
		printf("\n����ߣ������ʽΪ������1,����2,����1�Ͷ���2���Ȩֵ (�� 1,4,2 ��ʾ����1������4�ıߣ���ȨֵΪ2)\n");	
		for(i=1;i<=brim;i++)
		{
			printf("����� %d ���ߣ�",i);
			int brim1,brim2,weight;
			scanf("%d,%d,%d",&brim1,&brim2,&weight);
			getchar();
			network_undirected_set(p,brim1,brim2,weight);
		}
	}
	return 0;
}
int network_directed_set(NETWORK_HEAD_NODE *p,int brim1,int brim2,int weight)//������ �������� 
{
	NETWORK_NODE *s;
	s=(NETWORK_NODE *)malloc(sizeof(NETWORK_NODE));
	s->advertex=brim2;
	s->weight=weight;
	s->next=p[brim1].next;
	p[brim1].next=s;
	return 0;
}
int network_undirected_set(NETWORK_HEAD_NODE *p,int brim1,int brim2,int weight)//������ �������� 
{
	NETWORK_NODE *s;
	s=(NETWORK_NODE *)malloc(sizeof(NETWORK_NODE));
	s->advertex=brim2;
	s->weight=weight;
	s->next=p[brim1].next;
	p[brim1].next=s;
	////////////////
	s=(NETWORK_NODE *)malloc(sizeof(NETWORK_NODE));
	s->advertex=brim1;
	s->weight=weight;
	s->next=p[brim2].next;
	p[brim2].next=s;
	return 0;
}
int print_network(NETWORK_HEAD_NODE *p,int size)
{
	int i;
	for(i=1;i<=size;i++)
	{
		printf("���� %s  |",p[i].data);
		NETWORK_NODE *r;
		r=p[i].next;
		while(r)
		{
			printf("   --%d-->%s",r->weight,p[r->advertex].data);
			r=r->next;
		}
		printf("\n\n");
	}
	return 0;
}
int traverse_graph(HEAD_NODE *p,int i)//����ͼ���� 
{
	NODE *r;
	r=p[i].next;
	printf("%s  ",p[i].data);//����������ýڵ�ֵ 
	recording_spot[i]=1; 
	while(r)
	{
		if(!recording_spot[r->advertex])
		{
			traverse_graph(p,r->advertex);//�ݹ� 
			r=r->next;
		}
		else
		{
			r=r->next;
		}
	}
}
