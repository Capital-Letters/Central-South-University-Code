#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {   
        int A[n];
        for(int i=0;i<n;i++)
        {
            cin >> A[i];
        }
        int min;
        int min_i;
        int cost=0;
        for(int k=0;k<n-1;k++)
        {
            min=3000;
            for(int i=0;i<n-1-k;i++)
            {
                if(A[i]+A[i+1]<min)
                {
                    min=A[i]+A[i+1];
                    min_i=i;
                }
            }
            cost+=min;
            A[min_i]=min;
            for(int i=min_i+1;i<n-1-k;i++)
            {
                A[i]=A[i+1];
            }
        }
        cout << cost << endl;
    }
}