#include<stdio.h>
#include<malloc.h>
typedef struct
{
  int key;        /*记录的关键字域设为整型*/
  char data;      /*数据元素信息域定义 */
}Record;

int hp(int m)  /*求小于等于m的质数p*/
{
	 int i,p,flag;
for(p=m;p>=2;p--)
	 { 
	    for(i=2,flag=1;i<=p/2&&flag;i++)
    if(p%i==0) flag=0;
    if(flag==1) break;
 }
    return p;
}

int hi(int key,int p)
{  
 return key%p;   /*除留余数*/
}

void inputdata(Record **r,int n)   /*动态创建序列*/
{
  int i;
  (*r)=(Record*)malloc(n*sizeof(Record));
  printf("请输入%d个待散列的数据:\n",n);
  for(i=0;i<n;i++)
  scanf("%d",&((*r)[i].key));
}

void createhashtable(Record **ht,Record *r,int n,int m,int p)
{ 
   int i,j;                    /*通过除留余数法分配序列地址*/
   (*ht)=(Record*)malloc(m*sizeof(Record));
   for(i=0;i<m;i++) 
   (*ht)[i].key=0;           /*存放关键字的数组初始化 */
   for(i=0;i<n;i++)
   {
	     j=hi(r[i].key,p);        /*以除留余数法得到r[i].key的地址 */
     while((*ht)[j].key!=0)  /*线性探测法解决冲突*/
     j=(j+1)%m;
     (*ht)[j].key=r[i].key;
   }
}

int search(Record *ht,int key,int p,int *k)/* 散列表的查找 */
{
  int i;
  *k=1;
  i=hi(key,p);
  while(ht[i].key!=0&&ht[i].key!=key) /*地址中有记录关键字但不等于待查关键字*/
 { 
	   i++;                         
	   ++*k;                         /*比较次数加1 */
  }
  if(ht[i].key==0)   /*地址中无记录关键字，查找失败*/
	    return -1;
  else 
	   return i;   /*地址中有记录关键字且等于待查关键字，查找成功，返回其地址*/
}

main()
{
   Record *r,*ht;
   int key,i,n,m,p,k;
   char ch;
   printf("\n输入记录个数n和散列表长度m(n<=m):");
   scanf("%d %d",&n,&m);
   inputdata(&r,n);
   p=hp(m);                     /*确定小于散列表长m的质数p */
   printf("这个小于表长的质数是%d",p);
   createhashtable(&ht,r,n,m,p);    /*建立散列表*/
   printf("\n得到的散列表为：");
   printf("\n  位  置:");
   for(i=0;i<m;i++) 
	   printf("%5d",i);
   printf("\n  关键字:");
   for(i=0;i<m;i++) 
	   printf("%5d",ht[i].key);
   do{
      printf("\n输入要查找的记录的关键字:"); /*输入查找元素*/
      scanf("%d",&key);
      i=search(ht,key,p,&k);
      if(i!=-1)
      { 
	        printf("查找成功,位置是：%d",i);/*输出查找成功的位置*/
        printf("\n比较次数是：%d\n",k);
	      }
      else
      { 
	       printf("查找失败");
       printf("\n比较次数是：%d\n",k);
      }
    ch=getchar();
   }while(ch=='y'||ch=='Y');  /*是否继续?*/   
 } 
程序运行结果：
输入记录个数n和散列表长度m(n<=m)：7 9（回车）
请输入7个待散列的数据:
14  21  50  24  36  68  80
这个小于表长的质数是：7
得到的散列表为：
位  置  0   1   2   3   4   5   6   7   8 
关键字 14  21  50  24  36  68  80  0   0 
输入要查找的记录的关键字：36（回车）
查找成功,位置是：4
比较次数是：4
若输入待查找记录的关键字为37则显示：
查找失败
比较次数是：6
