#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c[100];
    int count=0;
    while(scanf("%s",c)==1)
    {
        count++;
        int i=0,j=strlen(c)-1;
        for(;i<j;i++,j--)
        {
            if(c[i]!=c[j]) break;
        }
        if(i>=j)
        {
            cout << "case" << count << ": yes"<<endl;
        }
        else
        {
            cout << "case" << count << ": no"<<endl;
        }
        
    }
}