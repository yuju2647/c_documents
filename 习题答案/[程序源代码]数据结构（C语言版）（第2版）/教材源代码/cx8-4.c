#include<stdio.h>
#include<malloc.h>
typedef struct
{
  int key;        /*��¼�Ĺؼ�������Ϊ����*/
  char data;      /*����Ԫ����Ϣ���� */
}Record;

int hp(int m)  /*��С�ڵ���m������p*/
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
 return key%p;   /*��������*/
}

void inputdata(Record **r,int n)   /*��̬��������*/
{
  int i;
  (*r)=(Record*)malloc(n*sizeof(Record));
  printf("������%d����ɢ�е�����:\n",n);
  for(i=0;i<n;i++)
  scanf("%d",&((*r)[i].key));
}

void createhashtable(Record **ht,Record *r,int n,int m,int p)
{ 
   int i,j;                    /*ͨ�������������������е�ַ*/
   (*ht)=(Record*)malloc(m*sizeof(Record));
   for(i=0;i<m;i++) 
   (*ht)[i].key=0;           /*��Źؼ��ֵ������ʼ�� */
   for(i=0;i<n;i++)
   {
	     j=hi(r[i].key,p);        /*�Գ����������õ�r[i].key�ĵ�ַ */
     while((*ht)[j].key!=0)  /*����̽�ⷨ�����ͻ*/
     j=(j+1)%m;
     (*ht)[j].key=r[i].key;
   }
}

int search(Record *ht,int key,int p,int *k)/* ɢ�б�Ĳ��� */
{
  int i;
  *k=1;
  i=hi(key,p);
  while(ht[i].key!=0&&ht[i].key!=key) /*��ַ���м�¼�ؼ��ֵ������ڴ���ؼ���*/
 { 
	   i++;                         
	   ++*k;                         /*�Ƚϴ�����1 */
  }
  if(ht[i].key==0)   /*��ַ���޼�¼�ؼ��֣�����ʧ��*/
	    return -1;
  else 
	   return i;   /*��ַ���м�¼�ؼ����ҵ��ڴ���ؼ��֣����ҳɹ����������ַ*/
}

main()
{
   Record *r,*ht;
   int key,i,n,m,p,k;
   char ch;
   printf("\n�����¼����n��ɢ�б���m(n<=m):");
   scanf("%d %d",&n,&m);
   inputdata(&r,n);
   p=hp(m);                     /*ȷ��С��ɢ�б�m������p */
   printf("���С�ڱ���������%d",p);
   createhashtable(&ht,r,n,m,p);    /*����ɢ�б�*/
   printf("\n�õ���ɢ�б�Ϊ��");
   printf("\n  λ  ��:");
   for(i=0;i<m;i++) 
	   printf("%5d",i);
   printf("\n  �ؼ���:");
   for(i=0;i<m;i++) 
	   printf("%5d",ht[i].key);
   do{
      printf("\n����Ҫ���ҵļ�¼�Ĺؼ���:"); /*�������Ԫ��*/
      scanf("%d",&key);
      i=search(ht,key,p,&k);
      if(i!=-1)
      { 
	        printf("���ҳɹ�,λ���ǣ�%d",i);/*������ҳɹ���λ��*/
        printf("\n�Ƚϴ����ǣ�%d\n",k);
	      }
      else
      { 
	       printf("����ʧ��");
       printf("\n�Ƚϴ����ǣ�%d\n",k);
      }
    ch=getchar();
   }while(ch=='y'||ch=='Y');  /*�Ƿ����?*/   
 } 
�������н����
�����¼����n��ɢ�б���m(n<=m)��7 9���س���
������7����ɢ�е�����:
14  21  50  24  36  68  80
���С�ڱ��������ǣ�7
�õ���ɢ�б�Ϊ��
λ  ��  0   1   2   3   4   5   6   7   8 
�ؼ��� 14  21  50  24  36  68  80  0   0 
����Ҫ���ҵļ�¼�Ĺؼ��֣�36���س���
���ҳɹ�,λ���ǣ�4
�Ƚϴ����ǣ�4
����������Ҽ�¼�Ĺؼ���Ϊ37����ʾ��
����ʧ��
�Ƚϴ����ǣ�6
