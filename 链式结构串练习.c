#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct lstring
{
	char data;
	struct lstring *next;
};
//定义全局变量 

//声明函数 
struct lstring *Substr(struct lstring *head,int pos,int len);
struct lstring *index_(struct lstring *head,char *a);
struct lstring *replace(struct lstring *head,int pos,int len,struct lstring *head2);
struct lstring *concat(struct lstring *head1,struct lstring *head2);
int main()
{
	struct lstring head[3];
	int i;
	for(i=0;i<=2;i++)
	{
		head[i].next=NULL;
	}
	assign(&head[0],"I am a good student");
	printf("s1=");
	printlstring(&head[0]);
	printf("  length(s1)=%d\n",calculate(&head[0]));
	assign(&head[1],"teacher");
	printf("s2=");
	printlstring(&head[1]);
	printf("              length(s2)=%d\n",calculate(&head[1]));
	assign(&head[2],"yes");
	printf("s3=");
	printlstring(&head[2]);
	printf("                  length(s3)=%d\n",calculate(&head[2]));
	printf("Substr(s1,8,12)=");
	printlstring(Substr(&head[0],8,12));
	printf("\n");
	printf("index(s1,'B')=");
	printlstring(index_(&head[0],"B"));
	printf("\nindex(s3,'s')=");
	printlstring(index_(&head[2],"s"));
	printf("\nreplace(s1,13,7,s2)=");
	printlstring(replace(&head[0],13,7,&head[1]));
	printf("\nconcat(s1,s2)=");
	printlstring(concat(&head[0],&head[2]));
	printf("\nconcat(substr(s1,6,6),concat(s3,substr(s2,1,3)))=");
	printlstring(concat(Substr(&head[0],6,6),concat(&head[2],Substr(&head[1],1,3))));
	return 0;
}
int assign(struct lstring *head,char *a)
{
	struct lstring *r,*s;
	r=head;
	int i;
	for(i=0;a[i];i++)
	{
		s=(struct lstring *)malloc(sizeof(struct lstring));
		s->next=NULL;
		s->data=a[i];
		r->next=s;
		r=s;
	}
	return 0;
}
int printlstring(struct lstring *head)
{
	struct lstring *s;
	s=head->next;
	while(s)
	{
		putchar(s->data);
		s=s->next;
	}
	return 0;
}
int calculate(struct lstring *head)
{
	int i=0;
	struct lstring *s;
	s=head->next;
	while(s)
	{
		i++;
		s=s->next;
	}
	return i;
}
struct lstring *Substr(struct lstring *head,int pos,int len)
{
	if(pos<1||pos>calculate(head)||len<0||len>calculate(head)-pos+1)
	{
		printf("位置输入错误\n");
		getch();
		exit(1);
	}
	struct lstring *p,*s;
	p=head->next;
	int i=0;
	while(p)
	{
		i++;
		if(i==pos)
		break;
		p=p->next;
	}
	struct lstring *str,*r;
	str=(struct lstring *)malloc(sizeof(struct lstring));
	str->next=NULL;
	r=str;
	for(i=1;i<=len;i++)
	{
		s=(struct lstring *)malloc(sizeof(struct lstring));
		s->data=p->data;
		s->next=NULL;
		r->next=s;
		r=s;
		p=p->next;
	}
	return str;
}
struct lstring *index_(struct lstring *head,char *a)
{
	struct lstring *head1,*r,*s,*p;
	head1=(struct lstring *)malloc(sizeof(struct lstring));
	r=head1;
	p=head->next;
	while(p)
	{
		s=(struct lstring *)malloc(sizeof(struct lstring));
		s->next=NULL;
		s->data=p->data;
		r->next=s;
		r=s;
		p=p->next;
	}
	s=(struct lstring *)malloc(sizeof(struct lstring));
	s->next=NULL;
	s->data=*a;
	r->next=s;
	return head1;
}
struct lstring *replace(struct lstring *head,int pos,int len,struct lstring *head2)
{
	if(head->next==NULL)
	printf("head->next指针为空\n");
	if(pos<1||pos>calculate(head)||len<0||len>calculate(head)-pos+1)
	{
		printf("位置填写错误\n");
		getch();
		exit(1);
	}
	struct lstring *p,*head1,*r,*s;
	head1=(struct lstring *)malloc(sizeof(struct lstring));
	head1->next=NULL;
	r=head1;
	p=head;
	if(p==NULL)
	printf("p指针为空1\n");
	int i;
	for(i=1;i<=pos-1;i++)
	{
		p=p->next;
		s=(struct lstring *)malloc(sizeof(struct lstring));
		if(p==NULL)
		printf("p指针为空2\n");
		s->data=p->data;
		s->next=NULL;
		r->next=s;
		r=s;
	}
	struct lstring *q;
	q=head2->next;
	for(i=1;i<=len&&q;i++)
	{
		s=(struct lstring *)malloc(sizeof(struct lstring));
		s->data=q->data;
		s->next=NULL;
		r->next=s;
		r=s;
		q=q->next;
		p=p->next;
	}
	p=p->next;
	while(p)
	{
		s=(struct lstring *)malloc(sizeof(struct lstring));
		s->data=p->data;
		s->next=NULL;
		r->next=s;
		r=s;
		p=p->next;
	}
	return head1;
}
struct lstring *concat(struct lstring *head1,struct lstring *head2)
{
	struct lstring *head3;
	head3=(struct lstring *)malloc(sizeof(struct lstring));
	head3->next=NULL;
	struct lstring *p,*r,*s;
	r=head3;
	p=head1->next;
	while(p)
	{
		s=(struct lstring *)malloc(sizeof(struct lstring));
		s->next=NULL;
		s->data=p->data;
		r->next=s;
		r=s;
		p=p->next;
	}
	p=head2->next;
	while(p)
	{
		s=(struct lstring *)malloc(sizeof(struct lstring));
		s->next=NULL;
		s->data=p->data;
		r->next=s;
		r=s;
		p=p->next;
	}
	return head3;
}
