#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a)
#define ll long long
#define MAX 1000010
#define INF 1000010
#define pii pair<int,int>
#define pb push_back
#define pf push_front

//list<pair<int,int> > *G;
vector<pair<int,int> > *G;

struct comp
{
	bool operator()(const pii &a , const pii &b)
	{
		return a.second > b.second;
	}
};

priority_queue< pii, vector< pii >, comp > Q;

int main()
{
	int i,j,k,e,n,x,y,v,w,u;
	sc(n);sc(e);
	
	G=new vector<pair<int,int> >[n+1];
	vector<int> D(n+1,INF);
	vector<bool> F(n+1,false);
	
	for(i=0;i<e;i++)
	{
		sc(x);sc(y);
		G[x].pb(pii(y,0));
		G[y].pb(pii(x,1));
	}
	
	vector<pair<int,int> >:: iterator it;
	D[1]=0;
	Q.push(pii(1,0));
	
	while(!Q.empty())
	{
		u=Q.top().first;
		Q.pop();
		for(it=G[u].begin();it!=G[u].end();it++)
		{
			v=it->first;
			w=it->second;
			
			if(!F[v] && D[u]+w < D[v])
			{
				D[v] = D[u] + w;
				Q.push(pii(v,D[v]));
			}
		}
		F[u]=1; // We are done with this vertex
	}
	
	if(D[n]!=INF)
		printf("%d\n",D[n]);
	else
		printf("-1\n");
	
	return 0;
}


/*
7 7
1 2 
3 2
3 4
7 4
6 2
5 6
7 5
*/
