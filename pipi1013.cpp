#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int A[10];
    while(cin>>s)
    {
        memset(A,0,sizeof(A));
        for(int i=0;i<s.size();i++)
        {
            A[s[i]-'0']++;
        }
        int max=0;
        for(int i=0;i<10;i++)
        {
            if(A[i]>A[max]) max=i;
        }
        cout << max << endl;
    }
}