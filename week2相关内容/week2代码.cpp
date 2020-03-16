#include<iostream>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<map>
#include<vector>
using namespace std;
struct point
{
    /* data */
    int x;
    int y; 
};
const int maxn=10;
int dx[]={+1,-1,0,0};
int dy[]={0,0,+1,-1};
int vis[maxn][maxn];
point dis[maxn][maxn];
vector<point> v;
void print(point &p)
{
	point target=p;
	v.push_back(p);
	while(target.x!=0 | target.y!=0)
	{
		target=dis[target.x][target.y];
		v.push_back(target);
	}
	for(int i=v.size()-1;i>=0;i--)
	{
		printf("(%d, %d)\n",v[i].x,v[i].y);
	}
}
void bfs(int sx,int sy,int tx,int ty)
{
	point target={tx,ty};
    point the_begin={sx,sy};
    queue<point> Q;
    Q.push(the_begin);
    vis[sx][sy]=0;
    while(!Q.empty()){
        point now=Q.front(); Q.pop();
        if(now.x==tx &&now.y==ty)
        print(target);
        for(int i=0;i<4;i++){
            int newx=now.x+dx[i],
                newy=now.y+dy[i];
                point start={now.x,now.y};
                point finish={newx,newy};
                if(newx>=0 && newx<=4 && newy>=0 && newy<=4 && vis[newx][newy]==-1){
                	vis[newx][newy]=vis[now.x][now.y]+1;
                    Q.push(finish);
                    dis[newx][newy]=start;
            }
        }
    }
}
int main()
{
    memset(vis,-1,sizeof(vis));
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            int number=0;
            cin>>number;
            if(number==1)
            {
                vis[i][j]=-2;
            }
        }
    }
	bfs(0,0,4,4);
    return 0;
}
