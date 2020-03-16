#include<iostream>
#include<cstdio>
#include <algorithm>
using namespace std;
int a[100001];
int search_j(int find_b,int left,int right)//找到最后一个小于等于x的值--j点位置 (j>i)
{
    int ans=-1;
    int mid=0;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(a[mid]<=find_b)
        {
            ans=mid;
            left=mid+1;
        }
        else
        right=mid-1;
    }
    return ans;
}
int search_mid(int num)//二分答案实质：对整个答案区间进行二分查找，在不知道每个具体值的情况下，利用其他的一些推导函数(例如名次)来进行查找 
{
	int left=0;
	int right=a[num-1]-a[0];
    int mid=0;
    int ans=-1;
	int mid_pos=(num*(num-1)/2+1)/2;
    while(right>=left)
    {
    	int rank=0;
        mid=(left+right)/2; 
        for(int i=0;i<num;i++)
        {
            int flag=search_j(a[i]+mid,0,num-1);
            if(flag!=-1)
            rank+=(flag-i);
        }
        if(rank>=mid_pos)//这里用大于等于的原因是，在等于情况下，有可能名次等于中位数，但是实际上并不是中位数
		//因为这里的rank找的是有多少组i-j<p,如果找的这个P在新的数列中并不存在，他等于队列中上一个比他小的数的名次
		//例如新队列 4 4 4 8 8 12，找5,6,7，得到的rank都等于3，但是其实5 6 7 都不是中位数，所以考虑到这种情况：任何一个数，只要>n,<n+1,在队列中的名次都是n 
		//如果在队列 4 4 4 8 8 12中找中位数，6的rank==3，但是仍然需要向前找---根本原因：rank等于中位数的这个值在生成的数列中不一定存在，且这个值一定大于要找的中位数
		//因为这里规定中位数是向下取整 
        {
            right=mid-1;
            ans=mid;
        }
        else
        left=mid+1;
    }
    return ans;
}
int main()
{
    int number=0;
    while(scanf("%d",&number)!=EOF)
    {
    for(int i=0;i<number;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+number);
    int result=search_mid(number);
    cout<<result<<endl;
    }
    return 0;
}
