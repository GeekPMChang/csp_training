#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int quan=0;
	int number=0;
	cin>>number;
	int each_day=0;
	bool flag=true; 
	for(int i=0;i<number;i++)
	{
		cin>>each_day;
		//规定一天的选择：最多只买一次1个的，剩下全买2个，手上只有两种情况：有1张券或没券 
		if(each_day%2==1)//如果买完两个的剩下还差一个不够 
		{
			if(quan==1)//把券用掉来填充缺的这个 
			quan=0;
			else if(quan==0)//没有券可以用，买1一个得到一张券 
			quan=1;
		}
		else if(each_day==0 && quan==1)//今天不需要买，但是还有券没用，不能实现 
		{
			flag=false;
		}
		//偶数的情况不需要考虑：因为偶数两种情况都不会改变券的情况
		//1@手上有券，用一张。买一张，剩下全买2个的，这天结束手上还是有券 
		//2@ 手上没券，全买2个的，手上还是没券 
	}
	if(flag==false || quan==1)//最后都买完，还剩了一张券，不能实现 
	cout<<"NO"<<endl;
	else
	cout<<"YES"<<endl; 
}
