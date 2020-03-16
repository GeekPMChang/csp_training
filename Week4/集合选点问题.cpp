#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> a,b,c,d,a_b; 
int find_L(int num)
{
    int left=0;
    int right=a_b.size()-1;
    int ans=-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(a_b.at(mid)==num)
        {
            right=mid-1;
            ans=mid;
        }
        else if(a_b.at(mid)>num)
        right=mid-1;
        else
        left=mid+1;
    }
    return ans;
}
int find_R(int num)
{
    int left=0;
    int right=a_b.size()-1;
    int ans=-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(a_b.at(mid)==num)
        {
            left=mid+1;
            ans=mid;
        }
        else if(a_b.at(mid)>num)
        right=mid-1;
        else
        left=mid+1;
    }
    return ans;
}
int main()
{
    int number=0;
    int compose_num=0;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int cin_a,cin_b,cin_c,cin_d=0;
        scanf("%d %d %d %d",&cin_a,&cin_b,&cin_c,&cin_d);
        a.push_back(cin_a);
        b.push_back(cin_b);
        c.push_back(cin_c);
        d.push_back(cin_d);
    }
    for(vector<int>::iterator it=a.begin();it!=a.end();it++)
    {
        for(vector<int>::iterator jt=b.begin();jt!=b.end();jt++)
        {
            a_b.push_back(*it+*jt);
        }
    }
    sort(a_b.begin(),a_b.end());
    int c_d=0;
    for(vector<int>::iterator it=c.begin();it!=c.end();it++)
    {
        for(vector<int>::iterator jt=d.begin();jt!=d.end();jt++)
        {
            c_d=-1*(*it+*jt);
            int flag1=find_L(c_d);
            int flag2=find_R(c_d);
            if(flag1!=-1 && flag2!=-1)
            compose_num+=(flag2-flag1+1);
        }
    }
    cout<<compose_num<<endl;
    return 0;
}