#include<iostream>
#include<cstdio>
#include<algorithm>

long long prefix[1000010];
void add_change(long long x,long long y,long long change)
{
    prefix[x]+=change;
    prefix[y+1]-=change;
}

int main()
{
    long long number;
    long long change_number;
    scanf("%lld %lld",&number,&change_number);
    long long last_number=0;
    long long cin_number=0;
    
    for(int i=1;i<=number;i++)
    {   
        scanf("%lld",&cin_number);
        prefix[i]=cin_number-last_number;
        last_number=cin_number;
    }
    long long change_x=0;
    long long change_y=0;
    long long the_change=0;
    for(int i=0;i<change_number;i++)
    {
    	scanf("%lld %lld %lld",&change_x,&change_y,&the_change);
		add_change(change_x,change_y,the_change);
	}
	long long front_number=0;
    for(int i=1;i<=number;i++)
    {
        printf("%lld ",front_number+prefix[i]);
        front_number=front_number+prefix[i];
    }
    return 0;
}
