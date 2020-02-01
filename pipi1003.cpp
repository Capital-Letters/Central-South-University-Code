#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c[50];
    while (scanf("%s",c)==1)
    {
        int flag1=0,flag2=0,flag3=0,flag4=0;
        if(strlen(c)<8) cout << "NO";
        else
        {
            for(int i=0;i<strlen(c);i++)
            {
                if('a'<=c[i]&&c[i]<='z') flag1=1;
                if('A'<=c[i]&&c[i]<='Z') flag2=1;
                if('0'<=c[i]&&c[i]<='9') flag3=1;
                if(c[i]=='~'||c[i]=='!'||c[i]=='@'||c[i]=='#'||c[i]=='$'||c[i]=='%'||c[i]=='^') flag4=1;

            }
            if(flag1+flag2+flag3+flag4>=3) cout<<"YES";
            else
            {
                cout << "NO";
            }
            
        }
        cout << endl;
    }
    
}