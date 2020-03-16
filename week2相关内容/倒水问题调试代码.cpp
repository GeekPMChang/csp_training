#include<cstring>
#include<cstdio>
#include<iostream>
#include<map>
#include<queue>
using namespace std;
struct status
{
    /* data */
    int a,b;
    bool operator<(const status &s)const{
        if(a!=s.a) return a<s.a;
        return b<s.b;
    }
    bool operator==(const status &s)const{
		return a==s.a && b==s.b;
	}
};
queue<status> Q;
map<status, status> from;
vector<status> ans;
/* 递归输出方案 */
void print(status &p,int A,int B,int C) 
{
	ans.push_back(p);
	while( from.find(p) != from.end() && (p.a!=0 | p.b!=0))
    {
		p=from[p];
		ans.push_back(p);
    }
	for(int i=ans.size()-1;i>0;i--)
    {
    	status start=ans[i];
    	status end=ans[i-1];
    	if(start.b==end.b)
    	{
    		if(start.a<A && end.a==A)
    		{
    			printf("fill A\n");
			}
			else if(start.a>0 && end.a==0)
			{
				printf("empty A\n");
			}
		}
		else if(start.a==end.a)
		{
			if(start.b<B && end.b==B)
			{
				printf("fill B\n");
			}
			else if(start.b>0 && end.b==0)
			{
				printf("empty B\n");
			}
		}	
		else if(start.a<end.a && start.b>end.b)
		{
			printf("pour B A\n");
		}
		else if(start.a>end.a && start.b<end.b)
		{
			printf("pour A B\n");
		}
	}
	printf("success\n");
}

void refresh(status &s, status &t) 
{
    if ( from.find(t) == from.end() ) 
    { // 特判合法，加入队列
        from[t] = s;
        Q.push(t);
    }
}

void bfs(int A, int B, int C) 
{
	// 起点, 两杯水都空
	status s,t; s.a=0; s.b=0; 
	Q.push(s);

    while (!Q.empty()) 
    {
    	// 取队首
        s = Q.front(); Q.pop();
        // 特判到达终点
        if (s.a == C || s.b == C) {
            print(s,A,B,C); // 输出方案
			while(!Q.empty())
			Q.pop();
			from.clear(); 
            ans.clear();
            return;
        }

        // 倒空 a 杯的水
        if (s.a > 0) {
            t.a = 0;  // 倒空
            t.b = s.b;// b 杯不变
            refresh(s, t);
        }

        // 同理，倒空 b 杯的水
        if (s.b > 0) {
            t.b = 0;  // 倒空
            t.a = s.a;// a 杯不变
            refresh(s, t);
        }

        // a 杯未满，续满 a 杯
        if (s.a < A) 
        {
        	// 续满 a 杯
        	t.a = A;  
        	t.b = s.b;
            refresh(s, t);
        }
        // 同理，b 杯未满，续满 b 杯
        if (s.b < B) 
        {
            //续满 b 杯
            t.a = s.a;
            t.b = B;
            refresh(s, t);
        }

        if (s.b != 0 && s.a<A) 
        {
            if (s.a + s.b <= A) 
            {
                t.a = s.a + s.b;
                t.b = 0;
           		refresh(s, t);
                } else 
            {
                t.a = A;
                t.b = s.a + s.b - A;
            	refresh(s, t);
                }
        }
        if (s.a != 0 && s.b<B) 
        {
            if (s.a + s.b <= B) 
            {
                t.a = 0;
                t.b = s.a + s.b;
                refresh(s, t);
            } else 
            {
                t.a = s.a + s.b - B;
                t.b = B;
                refresh(s, t);
            }
        }
    }
    printf("-1\n");
}
int main() 
{
    int a, b, c; 
    while(cin>>a>>b>>c)
    {
    	bfs(a, b, c);
	}
    return 0;
}/* 26 29 11 */

