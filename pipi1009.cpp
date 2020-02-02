// #include <iostream>
// using namespace std;

// int max(const int& a, const int& b)
// {
//     return a>b?a:b;
// }

// int main()
// {
//     int a[10005];
//     int count = 0;
//     while(cin >> a[count++]);
//     count--;
//     int ans = 0;
//     int result = a[0];
//     for(int i = 0; i < count; ++i)
//     {
//         ans = max(ans+a[i], a[i]);
//         result = max(result, ans);
//     }
//     cout << result << endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int arr[100000];
    while(cin>>n)
    {
        int flag=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]>=0) flag=1;
        }
        if(!flag) cout << "0 0 0" <<endl;
        else
        {
            int begin=0,right,left,sum=0,b=0;
            for(int j=0;j<n;j++)
            {
                if(b>0)
                {
                    b+=arr[j];
                }
                else
                {
                    b=arr[j];
                    begin=j;
                }
                if(b>sum)
                {
                    sum=b;
                    left=begin;
                    right=j;
                }
            }
            cout << sum << " " << left << " " << right <<endl;
        }
        
    }
}


