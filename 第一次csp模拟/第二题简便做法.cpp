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
		//�涨һ���ѡ�����ֻ��һ��1���ģ�ʣ��ȫ��2��������ֻ�������������1��ȯ��ûȯ 
		if(each_day%2==1)//�������������ʣ�»���һ������ 
		{
			if(quan==1)//��ȯ�õ������ȱ����� 
			quan=0;
			else if(quan==0)//û��ȯ�����ã���1һ���õ�һ��ȯ 
			quan=1;
		}
		else if(each_day==0 && quan==1)//���첻��Ҫ�򣬵��ǻ���ȯû�ã�����ʵ�� 
		{
			flag=false;
		}
		//ż�����������Ҫ���ǣ���Ϊż���������������ı�ȯ�����
		//1@������ȯ����һ�š���һ�ţ�ʣ��ȫ��2���ģ�����������ϻ�����ȯ 
		//2@ ����ûȯ��ȫ��2���ģ����ϻ���ûȯ 
	}
	if(flag==false || quan==1)//������꣬��ʣ��һ��ȯ������ʵ�� 
	cout<<"NO"<<endl;
	else
	cout<<"YES"<<endl; 
}
