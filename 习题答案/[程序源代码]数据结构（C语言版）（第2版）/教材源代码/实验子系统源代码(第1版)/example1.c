#include <stdio.h>
void main()
{
		int a[10],*p,*max,*min,k;
		for(p=a;p<a+10;p++)
		  scanf("%d",p);
		max=min=a;
		for(p=a+1;p<a+10;p++)
		{
			if(*max<*p)
				max=p;
			if(*min>*p)
				min=p;
		}
		p=a;
		if(*max==*(p+9)&&*min==*p)
		{
			k=*p;*p=*(p+9);*(p+9)=k;
		}
		else if(*max==*(p+9))
		{
			k=*max;*max=*p;*p=k;k=*min;*min=*(p+9);*(p+9)=k;
		}
		else
		{
			k=*min;*min=*(p+9);*(p+9)=k;k=*max;*max=*p;*p=k;
		}
		for(p=a;p<a+10;p++)
			printf("%4d",*p);
		printf("\n");
}

#include "stdio.h"
struct STUDENT 
{
		char id[10];
		char name[8];
		int score[3];
		double ave;
}stu[5];

void main()
{
		int num=5,i,j;
		for(i=0;i<num;i++)
		{
			printf("\t请输入第%d学生的数据",i+1);
			printf("\t学号：");
			scanf("%s",stu[i].id);
			printf("\t姓名：");
			scanf("%s",stu[i].name);
			int Tave=0;
			for(j=0;j<3;j++)
			{
				printf("\t第%d门课的成绩:",j+1);
				scanf("%d",&stu[i].score[j]);
				Tave+=stu[i].score[j];
			}
			stu[i].ave=(double)Tave/3.0;
		}
		printf("\n\t学号\t姓名\t成绩1\t成绩2\t成绩3\t平均分\n");
		for(i=0;i<num;i++)
		{
			printf("\t%s\t%s",stu[i].id,stu[i].name);	
			for(j=0;j<3;j++)
				printf("\t%d",stu[i].score[j]);
			printf("\t%f\n",stu[i].ave);
		}
}

#include <stdio.h>
void main()
{
		float a,b,c,t;
		scanf("%f,%f,%f",&a,&b,&c);
		if(a>b)
		{
			t=a;a=b;b=t;
		}
		if(a>c)
		{
			t=a,a=c,c=t;
		}
		if(b>c)
		{
			t=b;b=c;c=t;
		}
		printf("%5.2f,%5.2f,%5.2f",a,b,c);
}

#include <stdio.h>
void main()
{
		int i,a[10];
		for(i=0;i<=9;i++)
			a[i]=i;
		for(i=9;i>=0;i--)
			printf("%3d",a[i]);
		printf("\n");
}

#include <stdio.h>
void main()
{
		char diamond[][5]={{' ',' ','*'},{' ','*',' ','*'},{'*',' ',' ',' ','*'},
							{' ','*',' ','*'},{' ',' ','*'}};
		int i,j;
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
				printf("%c",diamond[i][j]);
			printf("\n");
		}
}
