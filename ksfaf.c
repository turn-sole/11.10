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
	printf("---------扫雷----------\n");
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
	printf("---------扫雷----------\n");
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
		printf("请输入要排查的坐标：");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("这坐标被排查过了\n");
				continue;
			}
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
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
			printf("坐标非法，重新输入\n");
		}
	}
	if (win == (row * col - EASY_COUNT))
	{
		printf("恭喜你，排雷成功\n");
		displayboard(mine, ROW, COL);
	}
}