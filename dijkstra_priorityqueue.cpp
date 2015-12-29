#include<bits/stdc++.h>
#include<queue>
using namespace std;
#define sc(a) scanf("%d",&a)
#define ll long long
#define MAX 10001
#define INF (1<<20)
#define pii pair<int,int>
#define pb push_back

struct comp
{
	bool operator()(const pii &a , const pii &b)
	{
		return a.second > b.second;
	}
};

priority_queue< pii, vector< pii >, comp > Q;
vector<pii> G[MAX];
int D[MAX];
bool F[MAX];

int main()
{
	int i,u,v,w,s,n,e,x,y;
	
	int t;
	sc(t);
	while(t--)
	{
	
		for(i=0;i<=10000;i++)
		{
			D[i]=100000;
			F[i]=false;
			G[i].clear();
		}
		
		sc(n);sc(e);
		for(i=0;i<e;i++)
		{
			sc(u);sc(v);sc(w);
			G[u].pb(pii(v,w));
			//G[v].pb(pii(u,w)); /*Foe undirected*/
		}
	
		sc(x);sc(y);
	
		D[x]=0;
		Q.push(pii(x,0));
	
		while(!Q.empty())
		{
			u=Q.top().first;
			Q.pop();
			if(F[u]) continue;
			for(i=0;i<G[u].size();i++)
			{
				v=G[u][i].first;
				w=G[u][i].second;
				if(!F[v] && D[u]+w < D[v])
				{
					D[v] = D[u] + w;
					Q.push(pii(v,D[v]));
				}
			}
			F[u] = true; //Done with u
		}
		
		if(D[y]!=100000)
			printf("%d\n",D[y]);
		else
			printf("NO\n");
	}
	return 0;
}
