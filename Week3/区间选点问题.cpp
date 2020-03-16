#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int map[200];
int number=0;
struct time
{
    int a;
    int b;
    bool operator<(const time & ano)const
    {
        if(b!=ano.b) return b<ano.b;
        return a>ano.a;
    }
    void insert()
    {
        bool flag=true;
        for(int i=a;i<=b;i++)
        {
            if(map[i]==1)
            flag=false;
        }
        if(flag==true)
        {
            number++;
            map[b]=1;
        }
    }
};

int main()
{
    int all_number=0;
    cin>>all_number;
    int start=0;
    int end=0;
    time a[200];
    for(int i=0;i<200;i++)
    {
        map[i]=0;
    }
    for(int i=0;i<all_number;i++)
    {
        cin>>start>>end;
        a[i].a=start;
        a[i].b=end;
    }
    sort(a,a+all_number);
    for(int i=0;i<all_number;i++)
    {
        a[i].insert();
    }
    cout<<number<<endl;
    return 0;
}
