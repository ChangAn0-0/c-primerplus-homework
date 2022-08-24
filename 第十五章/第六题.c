#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct {
	unsigned int id : 8;
	unsigned int size : 7;
	unsigned int alignment : 2;
	unsigned int B : 1;
	unsigned int I : 1;
	unsigned int U : 1;

}font = { 1,12,1,0,0,0 };

const static char ali[][8] = { "left","mid","right" };
const static char on_off[][4] = { "off","on" };

void show_mune(void);
void chang_font(void);
void chang_size(void);
void chang_alignment(void);
void change_other(char ch);
void choose(void);


int main(void)
{
	choose();

	return 0;
}

void show_mune(void)
{
	printf("ID:%d SIZE:%d ALIGNMENT:%s   B:%s  I:%s  U:%s,\n",font.id,font.size,ali[font.alignment],
		on_off[font.B],on_off[font.I],on_off[font.U]);
	printf("f)change font  s)change size    a)change alignment\n");
	printf("b)toggle bold  i)toggle italic  u)toggle underline\n");
	printf("q)quit\n");
}

void chang_font(void)
{
	int n;
	puts("enter a font(0-255):");
	scanf("%d", &n);
	font.id = n;
}

void chang_size(void)
{
	int n;
	puts("enter a size(0-127):");
	scanf("%d", &n);
	font.size = n;
}

void chang_alignment(void)
{
	char chn;
	puts("enter a alignment:\nl)left  m)mid  r)right");
	getchar(); 
	chn = getchar();                     //puts的\n需要处理
//	scanf("%c", &chn);
	
	if (chn == 'l')font.alignment = 0;
	if (chn == 'm')font.alignment = 1;
	if (chn == 'r')font.alignment = 2;

}

void change_other(char ch)
{
	if (ch == 'b')font.B = !font.B;
	if (ch == 'i')font.I = !font.I;
	if (ch == 'u')font.U = !font.U;
}

void choose(void)
{
	char ch;
	show_mune();

	while ((ch = getchar()) != 'q') {
	
		switch (ch) {
		case'f':	chang_font(); break;
		case's':	chang_size(); break;
		case'a':	chang_alignment(); break;
		default:	change_other(ch);
		}
		while (getchar() != '\n')
			continue;
		show_mune();

	}
}