#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
const int N =5e4+7;
char s1[N],s2[N];
int main()
{
	while(scanf("%s %s",s1,s2)==2)
	{
		int n=strlen(s1);
		int ab=0,ba=0;
		for(int i=0;i<n;i++)
		{
			if(s1[i]=='a'&&s2[i]=='b')
			{
				ab++;
			}
			else if(s1[i]=='b'&&s2[i]=='a') ba++;
		}
		int t=(ab%2)+(ba%2);
		if(t==1) printf("-1\n");
		else if(t==0) printf("%d\n",ab/2+ba/2);
		else printf("%d\n",(ab+ba)/2+1);
	}
	return 0;
}

