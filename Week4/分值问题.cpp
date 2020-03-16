#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct ddl
{
    int time;
    int score;
    int flag;
    bool operator<(ddl & a)
    {
        return score>a.score;
    }
}a[1010];
int main()
{
    int number=0;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int all_score=0;
        int end_time=0;
        int choose_score=0; 
        int group=0;
        scanf("%d",&group);
        for(int j=0;j<group;j++)
        {
            a[j].flag=0;
            a[j].score=0;
            a[j].time=0;
            scanf("%d",&a[j].time);
            if(a[j].time>end_time)
            end_time=a[j].time;
        }
        for(int j=0;j<group;j++)
        {
            scanf("%d",&a[j].score);
            all_score+=a[j].score;
        }
        sort(a,a+group);
        for(int k=end_time;k>=1;k--)
        {
            for(int q=0;q<group;q++)
            {
                if(a[q].flag==0 && a[q].time>=k)
                {
                    a[q].flag=1;
                    choose_score+=a[q].score;
                    break;
                }
            }
        }
        printf("%d\n",all_score-choose_score);
    }
}