#include<iostream>
#include<stdio.h>
#include<queue>
#include<string>
#include<vector>
using namespace std;
const int M=1e4+5;//注意这里最小是2e3+1
const int N=1e3+5;
const int inf=1e8;
int point_number;//点个数
int eco_line;//经济线条数
int busin_line;//商务线条数
int eco_tot;//经济线add计数
int busin_tot;//商务线add计数
bool cout_flag=true;
vector<int> vec;
struct Edge{
    int to,txt,value;
};
Edge eco_edge[M];//经济线边集
Edge busin_edge[M];//商务线边集

int eco_head[N];
int busin_head[N];

void eco_init()
{
    for(int i=0;i<=point_number;i++)
    eco_head[i]=-1;
}
void eco_add(int x,int y,int value)
{
    eco_tot++;
    eco_edge[eco_tot].to=y;
    eco_edge[eco_tot].value=value;
    eco_edge[eco_tot].txt=eco_head[x];
    eco_head[x]=eco_tot;
}
int vis[N];
int pre[N];
int back[N];

priority_queue<pair<int,int>> q;

void dijkstral(int s,int* dis,int*pre)
{
    while(q.size()) q.pop();

    for(int i=1;i<=point_number;i++)
    dis[i]=inf,vis[i]=0,pre[i]=0;

    dis[s]=0;
    vis[s]=0;
    pre[s]=s;
    q.push(make_pair(0,s));

    while(q.size())
    {
        int x=q.top().second;
        q.pop();
        if(vis[x]==1) continue;
        vis[x]=1;
        for(int i=eco_head[x];i;i=eco_edge[i].txt)
        {
            int y=eco_edge[i].to;
            int value=eco_edge[i].value;
            if(dis[y]>dis[x]+value)
            {
                dis[y]=dis[x]+value;
                pre[y]=x;
                q.push(make_pair(-dis[y],y));
            }
        }
    }
}
int main()
{
    cout_flag=false;
	while(cin>>point_number)
    {
	int start,end=0;

    eco_tot=0;
    busin_tot=0;

    cin>>start>>end;
    cin>>eco_line;
    eco_init();
    for(int i=0;i<eco_line;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        eco_add(x,y,z);
        eco_add(y,x,z);
    }
    int dis_start[N];
    int dis_end[N];
    dijkstral(start,dis_start,pre);
    dijkstral(end,dis_end,back);
    vec.clear();
    int dis_min=dis_start[end];
    int switch_start=0;
    int switch_end=0;
    int switch_line=0;
    cin>>busin_line;
    for(int i=0;i<busin_line;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        if(dis_start[x]+dis_end[y]+z<dis_min)
        {
            dis_min=dis_start[x]+dis_end[y]+z;
            switch_start=x;
            switch_end=y;
            switch_line=1;
        }
        if(dis_start[y]+dis_end[x]+z<dis_min)
        {
            dis_min=dis_start[y]+dis_end[x]+z;
            switch_start=y;
            switch_end=x;
            switch_line=1;
        }
    }

    if(cout_flag==true) printf("\n");
    else cout_flag=true;

    if(switch_line==0)
    {
        int flag=end;
        while(flag!=start)
        {
            vec.push_back(flag);
            flag=pre[flag];
        }
        vec.push_back(start);
        for(int i=vec.size()-1;i>=1;i--)
        printf("%d ",vec[i]);
        printf("%d\nTicket Not Used\n",vec[0]);
        printf("%d\n",dis_min);
    }
    else
    {
    	int flag=switch_start;
        while(flag!=start)
        {
            vec.push_back(flag);
            flag=pre[flag];
        }
        vec.push_back(start);
        flag=switch_end;
        while(flag!=end)
        {
            vec.insert(vec.begin(),flag);
            flag=back[flag];
        }
        vec.insert(vec.begin(),end);
        for(int i=vec.size()-1;i>=1;i--)
        printf("%d ",vec[i]);
        printf("%d\n%d\n",vec[0],switch_start);
        printf("%d\n",dis_min);
	}
    vec.clear();
	}
    return 0;
}
/*
6 1 6
4
1 2 3
2 3 4
3 5 3
5 6 4
1
2 5 5
6 1 6
4
1 2 3
2 3 4
3 5 3
5 6 4
1
2 5 8
*/