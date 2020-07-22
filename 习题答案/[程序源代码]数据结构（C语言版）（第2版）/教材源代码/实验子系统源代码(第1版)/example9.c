#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define L 8                          // ���������Ԫ�ظ���
#define FALSE 0
#define TURE 1
typedef struct
{	int key;
		char otherinfo;
}RecType;

typedef RecType Seqlist[L+1];
int num;
Seqlist R;
void Insertsort();
void Bubblesort();
void QuickSort(int low,int high);
void Shellsort();
void Selectsort();
void Mergesort();
int Partition(int i,int j);
void Heap();

void main()                          // ������ϵͳ������
{	Seqlist S;
		int i,k;
		char ch1,ch2,q;
		printf("\n\t������%d�����������ݣ�(���س�����)\n\t",L);
		for(i=1;i<=L;i++)
    { scanf ("%d",&S[i].key);getchar ();printf("\t");
		}
	printf("\n\t���������Ѿ��������!");
		ch1='y';
	while (ch1=='y'||ch1=='Y')
	{ printf ("\n\n\n\n\n");
	printf ("\t\t\t\t�� �� �� ϵ ͳ\n");
    printf ("\n\t\t**********************************************");
	printf ("\n\t\t*           1-------------������������             *");
    printf ("\n\t\t*           2-------------ֱ�Ӳ�������             *");
	printf ("\n\t\t*           3-------------ϣ ��  �� ��             *");
	printf ("\n\t\t*           4-------------ð ��  �� ��             *");
	printf ("\n\t\t*           5-------------�� ��  �� ��             *");
	printf ("\n\t\t*           6-------------ѡ ��  �� ��             *");
	printf ("\n\t\t*           7-------------�� ��  �� ��             *");
	printf ("\n\t\t*           8-------------��   ��   ��             *");
	printf ("\n\t\t*           0-------------��        ��             *");
	printf ("\n\t\t**********************************************");
	printf ("\n\t\t\t ��ѡ��˵��ţ�0--8����");
	  scanf ("%c",&ch2);getchar();
			for(i=1;i<=L;i++)
				R[i].key=S[i].key;
		switch(ch2)
			{
			case '1':
			printf("\n\t������%d�����������ݣ�(���س�����)\n\t",L);
				for(i=1;i<=L;i++)
				{ scanf("%d",&S[i].key);getchar();printf("\t");
				}
			printf("\n\t���������Ѿ��������!");
				break;
			case '2':Insertsort();break;
		case '3':Shellsort();break;
			case '4':Bubblesort();break;
			case '5':
				printf("\n\t��δ���������Ϊ(�س�����)��");
			for(k=1;k<=L;k++)
				printf("%5d",R[k].key);
				getchar();printf("\n");
			num=0;QuickSort(1,L);break;
			case '6':Selectsort();break;
			case '7':Mergesort();break;
		case '8':Heap();break;
			case '0':ch1='n';break;
			default:printf("\t���������\n");
		}
			if(ch2!='0')
			{if(ch2=='2'||ch2=='3'||ch2=='4'||ch2=='5'||ch2=='6'||ch2=='7'||ch2=='8')
				printf("\n\t������ʾ������!\n");
			printf("\n\t�밴�س����������˵�...");
				q=getchar();
				if(q!='\xA')
				{	getchar();ch1='n';
			}
			}
		}
}

void Insertsort()                       // ֱ�Ӳ�������
{	int i,j,k,m=0;
		printf("\n\t��δ���������Ϊ(�س�����)��");
	for(k=1;k<=L;k++)
		printf("%5d",R[k].key);
	getchar();
		printf("\n");
	for(i=2;i<=L;i++)
    { if(R[i].key<R[i-1].key)
			{ 	R[0]=R[i];j=i-1;
				while(R[0].key<R[j].key)
			{ R[j+1]=R[j];
				  j--;
				}
				R[j+1]=R[0];
		}
			m++;
			printf("\t��%d��������Ϊ(�س�����)��",m);
		for(k=1;k<=L;k++)
				printf("%5d",R[k].key);
			getchar();printf("\n");
	}
		printf("\n\n");
	printf("\t�����������ǣ�");
		for(i=1;i<=L;i++)
			printf("%5d",R[i].key);
	printf("\n");
}

void Bubblesort()                      // ð������
{	int i,j,k;
		int exchange;
		printf("\n\t��δ���������Ϊ(�س�����)��");
		for(k=1;k<=L;k++)
			printf("%5d",R[k].key);
	getchar();printf("\n");
		for(i=1;i<L;i++)
	{	exchange=FALSE;
			for(j=L;j>=i+1;j--)
				if(R[j].key<R[j-1].key)
				{	R[0].key=R[j].key;
					R[j].key=R[j-1].key;
				R[j-1].key=R[0].key;
					exchange=TURE;
				}
		if(exchange)
			{	printf("\t��%d��������Ϊ(�س�����)��",i);
				for(k=1;k<=L;k++)
					printf("%5d",R[k].key);
			getchar();printf("\n");
			}
	}
		printf("\n\n");
	printf("\t�����������ǣ�");
		for(i=1;i<=L;i++)
		printf("%5d",R[i].key);
		printf("\n");
}

int Partition(int i,int j)                  // ��������
{	RecType pirot=R[i];
		while(i<j)
		{  while(i<j&&R[j].key>=pirot.key)  
				j--;
		if(i<j)  
				R[i++]=R[j];
			while(i<j&&R[i].key<=pirot.key)  
				i++;
		if(i<j)  
				R[j--]=R[i];
	}
		R[i]=pirot;
	return i;
}

