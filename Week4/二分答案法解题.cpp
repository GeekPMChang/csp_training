#include<iostream>
#include<cstdio>
#include <algorithm>
using namespace std;
int a[100001];
int search_j(int find_b,int left,int right)//�ҵ����һ��С�ڵ���x��ֵ--j��λ�� (j>i)
{
    int ans=-1;
    int mid=0;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(a[mid]<=find_b)
        {
            ans=mid;
            left=mid+1;
        }
        else
        right=mid-1;
    }
    return ans;
}
int search_mid(int num)//���ִ�ʵ�ʣ���������������ж��ֲ��ң��ڲ�֪��ÿ������ֵ������£�����������һЩ�Ƶ�����(��������)�����в��� 
{
	int left=0;
	int right=a[num-1]-a[0];
    int mid=0;
    int ans=-1;
	int mid_pos=(num*(num-1)/2+1)/2;
    while(right>=left)
    {
    	int rank=0;
        mid=(left+right)/2; 
        for(int i=0;i<num;i++)
        {
            int flag=search_j(a[i]+mid,0,num-1);
            if(flag!=-1)
            rank+=(flag-i);
        }
        if(rank>=mid_pos)//�����ô��ڵ��ڵ�ԭ���ǣ��ڵ�������£��п������ε�����λ��������ʵ���ϲ�������λ��
		//��Ϊ�����rank�ҵ����ж�����i-j<p,����ҵ����P���µ������в������ڣ������ڶ�������һ������С����������
		//�����¶��� 4 4 4 8 8 12����5,6,7���õ���rank������3��������ʵ5 6 7 ��������λ�������Կ��ǵ�����������κ�һ������ֻҪ>n,<n+1,�ڶ����е����ζ���n 
		//����ڶ��� 4 4 4 8 8 12������λ����6��rank==3��������Ȼ��Ҫ��ǰ��---����ԭ��rank������λ�������ֵ�����ɵ������в�һ�����ڣ������ֵһ������Ҫ�ҵ���λ��
		//��Ϊ����涨��λ��������ȡ�� 
        {
            right=mid-1;
            ans=mid;
        }
        else
        left=mid+1;
    }
    return ans;
}
int main()
{
    int number=0;
    while(scanf("%d",&number)!=EOF)
    {
    for(int i=0;i<number;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+number);
    int result=search_mid(number);
    cout<<result<<endl;
    }
    return 0;
}
