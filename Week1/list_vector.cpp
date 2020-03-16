#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;
struct P
{
	int a, b, c;
	P()
	{
		a = 0;
		b = 0;
		c = 0;
	}
	void evalue(int cin_a, int cin_b, int cin_c)
	{
		a = cin_a;
		b = cin_b;
		c = cin_c;
	}
	bool operator<(P& p)
	{
		if (a != p.a) return a > p.a;
		if (b != p.b) return b < p.b;
		return c < p.c;
	}
	void output()
	{
		printf("%d", c);
	}
};
int main()
{
	int number = 0;
	int flag = scanf("%d", &number);
	while (flag == 1)
	{
		P ps[200];
		int length = 0;
		int width = 0;
		for (int i = 0; i < number; i++)
		{
			scanf("%d %d", &length, &width);
			ps[i].evalue(length - width, width, i);
		}
		sort(ps, ps + number);
		for (int i = 0;i < number - 1; i++)
		{
			ps[i].output();
			cout << " ";
		}
		ps[number - 1].output();
		cout << endl;
		flag = scanf("%d", &number);
	}
	return 0;
}
/*
struct P
{
	int a, b, c;
	P()
	{
		a = 0;
		b = 0;
		c = 0;
	}
	void evalue(int cin_a, int cin_b, int cin_c)
	{
		a = cin_a;
		b = cin_b;
		c = cin_c;
	}
	bool operator<(P& p)
	{
		if (a != p.a) return a < p.a;
		if (b != p.b) return b < p.b;
		return c < p.c;
	}
	void output()
	{
		printf("%d %d %d\n", a, b, c);
	}
};
int main()
{
	P ps[100];
	int number1, number2, number3;
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d %d %d", &number1, &number2, &number3);
		ps[i].evalue(number1, number2, number3);
	}
	sort(ps, ps + 5);
	for (int i = 0; i < 5; i++)
	{
		ps[i].output();
	}
}
*/
/*
int main()
{
	list<int> l1;
	l1.push_back(3);
	l1.push_back(4);
	l1.push_front(2);
	for (list<int>::iterator it = l1.begin(); it != l1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	for (list<int>::iterator it = l1.begin(); it != l1.end(); it++)
	{
		l1.insert(it, 1);
	}
	for (list<int>::iterator it = l1.begin(); it != l1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	l1.sort();
	l1.unique();
	for (list<int>::iterator it = l1.begin(); it != l1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	l1.remove(3);
	for (list<int>::iterator it = l1.begin(); it != l1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
*/
/*
int main()
{
	vector<int> v(10,0);
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		int number;
		cin >> number;
		*it = number;
	}
	for (int i = 0, n = v.size(); i < n; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	for (auto i : v) printf("%d ", i);
	cout << endl;
	return 0;
}
*/