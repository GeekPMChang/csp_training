#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int store_number[20];
int store[20];//存放每个点是否被访问过
int positive_number=0;//可供选择的数字个数
int add_number=0;//累计的数字个数
int num_addition=0;//累计的数字和
int sum_kind=0;//组合种类的个数
void bfs(int number,int addtion,int begin)
{
    if(number==add_number && addtion==num_addition)
    {
        sum_kind++;
    }
    else if(number<add_number)
    {
       if(addtion>=num_addition)
       return;
       else
       {
           for(int i=begin;i<positive_number;i++)
           {
           	if(store[i]==0)
			{
           	   store[i]=1;
               bfs(number+1,addtion+store_number[i],i+1);
           	}
           	store[i]=0;
           }
       }
    }
    
}
int main()
{
    int bfs_times=0;
    cin>>bfs_times;
    for(int i=0;i<bfs_times;i++)
    {
    	for(int k=0;k<20;k++)
    	{
    		store[k]=0;
		}
        cin>>positive_number>>add_number>>num_addition;
        for(int j=0;j<positive_number;j++)
            cin>>store_number[j];
        bfs(0,0,0); 
        cout<<sum_kind++<<endl;
        sum_kind=0;
    }
}
