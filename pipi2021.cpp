#include<bits/stdc++.h>
using namespace std;
int main()
{
    int  n;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n<6||n%4==1||n%4==3) printf("0\n");
        else
        {
            if(n%4==0) printf("%d\n",n/4-1);
            else printf("%d\n",n/4);
        }
    }
}