void QuickSort(int low,int high)
{	int pirotpos,k;
		if(low<high)
		{	pirotpos=Partition(low,high);
			num++;
			printf("\t��%d��������Ϊ(�س�����)��",num);
		for(k=1;k<=L;k++)
				printf("%5d",R[k].key);
			getchar();printf("\n");
		QuickSort(low,pirotpos-1);
			QuickSort(pirotpos+1,high);
		}
	printf("\n\n");
		printf("\t�����������ǣ�");
	for(k=1;k<=L;k++)
			printf("%5d",R[k].key);
	printf("\n");
}

void Selectsort()						// ѡ������
{	int i,j,k,h;
	printf("\n\t��δ���������Ϊ(�س�����)��");
		for(k=1;k<=L;k++)
			printf("%5d",R[k].key);
	getchar();printf("\n");
		for(i=1;i<L;i++)
    {	h=i;
			for(j=i+1;j<=L;j++)
				if(R[j].key<R[h].key)   
				h=j;
			if(h!=j)
			{ R[0]=R[i];R[i]=R[h];R[h]=R[0];
		}
			printf("\t��%d��������Ϊ(�س�����)��",i);
			for(k=1;k<=L;k++)
				printf("%5d",R[k].key);
		getchar();printf("\n");
		}
	printf("\n\n");
		printf("\t�����������ǣ�");
	for(i=1;i<=L;i++)
			printf("%5d",R[i].key);
	printf("\n");
}

void Merge(int low,int mm,int high)		// �鲢����
{	int i=low,j=mm+1,p=0;
		RecType  *R1;
	R1=(RecType * )malloc((high-low+1) *sizeof(RecType));
		if(!R1)
		printf("\t�ڴ���������!");
		while(i<=mm&&j<=high)
			R1[p++]=(R[i].key<=R[j].key)?R[i++]:R[j++];
	while(i<=mm)
			R1[p++]=R[i++];
	while(j<=high)
			R1[p++]=R[j++];
		for(p=0,i=low;i<=high;p++,i++)   
			R[i]=R1[p];
}

void MergePass(int length)
{	int i;
		for(i=1;i+2*length-1<=L;i=i+2*length)
		    Merge(i,i+length-1,i+2*length-1);
		if(i+length-1<L)
	    Merge(i,i+length-1,L);
}

void Mergesort()
{	int length,k,m=0;
    printf("\n\t��δ���������Ϊ(�س�����)��");
		for(k=1;k<=L;k++)
		printf("%5d",R[k].key);
		getchar();printf("\n");
	for(length=1;length<L;length*=2)
    {	MergePass(length);
			m++;
			printf("\t��%d��������Ϊ(�س�����)��",m);
		for(k=1;k<=L;k++)
				printf("%5d",R[k].key);
			getchar();printf("\n");
	}
		printf("\n\n");
	printf("\t�����������ǣ�");
		for(k=1;k<=L;k++)
			printf("%5d",R[k].key);
	printf("\n");
}


void Shellsort()                         // ϣ������
{	int i,j,gap,x,m=0,k;
    printf("\n\t��δ���������Ϊ(�س�����)��");
		for(k=1;k<=L;k++)
			printf("%5d",R[k].key);
	getchar();printf("\n");
		gap=L/2;
	while(gap>0)
		{
		for(i=gap+1;i<=L;i++)
			{	j=i-gap;
				while(j>0)
				{
					if(R[j].key>R[j+gap].key)
				{	x=R[j].key;R[j].key=R[j+gap].key;
						R[j+gap].key=x; 
						j=j-gap;
					}
					else 
						j=0;
			}
			}
			gap=gap/2;
		m++;
			printf("\t��%d��������Ϊ(�س�����)��",m);
			for(k=1;k<=L;k++)
				printf("%5d",R[k].key);
		getchar();printf("\n");
		}
	printf("\n\n");
		printf("\t�����������ǣ�");
	for(k=1;k<=L;k++)
			printf("%5d",R[k].key);
	printf("\n");
}

void CreateHeap(int root,int index)		// ����
{	int j,temp,finish;
		j=2*root;
	temp=R[root].key;
		finish=0;							// ��ʼ����δ�������
	while(j<=index&&finish==0)
		{ if(j<index)						// �������ӽ��
		if(R[j].key<R[j+1].key)
					j++;
			if(temp>=R[j].key)
			finish=1;					// �ѽ������
			else 
			{	R[j/2].key=R[j].key;		// ����㣽��ǰ���
				j=j*2;
		}
		}
	R[j/2].key=temp;					// ����㣽rootֵ
}

void HeapSort()                   
{	int i,j,temp,k;
		for(i=(L/2);i>=1;i--)				// ��������ת���ɶ�
  	CreateHeap(i,L);					// ����
	for(i=L-1,k=1;i>=1;i--,k++)
		{	temp=R[i+1].key;				// �ѣ�heap����rootֵ�����һ��ֵ����
			R[i+1].key=R[1].key;
		R[1].key=temp;
		CreateHeap(1,i);
		printf("\t��%d��������Ϊ(�س�����)��",k);
			for(j=1;j<=L;j++)
				printf("%5d",R[j].key);
		getchar();
			printf("\n");
		}
}

void Heap()								// ������
{	int i;
	printf("\t��δ���������Ϊ(�س�����)��");
		for(i=1;i<=L;i++)
			printf("%5d",R[i].key);
	printf("\n\t");
		getchar();
	HeapSort();
		printf("\n\n");
	printf("\t�����������ǣ�");
		for(i=1;i<=L;i++)
		printf("%5d",R[i].key);
		printf("\n");
}
