#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[50];
    map <string,int> num;
    num["one"]=1;
    num["two"]=2;
    num["three"]=3;
    num["four"]=4;
    num["five"]=5;
    num["six"]=6;
    num["seven"]=7;
    num["eight"]=8;
    num["nine"]=9;
    num["zero"]=0;
    gets(str);
    while (str!="zero + zero =")
    {
        int add=0;
        string A="",B="";
        for(int i=0;i<strlen(str);i++)
        {
            cout << str[i];
            if(add=0)
            {
                A+=str[i];
            }
            if(add==1)
            {
                B+=str[i];
            }
            if(str[i]=='+')
            {
                add=1;
            }
        }
        cout << A << " " << B;
        gets(str);
    }
    
    
    

}