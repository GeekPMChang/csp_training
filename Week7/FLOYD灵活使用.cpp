#include<iostream>
#include<stdio.h>
using namespace std;
const int M=5e2+1;
int dis[M][M];
int point_num;
int edge_num;
int floyd()
{
    int cnt=0;
    for(int k=1;k<=point_num;k++)
        for(int i=1;i<=point_num;i++)
        {
        	if(dis[i][k]!=1)//使用剪枝
        	{ continue;}
            for(int j=1;j<=point_num;j++)
            {
                if(dis[i][k]==1 && dis[k][j]==1 && dis[i][j]==0)
                {
                    dis[i][j]=1;
                    cnt++;
                }
        	}
        }
    return cnt;
}
int main()
{
    int group_num=0;
    cin>>group_num;
    for(int i=1;i<=group_num;i++)
    {
    	int a=0;
    	int b=0;
    	int cnt=0; 
        cin>>point_num>>edge_num;
        for(int j=1;j<=point_num;j++)
            for(int k=1;k<=point_num;k++)
                dis[j][k]=0;
        for(int j=0;j<edge_num;j++)
        {
            cin>>a>>b;
            dis[a][b]=1;
            cnt++;
        }
        cnt+=floyd();
        int res=(point_num*(point_num-1)/2)-cnt;
        cout<<res<<endl;;     
    }
}