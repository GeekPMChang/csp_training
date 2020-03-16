#include<iostream>
#include<stdio.h>
#include<string>
#include<math.h>
using namespace std;
string a="abcdefghijklmnopqrstuvwxyz";
int main()
{
	string cin_s1;
	cin>>cin_s1;
	int the_sum=0;
	int all_number=0; 
    for(int i=0;i<cin_s1.size();i++)
    {
    	int this_number=0;
    	int add_sum=0;
    	while(cin_s1[i]!=a[this_number])
    	{
    		this_number++;
		}
		add_sum=abs(this_number-all_number);
		if(add_sum<=13) 
		{
			the_sum+=add_sum;
		}
		else
		{
			the_sum+=(26-add_sum);
		}
		all_number=this_number;
	}
	cout<<the_sum<<endl;
    return 0;
}