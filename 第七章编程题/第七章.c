#include <stdio.h>
void one(void);//1
void two1(void);/*�ڶ�����Կ�����д����������two��two1����һ����һ��ʼд�ģ��������е�ʱ�������һ������
				������enter��ʱ���㿪ʼ�����ӡ�����޷������ڰ���enter����������������ַ��������Ԥ��Ĳ�һ����
				���ǵ�һ������ȴû������������⣬�Ҳ��ǵ�һ��printfд��ѭ�����ԭ��enter�����������ַ�'\n'
				Ӧ�û����������ã�����ˢ�����ѭ��������printfд��ѭ���ڵ���������ķ�����������д��two1���
				�����Ұ�printf��while��ѭ���ֿ����ȴ������������ι�Ȼû���յ�Ӱ�졣*/
void four(void);//4
int main()
{
	//one();
	two1();
	//four();
	return 0;
}

//1***********************************************
void one(void)
{
	char ch; int i, j, k;
	i = j = k = 0;
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case' ':i++; break;
		case'\n':j++; break;
		default:k++;
		}
	}
	printf("�ո�%d,���У�%d,������%d", i, j, k);
}

//2*********************************************
void two(void)
{
	char ch;
	int i = 0;
	while ((ch = getchar()) != '#')
	{
		printf("%3d ", ch);
		i++;
		if (!(i % 8))
			putchar('\n');
	}
}

void two1(void)
{
	char arr[10000] = { 0 };
	char ch;
	int i = 0;
	while ((ch = getchar()) != '#')
	{
		arr[i] = ch;
		i++;
	}
	int n = 0;
	for (n; n < i; n++)
	{
		if (!(n % 8))
			putchar('\n');
		printf("%3d ", arr[n]);
	}
}

//4***************************************************
void four(void)
{
	char ch;
	while ((ch= getchar()) != '#')
	{
		if (ch == '.')
			putchar('!');
		else if (ch == '!')
		{
			putchar('!');
			putchar('!');
		}
		else
			putchar(ch);
	}
}

//6**************************************************
void six(void)
{
	char ch;
	while ((ch = getchar()) != '#')
	{
	if(ch=='e')

	}
}