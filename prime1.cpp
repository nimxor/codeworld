#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define SIZE 1000000000
const int CACHE_SIZE=32768;

int sqrt1=sqrt(SIZE);
char is_prime[31674];

// Note : This is to generate smaller primes till sqrt1
void simple_sieve()
{
	memset(is_prime,1,sizeof(is_prime));
	is_prime[0]=0;
	is_prime[1]=0;
	int i,j,k;
	for(i=4;i<=sqrt1;i+=2)
	{
		is_prime[i]=0;
	}
	for(i=3;i*i<=sqrt1;i+=2)
	{
		if(is_prime[i])
		for(j=i*i;j<=sqrt1;j+=i)
		{
			if(is_prime[j])
				is_prime[j]=0;
		}
	}
}

int main()
{
	simple_sieve();
	int t;
	ll a,b,i,j,k;
	sc(t);                                  
	while(t--)
	{
		scl(a);scl(b);
		vector<char>p(100010,1); /*(b-a)<=100000*/
		p[0]=0;
		if(a==1)
			p[1]=0;
		for(i=2;i*i<=b;i++)
		{
			if(is_prime[i])         /*Precomputation of primes upto sqrt(1e9)*/
			for(j=a-a%i;j<=b;j+=i)  /*a-a%i is done to set j multiple of i*/ 
			{
				if (j>=a && j!=i)
					p[j-a+1]=0;
			}			
		}
		
		for(i=0;i<=(b-a+1);i++)
		{
			if(p[i])
				printf("%lld\n",(i+a-1));	
		}		
				
	}
}
