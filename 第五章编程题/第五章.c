#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void one(void);//��һ�⡣
void two(void);//�ڶ��⡣
               //�����ġ��塢�����ԣ��ⷨ���������⡣
void seven(void);//��7�⡣
double cube(double n);//��7�⺯��������
void eight(void);//��8��.
void nine(void);//��9��.
void Temperatures(const double n);//��9�⺯��������


int main(void)
{
	//one();
	//two();
	//seven();
	//eight();
	nine();
	return 0;
}

//��һ�⺯��*****************************************************
//�����븺��ʱû��������������
//���ԭ��Ϊѭ������˳�򲻶ԣ���ȷ���ɲ��յڰ���
//����scanf��������if(!(min>0))break;����ѭ����
void one(void)
{
	int min, hour;
	const int a = 60;
	min = 1;
	while(min>0)
	{
		printf("���������\n");
		scanf("%d", &min);
		hour = min / a;
		min = min % a;
		printf("%d:%d\n", hour, min);
	}
	printf("��������");
}

//�ڶ��⺯��****************************************************
void two(void)
{
	int num, a;
	printf("������һ������\n");
	scanf("%d", &num);
	a = num;
	
	//�ⷨ��
	/*for (a; a <= (num + 10); a++)
		printf("%d ", a);*/
	
	while (a<= (num + 10))
	{
		printf("%d ", a);
		a++;
	}

}

//������***********************************************************
void seven(void)
{
	double num = 0;
	printf("������һ������\n");
	scanf("%lf", &num);
	printf("%f\n", cube(num));
}

double cube(double n)
{
	double cub;
	cub = n * n * n;
	return cub;
}

//�ڰ���******************************************************************
void eight(void)
{
	int num1, num2;
	printf("������һ��������Ϊ�ڶ�����\n");
	scanf("%d", &num1);
	printf("������һ��������Ϊ��һ����\n");
	scanf("%d", &num2);
	while (num2 > 0)
	{
		printf("%d\n",num2%num1);
		printf("������һ��������Ϊ��һ����\n");
		scanf("%d", &num2);
	}
	printf("��������");

}

//�ھ���********************************************************
void nine(void)
{
	double num;
	printf("������һ�������¶�\n");
	_Bool a = (scanf("%lf", &num) == 1);//��ϰһ��bool�ͣ�����ʡȥ��while�е�
	while (a == 1)                      //�жϸĳɣ�scanf("%lf", &num) == 1
	{
		Temperatures(num);
		a = (scanf("%lf", &num) == 1);
	}
	printf("��������");
}

void Temperatures(const double n)
{
	double celsius,kelvin;//�����¶�,�����¶�
	
	celsius = 5.0 / 9.0 * (n - 32.0);
	kelvin = celsius + 273.16;
	
	printf("%.2f���϶� ", n);
	printf("%.2f���϶� ", celsius);
	printf("%.2f���϶� \n", kelvin);

}