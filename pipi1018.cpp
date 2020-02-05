#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int temp=0;
        int sum=0;
        for(int sub=2,i=1;i<=n;i++,sub+=2)
        {
            temp++;
            sum+=sub;
            if(temp==m)
            {
                if(i!=n)
                {
                    sum/=m;
                    cout << sum <<" ";
                    temp=0;
                    sum=0;
                }
            }
        }
        cout << sum/temp << endl;
    }
}