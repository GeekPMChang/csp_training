#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int Flag=3e2+2;
//存边
struct Edge
{
   int start;
   int end;
   int value;
   bool operator<(Edge & a)
   {
       return value<a.value;
   }
}Edges[Flag*Flag];
int total_es=0;

int par[Flag];//并查集祖先数组
int point_num[Flag];//并查集所在集合大小数组
int point_number;//点个数


//并查集
void init()
{
    for(int i=0;i<=point_number;i++)
    {
    par[i]=i;
	point_num[i]=1;
	}
}
int find(int x)
{
    if(par[x]==x)
    return x;
    else
    return find(par[x]);
}
bool unit(int x,int y)
{
    int father_x=find(x);
    int father_y=find(y);
    if(father_x==father_y)
    return false;
    if(point_num[father_x]>point_num[father_y])
    swap(father_x,father_y);
    par[father_x]=father_y;
    point_num[father_y]+=point_num[father_x];
    return true;
}

int kruscal()
{
	init();
    int route_length=0;
    sort(Edges,Edges+total_es);
    for(int i=0;i<total_es;i++)
    {
        bool criticize_flag=unit(Edges[i].start,Edges[i].end);
        if(criticize_flag==true)
        {
            route_length+=Edges[i].value;
        }
    }
    return route_length;
}
int main()
{
    cin>>point_number;
    total_es=0;
    int edge_value;
    for(int i=0;i<point_number;i++)
    {
        cin>>edge_value;
        Edges[total_es].start=i;
        Edges[total_es].end=point_number;
        Edges[total_es].value=edge_value;
        total_es++;
    }
    for(int i=0;i<point_number;i++)
    {
        for(int j=0;j<point_number;j++)
        {
            cin>>edge_value;
            if(i>j)
            {
                Edges[total_es].start=i;
                Edges[total_es].end=j;
                Edges[total_es].value=edge_value;
                total_es++;
            }
        }
    }
    int a=kruscal();
    /*for(int i=0;i<total_es;i++)
    {
        cout<<Edges[i].start<<" "<<Edges[i].end<<" "<<Edges[i].value<<endl;
    }*/
    cout<<a<<endl;
    return 0;
}