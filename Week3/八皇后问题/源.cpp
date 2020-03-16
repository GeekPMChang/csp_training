#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int number = 0;
bool check_right(int x, int y, int map[8][8])
{
	int left_x, left_y, right_x, right_y = 0;
	if (x == 0)
	{
		return true;
	}
	for (int i = 0; i < x; i++)
	{
		if (map[i][y] == 1)
		{
			return false;
		}
	}
	left_x = x - 1; left_y = y - 1;
	right_x = x - 1; right_y = y + 1;
	while (left_x >= 0 && left_y >= 0)
	{
		if (map[left_x][left_y] == 1)
		{
			return false;
		}
		left_x = left_x - 1;
		left_y = left_y - 1;
	}
	while (right_x >= 0 && right_y < 8)
	{
		if (map[right_x][right_y] == 1)
		{
			return false;
		}
		right_x = right_x - 1;
		right_y = right_y + 1;
	}
	return true;
}
void print(int map[8][8])
{
	number++;
	cout << number << ":" << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[i][j] == 0)
				cout << "#" << " ";
			else
				cout << "!" << " ";
		}
		cout << endl;
	}
}
void bfs(int row, int map[8][8])
{
	for (int the_col = 0; the_col < 8; the_col++)
	{
		map[row][the_col] = 1;
		if (check_right(row, the_col, map))
		{
			if (row == 7)
				print(map);
			else
				bfs(row + 1, map);
		}
		map[row][the_col] = 0;
	}
}
int main()
{
	int map[8][8];
	memset(map, 0, sizeof(map));
	bfs(0, map);
	cout << "八皇后问题的解决方案数量有：" << number << "个";
	return 0;
}