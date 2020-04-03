#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<sstream>
using namespace std;


string basic_add;
string each_add;
vector<string> vec;

void change_stack(string & cin_string)
{
	stringstream ss(cin_string);
	string ss_part;
	while(getline(ss,ss_part,'/'))
	{
		if(ss_part=="" || ss_part==".") continue;
		else if(ss_part==".." && !vec.empty()) vec.pop_back();
		else if(ss_part!=".." && ss_part!="" && ss_part!=".") vec.push_back(ss_part);
	}
}

int main()
{
	int add_number=0;
	cin>>add_number;
	cin>>basic_add;
	getchar();
	for(int i=0;i<add_number;i++)
	{
		vec.clear();
		getline(cin,each_add);
		if(each_add=="") each_add=basic_add;
		if(each_add[0]!='/')
		each_add=basic_add+"/"+each_add;
		change_stack(each_add);
		if(vec.empty())
		{
			cout<<"/"<<endl;
			continue;
		}
		for(auto j:vec)
		cout<<"/"<<j;
		cout<<endl;
	}
	return 0;
}
/*const int max_x = 1e3 + 1;
string basic_address[max_x];//存放基础目录
string each_address[max_x];//存放每次操作的目录
int basic_total = 0;//基础目录打开的目录个数
void turn_address(string s)
{
	int now_total = 0;
	if(s[0]!='/')
	{
		//把打开的当前目录复制到操作目录下
		now_total = basic_total;//操作字符串的目录个数
		for (int i = 0; i < basic_total; i++)
			each_address[i] = basic_address[i];
	}
		int flag = 0;//字符串访问哨兵
		int eff_flag = 1;//判断两个/xxxx/之间的内容是.类型还是目录类型
		while (flag < s.length())
		{
			eff_flag = 0;
			while (s[flag] == '/' && flag < s.length())
				flag++;
			while (s[flag] != '/' && flag < s.length())
			{
				char a = s[flag];
				if (a == '.')
				{
					flag++;
					if (flag < s.length())//如果.是最后一个元素,不需要操作
					{
						char b = s[flag];
						if (b == '.')//双点情况，退回一次
						{
							if (now_total > 1)
							{
								each_address[now_total - 1].clear();
								now_total--;
								flag++;
							}
							else
								flag++;
						}
					}
				}
				else
				{
					each_address[now_total] = each_address[now_total] + a;
					flag++;
					eff_flag=1;
				}
			}
			if (eff_flag == 1)
				now_total++;
		}
	if(now_total==0)
	cout<<"/"
	for (int i = 0; i < now_total; i++)
	{
		cout << "/" << each_address[i];
		each_address[i].clear();
	}
	cout << endl;
}
int main()
{
	int number = 0;
	cin >> number;
	string now_add;
	cin >> now_add;
	int basic_flag = 0;
	basic_total = 0;
	int basic_eff_flag = 1;
	while (basic_flag < now_add.length())
	{
		basic_eff_flag=0;
		while (now_add[basic_flag] == '/' && basic_flag < now_add.length())
			basic_flag++;
		while (now_add[basic_flag] != '/' && basic_flag < now_add.length())
		{
			char a = now_add[basic_flag];
			basic_address[basic_total] = basic_address[basic_total] + a;
			basic_flag++;
			basic_eff_flag=1;
		}
		if(basic_eff_flag==1)
		basic_total++;
	}
	for (int i = 0; i < number; i++)
	{
		string new_s;
		getline(cin,new_s)
		if(new_s=="")
		{
			for(int i=0;i<basic_total;i++)
			{
				cout<<"/"<<basic_address[i];
			}
			cout<<endl;
		}
		else
		turn_address(new_s);
	}
	return 0;
}*/
/*
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

int n;
string start;
vector<string> v;//栈结构
void split_stack(string str,vector<string> &v)//将str拆分到栈中
{
    stringstream stemp(str);
    string ss;
    while(getline(stemp,ss,'/'))
    {
        if(ss=="" || ss==".") continue;
        else if(ss==".." && !v.empty()) v.pop_back();
        else if(ss!="..") v.push_back(ss);
    }
}
int main()
{
    cin>>n; cin>>start;
    getchar();//将回车读入
    for (int i=1; i<=n; i++)
    {
        v.clear();
        string s; getline(cin,s);
        if(s=="") s=start;//空字符串代表当前目录
        if(s[0]!='/') s=start+'/'+s;//不以'/'开头的都是以".."或者'.'开头的，是相对路径

        split_stack(s,v);

        if(v.empty()){ cout<<'/'<<endl; continue;}//v为空，说明里面都是'/'，是根目录
        
        for (auto j:v)
            cout<<'/'<<j;
        cout<<endl;
    }
    return 0;
}
*/