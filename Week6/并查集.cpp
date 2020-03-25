#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int max_floor=3e4;
int parent[max_floor];
int number[max_floor];
int find(int pos)
{
    if(parent[pos]==pos)
    return pos;
    else 
    return find(parent[pos]); 
}
void unit(int x,int y)
{
    int father_x=find(x);
    int father_y=find(y);
    if(father_x==father_y)
    return;
    if(number[father_x]>number[father_y])
    swap(father_x,father_y);
    parent[father_x]=father_y;
    number[father_y]+=number[father_x];
    //cout<<x<<"--"<<father_x<<" "<<y<<"--"<<father_y<<endl; 
}
int main()
{
    int student,group=0;
    cin>>student>>group;
    while(student!=0)
    {
    for(int i=0;i<student;i++)
    {
        parent[i]=i;
		number[i]=1;
    }
    for(int i=0;i<group;i++)
    {
        int parter=0;
        cin>>parter;
        int start=0;
        cin>>start;
        int point=0;
        for(int j=1;j<parter;j++)
        {
        	cin>>point;
        	unit(start,point);
		}
    }
    int flag=find(0);
    cout<<number[flag]<<endl;
    cin>>student>>group;
	}
    return 0;
}