#include <stdio.h>
#define max_len 20 
typedef struct
{
	int  key;     /* 假设关键字的数据类型为整型*/ 
	char data;     /*记录的信息域定义 */
}Record;
typedef struct
{
	Record r[max_len+1];  /* r[0]为工作单元 */
	int length;
}seqTable;

int BinarySearch(seqTable sq,  int k)
/*在有序表sq中折半查找其关键字等于k的元素，
若找到，则函数值为该元素在表中的位置*/
{
	int low,high,mid;
	low=1;  
	high=sq.length;   /*设置初始查找区间*/
	while(low<=high)
	{
		mid=(low+high)/2;
		if(sq.r[mid].key<k)  
		  low=mid+1;     /*继续在右半区间进行查找*/
		else
		{ 
         if(sq.r[mid].key>k) 
	       high=mid-1;   /*未找到，则继续在左半区间进行查找*/
	     else            /*等于待查的关键字，查找结束*/
		   break;   
		}	
	}
   if(low>high)  
    return (0);  /*查找不成功，返回0作为结束标志*/
   else
	return (mid);
}

void main()
{
	seqTable sq;
	int rec,k,i,len,ch;
	printf("输入查找表的长度:");
	scanf("%d",&len);
	sq.length = len;
	printf("输入查找表的第%d条记录:\n",len);
	for(i=1;i<=len;i++)
	{
		scanf(" %d",&ch);
		sq.r[i].key=ch;
	}
	printf("请输入要查找的元素:");
	scanf("%d",&k);
	rec=BinarySearch(sq,k);
	if(rec==0)
      printf("该查找表中没有这条记录!\n");
	else
      printf("该记录在表中的位置为%d\n",rec);
	}

程序运行结果：
输入查找表的长度：8（回车）
输入8个记录的关键字值(数据之间用空格隔开):
5  12  16  20  24  28  31  35  36  42  46  50  58（回车）
输入要查找的元素：24（回车）
该元素在表中的位置为：5
若输入要查找的元素为32，则会显示该查找表中没有这条记录。
