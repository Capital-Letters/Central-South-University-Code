#include<cstdio>
#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
void swap(char &a,char &b)
{
    char temp;
    temp=a;
    a=b;
    b=temp;
}
void sort_decrese(string &s)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 3; j > i; j--)
        {
            if (s[j]>s[j-1])
            {
                swap(s[j],s[j-1]);
            }
        }
        
    }
    
}
void sort_increse(string &s)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 3; j > i; j--)
        {
            if (s[j]<s[j-1])
            {
                swap(s[j],s[j-1]);
            }
        }
        
    }
    
}
int main()
{
    int n;
    cin >> n;
    int black_hole=n;
    string temp_s=to_string(n);
    if (temp_s[0]==temp_s[1]==temp_s[2]==temp_s[3])
    {
        cout << n << " - " << n << " = " << "0000"; 
        return 0;
    }

    while (black_hole!=6174)
    {
        string s=to_string(black_hole);
        sort_decrese(s);
        string temps1=s;
        int temp1 = stoi(s,0,10);
        sort_increse(s);
        int temp2 = stoi(s,0,10);
        string temps2=s;
        black_hole = temp1 - temp2;
        if (black_hole==6174)
        {
            cout << temps1 << " - " << temps2 << " = " << black_hole;
        }
        else
        {
            cout << temps1 << " - " << temps2 << " = " << black_hole << endl;
        }
    }
    
    
}