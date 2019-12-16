#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


#define N 40	//显示的字母数

void tips(void);
void print_char(char *);
void time_s(char *);

int main(void)
{
	char ch;

	while (1)
	{
		//开始游戏提示
		tips();

		//随机字母显示
		char a[N + 1];
		print_char(a);
		printf("%s\n", a);

		//时间计数和正确率显示
		time_s(a);

		printf("请输入接下来的操作(R重新开始，ESC退出)：");


	re:
		ch = _getch();
		puts("");
		if (ch == 'R')
			system("cls");

		else if (ch == 27)
			exit(0);
		else
		{
			printf("无效的输入，请重新输入: ");
			goto re;
		}
	}


	return 0;
}

//开始游戏提示
void tips(void)
{
	puts("******************任意键开始游戏，R重新开始游戏，ESC退出**********************");
	puts("******************************************************************************");

	char ch = _getch();
	if (ch == 27)
		exit(0);


}

//产生随机字母
void print_char(char * a)
{
	int i;

	srand((unsigned)time(NULL));
	for (i = 0; i < N; i++)
		a[i] = rand() % 26 + 'a';
	a[i] = '\0';
}

//时间计数和正确率计算
void time_s(char *a)
{
	unsigned time_star, time_end;
	int i;
	char ch;
	int count = 0;

	time_star = time(NULL);

	for (i = 0; i < N; i++)
	{
		ch = _getch();

		if (ch != a[i])
			printf("-");
		else
		{
			printf("%c", ch);
			count++;
		}
	}

	time_end = time(NULL);

	puts("");

	printf("总共用时 %u 秒, 正确率 %.2f%%\n", time_end - time_star, (float)count / N * 100);

	if ((float)count / N * 100 >= 90)
		puts("你太棒啦！");
	else
		puts("还要继续加油哦！");
}
