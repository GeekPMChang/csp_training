#include<iostream>
#include<stdio.h>
#include<stack>
#include<algorithm>
using namespace std;
long long n;
long long a[100010];long long L[100010];long long R[100010];
stack<int> s;
//对于i来说
//L：i能向左边延伸的最靠左的位置 
//L[n]  等于他左边第一个比他小的位置-1
//R: i能向右边延伸的最靠右的位置
//R[n]  等于他右边第一个比他小的位置+1
/*模拟一个例子：
[3 1 2 4 0]
[3]
[3 1]
[1] R[1]=2-1
[1 2]
[1 2 4]
[1 2 4 0]
[1 2 0] R[4]=5-1=4
[1 0]  R[3]=5-1=4
[0 ] R[2]=5-1=4
R[5]=5
*/
void solve1()
{
    for(int i=1;i<=n;i++)
    {
    	if(s.empty())
    	s.push(i);
    	else
    	{
        	if(a[s.top()]<=a[i])
            s.push(i);
            else
            {
            	while(a[s.top()]>a[i])
        		{
            		R[s.top()]=i-1;
            		s.pop();
            		if(s.empty())
            		break;
        		}
        		s.push(i);
			}
    	}
    }
    while(!s.empty())
    {
        R[s.top()]=n;
        s.pop();
    }
}
void solve2()
{
    for(int i=n;i>=1;i--)
    {
    	if(s.empty())
    	s.push(i);
    	else
    	{
        	if(a[s.top()]<=a[i])
            s.push(i);
            else
            {
            	while(a[s.top()]>a[i])
        		{
            		L[s.top()]=i+1;
            		s.pop();
            		if(s.empty())
            		break;
        		}
        		s.push(i);
			}
    	}
    }
    while(!s.empty())
    {
        L[s.top()]=1;
        s.pop();
    }
}
int main()
{
	scanf("%lld",&n);
    while(n!=0)
    {
    	for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }  
    solve1();
    solve2();
    long long ans=0;
    for(int i=1;i<=n;i++)
	{
		ans=max(ans,a[i]*(R[i]-L[i]+1));
	 }
    printf("%lld\n",ans);
    scanf("%lld",&n);
	}
    return 0;
}
