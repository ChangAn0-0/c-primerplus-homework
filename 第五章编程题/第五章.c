#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void one(void);//第一题。
void two(void);//第二题。
               //三、四、五、六题略，解法参照其他题。
void seven(void);//第7题。
double cube(double n);//第7题函数声明。
void eight(void);//第8题.
void nine(void);//第9题.
void Temperatures(const double n);//第9题函数声明。


int main(void)
{
	//one();
	//two();
	//seven();
	//eight();
	nine();
	return 0;
}

//第一题函数*****************************************************
//在输入负数时没有立即结束程序
//造成原因为循环语句的顺序不对，正确语句可参照第八题
//或在scanf后加上语句if(!(min>0))break;结束循环。
void one(void)
{
	int min, hour;
	const int a = 60;
	min = 1;
	while(min>0)
	{
		printf("请输入分钟\n");
		scanf("%d", &min);
		hour = min / a;
		min = min % a;
		printf("%d:%d\n", hour, min);
	}
	printf("结束程序");
}

//第二题函数****************************************************
void two(void)
{
	int num, a;
	printf("请输入一个整数\n");
	scanf("%d", &num);
	a = num;
	
	//解法二
	/*for (a; a <= (num + 10); a++)
		printf("%d ", a);*/
	
	while (a<= (num + 10))
	{
		printf("%d ", a);
		a++;
	}

}

//第七题***********************************************************
void seven(void)
{
	double num = 0;
	printf("请输入一个数字\n");
	scanf("%lf", &num);
	printf("%f\n", cube(num));
}

double cube(double n)
{
	double cub;
	cub = n * n * n;
	return cub;
}

//第八题******************************************************************
void eight(void)
{
	int num1, num2;
	printf("请输入一个整数作为第二个数\n");
	scanf("%d", &num1);
	printf("请输入一个整数作为第一个数\n");
	scanf("%d", &num2);
	while (num2 > 0)
	{
		printf("%d\n",num2%num1);
		printf("请输入一个整数作为第一个数\n");
		scanf("%d", &num2);
	}
	printf("结束程序");

}

//第九题********************************************************
void nine(void)
{
	double num;
	printf("请输入一个华氏温度\n");
	_Bool a = (scanf("%lf", &num) == 1);//练习一下bool型，可以省去将while中的
	while (a == 1)                      //判断改成：scanf("%lf", &num) == 1
	{
		Temperatures(num);
		a = (scanf("%lf", &num) == 1);
	}
	printf("结束程序！");
}

void Temperatures(const double n)
{
	double celsius,kelvin;//摄氏温度,开氏温度
	
	celsius = 5.0 / 9.0 * (n - 32.0);
	kelvin = celsius + 273.16;
	
	printf("%.2f华氏度 ", n);
	printf("%.2f摄氏度 ", celsius);
	printf("%.2f开氏度 \n", kelvin);

}