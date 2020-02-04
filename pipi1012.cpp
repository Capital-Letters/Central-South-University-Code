#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c[1000];
    while(scanf("%s",c)!=EOF)
    {
        string s="";
        int i;
        for(i=0;i<strlen(c);i++)
        {
            if(c[i]=='E'&&s.size()==0)
            {
                s+=c[i];
            }
            if(c[i]=='A'&&s.size()==1)
            {
                s+=c[i];
            }
            if(c[i]=='S'&&s.size()==2)
            {
                s+=c[i];
            }
            if(c[i]=='Y'&&s.size()==3)
            {
                break;
            }
        }
        if(i>=strlen(c)) cout << "difficult" << endl;
        else cout << "easy" << endl;
    }
}