#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void one(void);//1
void two1(void);/*第二题可以看到我写了两个函数two和two1，第一个是一开始写的，但是运行的时候出现了一个问题
				即按下enter键时，便开始输出打印，这无法使我在按下enter键后继续输入其他字符，这和我预想的不一样，
				但是第一个程序却没有遇到这个问题，我猜是第一个printf写在循环外的原因，enter键除了输入字符'\n'
				还刷新了缓冲区，所以printf写在循环内导致了问题的发生？所以我写了two1这个
				程序，我把printf和while的循环分开，先储存再输出，这次果然没有收到影响。*/
void four(void);//4
void six(void);//6,此为错误解法。
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
	printf("空格：%d,换行：%d,其他：%d", i, j, k);
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
			putchar('!');//while循环内的输出存在与2同样的问题。
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
			if (getchar() == 'i')//此处有误，当输入为eei时，中间的e被此处的getchar获取，                
				i++;             //之后的while循环中的getchar获取i，导致程序输出为0。
	}                            //所以在while循环中应该避免用getchar。
	printf("%d", i);
}

void six1(void)//此为书本答案的解法，我的本意是如同two1一样，先设置数组读入输入，然后通过
{              //arr[i]=='e'&&arr[i+1]=='i'是否为真来判断，不过我觉得答案的解法更好。
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

	start:printf("请正确的输入相应数字选择工资等级\n");
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

	printf("请输入一周工作时间\n");
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

end:printf("程序结束");
}
//9**********************************************************
void nine(void)
{
	int n,i,j;
	_Bool a = 1;
	printf("请输入正整数");
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

    printf("请正确的输入相应字母选购商品\n");
	printf("a)洋蓟      b)甜菜\n");
	printf("c)胡萝卜    q)离开选购\n");

	while ((ch = getchar()) != 'q')
	{
		switch (ch)
		{
		case 'a': {
			printf("请选择洋蓟购买数量\n");
			scanf("%lf", &i);
			sum1 += i;
		}break;
		case 'b': {
			printf("请选择甜菜购买数量\n");
			scanf("%lf", &j);
			sum2 += j;
		}break;
		case 'c': {
			printf("请选择胡萝卜购买数量\n");
			scanf("%lf", &k);
			sum3 += k;
		}break;
		case 'q':goto end;
		default:printf("请重新选择\n");
		}
		getchar();                            //获取enter键的\n防止while循环出错
		printf("请正确的输入相应字母选购商品\n");
		printf("a)洋蓟      b)甜菜\n");
		printf("c)胡萝卜    q)离开选购\n");
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
	
	printf("总价：%.2lf美元 折扣：%.2lf美元 运费和包装费：%.2lf美元\n",
		sum + freight, sum - discount, freight);
	printf("洋蓟  ：%.2lf磅  单价：%.2lf美元/磅 总价：%.2lf美元\n",
		sum1, Artichoke,sum1*Artichoke);
	printf("甜菜  ：%.2lf磅  单价：%.2lf美元/磅 总价：%.2lf美元\n", 
		sum2, beet,sum2*beet);
	printf("胡萝卜：%.2lf磅  单价：%.2lf美元/磅 总价：%.2lf美元\n", 
		sum3, carrot,sum3*carrot);
	printf("应付：%.2lf美元\n",discount+freight);
}

