#include<iostream>
#include<stdio.h>
#include<stdio.h>
using namespace std;
int num_target[100001];
int num_table[100001];
bool flag=false;
void dfs(int now,int end)
{
    if(now==end)
    {
        if((num_target[now]-num_table[now])%2==0)
        flag=true;
    }
    else if(now<end)
    {
        int need_add=num_target[now]-num_table[now];//今天要花钱买的个数
        int max_next=num_target[now+1];//明天要买的个数
        if(need_add==0)
        {
         dfs(now+1,end);//不用买
        }
        for(int quan=0;quan<=max_next;quan++)
        {
            if((need_add-quan)%2==0)
            {
                num_table[now+1]+=quan;
                dfs(now+1,end);
                num_table[now+1]=0;
            }
        }
    }
}
int main()
{
    int number=0;
    cin>>number;
    for(int i=0;i<number;i++)
    {
        cin>>num_target[i];
        num_table[i]=0;
    }
    dfs(0,number-1);
    if(flag==true)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    return 0;
}