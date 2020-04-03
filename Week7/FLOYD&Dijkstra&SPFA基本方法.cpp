#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

void Floyd(int n,int dis**)
{
    for(int k=1;k<=n;k++)//外面k层是更新的次数
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}

//n个人
//A>B && B>C -->A>C
//使用Floyd解决
//因为胜负关系具有传递性，可以使用FLoyd传递闭包
//dis[a][b]=1表示a比b强
//dis[a][b]=0表示a和b的关系不知道
//dis[a][b]=0 && dis[b][a]则a和b的大小关系不已知


//dijkstra
//维护一个最小堆， 和一个距离原点的距离数组(因为最小堆的初始化不好写，一般用最大堆，将距离的负值传入到最大堆中，拿到的堆顶元素就和最小堆一致了)
//从堆中取出一个距离源点最小的点，如果这个点没有被弹出过(dijkstra每个点可以被弹出多次只能被弹出一次)
//遍历他的所有边，如果能够完成松弛，将松弛的点加入堆中

//dijkstra的最大距离问题
//从最大堆中弹出的点更新后结果不一定是最后的结果，所以并不需要记录是否被弹出过
//如果x=q.top().first<dis[x],说明这个点的最长距离已经被其他点更新过，不是最长路径，直接continue

const int inf=1e8;
const int M=1e6;
const int N=1e5;
struct Edge
{
    int to,nxt,value;
}e[M];

int head[N];
int tot=1;
int dis[N];
int n;//点数
int m;//边数
void init(int num)
{
    for(int i=1;i<=num;i++)
    head[i]=-1;
}
void add(int x,int y,int value)
{
    tot++;
    e[tot].to=y;
    e[tot].value=value;
    e[tot].nxt=head[x];
    head[x]=tot;
}
priority_queue<pair<int,int>> q;
void dijkstra(int s)
{
    while(q.size()) q.pop();
    //初始化
    for(int i=1;i<=n;I++)
    vis[i]=0,dis[i]=inf;
    dis[s]=0;
    q.push(make_pair(0,s));
    //初始化堆和访问数组
    while(q.size())
    {
        int x=q.top().second;
        q.pop();
        //每个点只能被弹出一次
        //在dijkstra的最短路中，一个点被堆弹出一次，则它已经到达最短路
        if(vis[x]==1) continue;
        vis[x]=1;
        //取出堆
        for(int i=head[x];i>=0;i=e[i].nxt)
        {
            int y=e[i].to;
            int value=e[i].value;
            if(dis[y]>dis[x]+value)//松弛
            {
                dis[y]=dis[x]+value;
                q.push(make_pair(-dis[y],y));
            }
        }
    }
}

//bellman-ford算法O(mn):个给出原点到所有点的最短路和前驱子图
//条件：1、无负环2、使用最短的子路进行松弛的长路，一定是最短路
//算法跑n-1轮，每一轮向前优化最短边一次
//松弛n-1轮就可以确定出全部边
//由于最短路的路径条数小于点数，所以n-1轮
struct edge
{
    int x;
    int y;
    int value;
};
edge edges[1000];
for(int i=0;i<=n;i++)
{
    dis[i]=inf;
    pre[i]=0;
}
dis[s]=0;
//更新n-1趟，每次更新全部边，并不够优秀
for(int k=1;k<n;k++)
    for(int i=0;i<=m;i++)
    {
        if(dis[edges[i].y)>dis[edges[i].x]+edges[i].value)
        {
            dis[edges[i].y]=dis[edges[i].x]+edges[i].value;
            pre[edges[i].y]=edges[i].x;
        }

    }

//SPFAO(km) k是一个一般比较小的常数，一般小于n，所以SPFA算法比较优秀
//只做有效的的松弛操作(因为只有被松弛过的边才会被再次松弛其他的边)
//建立一个队列
//从队列中取出头结点，并查看是否可以松弛
//如果做了松弛操作加入队列
//要注意的是，记录一个从原点到某个点的边数cnt[x],因为按照bellman-ford的原理
//一旦边数达到n，证明出现了负环。
//SPFA每个点可以进队列多次，多次松弛
queue<int> q;
int cnt[N];
int vis[N];
int pre[N];
int dis[N];
void SPFA(int s)
{
    while(q.size()) q.pop();
    //q置空
    for(int i=1;i<=n;i++)
    { cnt[i]=0,dis[i]=inf,pre[i]=0;vis[i]=0;}
    pre[s]=s;
    cnt[s]=0;
    dis[s]=0;
    vis[s]=1;//证明这个点在松弛队列中
    q.push(s);
    while(q.size())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        //x出队，则将vis[x] 重置为0
        for(int i=head[x];i;i=e[i].nxt)
        {
            int y=e[i].to;
            int value=e[i].value;
            if(dis[y]>dis[x]+value)//松弛
            {
                dis[y]=dis[x]+value;
                pre[y]=x;
                cnt[y]=cnt[x]+1;
                if(cnt[y]>=n)//负环
                {
                    dfs(y);//找到负环就dfs负环点，都标记为-inf
                    //标记到的这些点永远不能进队列
                }
                if(vis[y]==0)//如果队列中没有这个点，就加入到队列中
                {
                    vis[y]=1;
                    q.push(y);
                }
            }
        }
    }
}


//关于负环
//考虑单源最短路径问题时，如果都为正值，使用dijkstra
//如果有负值，使用bellman-ford或SPFA，如果出现cnt[x]>=n,说明有负环
//有负环，则无最短路径
//y在负环上，dis[y]=-inf
//所有会被y到达的点的dis[]都需要变成-inf
//使用dfs就可以，只要能够dfs打上负环标记的都是-inf
