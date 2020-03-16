#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int room_number=0;
int destination=0;
struct room
{
    int a;
    int b;
    bool operator<(const room& ano)
    {
         return a<ano.a;
    }
}a[25001];
int choose(int begin,int end)
{
    int cnt=0;
    int j=0;
    int flag=0;
    for(int i=0;i<room_number;i++)
    {
        int max_choose=-2e9;
        for(j=i;j<room_number && a[j].a<=begin;j++)
        {
            max_choose=max(max_choose,a[j].b);
        }
        if(max_choose<begin)
        {
            cnt=-1;
            break;
        }
        cnt++;
        if(max_choose>=end)
        {
        	flag=1;
            break;
        }
        i=j-1;
        begin=max_choose+1;
    }
    if(flag==1)
    return cnt;
    else
    return -1;
}
int main()
{
    while(scanf("%d%d",&room_number,&destination)!=EOF)
    {
    	for(int i=0;i<room_number;i++)
    	{
    		a[i].a=0;
    		a[i].b=0;
		}
        int begin,end=0;
        for(int i=0;i<room_number;i++)
        {
            scanf("%d %d",&begin,&end);
                a[i].a=begin;
                a[i].b=end;
        }
        sort(a,a+room_number);
        int number=choose(1,destination);
        cout<<number<<endl;
    }
    return 0;
}