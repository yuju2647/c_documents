/* ======================================== */
/*    程序: 2-2.c                           */
/*    顺序表上元素的删除操作                 */
/* ======================================== */
#include<stdio.h>
#include<malloc.h>
#define MAXLEN 100          /* MAXSIZE 要大于实际线性表的长度*/ 
typedef int elementtype;      	/*根据需要，elementtype也可以定义为其他任何类型*/
typedef struct               	/*定义线性表*/
{
	elementtype s[MAXLEN];  	/*定义线性表中元素，MAXLEN为线性表的最大容量*/
	int len;                  /*定义线性表的表长*/
}SqList;

/* ---------------------------------------- */
/*  元素的删除                */
/* ---------------------------------------- */
int  DelList(SqList *sql,int i,elementtype *x)
	/*在顺序表sql中删除第i个数据元素，并用指针参数x返回其值，
i的合法取值为1≤i≤sql.len*/    
{ 
	int k;
	if((i<1)||(i>sql->len))   
	{ 
		printf("删除位置不合法!");
		return(0);
	}
	*x = sql->s[i];  				/* 将删除的元素存放到x所指向的变量中*/
	for(k=i+1; i<=sql->len; k++)
		sql->s[k-1] = sql->s[k];  	/*将后面的元素依次前移*/
	sql->len--;
	return(1);
}

/* -------------------------------------------------------------- */
/*  主程序:创建顺序表，并在指定位置删除元素   */
/* -------------------------------------------------------------- - */
void main()
{
	SqList *seq;
	int p,r,*q,i;
	seq =(SqList*)malloc(sizeof(SqList));
	q=(int*)malloc(sizeof(int));
	printf("输入线性表的长度：");
	scanf("%d",&r);
	seq->len=r;
	printf("输入线性表的各元素值：\n");
	for(i=1; i<=seq->len; i++)
		/*赋线性表各元素初值，为与前概念描述一致，seq.s[0]闲置不用*/
	{
		scanf("%d",&seq->s[i]);
	}
	printf("输入要删除的元素位置：");
	scanf("%d",&p);
	DelList(seq,p,q);
	printf("删除的元素值为：%d\n",*q);
}

//程序运行结果：
//输入线性表的长度：6（回车）
//输入线性表的各元素值：
//9 10 2 3 5 7
//输入要删除的位置：2（回车）
//删除的元素为：10
