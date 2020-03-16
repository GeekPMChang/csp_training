#include<iostream>
#include<string>
#include<cstdio>
#include<map>
using namespace std;
struct person
{
	string pos;
	string num;
	string col;
	int value[20];
	void give_value()
	{
		for (int i = 0; i < 20; i++)
		{
			value[i] = 0;
		}
		for (int i = 0; i < 13; i++)
		{
			int number = 0;
			int colber = 0;
			if (num[i] == '1') number = 1;
			else if (num[i] == '2') number = 2;
			else if (num[i] == '3') number = 3;
			else if (num[i] == '4') number = 4;
			else if (num[i] == '5') number = 5;
			else if (num[i] == '6') number = 6;
			else if (num[i] == '7') number = 7;
			else if (num[i] == '8') number = 8;
			else if (num[i] == '9') number = 9;
			else if (num[i] == 'T') number = 10;
			else if (num[i] == 'J') number = 11;
			else if (num[i] == 'Q') number = 12;
			else if (num[i] == 'K') number = 13;
			else if (num[i] == 'A') number = 14;
			if (col[i] == 'C') colber = 1;
			else if (col[i] == 'D') colber = 2;
			else if (col[i] == 'S') colber = 3;
			else if (col[i] == 'H') colber = 4;
			value[i] = 14 * colber + number;
		}
	}
	void sort_person()
	{
		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 12-i; j++) {
				if (value[j + 1] < value[j]) {
					swap(value[j + 1], value[j]);
					swap(col[j + 1], col[j]);
					swap(num[j + 1], num[j]);
				}
			}
		}
	}
	void print()
	{
		cout<<pos<<":"<<endl;
		for(int i=0;i<52;i++)
		{
			if(i%4==0) cout<<"+";
			else
			cout<<"-";
		}
		cout<<"+"<<endl;

		for(int i=0;i<13;i++)
		{
			cout<<"|"<<num[i]<<" "<<num[i];
		}
		cout<<"|"<<endl;

		for(int i=0;i<13;i++)
		{
			cout<<"|"<<" "<<col[i]<<" ";
		}
		cout<<"|"<<endl;

		for(int i=0;i<13;i++)
		{
			cout<<"|"<<num[i]<<" "<<num[i];
		}
		cout<<"|"<<endl;

		for(int i=0;i<52;i++)
		{
			if(i%4==0) cout<<"+";
			else
			cout<<"-";
		}
		cout<<"+"<<endl;
	}
};
int position(person* a, string pos)
{
	if (pos == "E")
	{
		a[0].pos = "South player";
		a[1].pos = "West player";
		a[2].pos = "North player";
		a[3].pos = "East player";
		return 0;
	}
	else if (pos == "S")
	{
		a[3].pos = "South player";
		a[0].pos = "West player";
		a[1].pos = "North player";
		a[2].pos = "East player";
		return 3;
	}
	else if (pos == "N")
	{
		a[0].pos = "East player";
		a[1].pos = "South player";
		a[2].pos = "West player";
		a[3].pos = "North player";
		return 1;
	}
	else
	{
		a[2].pos = "South player";
		a[3].pos = "West player";
		a[0].pos = "North player";
		a[1].pos = "East player";
		return 2;
	}
}
int main()
{
	string start_pos;
	cin >> start_pos;
	while (start_pos != "#")
	{
		person a[4];
		int thep=position(a, start_pos);
		string card;
		string card2;
		cin >> card;
		cin >> card2;
		card += card2;
		for (int i = 0; i < 104; i = i + 2)
		{
			int flag = i / 2;
			if (flag % 4 == 0)
			{
				a[0].num += card[i + 1];
				a[0].col += card[i];
			}
			else if (flag % 4 == 1)
			{
				a[1].num += card[i + 1];
				a[1].col += card[i];
			}
			else if (flag % 4 == 2)
			{
				a[2].num += card[i + 1];
				a[2].col += card[i];
			}
			else if (flag % 4 == 3)
			{
				a[3].num += card[i + 1];
				a[3].col += card[i];
			}
		}
		for (int i = 0; i < 4; i++)
		{
			int flag = (i + thep) % 4;
			a[flag].give_value();
			a[flag].sort_person();
			a[flag].print();
		}
		cout<<endl;
		cin >> start_pos;
	}
	return 0;
}
