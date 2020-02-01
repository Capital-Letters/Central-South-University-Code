#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    
    while(scanf("%d %d",&a,&b)==2)
    {
        int count=0;
        int shuxianhuashu[b-a];
        for(int i=a;i<=b;i++)
        {
            int temp=i;
            int sum=0;
            while (temp>0)
            {
                sum+=((temp%10)*(temp%10)*(temp%10));
                temp/=10;
            }
            if(sum==i)
            {
                shuxianhuashu[count++]=i;
            }
        }
        if(count==0) cout << "no";
        else
        {
            for(int i=0;i<count;i++)
            {
                if(i!=0) cout << " ";
                cout << shuxianhuashu[i];
            }
        }
        cout<<endl;
        
    }
}