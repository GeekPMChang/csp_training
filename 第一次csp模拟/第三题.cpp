#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
int vis[200][200];
int time[100];
int visit_num=0;
int point_num=0;
struct point
{
    int id;//第几次分裂
    int step;//分裂走的第几步
    int x;
    int y;
    int angle;//分裂走的角度
}; 
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
        if(now.step==time[now.id])//要转湾了
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
                change_visit(new1.x+100,new1.y+100);
                change_visit(new2.x+100,new2.y+100);
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
            change_visit(new_point.x+100,new_point.y+100);
        }
    }
}
int main()
{
    scanf("%d",&point_num);
    for(int i=0;i<point_num;i++)
    {
        scanf("%d",&time[i]);
    }
    for(int i=0;i<200;i++)
        for(int j=0;j<200;j++)
                vis[i][j]=0;
    int count_num=BFS();
    cout<<count_num<<endl;
}