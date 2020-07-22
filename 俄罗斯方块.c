#include<stdio.h>
#include<malloc.h>
#include<windows.h>
#define N1 150000000ULL
#define N2 20000000ULL 
#define N3 100000000ULL
#define N4 110000000ULL
#define N5 90000000ULL
#define N6 70000000ULL
#define N7 50000000ULL
#define F 20000
typedef struct diamond
{
	int x;
	int y;
	struct diamond *next;
}diamond,*address;
//声明函数//
address buildone(int b,int a);
address godown(address head);
address goleft(address head);
address goright(address head);
//定义全局变量//
address HEAD,diamondSET,borderSET,line[35],leftSET,rightSET;
diamond TEMP;
int n1=N1,n2=N2,T=2,O=2,L1=2,L2=2,I=2,Z1=2,Z2=2,shape=1,f=0,d=0,g=0,h=0;
int main()//////////////////////////////////////
{
	startgame();
    buildplatform();
	control_center();
	at(0,30);
}////////////////////////////////////////////////
int at(int x,int y)//光标位置移动 
{
	COORD pos;
	HANDLE hOutput;
    pos.X=x;
    pos.Y=y;
    hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput,pos);
    return 0;
}
int control_center()//控制中心 
{
	initdiamondSET();
	buildline();
	int i,j,k=1,m=55,nextshape,score=0,s;
	at(10,2);
	printf("得 分");
	while(1)
	{
	   HEAD=buildone(shape,1);
	   printdiamonds(HEAD);
	   if(k%10==0)
	   m++;
	   nextshape=(3*k+m)%8;
	   while(nextshape==0)
	   {
	   	k++;
	   	nextshape=(3*k+m)%8;
	   }
	   wipenext();
	   at(98,2);
	   printf("下    一    个");
	   printdiamonds(buildone(nextshape,2)); 
	   i=downcircle(HEAD);
	   s=linefull();
	   score+=s;
	   at(10,4);
	   printf("      ");
	   at(10,4);
	   printf("  %d",score);
	   if(score>=100)
	   n1=N3;
	   else if(score>=200)
	   n1=N4;
	   else if(score>=300)
	   n1=N5;
	   else if(score>=400)
	   n1=N6;
	   else if(score>=500)
	   n1=N7;
	   else if(score>=600)
	   n1=N2;
	   /*at(2,14);
	   printf("       \n");
	   printf("       ");
	   at(2,14);
	   printf("s=%d\n",s);
	   printf("score=%d",score);*/
	   for(j=1;j<=N1;j++)
	   {}
	   shape=(3*k+m)%8;
	   k++;
	   if(ifendgame()==0)
	   {
	   	at(8,15);
	   	printf("游戏结束");
	   	break;
	   }
	}
	return 1;
}
int buildplatform()//建立左、右、下边界 
{
	int i,j;
	address head,r,s;
	head=(address)malloc(sizeof(diamond));
	head->next=NULL;
	r=head;
	for(j=1;j<=3;j++)
	{
		switch(j)
		{
			case 1:{
				   for(i=0;i<=28;i++)//建立界集 ，左 
		           {
			        s=(address)malloc(sizeof(diamond));
			        s->x=26;
			        s->y=i;
			        s->next=NULL;
			        r->next=s;
			        r=s;
		           }break;
		           }
		    case 2:{
		    	    for(i=26;i<=90;i+=2)// 建立界集，底 
		    	    {
		    	    s=(address)malloc(sizeof(diamond));
			        s->x=i;
			        s->y=29;
			        s->next=NULL;
			        r->next=s;
			        r=s; 
					}
				    break;
			       }
			case 3:{
				    for(i=28;i>=0;i--)//建立界集，右 
				    {
				    s=(address)malloc(sizeof(diamond));
			        s->x=90;
			        s->y=i;
			        s->next=NULL;
			        r->next=s;
			        r=s;	
					}
				    break;
			       }
		}	
	}
	borderSET=head;
	printdiamonds(head);
	return 1;
}
int initdiamondSET()//初始化方块坐标集单链表 
{
	address head;
	head=(address)malloc(sizeof(diamond));
	head->next=NULL;
	diamondSET=head;
	return 0;
}
address buildone(int b,int a)//建立一个俄罗斯方块 
{
	int i,X=64,Y=0;
	if(a==1)
	{
		X=64;
		Y=0;
	}
	else
	{
		X=104;
		Y=4;
	}
	address head,r,s;
	switch(b)
	{
		case 1:{
			    head=(address)malloc(sizeof(diamond));
	            head->next=NULL;
	            r=head;
	            s=(address)malloc(sizeof(diamond));
		        s->next=NULL;
		        s->x=X;
		        s->y=Y;
		        r->next=s;
		        r=s;
	            for(i=1;i<=2;i++)
	            {
		         Y++;
		         s=(address)malloc(sizeof(diamond));
		         s->next=NULL;
		         s->x=X;
		         s->y=Y;
		         r->next=s;
		         r=s;
	            }
	            s=(address)malloc(sizeof(diamond));
		        s->next=NULL;
		        s->x=X+2;
		        s->y=Y-1;
		        r->next=s;
		        r=s;
			    break;
		       }
		case 2:{
			    head=(address)malloc(sizeof(diamond));
			    r=head;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X;
			    s->y=Y;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X;
			    s->y=Y+1;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X;
			    s->y=Y+2;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X+2;
			    s->y=Y+2;
			    r->next=s;
			    s->next=NULL;
				break;
		       }
		case 3:{
			    head=(address)malloc(sizeof(diamond));
			    r=head;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X;
			    s->y=Y;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X;
			    s->y=Y+1;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X;
			    s->y=Y+2;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X-2;
			    s->y=Y+2;
			    r->next=s;
			    s->next=NULL;
			    break;
		       }
		case 4:{
			    head=(address)malloc(sizeof(diamond));
			    r=head;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X;
			    s->y=Y;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X+2;
			    s->y=Y;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X+2;
			    s->y=Y+1;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X+4;
			    s->y=Y+1;
			    r->next=s;
			    s->next=NULL;
			    break;
		       }
		case 5:{
			    head=(address)malloc(sizeof(diamond));
			    r=head;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X;
			    s->y=Y;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X-2;
			    s->y=Y;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X-2;
			    s->y=Y+1;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X-4;
			    s->y=Y+1;
			    r->next=s;
			    s->next=NULL;
			    break;
		       }
		case 6:{
			    head=(address)malloc(sizeof(diamond));
			    r=head;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X;
			    s->y=Y;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X+2;
			    s->y=Y;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X;
			    s->y=Y+1;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X+2;
			    s->y=Y+1;
			    r->next=s;
			    s->next=NULL;
				break;
			   }
		case 7:{
			    head=(address)malloc(sizeof(diamond));
			    r=head;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X;
			    s->y=Y;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X;
			    s->y=Y+1;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X;
			    s->y=Y+2;
			    r->next=s;
			    r=s;
			    s=(address)malloc(sizeof(diamond));
			    s->x=X;
			    s->y=Y+3;
			    r->next=s;
			    s->next=NULL;
				break;
		       }
	}
	return head;
}
int printcoordinates(address head)//打印单链表坐标（用于调试） 
{
	address p=head->next;
	while(p)
	{
		printf("(%d,%d) ",p->x,p->y);
		p=p->next;
	}
	return 0;
}
int printcoordinate(address p)//打印单个结点坐标 
{
	printf("(%d,%d) ",p->x,p->y);
	return 0;
}
int printdiamonds(address head)//打印出单链表中的坐标，即俄罗斯方块 
{
	address p=head->next;
	while(p)
	{
		printdiamond(p->x,p->y);
		p=p->next;
	}
	return 0;
}
int printdiamond(int x,int y)//在指定坐标上打印方块 
{
	at(x,y);
	printf("■");
	return 0;
}
int deletediamond(address s)//清除方块，不释放坐标结点 
{
	at(s->x,s->y);
	printf("  ");
	return 0;
}
int freediamond(address s)//清除方块并释放坐标结点 
{
	at(s->x,s->y);
	printf("  ");
	free(s);
	return 0;
}
int freediamonds(address head)//清除单链表坐标集对应的方块并释放单链表坐标集 
{
	address q,s;
	s=head;
	while(s->next!=NULL)
	{
	while(s->next!=NULL)
	{
		q=s;
		s=s->next;
	}
	q->next=NULL;
	freediamond(s);
	s=head;	
	}
	free(s);
	return 0;
}
int freelist(address head)//释放单链表 
{
	address q,s;
	s=head;
	while(s->next!=NULL)
	{
	while(s->next!=NULL)
	{
		q=s;
		s=s->next;
	}
	q->next=NULL;
	free(s);
	s=head;	
	}
	free(s);
	return 0;
}
address godown(address head)//实现俄罗斯方块向下运动 
{
	address r,p,s,nexthead;
	int i;
	r=head->next;
	nexthead=(address)malloc(sizeof(diamond));
	nexthead->next=NULL;
	p=nexthead;
	while(r)
	{
		s=(address)malloc(sizeof(diamond));
		s->x=r->x;
		s->y=r->y+1;
		s->next=NULL;
		p->next=s;
		p=s;
		r=r->next;
	}
	if(GetAsyncKeyState(VK_DOWN))
	{
		n1=F;
	}
	for(i=1;i<=n1;i++)
	{}
	if(GetAsyncKeyState(VK_LEFT))
	{
		freelist(nexthead);
		i=leftmove(head);
		if(i==0)
		return &TEMP;
	}
	else if(GetAsyncKeyState(VK_RIGHT))
	{
		freelist(nexthead);
		i=rightmove(head);
		if(i==0)
		return &TEMP;
	}
	if((ifdowncollide(nexthead))==0)///判断是否落地 
	{
		freelist(nexthead);
		n1=N1;
		connectSET(head);
		return &TEMP;
	}
	if(shape!=6)
	if(GetAsyncKeyState(VK_UP))
	{
		freelist(nexthead);
		i=deform(head);
		if(i==0)
		return &TEMP;
	}
	freediamonds(head);
	printdiamonds(nexthead);	
	return nexthead;
}
address goleft(address head)//实现俄罗斯方块向左运动 
{
	address nexthead,p,s,r;
	r=head->next;
	nexthead=(address)malloc(sizeof(diamond));
	nexthead->next=NULL;
	p=nexthead;
	while(r)
	{
		s=(address)malloc(sizeof(diamond));
		s->x=r->x-2;
		s->y=r->y;
		s->next=NULL;
		p->next=s;
		p=s;
		r=r->next;
	}	
	if((ifleftrightcollide(nexthead))!=1)//判断是否撞到左右边界 
	{
		
		freelist(nexthead);
		HEAD=head;
		return &TEMP;
	}
	else
	{
	int i;
	for(i=1;i<=n2;i++)
	{}
	freediamonds(head);
	printdiamonds(nexthead);
	return nexthead;		
	}
}
address goright(address head)//实习俄罗斯方块向右运动 
{
	address p,r,s,nexthead;
	r=head->next;
	nexthead=(address)malloc(sizeof(diamond));
	nexthead->next=NULL;
	p=nexthead;
	while(r)
	{
		s=(address)malloc(sizeof(diamond));
		s->x=r->x+2;
		s->y=r->y;
		s->next=NULL;
		p->next=s;
		p=s;
		r=r->next;
	}
	if((ifleftrightcollide(nexthead))!=1)//判断是否撞上左右边界 
	{
		HEAD=head;
		freelist(nexthead);
		return &TEMP;
	}
	else
	{
	int i;
	for(i=1;i<=n2;i++)
	{}
	freediamonds(head);
	printdiamonds(nexthead);
	return nexthead;	
	}
}
int downcircle(address head)//实现俄罗斯方块循环向下运动 
{
	int i;
	for(i=1;i<=100;i++)
	{
		head=godown(head);
		if(head==&TEMP)
		{
			return 0;
		}
		if(GetAsyncKeyState(VK_SPACE))
		{
			at(120,20);
			system("pause");
		}
		at(120,20);
		printf("                    ");
	}
}
int leftmove(address head)//实现俄罗斯方块循环向左运动 
{
	int i;
	head=goleft(head);
	if(head==&TEMP)
	{
		i=downcircle(HEAD);
		if(i==0)
		return 0;
	}		
	while(GetAsyncKeyState(VK_LEFT))
	{
		head=goleft(head);
		if(head==&TEMP)
		{
			i=downcircle(HEAD);
			if(i==0)
			return 0;
		}
	}
	i=downcircle(head);
	if(i==0)
	return 0;
	return 1;
}
int rightmove(address head)//实现俄罗斯方块循环想右运动 
{
	int i=22;
	head=goright(head);
	if(head==&TEMP)
	{
		i=downcircle(HEAD);
		if(i==0)
		return 0;
	}
	while(GetAsyncKeyState(VK_RIGHT))
	{
		head=goright(head);
		if(head==&TEMP)
		{
			i=downcircle(HEAD);
			if(i==0)
			return 0;
		}
	}
	i=downcircle(head);
	if(i==0)
	return 0;
	return 1;
}
int deform(address head)//实现俄罗斯方块变形 
{
	int i=22,a,b,j;
	address nexthead,r,s;
	do
	{
		a=head->next->next->x;
		b=head->next->next->y;
		switch(shape)
		{
			case 1:{
				    switch(T)
		            {
		              case 1:{
			                  nexthead=(address)malloc(sizeof(diamond));
			                  nexthead->next=NULL;
			                  r=nexthead;
			                  s=(address)malloc(sizeof(diamond));
			                  s->x=a;
			                  s->y=b-1;
			                  r->next=s;
			                  r=s;//
			                  s=(address)malloc(sizeof(diamond));
			                  s->x=a;
			                  s->y=b;
			                  r->next=s;
			                  r=s;//
			                  s=(address)malloc(sizeof(diamond));
			                  s->x=a;
			                  s->y=b+1;
			                  r->next=s;
			                  r=s;//
			                  s=(address)malloc(sizeof(diamond));
			                  s->x=a+2;
			                  s->y=b;
			                  r->next=s;
			                  s->next=NULL;
			                  adjust(nexthead);
				              break;
		                     }
		              case 2:{
			                  nexthead=(address)malloc(sizeof(diamond));
			                  nexthead->next=NULL;
			                  r=nexthead;
			                  s=(address)malloc(sizeof(diamond));
			                  s->x=a;
			                  s->y=b-1;
			                  r->next=s;
			                  r=s;//
			                  s=(address)malloc(sizeof(diamond));
			                  s->x=a;
			                  s->y=b;
			                  r->next=s;
			                  r=s;//
			                  s=(address)malloc(sizeof(diamond));
			                  s->x=a-2;
			                  s->y=b;
			                  r->next=s;
			                  r=s;//
			                  s=(address)malloc(sizeof(diamond));
			                  s->x=a+2;
			                  s->y=b;
			                  r->next=s;
			                  s->next=NULL;
			                  adjust(nexthead);
				              break;
		                     }
		              case 3:{
			                  nexthead=(address)malloc(sizeof(diamond));
			                  nexthead->next=NULL;
			                  r=nexthead;
			                  s=(address)malloc(sizeof(diamond));
			                  s->x=a;
			                  s->y=b-1;
			                  r->next=s;
			                  r=s;//
			                  s=(address)malloc(sizeof(diamond));
			                  s->x=a;
			                  s->y=b;
			                  r->next=s;
			                  r=s;//
			                  s=(address)malloc(sizeof(diamond));
			                  s->x=a-2;
			                  s->y=b;
			                  r->next=s;
			                  r=s;//
			                  s=(address)malloc(sizeof(diamond));
			                  s->x=a;
			                  s->y=b+1;
			                  r->next=s;
			                  s->next=NULL;
			                  adjust(nexthead);
				              break;
		                      }
		               case 4:{
			                   nexthead=(address)malloc(sizeof(diamond));
			                   nexthead->next=NULL;
			                   r=nexthead;
			                   s=(address)malloc(sizeof(diamond));
			                   s->x=a-2;
			                   s->y=b;
			                   r->next=s;
			                   r=s;//
			                   s=(address)malloc(sizeof(diamond));
			                   s->x=a;
			                   s->y=b;
			                   r->next=s;
			                   r=s;//
			                   s=(address)malloc(sizeof(diamond));
			                   s->x=a+2;
			                   s->y=b;
			                   r->next=s;
			                   r=s;//
			                   s=(address)malloc(sizeof(diamond));
			                   s->x=a;
			                   s->y=b+1;
			                   r->next=s;
			                   s->next=NULL;
			                   adjust(nexthead);
				               break; 
		                      }
		            }
		            freediamonds(head);
		            printdiamonds(nexthead);
		            head=nexthead;
		            T++;
		            if(T>4)
		            T=1;
					break;
			       }
		    case 2:{
				    switch(L1)
				    {
				    	case 1:{
							    nexthead=(address)malloc(sizeof(diamond));
			                    nexthead->next=NULL;
			                    r=nexthead;
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b-1;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b+1;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a+2;
			                    s->y=b+1;
			                    r->next=s;
			                    s->next=NULL;
			                    adjust(nexthead);
								break;
						       }
						case 2:{
							    nexthead=(address)malloc(sizeof(diamond));
			                    nexthead->next=NULL;
			                    r=nexthead;
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a-2;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a+2;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a+2;
			                    s->y=b-1;
			                    r->next=s;
			                    s->next=NULL;
			                    adjust(nexthead);
								break;
						       }
						case 3:{
							    nexthead=(address)malloc(sizeof(diamond));
			                    nexthead->next=NULL;
			                    r=nexthead;
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b+1;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b-1;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a-2;
			                    s->y=b-1;
			                    r->next=s;
			                    s->next=NULL;
			                    adjust(nexthead);
								break;
						       }
						case 4:{
							    nexthead=(address)malloc(sizeof(diamond));
			                    nexthead->next=NULL;
			                    r=nexthead;
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a+2;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a-2;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a-2;
			                    s->y=b+1;
			                    r->next=s;
			                    s->next=NULL;
			                    adjust(nexthead);
								break;
						       } 
					}
					freediamonds(head);
		            printdiamonds(nexthead);
		            head=nexthead;
		            L1++;
		            if(L1>4)
		            L1=1;
					break;
			       }
			case 3:{
				    switch(L2)
				    {
				    	case 1:{
							    nexthead=(address)malloc(sizeof(diamond));
			                    nexthead->next=NULL;
			                    r=nexthead;
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b-1;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b+1;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a-2;
			                    s->y=b+1;
			                    r->next=s;
			                    s->next=NULL;
			                    adjust(nexthead);
								break;
						       }
						case 2:{
							    nexthead=(address)malloc(sizeof(diamond));
			                    nexthead->next=NULL;
			                    r=nexthead;
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a+2;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a-2;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a-2;
			                    s->y=b-1;
			                    r->next=s;
			                    s->next=NULL;
			                    adjust(nexthead);
								break;
						       }
						case 3:{
							    nexthead=(address)malloc(sizeof(diamond));
			                    nexthead->next=NULL;
			                    r=nexthead;
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b+1;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b-1;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a+2;
			                    s->y=b-1;
			                    r->next=s;
			                    s->next=NULL;
			                    adjust(nexthead);
								break;
						       }
						case 4:{
							    nexthead=(address)malloc(sizeof(diamond));
			                    nexthead->next=NULL;
			                    r=nexthead;
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a-2;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a+2;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a+2;
			                    s->y=b+1;
			                    r->next=s;
			                    s->next=NULL;
			                    adjust(nexthead);
								break;
						       } 
					}
					freediamonds(head);
		            printdiamonds(nexthead);
		            head=nexthead;
		            L2++;
		            if(L2>4)
		            L2=1;
					break;
			       }
			case 4:{
				    switch(Z1)
				    {
				    	case 1:{
							    nexthead=(address)malloc(sizeof(diamond));
			                    nexthead->next=NULL;
			                    r=nexthead;
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a-2;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b+1;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a+2;
			                    s->y=b+1;
			                    r->next=s;
			                    s->next=NULL;
			                    adjust(nexthead);
								break;
						       }
						case 2:{
							    nexthead=(address)malloc(sizeof(diamond));
			                    nexthead->next=NULL;
			                    r=nexthead;
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b-1;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a-2;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a-2;
			                    s->y=b+1;
			                    r->next=s;
			                    s->next=NULL;
			                    adjust(nexthead);
								break;
						       }
					}
					freediamonds(head);
		            printdiamonds(nexthead);
		            head=nexthead;
		            Z1++;
		            if(Z1>2)
		            Z1=1;
					break;
			       }
			case 5:{
				    switch(Z2)
				    {
				    	case 1:{
							    nexthead=(address)malloc(sizeof(diamond));
			                    nexthead->next=NULL;
			                    r=nexthead;
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a+2;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b+1;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a-2;
			                    s->y=b+1;
			                    r->next=s;
			                    s->next=NULL;
			                    adjust(nexthead);
								break;
						       }
						case 2:{
							    nexthead=(address)malloc(sizeof(diamond));
			                    nexthead->next=NULL;
			                    r=nexthead;
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b-1;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a+2;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a+2;
			                    s->y=b+1;
			                    r->next=s;
			                    s->next=NULL;
			                    adjust(nexthead);
								break;
						       }
					}
					freediamonds(head);
		            printdiamonds(nexthead);
		            head=nexthead;
		            Z2++;
		            if(Z2>2)
		            Z2=1;
					break;
			        }
			case 7:{
				    switch(I)
				    {
				    	case 1:{
							    nexthead=(address)malloc(sizeof(diamond));
			                    nexthead->next=NULL;
			                    r=nexthead;
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b-1;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b+1;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b+2;
			                    r->next=s;
			                    s->next=NULL;
			                    adjust(nexthead);
								break;
						       }
						case 2:{
							    nexthead=(address)malloc(sizeof(diamond));
			                    nexthead->next=NULL;
			                    r=nexthead;
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a-2;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a+2;
			                    s->y=b;
			                    r->next=s;
			                    r=s;//
			                    s=(address)malloc(sizeof(diamond));
			                    s->x=a+4;
			                    s->y=b;
			                    r->next=s;
			                    s->next=NULL;
			                    adjust(nexthead);
								break;
						       }
					}
					freediamonds(head);
		            printdiamonds(nexthead);
		            head=nexthead;
		            I++;
		            if(I>2)
		            I=1;
					break;
			       }
		}	
	}
	while(GetAsyncKeyState(VK_UP));
	i=downcircle(head);
	if(i==0)
	return 0;
}
int connectSET(address head)//将落到底的俄罗斯方块的坐标并入方块坐标集diamondSET 
{
	address p=diamondSET;
	while(p->next!=NULL)
	p=p->next;
	p->next=head->next;
	free(head);
	return 1;
}
int ifleftrightcollide(address head)//判断俄罗斯方块是否到达左右边界 
{
	address p=head->next,q=diamondSET->next;
	if(q)
	{
		while(p)
	   {
		  while(q)
		  {
			if(p->x==q->x&&p->y==q->y)
			return p->x;
			q=q->next;
		  }
		q=diamondSET->next;
		p=p->next;
	   }
	}
	p=head->next;
	q=borderSET->next;
	while(p)
	{
		while(q)
		{
			if(p->x==q->x&&p->y==q->y)
			return p->x;
			q=q->next;
		}
		q=borderSET->next;
		p=p->next;
	}
	return 1;
}
int ifdowncollide(address head)//判断俄罗斯方块是否到达底部边界 
{
	address p=head->next,q=diamondSET->next;
	if(q)
	{
		while(p)
	   {
		  while(q)
		  {
			if(p->x==q->x&&p->y==q->y)
			return 0;
			q=q->next;
		  }
		q=diamondSET->next;
		p=p->next;
	   }
	}
	p=head->next;
	q=borderSET->next;
	while(p)
	{
		while(q)
		{
			if(p->x==q->x&&p->y==q->y)
			return 0;
			q=q->next;
		}
		q=borderSET->next;
		p=p->next;
	}
	return 1;
}
int wipenext()//清除下一个俄罗斯方块显示区域 
{
	int i;
	for(i=4;i<=8;i++)
	{
		at(100,i);
		printf("          ");
	}
}
int buildline()// 建立行集 
{
	int i,j,k;
	address r,s;
	for(i=28,k=0;i>=0;i--,k++)
	{
		line[k]=(address)malloc(sizeof(diamond));
		line[k]->next=NULL;
		r=line[k];
		for(j=28;j<=88;j+=2)
		{
			s=(address)malloc(sizeof(diamond));
			s->next=NULL;
			s->x=j;
			s->y=i;
			r->next=s;
			r=s;
		}
	}
	return 0;
}
int linefull()//判断行满以及行满时清除操作 
{
	int k,number=0; 
	for(k=0;k<=28;k++)
	{
	int c=0,i;
	address p=diamondSET->next,q=line[k]->next,front;
	while(p)
	{
		while(q)
		{
			if(q->x==p->x&&q->y==p->y)
			{
				c++;
				break;
			}
			else
			{
				q=q->next;
			}
		}
		q=line[k]->next;
		p=p->next;
	}
	if(c==31)
	{
		q=line[k]->next,p=diamondSET->next,front=diamondSET;
		while(q)
		{
			while(p)
			{
				if(p->x==q->x&&p->y==q->y)
				{
					front->next=p->next;
					freediamond(p);
					break;
				}
				else
				{
					front=p;
					p=p->next;
				}
			}
			front=diamondSET;
			p=diamondSET->next;
			q=q->next;
		}
	p=diamondSET->next;
	address nexthead,r,s;
	nexthead=(address)malloc(sizeof(diamond));
	r=nexthead;
	while(p)
	{
		s=(address)malloc(sizeof(diamond));
		s->x=p->x;
		s->y=p->y;
		if(ifup(p,k)==1)
		p->y++;
		s->next=NULL;
		r->next=s;
		r=s;
		p=p->next;
	}
	for(i=0;i<=N1;i++)
	{}
	freediamonds(nexthead);
	printdiamonds(diamondSET);
	f+=15;
	k--;
	number++;
	}	
	}
	return number*number*10;
}
int ifup(address p,int k)//筛选出消掉行以上的 
{
	int i;
	for(i=0;i<k;i++)
	{
		address r=line[i]->next;
		while(r)
		{
			if(p->x==r->x&&p->y==r->y)
			return 0;
			else
			r=r->next;
		}
	}
	return 1;
}
int  adjust(address head)//调整变形的俄罗斯方块，防止撞上左右边界 
{
		address p=head->next;
		int data,left=0,right=0,temp=0;
		  while(p)
		  {
			  if(p->x<=26)
			  {
			  	  temp=1;
			  	  movetoright(head,(26-p->x)+2);
			  }
		      p=p->next;
		  }
		  p=head->next;
		  while(p)
		  {
			  if(p->x>=90)
			  {
			  	  temp=1;
				  movetoleft(head,(p->x-90)+2);
			  }
			  p=p->next;
		  }
		  p=head->next;
		  if((data=ifleftrightcollide(head))!=1)
		  {
		  	if(temp!=0)
		  	return 1;
		  	while(p)
		  	{
		  		if(p->x>data)
		  		right++;
		  		else if(p->x<data)
		  		left++;
		  		if(right>left)
		  		{
		  			p=head->next;
		  			while(p)
		  			{
		  				if(p->x<=data)
		  				{
		  					movetoright(head,(data-p->x)+2);
						}
						p=p->next;
					}
				}
				else if(right<left)
				{
					p=head->next;
					while(p)
					{
						if(p->x>=data)
					}
				}
			}
		  }
		
		return 0;
}
int movetoright(address head,int i)//变形时撞上左边界向右调整 
{
	address p=head->next;
	while(p)
	{
		p->x+=i;
		p=p->next;
	}
	return 0;
}
int movetoleft(address head,int i)//变形时撞上右边界向左调整 
{
	address p=head->next;
	while(p)
	{
		p->x-=i;
		p=p->next;
	}
	return 0;
}
int ifendgame()//结束游戏 
{
	address p=diamondSET->next;
	while(p)
	{
		if(p->y==0)
		return 0;
		else
		p=p->next;
	}
	return 1;
}
int startgame()//开始游戏界面 
{
	int a=45,b=10;
	at(a,b);
	printf("欢迎来到 俄罗斯方块 游戏");
	at(a,b+2);
	system("pause");
	system("cls");
	at(a,b);
	printf("游戏规则");
	at(a,b+2);
	printf("傻逼都知道");
	at(a,b+4);
	system("pause");
	system("cls");
	at(a,b);
	printf("操作说明");
	at(a,b+2);
	printf("使用 ← 和 →键 控制方块向左和向右移动");
	at(a,b+4);
	printf("使用 ↑键 控制方块变形");
	at(a,b+6);
	printf("使用 ↓键 控制方块迅速到达底部");
	at(a,b+8);
	printf("使用 空格键 暂停游戏"); 
	at(a,b+10);
	printf("按任意键可开始游戏");
	at(a,b+12);
	system("pause");
	system("cls");
	 
} 
