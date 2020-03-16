#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

struct point
{
	int x;
	int y;
	bool operator < (const point& a) const
	{
		if (x != a.x) return x < a.x;
		return y < a.y;
	}
};
int point_num = 0;//分裂次数
set<point> s;//点集
set<point> copy_s;//工具人
int time[100];//每次的分裂次数
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };
//angle    0,1,2,3,4, 5, 6, 7
void DFS(int begin_x, int begin_y, int angle, int id)
{
	if (id > point_num)
		return;

	DFS(begin_x + time[id] * dx[angle], begin_y + time[id] * dy[angle], (angle + 1) % 8, id + 1);
	for (set<point>::iterator it = s.begin(); it != s.end(); it++)
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
	s.insert(copy_s.begin(), copy_s.end());
	copy_s.clear();
	for (int i = 0; i < time[id]; i++)
	{
		begin_x = begin_x + dx[angle];
		begin_y = begin_y + dy[angle];
		s.insert({ begin_x,begin_y });
	}
}

int main()
{
	scanf("%d", &point_num);
	for (int i = 1; i <= point_num; i++)
		scanf("%d", &time[i]);
	DFS(0, 0, 0, 1);
	printf("%d", s.size());
	return 0;
}
