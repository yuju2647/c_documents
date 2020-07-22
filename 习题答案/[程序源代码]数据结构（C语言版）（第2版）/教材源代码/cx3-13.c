/* ======================================== */
/*    ����ʵ��: 3-13.c                       */
/*    �ϲ�����ѭ��������                     */
/* ======================================== */
#include <stdio.h>
#include <malloc.h>
typedef int elementtype;
typedef struct CNode    /*�ڵ����Ͷ���*/ 
{ 
	elementtype data;
	struct CNode  * next;
}CNode, *CLinkList;  /* CLinkListΪ�ṹָ������*/

CLinkList crt_linklist()/*����βָ���ʾ��ѭ������*/
{
	CLinkList list;
	int num;
	CNode *p;
	list=(CNode*)malloc(sizeof(struct CNode));
	list->data=-1;
	list->next=list;
	printf("������ѭ�������Ԫ�أ���-1��������\n"); 
	scanf("%d",&num);
	while(num != -1)
	{
		p=(CNode*)malloc(sizeof(struct CNode));
		p->data=num;
		p->next=list->next;
		list->next=p;
		scanf("%d",&num);
	}
	p=list;
	while(p->next!=list)
	{
		p=p->next;
	}
	return p;
}

CLinkList  merge_rear(CLinkList reara,CLinkList rearb)
{        /*���㷨����������βָ���ѭ��������β��������*/
	CNode *p;
	p=reara->next; /*��������reara��ͷ�ڵ��ַ*/
	reara->next=rearb->next->next;  /*����rearb�Ŀ�ʼ�ڵ���������reara���ն˽ڵ�֮��*/
	free(rearb->next);	        /*�ͷ�����rearb��ͷ�ڵ�*/
	rearb->next=p;  	             /*����reara��ͷ�ڵ���������rearb���ն˽ڵ�֮��*/
	return  rearb;		        /*������ѭ�������βָ��*/
}
void print(CLinkList cl)
{  
	CNode *p;
	p=cl->next->next;
	while(p!=cl->next)
	{
		printf("%d  ",p->data);
		p=p->next;
	}
	printf("\n");
}

void main()
{
	CLinkList clista,clistb,clistc;
	printf("����ѭ������A������������!\n");
	clista=crt_linklist();
	printf("������ѭ��������AΪ��\n");
	print(clista);
	printf("\n����ѭ������B������������!\n");
	clistb=crt_linklist();
	printf("������ѭ��������BΪ��\n");
	print(clistb);
	clistc=merge_rear(clista,clistb);
	printf("\n�ϲ����ѭ������Ϊ��\n");
	print(clistc);
}
//�������н����
//����ѭ������A������������!
//������ѭ�������Ԫ�أ���-1��������
//6  5  4  3  2  -1���س��� 
//������ѭ��������AΪ��
//2  3  4  5  6
//����ѭ������B������������!
//������ѭ�������Ԫ�أ���-1�������� 
//8  9  4  6  3  -1���س��� 
//������ѭ��������BΪ��
//3  6  4  9  8
//�ϲ����ѭ��������Ϊ��
//2  3  4  5  6  3  6  4  9  8
