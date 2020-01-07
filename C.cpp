#include <cstdio>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool D[1000005];
int main()
{
	int i,j,f,x,a,b;
	cin >> x >> a >> b;
	for(i=1,D[0]=0;i<=x;i++)
	{
		if(i<=a) D[i]=!D[i-1];
		else if(i<=b+1) D[i]=1;
		else
		{
			if(!D[i-1]) D[i]=1;
			else
			{
				for(f=0,j=a;!f&&j<=b;j++)
				{
					if(!D[i-j-1]) f=1;
				}
				D[i]=f;
			}
		}
	}
	D[x] ? cout << "PIPI" : cout << "POPO" ;
	return 0;
}

