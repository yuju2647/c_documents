#include<stdio.h>
#include<malloc.h>
#define Maxsize 20
typedef struct node//图 表节点数据类型
{
	int advertex;
	struct node *next;
}NODE;
typedef struct t//图 头节点 数据类型 
{
	char data[4];
	NODE *next;
}HEAD_NODE;
typedef struct web//网 表节点 数据类型
{
	int advertex;
	int weight;
	struct web *next;
}NETWORK_NODE;
typedef struct w//网 头节点数据类型
{
	char data[4];
	NETWORK_NODE *next;
}NETWORK_HEAD_NODE;

//函数声明//


//全局变量定义//
int recording_spot[Maxsize];

int main()
{
	int chioce;
	printf("图/网 遍历算法\n\n先建立起图/网，要建立的是图--1，还是网--2：");
	scanf("%d",&chioce);
	getchar();
	HEAD_NODE ver[Maxsize];
	NETWORK_HEAD_NODE net[Maxsize];
	if(chioce==1)
	{
		build_graph(ver);//建立图
		printf("输入开始遍历节点：");
		int start;
		scanf("%d",&start);
		getchar();
		printf("深度优先搜索遍历结果："); 
		traverse_graph(ver,start);
	}
	else
	build_network(net);//建立网 
	
	return 0;
}
int build_graph(HEAD_NODE *p)//建立 邻接表储存结构 的图 
{
	printf("\n请输入顶点数和边数，输入格格式为：顶点数,边数：");
	int size,brim;
	scanf("%d,%d",&size,&brim);
	getchar();//吞噬 换行符 
	init_recording_spot(size);//初始化 记录点 数组 	
	input_data(p,size);
	printf("检验顶点值输入情况\n");
	int i;
	for(i=1;i<=size;i++)
	{
		printf("%d.  ",i);
		puts(p[i].data);
		printf("\n\n");
	}
	build_list(p,brim);
	printf("\n检验邻接表建立情况\n\n");
	print_list(p,size);
}
int init_recording_spot(int n)//将 记录节点 遍历状态 的数组 都赋初值 为 0，表示 未被遍历 
{
	int i;
	for(i=1;i<=n;i++)
	{
		recording_spot[i]=0;
	}
	return 0;
} 
int input_data(HEAD_NODE *p,int size)//根据顶点数，依次输入各顶点元素值 
{
	int i;
	for(i=1;i<=size;i++)//循环输入顶点值，从1开始不用0 
	{
	   printf("第 %d 个：",i);
	   gets(p[i].data);
	   p[i].next=NULL;
	}
	return 0;
}
int build_list(HEAD_NODE *p,int brim)//根据顶点数，边数，建立起邻接表 
{
	printf("要建立的是有向图-1，还是无向图-2：");
	int chioce;
	scanf("%d",&chioce); 
	getchar();
	int i;
	if(chioce==1)
	{
		printf("\n建立有向图\n");
		printf("\\n输入边，输入格式为：顶点序号1,顶点序号2 (如：1,2  表示顶点1到顶点2的边)\n\n"); 
		for(i=1;i<=brim;i++)
		{
			printf("第 %d 条边：",i);
			int brim1,brim2;
			scanf("%d,%d",&brim1,&brim2);
			getchar();
			directed_set(p,brim1,brim2);
		}
	}
	else
	{
		printf("\n建立无向图\n"); 
	    printf("\n输入边，输入格式为：顶点序号1,顶点序号2 (如：1,2  表示顶点1到顶点2的边)\n"); 
	    for(i=1;i<=brim;i++)
		{
			printf("第 %d 条边：",i);
			int brim1,brim2;
			scanf("%d,%d",&brim1,&brim2);
			getchar();
			undirected_set(p,brim1,brim2);
		}

	}
	return 0;
}
int directed_set(HEAD_NODE *p,int brim1,int brim2)//建立有向图时 单链表设置 
{
	NODE *s;//用来创建新的节点
	s=(NODE *)malloc(sizeof(NODE));
	s->advertex=brim2;
	s->next=p[brim1].next;
	p[brim1].next=s;
	return 0; 
}
int undirected_set(HEAD_NODE *p,int brim1,int brim2)//建立无向图时 单链表设置 
{
	NODE *s;//同样用来创建新的节点
	s=(NODE *)malloc(sizeof(NODE));//以顶点p[brim1]为头节点指向brim2 
	s->advertex=brim2;
	s->next=p[brim1].next;
	p[brim1].next=s;
	s=(NODE *)malloc(sizeof(NODE));//以顶点p[brim2]为头节点指向brim1 
	s->advertex=brim1;
	s->next=p[brim2].next;
	p[brim2].next=s;
	return 0;
}
int print_list(HEAD_NODE *p,int size)//打印出 邻接表 
{
	NODE *r;//用于遍历
	int i;
	for(i=1;i<=size;i++)
	{
		printf("顶点 %s |",p[i].data);
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
////////////////建立网操作////////////////// 
int build_network(NETWORK_HEAD_NODE *p)//建立邻接表储存结构的 网 
{
	printf("\n请输入顶点数和边数，输入格式为：顶点数,边数：");
	int size,brim;
	scanf("%d,%d",&size,&brim);
	getchar();
	init_HEAD_NODE(p,size);
	printf("\n检验顶点输入情况\n");
	int i;
	for(i=1;i<=size;i++)
	{
		printf("%d.  ",i);
		puts(p[i].data);
		printf("\n");
	}
	build_network_list(p,brim); 
	printf("\n检验建表情况\n");
	print_network(p,size);
	return 0;
}
int init_HEAD_NODE(NETWORK_HEAD_NODE *p,int size)//输入网中各个顶点的值 
{
	int i;
	for(i=1;i<=size;i++)
	{
		printf("第 %d 个顶点：",i);
		gets(p[i].data);
		p[i].next=NULL;
	}
	return 0;
}
int build_network_list(NETWORK_HEAD_NODE *p,int brim)//建立 网 的邻接表 
{
	printf("要建立的是有向网--1,还是无向网--2：");
	int chioce;
	scanf("%d",&chioce);
	getchar();//吞噬换行符 
	int i;
	if(chioce==1)
	{
		printf("\n建立有向网\n");
		printf("\n输入边，输入格式为：顶点1,顶点2,顶点1到顶点2的权值 (如 1,4,2 表示顶点1到顶点4的有向边，且权值为2)\n");	
		for(i=1;i<=brim;i++)
		{
			printf("输入第 %d 条边：",i);
			int brim1,brim2,weight;
			scanf("%d,%d,%d",&brim1,&brim2,&weight);
			getchar();
			network_directed_set(p,brim1,brim2,weight);
		} 
	}
	else
	{
		printf("\n建立无向网\n");
		printf("\n输入边，输入格式为：顶点1,顶点2,顶点1和顶点2间的权值 (如 1,4,2 表示顶点1到顶点4的边，且权值为2)\n");	
		for(i=1;i<=brim;i++)
		{
			printf("输入第 %d 条边：",i);
			int brim1,brim2,weight;
			scanf("%d,%d,%d",&brim1,&brim2,&weight);
			getchar();
			network_undirected_set(p,brim1,brim2,weight);
		}
	}
	return 0;
}
int network_directed_set(NETWORK_HEAD_NODE *p,int brim1,int brim2,int weight)//有向网 建表设置 
{
	NETWORK_NODE *s;
	s=(NETWORK_NODE *)malloc(sizeof(NETWORK_NODE));
	s->advertex=brim2;
	s->weight=weight;
	s->next=p[brim1].next;
	p[brim1].next=s;
	return 0;
}
int network_undirected_set(NETWORK_HEAD_NODE *p,int brim1,int brim2,int weight)//无向网 建表设置 
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
		printf("顶点 %s  |",p[i].data);
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
int traverse_graph(HEAD_NODE *p,int i)//遍历图操作 
{
	NODE *r;
	r=p[i].next;
	printf("%s  ",p[i].data);//遍历，输出该节点值 
	recording_spot[i]=1; 
	while(r)
	{
		if(!recording_spot[r->advertex])
		{
			traverse_graph(p,r->advertex);//递归 
			r=r->next;
		}
		else
		{
			r=r->next;
		}
	}
}
