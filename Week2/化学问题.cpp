#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int point[10]
int main()
{
    int number=0;
    cin>>number;
    for(int i=0;i<number;i++)
    {
        int start,end;
        for(int i=0;i<10;i++) point[i]=0;
        for(int i=0;i<5)
        {
            cin>>start>>end;
            point[start]++;
            point[end]++;
        }
        int two_time=0;
        int three_time=0;
        for(int i=1;i<=6;i++)
        {
            if(point[i]==4){
                cout<<"2,2-dimethylbutane"<<endl;
                return;
            }
            else if(point[i]==3){
                three_time++;
            }
            else if(point[i]==2){
                two_time++;
            }
        }
        if(three_time==2){
            cout<<"2,3-dimethylbutane"<<endl;
        }
        else if(two_time==4){
            cout<<"n-hexane"<<endl;
        }
        else if(three_time==1 && two_time==2)
        {
            if(point[4]==3){
                cout<<"3-methylpentane"<<endl;
            }
            else
            {
                cout<<"2-methylpentane"<<endl;
            }
            
        }
    }
    return 0;
}