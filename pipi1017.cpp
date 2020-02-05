#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        int dis[k+1];
        for(int i=0;i<=k;i++)
        {
            cin>>dis[i];
        }
        int temp=n;
        int count=0;
        int flag=0;
        for(int i=0;i<=k;i++)
        {
            if(n<dis[i])
            {
                flag=1;
                break;
            } 
            if(temp-dis[i]<0)
            {
                temp=n;
                count++;
            }
            temp-=dis[i];
            if(temp==0)
            {
                temp=n;
                count++;
            }
        }
        if(flag)
        {
            cout << "NoSolution" << endl;
        }
        else cout<< count << endl;
        
    }
}