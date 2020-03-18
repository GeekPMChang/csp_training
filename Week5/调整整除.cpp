#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000001];
int number=0;
int sum1=0;
int sum2=0;
int sum3=0;
int sum4=0;
int max_one(int a,int b,int c,int d)
{
	int maxone=0;
    if(a>=maxone)
    maxone=a;
    if(b>=maxone)
    maxone=b;
    if(c>=maxone)
    maxone=c;
    if(d>=maxone)
    maxone=d;
    return maxone; 
}
bool balance_criticize(int x,int y)
{
    int maxx=max_one(sum1,sum2,sum3,sum4);
    int need_fill_number=maxx*4-sum1-sum2-sum3-sum4;
    int free_number=y-x+1-need_fill_number;
    if(free_number%4==0 && free_number>=0)
    return true;
    else
    return false;
}
int main()
{
    string s;
    cin>>s;
    int flag1=0;
    int flag2=0;
    int flag3=0;
    int flag4=0;
    for(int i=0;i<s.length();i++)
    {
        if(s.at(i)=='Q')
        a[i]=1,flag1++;
        else if(s.at(i)=='W')
        a[i]=2,flag2++;
        else if(s.at(i)=='E')
        a[i]=3,flag3++;
        else if(s.at(i)=='R')
        a[i]=4,flag4++;
    }
    if(flag1==flag2 &&flag2==flag3 && flag3==flag4)
    {
    	printf("0\n");
	}
	else
	{
    number=s.length();
    int L=0;
	int R=0;
	for(int i=1;i<number;i++)
	{
	 
    if(a[i]==1)
        sum1++;
    else if(a[i]==2)
        sum2++;
    else if(a[i]==3)
        sum3++;
    else if(a[i]==4)
        sum4++; 
    }
    int ans=100001;
    while(R<number-1) 
    {
        while(R<number-1 && balance_criticize(L,R)==false)
        {
            R++;
            if(a[R]==1)
            sum1--;
            else if(a[R]==2)
            sum2--;
            else if(a[R]==3)
            sum3--;
            else if(a[R]==4)
            sum4--;
        }
         ans=min(ans,R-L+1);
        while(balance_criticize(L,R)==true && L<=R)
        {
            L++;
            if(a[L-1]==1)
            sum1++;
            else if(a[L-1]==2)
            sum2++;
            else if(a[L-1]==3)
            sum3++;
            else if(a[L-1]==4)
            sum4++;
            if(balance_criticize(L,R)==true && R>=L) 
            ans=min(ans,R-L+1);
        }
        if(L>R) 
        {
            R=L;
            if(a[R]==1)
            sum1--;
            else if(a[R]==2)
            sum2--;
            else if(a[R]==3)
            sum3--;
            else if(a[R]==4)
            sum4--;
        }
    }
    printf("%d\n",ans);
	}
    return 0;
}