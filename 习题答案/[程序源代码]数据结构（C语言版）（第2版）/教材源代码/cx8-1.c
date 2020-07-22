#include <stdio.h>
#define max_len 20 
typedef struct
{
	int  key;     /* 假设关键字的数据类型为整型*/ 
	char data;     /*记录的信息域定义 */
}Record;

typedef struct
{
	Record  r[max_len+1];  /* r[0]未存放记录 */
	int length;
}seqTable;

int SeqSearch(seqTable  st,  int  k)
/*在顺序表st中顺序查找其关键字等于k的元素,
若找到,则函数值为该元素在表中的位置,否则为0*/
{
	int i;
	st.r[0].key=k; 
	i=st.length;
	while (st.r[i].key!=k) i- -;
	return(i);
}

void main()
{
	seqTable st;
	int rec,k,i,len,ch;	
	printf("输入查找表的长度:");
	scanf("%d",&len);
	st.length=len;
printf("输入%d个记录的关键字值(用空格隔开):\n",len);
	for(i=1; i<=len; i++)
	{
		scanf(" %d",&ch);
		st.r[i].key = ch;
	}
	printf("输入要查找的元素:");
	scanf(" %d",&k);
rec=SeqSearch(st,k);
	if(rec==0)
	 printf("该元素不存在!\n");
	else
	 printf("该元素在表中的位置为：%d\n",rec);
}

程序运行结果：
输入查找表的长度：8（回车）
输入8个记录的关键字值(数据之间用空格隔开):
6   17   8  53  27  98  60  80  （回车）
输入要查找的元素：53（回车）
该元素在表中的位置为：4
若输入要查找的元素为5，则会显示该元素不存在。
