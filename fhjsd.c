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
	char mine[ROWS][COLS] = { 0 };/*�����׵�ɨ����Ϣ*/
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
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}