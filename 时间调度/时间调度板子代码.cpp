#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int map[10000];//记录整个数组每个点是否被访问过 
struct time
{
    int begin_time;
    int end_time;
    time()
    {
        begin_time=0;
        end_time=0;
    }
    bool operator<(const time &a)const//这里要重载<运算符，方便后面使用sort() 
    {
        if(end_time!=a.end_time) return end_time<a.end_time;//优先级应该是end_time最高，贪心原则是根据任务结束时间排序，且应该是升序排列 
        return begin_time>a.begin_time;//在相同结束时间的时候，选开始时间晚的，这样满足选取的区间最多 
    }
    void print()
    {
        cout<<begin_time<<" "<<end_time<<endl;
    }
    bool choose()//选取函数，返回值决定是否选择这个区间 
    {
    	bool flag=true;
    	for(int i=begin_time;i<=end_time;i++)//遍历起始点到结束点，如果有已经选取过的点，则这个时间段不能再选取，返回false 
    	{
    		if(map[i]==1)
    		flag=false;
		}
		if(flag==true)//如果判断这个点可以确定选取(返回值为true)，将时间段之间的点都标记上 
		{
			for(int i=begin_time;i<=end_time;i++)
			{
				map[i]=1;
			}
		}
		return flag;//返回值如果是true，证明选取了，如果是false，证明不能选取 
	}
	
}; 
int main()
{
    int group=0;//数据的组数 
    int area=0;//数字的取值范围 
    cin>>group>>area;
    time a[10000];
    int record_time[10000];//区间选取数组 
    int time_number=0;//记录有多少个点 
    for(int i=0;i<=area+1;i++)
    {
    	map[i]=0;
	}
    for(int i=1;i<=group;i++)
    {
        int time_1=0;
        int time_2=0;
        cin>>time_1>>time_2;
        a[i].begin_time=time_1;
        a[i].end_time=time_2;
    }
    sort(a,a+group);
    for(int i=1;i<=group;i++)
    {
        bool flag1=a[i].choose();
        if(flag1==true)//接收到的返回值如果是true，将这个点加入到选取数组 
        {
        	record_time[time_number]=i;
        	time_number++;
		}
    }
    cout<<time_number<<endl;//选取的区间个数 
    for(int i=0;i<time_number;i++)//选取的区间 
    {
    	cout<<record_time[i]<<" " ;
	}
    return 0;
}