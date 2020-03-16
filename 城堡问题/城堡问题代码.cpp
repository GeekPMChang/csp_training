#include<iostream>
#include<stack>
#include<cstring>
#include<stdio.h>
using namespace std;
int rooms[60][60];
int color[60][60];
int maxRoomArea=0;//最大房间面积
int roomNum=0;//已经找到的房间个数
int roomArea=0;//当前正在找的房间的面积大小
void Dfs(int i,int k)
{
    if(color[i][k]!=0) return;
    ++roomArea;
    color[i][k]=roomNum;
    if((rooms[i][k]&1)==0) Dfs(i,k-1);
    if((rooms[i][k]&2)==0) Dfs(i-1,k);
    if((rooms[i][k]&4)==0) Dfs(i,k+1);
    if((rooms[i][k]&8)==0) Dfs(i+1,k);
}
int main()
{
	freopen("chengbao_data.txt","r",stdin);
    int R,C=0;//R行C列
    cin>>R>>C;
    for(int i=1;i<=R;++i)
        for(int k=1;k<=C;++k)
        {
            cin>>rooms[i][k];
        }
    memset(color,0,sizeof(color));
    for(int i=1;i<=R;++i)
    {
        for(int k=1;k<=C;++k)
        {
            if(color[i][k]==0)
            {
                ++roomNum;
                roomArea=0;
                Dfs(i,k);
                cout<<"第"<<roomNum<<"个分区面积："<<roomArea<<endl;
                maxRoomArea=max(roomArea,maxRoomArea);
            }
        }
	}
    cout<<"分区个数："<<roomNum<<endl;
    cout<<"最大的区域面积："<<maxRoomArea<<endl;
    return 0;
}
