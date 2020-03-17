#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

struct Point
{
	int x;
	int y;
	bool operator < (const Point& a) const
	{
		if (x != a.x) return x < a.x;
		return y < a.y;
	}
};
int split_num = 0;//分裂次数
set<Point> s_gather;//点集
set<Point> copy_s;//工具人
int split_time[100];//每次的分裂次数
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };
//angle    0,1,2,3,4, 5, 6, 7
void DFS(int begin_x, int begin_y, int angle, int id)
{
	if (id > split_num)
		return;

	DFS(begin_x + split_time[id] * dx[angle], begin_y + split_time[id] * dy[angle], (angle + 1) % 8, id + 1);
	for (set<Point>::iterator it = s_gather.begin(); it != s_gather.end(); it++)
	{
		if (angle % 4 == 0)
			copy_s.insert({ 2 * begin_x - (it->x),it->y });
		else if (angle % 4 == 1)
			copy_s.insert({ begin_x + (it->y) - begin_y,begin_y + (it->x) - begin_x });
		else if (angle % 4 == 2)
			copy_s.insert({ it->x,2 * begin_y - (it->y) });
		else
			copy_s.insert({ begin_x + begin_y - (it->y),begin_x + begin_y - (it->x) });

	}
	s_gather.insert(copy_s.begin(), copy_s.end());
	copy_s.clear();
	for (int i = 0; i < split_time[id]; i++)
	{
		begin_x = begin_x + dx[angle];
		begin_y = begin_y + dy[angle];
		s_gather.insert({ begin_x,begin_y });
	}
}

int main()
{
	scanf("%d", &split_num);
	for (int i = 1; i <= split_num; i++)
		scanf("%d", &split_time[i]);
	DFS(0, 0, 0, 1);
	printf("%d", s_gather.size());
	return 0;
}
