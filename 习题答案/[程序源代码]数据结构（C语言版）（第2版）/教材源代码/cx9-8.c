#include <stdio.h>
typedef struct
{
	int key;    /* 假设关键字的数据类型为整型*/ 
	int data;   /* 假设记录的信息域的数据类型为字符型*/
}Record;

void   sift(Record r[],int k, int m)
/* 假设r[k..m]是以r[k]为根的完全二叉树，且分别以r[2k]和r[2k+1]为
左、右子树的小顶堆，调整r[k]，使整个序列r[k..m]满足堆的性质 */
{
	Record t;
	int i,j;
	int x;
	int finished;
	t= r[k];   /* 暂存"根"记录r[k] */ 
	x=r[k].key;
	i=k;
	j=2*i;
	finished=0;
		while(j<=m&&!finished  ) 
		{     
		if(j<m&&r[j].key>r[j+1].key ) 
		j=j+1;  /* 若存在右子树，且右子树根的关键字小，则沿右分支"筛选" */
		if (x<=r[j].key)
		 finished=1;       /*  筛选完毕  */ 
		else 
		{
			r[i] = r[j];
			i=j;
			j=2*i;
		}               /* 继续筛选 */ 
		}
		r[i] =t; /* r[k]填入到恰当的位置 */ 
}  

void   creatheap(Record r[], int length )
/*对记录数组r建堆，length为数组的长度*/
{
	int i,n;
    n=length;
	for(i=n/2;i>=1;--i)   /* 自第[n/2]个记录开始进行筛选建堆 */ 
	sift(r,i,n);
}

void  HeapSort(Record  r[],int length)
/* 对r[1..n]进行堆排序，执行本算法后，r中记录按关键字由大到小有序排列 */ 
{
	int i,n;
	Record b;
	creatheap(r, length);
	n=length;
	for (i=n;i>=2;--i) 
	{
		b=r[i];              /* 将堆顶记录和堆中的最后一个记录互换 */ 
		r[i]= r[1];
		r[1]=b; 
		sift(r,1,i-1);  /* 进行调整，使r[1..i-1]变成堆 */ 
	}
}

void main()
{
	int i,j;
	Record r[20];
	int len;
	printf("输入待排序记录的长度:");
	scanf("%d",&len);
    printf("输入%d个记录的关键字值(数据之间用空格隔开):\n",len);
	for(i=1;i<=len;i++)
	{
		scanf(" %d",&j);
		r[i].key=j;
	}
	HeapSort(r,len);
	printf("堆排序输出：\n");
	for(i=1;i<=len;i++)
	printf("%d  ",r[i].key);
	printf("\n");	
}

程序运行结果：
输入待排序记录的长度：8（回车）
输入8个记录的关键字值(数据之间用空格隔开):
53  36  48  36  60  7  18  41（回车）
堆排序输出：
60  53  48  	41  36  36  18  7
