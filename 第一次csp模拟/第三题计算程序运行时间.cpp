#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
#include<queue> 
#include<ctime>
using namespace std;
struct point//BFS
{
    int id;//第几次分裂
    int step;//分裂走的第几步
    int x;
    int y;
    int angle;//分裂走的角度
};
struct Point//DFS
{
	int x;
	int y;
	bool operator < (const Point& a) const
	{
		if (x != a.x) return x < a.x;
		return y < a.y;
	}
};

int vis[2000][2000];
int go_time[100];
int visit_num=0;
int point_num=0;

int split_num = 0;//分裂次数
set<Point> s_gather;//点集
set<Point> copy_s;//工具人
int split_time[100];//每次的分裂次数
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };
//angle    0,1,2,3,4, 5, 6, 7

//DFS
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

//BFS 
void step(point &new_point,point &now)
{
    int angle=new_point.angle;
            if(angle==0)
            {
                new_point.x=now.x;
                new_point.y=now.y+1;
            }
            else if(angle==45)
            {
                new_point.x=now.x+1;
                new_point.y=now.y+1;
            }
            else if(angle==90)
            {
                new_point.x=now.x+1;
                new_point.y=now.y;
            }
            else if(angle==135)
            {
                new_point.x=now.x+1;
                new_point.y=now.y-1;
            }
            else if(angle==180)
            {
                new_point.x=now.x;
                new_point.y=now.y-1;
            }
            else if(angle==225)
            {
                new_point.x=now.x-1;
                new_point.y=now.y-1;
            }
            else if(angle==270)
            {
                new_point.x=now.x-1;
                new_point.y=now.y;
            }
            else if(angle==315)
            {
                new_point.x=now.x-1;
                new_point.y=now.y+1;
            }
}
void change_visit(int x,int y)
{
    if(vis[x][y]==0)
    {
        visit_num++;
        vis[x][y]=1;
    }
}
queue<point> q1;
int BFS()
{
    point start;
    start.x=0;
    start.y=0;
    start.angle=0;
    start.id=0;
    start.step=0;
    q1.push(start);
    while(!q1.empty())
    {
        point now=q1.front(); q1.pop();
        if(now.step==go_time[now.id])//要转湾了
        {
            point new1,new2;
            if(now.id==point_num-1)
            return visit_num;
            else
            {
                new1.id=now.id+1;
                new1.step=1;
                new1.angle=(now.angle+45)%360;
                new2.id=now.id+1;
                new2.step=1;
                new2.angle=(now.angle-45)%360;
                if(new2.angle<0)
                new2.angle+=360;
                step(new1,now);
                step(new2,now);
                q1.push(new1);
                q1.push(new2);
                change_visit(new1.x+1000,new1.y+1000);
                change_visit(new2.x+1000,new2.y+1000);
            }
            
        }
        else//继续向前走
        {
            point new_point;
            new_point.angle=now.angle;
            new_point.id=now.id;
            new_point.step=now.step+1;
            step(new_point,now);
            q1.push(new_point);
            change_visit(new_point.x+1000,new_point.y+1000);
        }
    }
}
int main()
{
    clock_t start_Time_dfs,end_Time_dfs;
	//DFS 
	scanf("%d", &split_num);
	for (int i = 1; i <= split_num; i++)
		scanf("%d", &split_time[i]);
    start_Time_dfs=clock();
	DFS(0, 0, 0, 1);
    end_Time_dfs=clock();
	printf("%d\n", s_gather.size());
	
	//BFS
	scanf("%d",&point_num);
    for(int i=0;i<point_num;i++)
    {
        scanf("%d",&go_time[i]);
    }
    clock_t start_Time_bfs,end_Time_bfs;
    start_Time_bfs=clock();
    for(int i=0;i<2000;i++)
        for(int j=0;j<2000;j++)
                vis[i][j]=0;
    int count_num=BFS();
    end_Time_bfs=clock();
    cout<<count_num<<endl;
    printf("The DFS run time is %lf\n",(double)(end_Time_dfs-start_Time_dfs)/CLOCKS_PER_SEC);
    printf("The BFS run time is %lf\n",(double)(end_Time_bfs-start_Time_bfs)/CLOCKS_PER_SEC);
	return 0;
}


/*
30
2 3 4 5 1 2 1 3 4 5 5 4 3 2 2 2 3 2 3 4 3 4 5 4 3 2 3 4 1 2

28
2 3 4 5 3 2 3 4 3 2 3 4 5 6 7 3 4 5 6 7 2 5 5 5 5 2 3 4

20
1 2 3 4 5 5 4 3 2 1 1 2 3 4 5 5 4 3 2 1

25
2 3 4 5 3 2 3 4 3 2 3 4 5 6 7 3 4 5 6 7 2 5 5 5 5 
*/