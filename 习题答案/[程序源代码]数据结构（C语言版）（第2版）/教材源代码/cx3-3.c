/* ======================================== */
/*    ����ʵ��: 3-3.c                              */
/*    �������ƽ���ɼ�(�ڴ涯̬����)              */
/* ======================================== */
#include <stdlib.h>

void main()
{
	struct grade                      /* �ɼ��ṹ����     */
	{
		int math;                   /* ��ѧ�ɼ�         */
		int english;                 /* Ӣ��ɼ�         */
		int computer;               /* ������ɼ�         */
	};

	struct grade *student;            /* �ṹ����������� */
	int i;
	int num;                       /* ѧ������         */
	int m_sum,e_sum,c_sum;         /* ���Ƴɼ��ֱܷ��� */
	float m_ave,e_ave,c_ave;         /* ����ƽ���ɼ����� */

	m_sum = e_sum = c_sum = 0;       /* �ֳܷ�ֵ         */
	printf("������ѧ������ ==> ");
	scanf("%d",&num);               /* ��ȡѧ������     */

	student = (struct grade *)           /* �����ڴ�       */
		malloc(num * sizeof(struct grade));
	if ( !student )                     /* ���ָ��         */
	{
		printf("�ڴ����ʧ��! \n");
		exit(1);
	}

	for ( i = 0; i < num; i++ )
	{
		printf("ѧ�����: %d\n",i + 1);
		printf("��������ѧ�ɼ�. ==> ");
		scanf("%d",&student[i].math);      /* ��ȡ��ѧ�ɼ�   */
		m_sum += student[i].math;         /* ������ѧ�ܷ�   */
		printf("������Ӣ��ɼ�. ==> ");
		scanf("%d",&student[i].english);    /* ��ȡӢ��ɼ�   */
		e_sum += student[i].english;        /* ����Ӣ���ܷ�   */
		printf("�����������ɼ�. ==> ");
		scanf("%d",&student[i].computer);  /* ��ȡ������ɼ�  */
		c_sum += student[i].computer;     /* ���������ܷ�  */
	}

	m_ave = (float) m_sum / (float) num;     /* ������ѧƽ��    */
	e_ave = (float) e_sum / (float) num;      /* ����Ӣ��ƽ��    */
	c_ave = (float) c_sum / (float) num;      /* ��������ƽ��  */

	printf("��ѧƽ���ɼ�: %6.2f \n",m_ave);
	printf("Ӣ��ƽ���ɼ�: %6.2f \n",e_ave);
	printf("�����ƽ���ɼ�: %6.2f \n",c_ave);
}
//�������н����
//������ѧ������ ==> 3
//ѧ�����: 1
//��������ѧ�ɼ�. ==> 80
//������Ӣ��ɼ�. ==> 85
//�����������ɼ�. ==> 88
//ѧ�����: 2
//��������ѧ�ɼ�. ==> 75
//������Ӣ��ɼ�. ==> 82
//�����������ɼ�. ==> 80
//ѧ�����: 3
//��������ѧ�ɼ�. ==> 90
//������Ӣ��ɼ�. ==> 80
//�����������ɼ�. ==> 65
//��ѧƽ���ɼ�:  81.67
//Ӣ��ƽ���ɼ�:  82.33
//�����ƽ���ɼ�:  77.67
