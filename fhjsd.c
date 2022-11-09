#include"hfk.h"
void menu()
{
	printf("*********************************\n");
	printf("**********   1.play     *********\n");
	printf("**********   2.exit     *********\n");
	printf("*********************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };/*布置雷的扫雷信息*/
	char show[ROWS][COLS] = { 0 };
	initboard(mine, ROWS, COLS,'0');
	initboard(show, ROWS, COLS, '*');
	displayboard(show, ROW, COL);
	setmine(mine, ROW, COL);
	displayboard(mine, ROW, COL);
	findmine(mine, show, ROW, COL);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}