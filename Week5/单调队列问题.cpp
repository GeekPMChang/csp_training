#include<iostream>
#include<cstdio>
using namespace std;
int q[1000010];
int a[1000010];
int max_num[1000010];
int min_num[1000010];
int number=0;
int win=0;
void make_max()//维持递减数列
{
    int L=1;
    int R=0;
    for(int i=1;i<=number;i++)
    {
        while(R>=L && a[q[R]]<=a[i])
        {R--;}
        q[++R]=i;
        if(q[R]-q[L]>win-1)
        L++;
        max_num[i]=q[L];
    }
}
void make_min()//维持递增数列数列
{
    int L=1;
    int R=0;
    for(int i=1;i<=number;i++)
    {
        while(R>=L && a[q[R]]>=a[i])
        {R--;}
        q[++R]=i;
        if(q[R]-q[L]>win-1)
        L++;
        min_num[i]=q[L];
    }
}
int main()
{
    scanf("%d %d",&number,&win);
    for(int i=1;i<=number;i++)
    {
        scanf("%d",&a[i]);
    }
    make_max();
    make_min();
    for(int i=win;i<=number;i++)
    {
        printf("%d ",a[min_num[i]]);
    }
    printf("\n");
    for(int i=win;i<=number;i++)
    {
        printf("%d ",a[max_num[i]]);
    }
    printf("\n");
    
    return 0;
}