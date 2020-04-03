#include<string.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	int a=0;
	int b=0;
	while(cin>>s)
	{
		if(s=="+") swap(a,b);
		else if(s=="=")
		{
			if(a+b==0)
			break;
			else
			cout<<a+b<<endl;
			a=0;b=0;
		}
		else if(s=="one") a*=10,a+=1;
		else if(s=="two") a*=10,a+=2;
		else if(s=="three") a*=10,a+=3;
		else if(s=="four") a*=10,a+=4;
		else if(s=="five") a*=10,a+=5;
		else if(s=="six") a*=10,a+=6;
		else if(s=="seven") a*=10,a+=7;
		else if(s=="eight") a*=10,a+=8;
		else if(s=="nine") a*=10,a+=9;
		else if(s=="zero") a*=10,a+=0;
	}
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
*/
/* 
int main()
{
	int m=0;
	int n=0;
	int flag=scanf("%d %d",&m,&n);
	while(flag==2)
	{
		int the_max=0;
		int the_min=0;
		int ou_ans=0;
		int ji_ans=0;
		if(m<=n)
		{
			the_max=n;
			the_min=m;
		}
		else
		{
		the_max=m;
		the_min=n;
		}
		for(int i=the_min;i<=the_max;i++)
		{
			if(i%2==1)
			{
				ji_ans+=i*i*i;
			}
			else
			ou_ans+=i*i;
		}
		cout<<ou_ans<<" "<<ji_ans<<endl;
		flag=0;
		flag=scanf("%d %d",&m,&n);
	}
	return 0;
}
*/
/*
int main()
{
	int number=0;
	cin>>number;
	for(int i=0;i<number;i++)
	{
		int flag;
		double answer=0;
		scanf("%d",&flag);
		for(int i=1;i<=flag;i++)
		{
			if(i%2==1)
			{
				answer+=(double)1/(double)i;
			}
			else
			{
				answer-=(double)1/(double)i;
			}
		}
		printf("%.2f\n",answer);
	}
}
*/
/*
int main()
{
	int list;
	int insert_number;
	int a[10000];
	scanf("%d %d",&list,&insert_number);
	while(list!=0 || insert_number!=0 )
	{
		for(int i=0;i<list;i++)
		{
			int number=0;
			cin>>number;
			a[i]=number;
		}
		int flag=0;
		while(a[flag]<insert_number)
		{
			flag++;
		}
		for(int i=list;i>flag;i--)
		{
			a[i]=a[i-1];
		}
		a[flag]=insert_number;
		for(int i=0;i<list;i++)
		{
			printf("%d",a[i]);
			printf(" ");
		}
		printf("%d\n",a[list]);
		scanf("%d %d",&list,&insert_number);
	}
	return 0;
}
*/
/*
int main()
{
	int number=0;
	cin>>number;
	for(int i=0;i<number;i++)
	{
		char s[1000];
		scanf("%s",s);
		int length=strlen(s);
		bool flag=true;
		for(int i=0;i<length/2;i++)
		{
			if(s[i]!=s[length-1-i])
			flag=false;
		}
		if(flag==true)
		printf("yes\n");
		else
		printf("no\n");
	}
	return 0;
 } 
 */
/*
int main()
{
	int number=0;
	scanf("%d",&number);
	while(number!=0)
	{
		int a[2000];
		for(int i=0;i<number;i++)
		{
			int each_number=0;
			scanf("%d",&each_number);
			a[i]=each_number;
		}
		int target=0;
		scanf("%d",&target);
		int count=0;
		for(int i=0;i<number;i++)
		{
			if(target==a[i])
			{
				count++;
			}
		}
		printf("%d\n",count);
		scanf("%d",&number);
	}
}
*/
/*
int main()
{
	int number=0;
	int flag=scanf("%d",&number);
	while(flag==1)
	{
	int a[200];
	int max_flag=0;
	int min_number=100000;
	int min_flag=0;
	int max_number=0;
	for(int i=0;i<number;i++)
	{
		int each_number=0;
		scanf("%d",&each_number);
		if(each_number>max_number)
		{
			max_number=each_number;
			max_flag=i;
		}
		if(each_number<min_number)
		{
			min_number=each_number;
			min_flag=i;
		}
		a[i]=each_number;
	}
	int all_number=0;
	for(int i=0;i<number;i++)
	{
		if(i!=max_flag && i!=min_flag)
		{
			all_number+=a[i];
		}
	}
	int fenzi=number-2;
	double answer=(double)all_number/(double)fenzi;
	printf("%.2f\n",answer);
	flag=0;
	flag=scanf("%d",&number);
	}
	return 0;
}
*/
/*
int main()
{
	int flag_number=0;
	scanf("%d",&flag_number);
	while(flag_number!=0)
	{
		int answer=0;
		for(int i=0;i<flag_number;i++)
		{
			int person=0;
			scanf("%d",&person);
			int ans=0;
			ans+=person/100;
			person=person%100;
			ans+=person/50;
			person=person%50;
			ans+=person/10;
			person=person%10;
			ans+=person/5;
			person=person%5;
			ans+=person/2;
			person=person%2;
			ans+=person;
			answer+=ans;
		}
		printf("%d\n",answer);
		scanf("%d",&flag_number);
		}	
}
*/
/*int main()
{
	int number=0;
	cin>>number;
	for(int i=0;i<number;i++)
	{
		char s[10000];
		scanf("%s",s);
		int j=strlen(s);
		int num=0;
		for(int i=0;i<j;i++)
		{
			if((int)s[i]>=48 && (int)s[i]<=57)
			{
				num++;
			}
		}
		printf("%d\n",num);
	}
}*/
/*
int main()
{
	char a[10];
	int a_number=scanf("%s",a);	
	while(a_number==1)
	{
	char s_1=a[0];
	char s_2=a[1];
	char s_3=a[2];
	if(s_1>s_2)
	{
		if(s_2>s_3)
		{
			printf("%c %c %c\n",s_3,s_2,s_1);
		}
		else
		{
			if(s_1>s_3)
				printf("%c %c %c\n",s_2,s_3,s_1);
			else
				printf("%c %c %c\n",s_2,s_1,s_3);
		}
	}
	else
	{
		if(s_1>s_3)
			printf("%c %c %c\n",s_3,s_1,s_2);
		else
		{
			if(s_2>s_3)
				printf("%c %c %c\n",s_1,s_3,s_2);
			else
				printf("%c %c %c\n",s_1,s_2,s_3);
		}
	}
	a_number=0;
	a_number=scanf("%s",a);	
	}
	return 0;
	
}
*/
/*
int main()
{
	char s[100];
	int s_number=scanf("%s",&s);
	printf("%d",s_number);
	int a=0;
	int a_number=scanf("%d",&a);
	printf("%d",a_number);
	return 0;
}*/
