#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//δд����Ŀ�ɲ���������ⷨ����Ϊ��
void one(void);//��һ��
void three(void);//������
void four(void);//������
void five(void);//������
void twelve(void);//��ʮ����
void fourteen(void);//��ʮ����
void fiveteen(void);//15
void sixteen(void);//16
void seventeen(void);//17
void eighteen(void);//18
int main(void)
{
	//one();
	//three();
	//four();
	//five();
	//twelve();
	//fourteen();
	//fiveteen();
	//sixteen();
	//seventeen();
	eighteen();
	return 0;
}

//��һ��****************************************************
void one(void)
{
	int i = 0 ;
	char arr[26] = { 0 };
	char ch = 'a';
	for ( i = 0; i < 26; i++)
	{
		arr[i] = 'a' + i;
	}
	i = 0;
	while (i < 26)
	{
		printf("%c ", arr[i]);
		i++;
	}
}

//������*********************************************
void three(void)
{
	char ch = 'F';
	int i,j;
	for (i = 1; i < 7; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf("%c", ch - j);
		}
		putchar('\n');
	}
}

//������****************************************
void four(void)
{
	char ch[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//����ϵͳ��ʹ��ASCII������������Ϊ˳��Ĵ���
	int i, j, k=0;
	for (i = 1; i < 7; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf("%c",ch[k++]);
		}
		putchar('\n');
	}
}

//������*******************************************
void five(void)
{
	char ch;
	printf("�������д��ĸ");
	scanf("%c",&ch);
	int a = 0;
	int b = ch - 'A';

	for (a; ('A' + a) <= ch; a++,b--)
	{
		for (int i = 0; i <= b; i++)
			putchar(' ');
		for (int j = 0; j <=a ; j++)
			printf("%c", 'A' + j);
		for (int k = 1; k <= a; k++)
			printf("%c", ch - k);
		putchar('\n');
	}

}

//��ʮ����*************************************
void twelve(void)
{
	int a;
	double sum=0;
	printf("�������\n");
	scanf("%d", &a);
	while (a > 0)
	{
		for (int i = 1; i <= a; i++)
			sum += 1 / (double)i;
		printf("%lf\n",sum);
		sum = 0;
		for (int n = 1; n <= a; n++)
		{
			if (n % 2)//�ж�Ϊ�����n%2=1��ִ�С�
				sum += 1 / (double)n;
			else//�ж�Ϊż����
				sum -= 1 / (double)n;
		}
		printf("%lf\n", sum);
		sum = 0;
		printf("�������\n");
		scanf("%d", &a);
	}
	printf("�������\n");
}

//��ʮ����*****************************************
void fourteen(void)
{
	double sum = 0;
	double num1[8] = { 0 };
	double num2[8] = { 0 };
	printf("����������8����\n");
	for (int i = 0; i < 8; i++)
		scanf("%lf", &num1[i]);
	for (int i = 0; i < 8; i++)
		printf("%lf ", num1[i]);
	putchar('\n');
	for (int i = 0; i < 8; i++)
	{
		sum += num1[i];
		num2[i] = sum;
		printf("%lf ", num2[i]);
	}
}

//��ʮ����*************************************
void fiveteen(void)
{
	char ch[256] = { 0 };
	int i = 0;
	printf("������һ������\n");
	while ((ch[i++]=getchar())!= '\n')
	i = strlen(ch);
	for (i; i - 1 >= 0; i--)
		printf("%c", ch[i - 1]);
}

//16****************************************
void sixteen(void)
{
	double num1, num2;
	int i = 0;
	num1 = num2 = 100;
	while (!(num2 > num1))
	{
		num1 += 10;
		num2 *= 1.05;
	    i++;
	}
	printf("%d��,%lf,%lf", i, num1, num2);
}

//17************************************************
void seventeen(void)
{
	double sum = 100;
	int i = 0;
	do {
		sum *= 1.08;
		sum -= 10;
		i++;
		printf("%lf \n", sum);
	} while (sum > 0);
	printf("%d", i);
}

//18*************************************
void eighteen(void)
{
	int friends = 5;
	int i = 1;
	do {
		friends = friends - i;
		friends *= 2;
		i++;
	} while (friends <= 150);
	printf("%d %d", i,friends);
}