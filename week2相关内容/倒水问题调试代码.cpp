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
/* �ݹ�������� */
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
    { // ���кϷ����������
        from[t] = s;
        Q.push(t);
    }
}

void bfs(int A, int B, int C) 
{
	// ���, ����ˮ����
	status s,t; s.a=0; s.b=0; 
	Q.push(s);

    while (!Q.empty()) 
    {
    	// ȡ����
        s = Q.front(); Q.pop();
        // ���е����յ�
        if (s.a == C || s.b == C) {
            print(s,A,B,C); // �������
			while(!Q.empty())
			Q.pop();
			from.clear(); 
            ans.clear();
            return;
        }

        // ���� a ����ˮ
        if (s.a > 0) {
            t.a = 0;  // ����
            t.b = s.b;// b ������
            refresh(s, t);
        }

        // ͬ������ b ����ˮ
        if (s.b > 0) {
            t.b = 0;  // ����
            t.a = s.a;// a ������
            refresh(s, t);
        }

        // a ��δ�������� a ��
        if (s.a < A) 
        {
        	// ���� a ��
        	t.a = A;  
        	t.b = s.b;
            refresh(s, t);
        }
        // ͬ��b ��δ�������� b ��
        if (s.b < B) 
        {
            //���� b ��
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

