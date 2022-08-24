#include <stdio.h>

#define aver(x,y) 1/(((1/x)+(1/y))/2)
#define squa(x)  printf("\n"#x" square is %d",((x)*(x)));
int main(void)
{
	double x = 2, y = 4;
	printf("%lf", aver(x, y));
	squa(2);
}