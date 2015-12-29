#include<bits/stdc++.h>
using namespace std;
#define ll long long
int d[10000];  // Distance Function
list<pair<int,int> > *graph;
#define sc(a) scanf("%d",&a)

void dijkstra(int root)
{
	set<pair<int,int> > pq;
	/*It will sor in O(logn) gives insertions and extractions in O(logn)*/
	
	set<pair<int,int> >:: iterator it;
	int u,v,wt;
	
	list<pair<int,int> >:: iterator i;
	
	d[root]=0;
	
	pq.insert(pair<int,int>(0,root)); /*pq.insert(make_pair(0,root))*/
	
	while(pq.size()!=0)
	{
		it=pq.begin();
		u=it->second;
		pq.erase(it);
		
		for(i=graph[u].begin();i!=graph[u].end();i++)
		{
			v=i->first;
			wt=i->second;
			if(d[v]>d[u]+wt)
			{
				if(d[v]!=1e8)  // Important line
            			{
                			pq.erase(pq.find(pair<int,int>(d[v],v)));
            			}
            			d[v]=d[u]+wt;
            			pq.insert(pair<int,int>(d[v],v));
			}
		}
	}
}

void addedge(int src,int des,int wt)
{
	pair<int,int>x;
	x.first=des;
	x.second=wt;
	graph[src].push_front(x);
	
		/*For adding undirected component add reverse edges
		x.first=src;
		x.second=wt;
		graph[des].push_front(x);
		*/
	
	// This Algotithm works for both Directed and undirected graphs;
}

int main()
{
	int i,j,k,t;
	cin>>t;
	while(t--)
	{
		int v,e,src,des,wt;
		sc(v);sc(e);
		
		for(i=0;i<=v;i++)
		{
			d[i]=1e8;   // Initialise all distances to infinity
		}
	
		graph=new list<pair<int,int> >[v+1];
		
		for(i=0;i<e;i++)
		{
			cin>>src>>des>>wt;
			addedge(src,des,wt);
		}
	
		int x,y;
	
		sc(x);sc(y);
	
	
		dijkstra(x);
		
		if(d[y]!=1e8)
			printf("%d\n",d[y]);
		else
			printf("NO\n");
	}
	return 0;
}
