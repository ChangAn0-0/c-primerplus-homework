#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void one(void);//1
void two1(void);/*�ڶ�����Կ�����д����������two��two1����һ����һ��ʼд�ģ��������е�ʱ�������һ������
				������enter��ʱ���㿪ʼ�����ӡ�����޷�ʹ���ڰ���enter����������������ַ��������Ԥ��Ĳ�һ����
				���ǵ�һ������ȴû������������⣬�Ҳ��ǵ�һ��printfд��ѭ�����ԭ��enter�����������ַ�'\n'
				��ˢ���˻�����������printfд��ѭ���ڵ���������ķ�����������д��two1���
				�����Ұ�printf��while��ѭ���ֿ����ȴ������������ι�Ȼû���յ�Ӱ�졣*/
void four(void);//4
void six(void);//6,��Ϊ����ⷨ��
void six1(void);//6
void eight(void);//8
void nine(void);//9
void eleven(void);//11
int main()
{
	//one();
	//two1();
	//four();
	//six1();
	//eight();
	//eleven();
	nine();
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
void eight(void)
{
	double salary_grade = 0; int choose;
	double hour,salary;

	start:printf("����ȷ��������Ӧ����ѡ���ʵȼ�\n");
	printf("1)8.75/hr      2)9.33/hr\n");
	printf("3)10.00/hr     4)11.20/hr\n");
	printf("5)quit   \n");
	
	scanf("%d", &choose);

	switch (choose)
	{
	case 1:salary_grade = 8.75;
		break;
	case 2:salary_grade = 9.33;
		break;
	case 3:salary_grade = 10.00;
		break;
	case 4:salary_grade = 11.20;
		break;
	case 5:goto end;
	default:goto start;
	}

	printf("������һ�ܹ���ʱ��\n");
	scanf("%lf", &hour);
	if (hour > 40)
		hour = (hour - 40) * 1.5 + 40;
	salary = hour * salary_grade;
	if (salary <= 300)
		salary *= 0.85;
	else if (salary <= 450)
		salary = (300 * 0.85) + (salary - 300) * 0.8;
	else
		salary = (300 * 0.85) + (150 * 0.8) + (salary - 450) * 0.75;

	printf("%.2lf\n", salary);

end:printf("�������");
}
//9**********************************************************
void nine(void)
{
	int n,i,j;
	_Bool a = 1;
	printf("������������");
	scanf("%d", &n);
	if (n == 1)goto end;
	for (i = 1; i <= n; i++)
	{
		if (i == 1)continue;//skip 1;
		for (j = 1; j * j <= i; j++)
		{
			if (j == 1)continue;
			if (i % j == 0)
			{
				a = 0;
				break;
			}
			else
				a = 1;
		}
		if (a)printf("%d ", i);
	}
end:return;
}
//11**********************************************************
void eleven(void)
{
	char ch;
	double i, j, k,sum,sum1,sum2,sum3, gross_weight,discount, freight;
	sum1 = sum2 = sum3 = 0;
	const double Artichoke = 2.05;
	const double beet = 1.15;
	const double carrot = 1.09;

    printf("����ȷ��������Ӧ��ĸѡ����Ʒ\n");
	printf("a)��      b)���\n");
	printf("c)���ܲ�    q)�뿪ѡ��\n");

	while ((ch = getchar()) != 'q')
	{
		switch (ch)
		{
		case 'a': {
			printf("��ѡ���󼻹�������\n");
			scanf("%lf", &i);
			sum1 += i;
		}break;
		case 'b': {
			printf("��ѡ����˹�������\n");
			scanf("%lf", &j);
			sum2 += j;
		}break;
		case 'c': {
			printf("��ѡ����ܲ���������\n");
			scanf("%lf", &k);
			sum3 += k;
		}break;
		case 'q':goto end;
		default:printf("������ѡ��\n");
		}
		getchar();                            //��ȡenter����\n��ֹwhileѭ������
		printf("����ȷ��������Ӧ��ĸѡ����Ʒ\n");
		printf("a)��      b)���\n");
		printf("c)���ܲ�    q)�뿪ѡ��\n");
	}

end:sum = sum1*Artichoke + sum2* beet + sum3*carrot;
	discount = sum;
	gross_weight = sum1 + sum2 + sum3;
	if (sum >= 100)
		discount *= 0.95;

	if (gross_weight <= 5)
		freight = 6.5;
	else if (gross_weight <= 20)
		freight = 14;
	else
		freight = 14 + (gross_weight - 20) * 0.5;
	
	printf("�ܼۣ�%.2lf��Ԫ �ۿۣ�%.2lf��Ԫ �˷ѺͰ�װ�ѣ�%.2lf��Ԫ\n",
		sum + freight, sum - discount, freight);
	printf("��  ��%.2lf��  ���ۣ�%.2lf��Ԫ/�� �ܼۣ�%.2lf��Ԫ\n",
		sum1, Artichoke,sum1*Artichoke);
	printf("���  ��%.2lf��  ���ۣ�%.2lf��Ԫ/�� �ܼۣ�%.2lf��Ԫ\n", 
		sum2, beet,sum2*beet);
	printf("���ܲ���%.2lf��  ���ۣ�%.2lf��Ԫ/�� �ܼۣ�%.2lf��Ԫ\n", 
		sum3, carrot,sum3*carrot);
	printf("Ӧ����%.2lf��Ԫ\n",discount+freight);
}

