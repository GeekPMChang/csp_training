#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000];
int main()
{
    int number=0;
    cin>>number;
    for(int i=0;i<number;i++)
    {
        cin>>a[i];
    }
    int sum_value=0;
    cin>>sum_value;
    int L=0;
	int R=0; 
    int ans=10000;
    int sum_number=a[0];
    //整体思路是每次while先移动R到一个解，再移动L，缩小区间长度
    while(R<number-1)//这种条件能够保证在R=number-1，也就是最后一个元素的位置，就直接被筛掉，而不会访问没有元素的区间部分 
    {
        //sum_number<sum_value
        while(R<number-1 && sum_number<sum_value)//这里的松弛条件要和上面的松弛条件保持一致
        {
            R++;
            sum_number+=a[R];
        }
        //出循环的条件是sum_number>=sum_value 或者 R已经达到了数组的边界值下标number-1，再++就会越界 
        ans=min(ans,R-L+1);
        while(sum_number>=sum_value && L<=R)
        {
            sum_number-=a[L];
            L++;
            if(sum_number>=sum_value) //这里如果仍然满足，一定有R>=L，所以R-L+1>=1一定成立 
            ans=min(ans,R-L+1);
        }
        //出循环的条件是sum_number<sum_value 或者 L > R
        if(L>R) //如果在某个位置a[i]>sum_value，这时会出现L++后大于R的情况，要把R上移一位，并且初始化sum_value为a[i+1]的值 
        {
            R=L;
            sum_number=a[L];
        }
    }
    cout<<ans<<endl;
}