#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void one(void);//��һ��
               //�ڶ�����յ�����
void three(void);//������
void four(void);//������
void five(void);//������
int main(void)
{
	//one();
	//three();
	//four();
	five();
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

//��ʮ����ڶ�������****************************************
void twelve(void)
{
	int ch;
	printf("���������");
	scanf("%c", &ch);

}