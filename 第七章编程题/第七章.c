#include <stdio.h>
void one(void);//1
void two1(void);/*�ڶ�����Կ�����д����������two��two1����һ����һ��ʼд�ģ��������е�ʱ�������һ������
				������enter��ʱ���㿪ʼ�����ӡ�����޷������ڰ���enter����������������ַ��������Ԥ��Ĳ�һ����
				���ǵ�һ������ȴû������������⣬�Ҳ��ǵ�һ��printfд��ѭ�����ԭ��enter�����������ַ�'\n'
				Ӧ�û����������ã�����ˢ�����ѭ��������printfд��ѭ���ڵ���������ķ�����������д��two1���
				�����Ұ�printf��while��ѭ���ֿ����ȴ������������ι�Ȼû���յ�Ӱ�졣*/
void four(void);//4
void six(void);//6,��Ϊ����ⷨ��
void six1(void);//6
int main()
{
	//one();
	//two1();
	//four();
	six1();
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
			putchar('!');//whileѭ���ڵ����������2ͬ�������⡣
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
	char ch; int i = 0;
	while ((ch = getchar()) != '#')
	{
		if (ch == 'e')
			if (getchar() == 'i')//�˴����󣬵�����Ϊeeiʱ���м��e���˴���getchar��ȡ��                
				i++;             //֮���whileѭ���е�getchar��ȡi�����³������Ϊ0��
	}                            //������whileѭ����Ӧ�ñ�����getchar��
	printf("%d", i);
}

void six1(void)//��Ϊ�鱾�𰸵Ľⷨ���ҵı�������ͬtwo1һ��������������������룬Ȼ��ͨ��
{              //arr[i]=='e'&&arr[i+1]=='i'�Ƿ�Ϊ�����жϣ������Ҿ��ô𰸵Ľⷨ���á�
	char ch; int j,i;
	j = i = 0;
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case'e':j = 1; break;
		case'i':if (j) {
			i++; j = 0;
		}break;
		default:j = 0;
		}
	}
	printf("%d", i);
}

//7****************************************************
void seven(void)
{

}