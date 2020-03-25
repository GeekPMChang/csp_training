#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int flag=1e5+1;
struct Edge
{
    int start;//起点
    int end;//终点
    int nxt;//下一条边的编号
    int value;
}Edges[flag];//边集
int Map[flag];//前向星数组
int key;//边数
void init(int point_number)
{
    key=0;
    for(int i=1;i<=point_number;i++)
    Map[i]=-1;
}
void addEdge(int x,int y,int z)
{
    Edges[key].start=x;
    Edges[key].end=y;
    Edges[key].value=z;
    Edges[key].nxt=Map[x];
    Map[x]=key;
    key++;
}
int max_length[flag];
int vis[flag];//访问数组
int max_point=0;
int maxLength=0;
queue<int> q;   
int pointNumber=0;
void BFS(int x)
{
    for(int i=0;i<=pointNumber;i++)
    {
        vis[i]=0;
        max_length[i]=0;
    }
    max_point=0;
    maxLength=0;
    q.push(x);
    vis[x]=1;
    while(!q.empty())
    {
        int vis_flag=0;//该点的边访问指针
        int head=q.front();//该点的一个哨兵，方便后面计算length，指向这个点
        vis_flag=Map[q.front()];
        q.pop();
        while (vis_flag!=-1)//有下一条边访问
        {
            if(vis[Edges[vis_flag].end]==0)//没访问过
            {
                q.push(Edges[vis_flag].end);
                vis[Edges[vis_flag].end]=1;//标为访问过
                max_length[Edges[vis_flag].end]=max_length[head]+Edges[vis_flag].value;//更新距离
                if(max_length[Edges[vis_flag].end]>maxLength)
                {
                    maxLength=max_length[Edges[vis_flag].end];
                    max_point=Edges[vis_flag].end;
                }
            }
            vis_flag=Edges[vis_flag].nxt;
        }
    }
}
int point1_dis[flag];
int point2_dis[flag];
void copy_dis1()
{
	for(int i=1;i<=pointNumber;i++)
	point1_dis[i]=0;
	for(int i=1;i<=pointNumber;i++)
    point1_dis[i]=max_length[i];
}
void copy_dis2()
{
	for(int i=1;i<=pointNumber;i++)
	point2_dis[i]=0;
	for(int i=1;i<=pointNumber;i++)
    point2_dis[i]=max_length[i];
}
int main()
{
    while(cin>>pointNumber)
    {
    init(pointNumber);
    int value,end_poiont=0;
    for(int i=2;i<=pointNumber;i++)
    {
        cin>>end_poiont>>value;
        addEdge(i,end_poiont,value);
        addEdge(end_poiont,i,value);
    }
    BFS(1);
    int point1=max_point;
    BFS(point1);
    copy_dis1();
    int point2=max_point;
    BFS(point2);
    copy_dis2();
    for(int i=1;i<=pointNumber;i++)
    {
        if(point1_dis[i]>point2_dis[i])
        printf("%d\n",point1_dis[i]);
        else
        printf("%d\n",point2_dis[i]);
    }
	/*for(int i=1;i<=pointNumber;i++)
	{
		int vis_flag=0;
		vis_flag=Map[i];
        cout<<i<<":";
		while(vis_flag!=-1)
		{
			cout<<Edges[vis_flag].end<<" "<<Edges[vis_flag].value<<"--";
            vis_flag=Edges[vis_flag].nxt;
		}
        cout<<endl;
	 }*/	
	}
    return 0;
}