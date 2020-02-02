#include<bits/stdc++.h>
using namespace std;
int main()
{
    int score;
    while (scanf("%d",&score)==1)
    {
        if(108<=score&&score<=120) cout << "A";
        else if(100<=score&&score<=107) cout << "B";
        else if(80<=score&&score<=99) cout << "C";
        else if(72<=score&&score<=79) cout << "D";
        else if(0<=score&&score<=71) cout << "E";
        else cout << "Score is error!";
        cout << endl;
    }
    
}