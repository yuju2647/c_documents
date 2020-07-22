/* ======================================== */
/*    程序实例: 3-3.c                              */
/*    计算各科平均成绩(内存动态分配)              */
/* ======================================== */
#include <stdlib.h>

void main()
{
	struct grade                      /* 成绩结构声明     */
	{
		int math;                   /* 数学成绩         */
		int english;                 /* 英语成绩         */
		int computer;               /* 计算机成绩         */
	};

	struct grade *student;            /* 结构数组变量声明 */
	int i;
	int num;                       /* 学生人数         */
	int m_sum,e_sum,c_sum;         /* 各科成绩总分变量 */
	float m_ave,e_ave,c_ave;         /* 各科平均成绩变量 */

	m_sum = e_sum = c_sum = 0;       /* 总分初值         */
	printf("请输入学生人数 ==> ");
	scanf("%d",&num);               /* 读取学生人数     */

	student = (struct grade *)           /* 分配内存       */
		malloc(num * sizeof(struct grade));
	if ( !student )                     /* 检查指针         */
	{
		printf("内存分配失败! \n");
		exit(1);
	}

	for ( i = 0; i < num; i++ )
	{
		printf("学生编号: %d\n",i + 1);
		printf("请输入数学成绩. ==> ");
		scanf("%d",&student[i].math);      /* 读取数学成绩   */
		m_sum += student[i].math;         /* 计算数学总分   */
		printf("请输入英语成绩. ==> ");
		scanf("%d",&student[i].english);    /* 读取英语成绩   */
		e_sum += student[i].english;        /* 计算英语总分   */
		printf("请输入计算机成绩. ==> ");
		scanf("%d",&student[i].computer);  /* 读取计算机成绩  */
		c_sum += student[i].computer;     /* 计算计算机总分  */
	}

	m_ave = (float) m_sum / (float) num;     /* 计算数学平均    */
	e_ave = (float) e_sum / (float) num;      /* 计算英语平均    */
	c_ave = (float) c_sum / (float) num;      /* 计算计算机平均  */

	printf("数学平均成绩: %6.2f \n",m_ave);
	printf("英语平均成绩: %6.2f \n",e_ave);
	printf("计算机平均成绩: %6.2f \n",c_ave);
}
//程序运行结果：
//请输入学生人数 ==> 3
//学生编号: 1
//请输入数学成绩. ==> 80
//请输入英语成绩. ==> 85
//请输入计算机成绩. ==> 88
//学生编号: 2
//请输入数学成绩. ==> 75
//请输入英语成绩. ==> 82
//请输入计算机成绩. ==> 80
//学生编号: 3
//请输入数学成绩. ==> 90
//请输入英语成绩. ==> 80
//请输入计算机成绩. ==> 65
//数学平均成绩:  81.67
//英语平均成绩:  82.33
//计算机平均成绩:  77.67
