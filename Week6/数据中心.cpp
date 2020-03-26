#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int flag1=5e4+1;
const int flag2=1e5+1;
int point_number=0;//点数量
int edge_number=0;//边数量
struct Edge
{
    int start;
    int end;
    int value;
    bool operator<(Edge & a)
    {
        return value<a.value;
    }
}Edges[flag2];

int par[flag1];
int key[flag1];
void init()
{
    for(int i=1;i<=point_number;i++)
    {
        par[i]=i;
        key[i]=1;
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
    if(key[father_x]>key[father_y])
    swap(father_x,father_y);
    par[father_x]=father_y;
    key[father_y]+=key[father_x];
    return true;
}

int length=0;
int kruskal()
{
    init();
    sort(Edges,Edges+edge_number);
    for(int i=0;i<edge_number;i++)
    {
        bool unit_flag=unit(Edges[i].start,Edges[i].end);
        if(unit_flag==true)
        {
            if(length<Edges[i].value)
            length=Edges[i].value;
        } 
    }
    return length;
}
int main()
{
    cin>>point_number;
    cin>>edge_number;
    int begin_root=0;
    cin>>begin_root;
    int point_start=0;
    int point_end=0;
    int point_value=0;
    for(int i=0;i<edge_number;i++)
    {
        cin>>point_start>>point_end>>point_value;
        Edges[i].start=point_start;
        Edges[i].end=point_end;
        Edges[i].value=point_value;
    }
    int a=kruskal();
    /*for(int i=0;i<edge_number;i++)
    {
    	cout<<Edges[i].start<<" "<<Edges[i].end<<" "<<Edges[i].value<<endl;
	}*/
    cout<<a<<endl;
    return 0;
}