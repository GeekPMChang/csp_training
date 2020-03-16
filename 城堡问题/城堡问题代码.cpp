#include<iostream>
#include<stack>
#include<cstring>
#include<stdio.h>
using namespace std;
int rooms[60][60];
int color[60][60];
int maxRoomArea=0;//��󷿼����
int roomNum=0;//�Ѿ��ҵ��ķ������
int roomArea=0;//��ǰ�����ҵķ���������С
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
    int R,C=0;//R��C��
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
                cout<<"��"<<roomNum<<"�����������"<<roomArea<<endl;
                maxRoomArea=max(roomArea,maxRoomArea);
            }
        }
	}
    cout<<"����������"<<roomNum<<endl;
    cout<<"�������������"<<maxRoomArea<<endl;
    return 0;
}
