#include <stdio.h>
#include <stdarg.h>

double sum(int n, ...);

int main(void)
{
	double s, t=0.1;
	s = sum(2, 0.1, t);

	return 0;
}

double sum(int n, ...)
{
	va_list ap;
	double sum = 0;
	va_start(ap, n);
	for (int i = 0; i < n; i++)
	{
		sum += va_arg(ap, double);
	}
	va_end(ap);
	return sum;
}
