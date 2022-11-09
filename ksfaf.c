#include"hfk.h"
void initboard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	for (i = 0; i < cols; i++)
	{
		int j = 0;
		for (j = 0; j < rows; j++)
		{
			board[i][j] = set;
		}
	}
}
void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("---------ɨ��----------\n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("---------ɨ��----------\n");
}
void setmine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return(mine[x - 1][y] + mine[x - 1][y - 1] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] +
		mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0');
}
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<(row*col-EASY_COUNT))
	{
		printf("������Ҫ�Ų�����꣺");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("�����걻�Ų����\n");
				continue;
			}
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����\n");
				displayboard(mine, ROW, COL);
				break;
			}
			else
			{
				int n = get_mine_count(mine, x, y);
				show[x][y] = n + '0';
				displayboard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("����Ƿ�����������\n");
		}
	}
	if (win == (row * col - EASY_COUNT))
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		displayboard(mine, ROW, COL);
	}
}