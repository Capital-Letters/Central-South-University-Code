#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int money[6]={100,50,10,5,2,1};
    while(scanf("%d",&n)==1)
    {
        int salary;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            cin >> salary;
            
            while(salary!=0)
            {
                for(int j=0;j<6;j++)
                {
                    if(salary-money[j]>=0)
                    {
                        salary-=money[j];
                        break;
                    }
                }
                cnt++;
            }
            sum+=cnt;
        }
        cout << sum << endl;
    }
    // int sum;
    // int n,i,j,m;
    // while(scanf("%d",&n)!=0)
    // {
    //     sum=0;
    //     for(int i=1;i<=n;i++)
    //     {
    //         scanf("%d",&m);
    //         sum+=m/100+m%100/50+m%100%50/10+m%100%50%10/5+m%100%50%10%5/2+m%100%50%10%5%2;
    //     }
    //     cout<<sum << endl;
        
    // }
}