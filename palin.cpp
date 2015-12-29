#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scs(a) scanf("%s",a)

int check_palin(string s)
{
	int i,j,k,flag=0;
	k=s.size();
	for(i=0;i<k/2;i++)
	{
		if(s[i]!=s[k-i-1] && s[i]!='?' && s[k-i-1]!='?')
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		return 1;
	else
		return 0;
}

int main()
{
	int i,j,k,t,cnt=0;
	string s;
	sc(t);
	while(t--)
	{
		cnt=0;
		cin>>s;
		int sz=s.size();
		for(i=0;i<=s.size();i++)
		{
			string str=s.substr(0,i)+'?'+s.substr(i,sz);
			cnt+=check_palin(str);
		}
		printf("%d\n",cnt);
	}
	return 0;
}


/*
2
aaa
aca

*/
