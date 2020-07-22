/* ======================================== */
/*    程序实例: 3-5.c                    */
/*    基本链表的建立                        */
/* ======================================== */
#include <stdlib.h>

struct llist                      /* 链表结构体声明      */
{
	int num;                       /* 学号          */
	char name[10];                  /* 姓名          */
	struct llist *next;                 /* 指向下一节点      */
};
typedef struct llist node;                /* 定义新类型        */
typedef node *llink;                   /* 定义新类型指针    */

void main()
{
	llink head;                      /* 链表的开始指针    */
	llink ptr;
	int i;

	head = ( llink ) malloc(sizeof(node)); /* 分配内存 */
	if ( !head )                      /* 检查指针          */
	{
		printf("内存分配失败! \n");
		exit(1);
	}
	head->next = NULL;             /* 设置指针初值      */
	ptr = head;                      /* 将ptr指向链表开始 */
	printf("输入6个学生信息:\n");

	for ( i = 0; i < 6; i++ )             /* 循环建立其它节点  */
	{
		printf("请输入学号 ==> ");
		scanf("%d",&ptr->num);     /* 读取学号         */
		printf("请输入学号(%d)的姓名 ==> ",ptr->num);
		scanf("%s",ptr->name);      /* 读取姓名          */
		ptr->next = ( llink ) malloc(sizeof(node));
		if ( !ptr->next )
		{
			printf("内存分配失败! \n");
			exit(1);
		}
		ptr->next->next = NULL;    /* 设置指针初值      */
		ptr = ptr->next;            /* 指向下一节点      */
	}

	printf("学生信息:\n");           /* 输出数据内容      */

	ptr = head;                    /* 将ptr指向链表开始 */
	for ( i = 0; i < 6; i++ )           /* 循环输出          */
	{
		printf("学号: %d\n",ptr->num);
		printf("  姓名: %s\n",ptr->name);
		ptr = ptr->next;            /* 指向下一节点      */
	}
}
//程序运行结果：
//输入6个学生信息:
//请输入学号 ==> 1001
//请输入学号(1001)的姓名 ==> 张三
//请输入学号 ==> 1002
//请输入学号(1002)的姓名 ==> 李四
//请输入学号 ==> 1003
//请输入学号(1003)的姓名 ==> 王五
//请输入学号 ==> 1004
//请输入学号(1004)的姓名 ==>李明
//请输入学号 ==> 1005
//请输入学号(1005)的姓名 ==> 王毛
//请输入学号 ==> 1006
//请输入学号(1006)的姓名 ==> 周兴
//学生信息:
//学号: 1001
//  姓名: 张三
//学号: 1002
//  姓名: 李四
//学号: 1003
//  姓名: 王五
//学号: 1004
//  姓名:李明
//学号: 1005
//  姓名: 王毛
//学号: 1006
//  姓名: 周兴
