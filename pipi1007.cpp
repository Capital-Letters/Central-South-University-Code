#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    while(scanf("%d %d",&x,&y)==2)
    {
        long long sum1=0,sum2=0;
        for(int i=x;i<=y;i++)
        {
            if(i%2==0)
            {
                sum1+=(long long)i*i;
            }
            else
            {
                sum2+=(long long)i*i*i;
            }
            
        }
        cout << sum1 << " " << sum2;
        cout << endl;
    }
}