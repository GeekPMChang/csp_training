#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<string>
using namespace std;

const int M=1e6+1;
const int N=1e3+1;
const int inf=1e8+1;
int point_number;//点个数
int edge_number;
int tot=0;
int point_value[N];//点价值

int head[N];
struct Edge
{
    int to,nxt,value;
}e[M];
void init()
{
    for(int i=0;i<=point_number;i++)
    head[i]=-1;
}
void add(int x,int y)
{
    tot++;
    e[tot].to=y;
    e[tot].value=(point_value[y]-point_value[x])*(point_value[y]-point_value[x])*(point_value[y]-point_value[x]);
    e[tot].nxt=head[x];
    head[x]=tot;
}

int vis[N];//记录是否在队列里
int cnt[N];//记录到该点使用的边数
int dis[N];//记录到该点最短的距离
int flag[N];//记录该点是否是环路影响到的点
int dfs_vis[N];//记录dfs过程中是否被访问过
queue<int> q;

void dfs(int s)
{
    if(dfs_vis[s]==1)
    return;
    else
    {
        dfs_vis[s]=1;
        flag[s]=1;
        for(int i=head[s];i;i=e[i].nxt)
        {
            dfs(e[i].to);
        }
    }
}
void SPFA(int s)
{
    //初始化
    for(int i=1;i<=point_number;i++)
    {
        vis[i]=0;
        cnt[i]=0;
        dis[i]=inf;
        flag[i]=0;
    }
    while(!q.empty()) q.pop();
    vis[s]=1,cnt[s]=0,dis[s]=0,flag[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=head[x];i;i=e[i].nxt)
        {
            int y=e[i].to;
            int value=e[i].value;
            //松弛
            if(dis[y]>dis[x]+value)
            {
                dis[y]=dis[x]+value;
                cnt[y]=cnt[x]+1;
                if(cnt[y]>=point_number)//如果松弛后边数已经>=n，说明成环
                {
                    for(int i=1;i<=point_number;i++)
                    dfs_vis[i]=0;
                    dfs(y);
                }
                if(vis[y]==0 && flag[y]==0)//如果已经在队列中且不是环路点，加入队列
                {
                    vis[y]=1;
                    q.push(y);
                }
            }
        }
    }
}

int main()
{
    int group=0;
    scanf("%d",&group);
    int cout_case=1;
    for(int j=0;j<group;j++)
    {
        //初始化
        tot=0;
        scanf("%d",&point_number);
        for(int i=0;i<=point_number;i++)
        point_value[i]=0;
        //输入
        for(int i=1;i<=point_number;i++)
        {
            scanf("%d",&point_value[i]);
        }
        scanf("%d",&edge_number);
        init();
        for(int i=1;i<=edge_number;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            add(x,y);
        }
        /*for(int i=1;i<=point_number;i++)
        {
            for(int k=head[i];k;k=e[k].nxt)
    			printf("%d %d %d->",i,e[k].to,e[k].value);
            cout<<endl;
        }*/
        SPFA(1);
        /*for(int i=1;i<=point_number;i++)
        {
        	printf("%d ",dis[i]);
		}
		printf("\n");
		for(int i=1;i<=point_number;i++)
        {
        	printf("%d ",flag[i]);
		}
		printf("\n");*/
		printf("Case %d:\n",cout_case);
		cout_case++;
        int check_number=0;
        scanf("%d",&check_number);
        for(int i=1;i<=check_number;i++)
        {
        	int check;
        	scanf("%d",&check);
        	if(dis[check]<3 || flag[check]==1 || dis[check]==inf)
        	printf("?\n");
        	else
        	printf("%d\n",dis[check]);
		}
    }
    return 0;
}
