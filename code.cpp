#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scf(a) scanf("%lf",&a)
#define scan(a) scanf("%s",a)
#define ll long long
#define mset(a) memset(a,0,sizeof(a))
#define mod 1000000007

int dp[2][1025];

int main()
{
	int t,n,i,j,k,q,cnt=0,e=1;
	int num;
	char p[12];
	sc(t);
	while(t--)
	{
		for(i=0;i<1024;i++)
			dp[0][i]=0;
		scanf("%s",&p);
		cnt=0;e=1;
		for(i=10;i>=1;i--)
		{
			if(p[i-1]=='b')
				cnt+=e;
			e<<=1;
		}
		dp[0][cnt]=1;
		sc(n);
		for(i=0;i<n;i++)
		{
			cnt=0;e=1;
			scanf("%s",p);
			for(j=10;j>=1;j--)
			{
				if(p[j-1]=='+')
					cnt+=e;
				e<<=1;
			}
			for(j=0;j<1024;j++)
			{
				dp[1][j] = dp[0][j] + dp[0][j^cnt];
				if(dp[1][j]>=mod)
					dp[1][j] -= mod;
			}
			for(j=0;j<1024;j++)
				dp[0][j]=dp[1][j];
		}
		
		num=dp[0][1023];
		printf("%d\n",num);		
	}
	return 0;
}
