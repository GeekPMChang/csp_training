#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
map<char,int> num_map=({
	{"2",2},
    {"3",3},
    {"4",4},
    {"5",5},
    {"6",6},
    {"7",7},
    {"8",8},
    {"9",9},
    {"T",10},
    {"J",11},
    {"Q",12},
    {"K",13},
    {"A",14}
});
map<char,int> col_map=({
    {"C",1},
    {"D",2},
    {"S",3},
    {"H",4}
});
struct person
{
    string pos;
    string num;
    string col;
    int value[20];
    for(int i=0;i<13;i++)
    {
    	value[i]=col_map[col[i]]*14+num_map[num[i]];
	}
    void print()
     {/*
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
         */
        for(int i=0;i<13;i++)
        {
            cout<<value[i]<<" ";
        }
        cout<<endl;
     }
}; 
void position(person *a,string pos)
{
    if(pos=="E")
    {
    	a[0].pos="South player";
        a[1].pos="West player";
        a[2].pos="North player";
        a[3].pos="East player";
        
       
    }
    else if(pos=="S")
    {
        a[3].pos="South player";
        a[0].pos="West player";
        a[1].pos="North player";
        a[2].pos="East player";
    }
    else if(pos=="N")
    {
    	 a[0].pos="East player";
        a[1].pos="South player";
        a[2].pos="West player";
        a[3].pos="North player";
       
    }
    else
    {
         a[2].pos="South player";
        a[3].pos="West player";
        a[0].pos="North player";
        a[1].pos="East player";
    }
}
int main()
{
    string start_pos;
    cin>>start_pos;
    while(start_pos!="#")
    {
        person a[4];
        position(a,start_pos);
        string card;
        string card2; 
        cin>>card;
        cin>>card2;
        card+=card2;
        for(int i=0;i<104;i=i+2)
        {
        	int flag=i/2;
            if(flag%4==0)
            {
               a[0].num+=card[i+1];
               a[0].col+=card[i];
            }
            else if(flag%4==1)
            {
                a[1].num+=card[i+1];
                a[1].col+=card[i];
            }
            else if (flag%4==2)
            {
            	a[2].num+=card[i+1];
                a[2].col+=card[i];
            }
            else if(flag%4==3) 
            {
                a[3].num+=card[i+1];
                a[3].col+=card[i];
            }
        }
        for(int i=0;i<4;i++)
        {
            a[i].print();
        }
        cin>>start_pos;
        }
        return 0;
    }