#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

struct point
{
    int wide_direct;//横向线
    int long_direct;//纵向线
    char filling;
};

struct pos
{
    int x;
    int y;
};

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

point a[101][101];
int wideth,length=0;
queue<pos> q;

void BFS_fill(int start_x,int start_y,char filling)
{
    if(a[start_x][start_y].wide_direct==1 || a[start_x][start_y].long_direct==1)
    {
        return;
    }
    a[start_x][start_y].filling=filling;

    pos start;
    start.x=start_x;
    start.y=start_y;
    q.push(start);
    while(!q.empty())
    {
        pos node=q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            int new_node_x=node.x+dx[i];
            int new_node_y=node.y+dy[i];
            if(a[new_node_x][new_node_y].wide_direct==0 && a[new_node_x][new_node_y].long_direct==0 && a[new_node_x][new_node_y].filling!=filling && new_node_x<wideth && new_node_y<length && new_node_x>=0 && new_node_y>=0)
            {
                a[new_node_x][new_node_y].filling=filling;
                pos new_node;
                new_node.x=new_node_x;
                new_node.y=new_node_y;
                q.push(new_node);
            }
        }
    }
}
void make_line(int x_1,int y_1,int x_2,int y_2)
{
    if(x_1==x_2)//纵向划线
    {
        if(y_1==y_2)//不划线
        return;
        else if(y_1>y_2)//向下划线
        {
            for(int i=y_2;i<=y_1;i++)
            {
                a[x_1][i].long_direct=1;
            }
        }
        else
        {
            for(int i=y_1;i<=y_2;i++)//向上划线
            {
                a[x_1][i].long_direct=1;
            }
        }
    }
    else if(y_1==y_2)//横向划线
    {
        if(x_1>x_2)//向左划线
        {
            for(int i=x_2;i<=x_1;i++)
            {
                a[i][y_1].wide_direct=1;
            }
        }
        else
        {
            for(int i=x_1;i<=x_2;i++)
            {
                a[i][y_1].wide_direct=1;
            }
        }   
    }
}
void output()
{
    for(int j=length-1;j>=0;j--)
    {
        for(int i=0;i<wideth;i++)
            {
                if(a[i][j].long_direct==1 && a[i][j].wide_direct==1)
                printf("+");
                else if(a[i][j].long_direct==1 && a[i][j].wide_direct==0)
                printf("|");
                else if(a[i][j].long_direct==0 && a[i][j].wide_direct==1)
                printf("-");
                else if(a[i][j].long_direct==0 && a[i][j].wide_direct==0)
                printf("%c",a[i][j].filling);
            }
            printf("\n");
    }
}
int main()
{
    int done_num=0;
    int control_num=0;
    int x_1,x_2,y_1,y_2=0;
    int x,y=0;
    char str;
    scanf("%d %d %d",&wideth,&length,&done_num);
    for(int i=0;i<wideth;i++)
        for(int j=0;j<length;j++)
            a[i][j].long_direct=0,a[i][j].wide_direct=0,a[i][j].filling='.';
    for(int i=0;i<done_num;i++)
    {
        scanf("%d",&control_num);
        if(control_num==0)
        {
            scanf("%d %d %d %d",&x_1,&y_1,&x_2,&y_2);
            make_line(x_1,y_1,x_2,y_2);
        }
        else
        {
            scanf("%d %d %c",&x,&y,&str);
            BFS_fill(x,y,str);
        }
    }
    output();
    return 0;
}