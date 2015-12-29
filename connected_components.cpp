#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

vector<int>v[10];
bool visited[10];

void dfs(int s)
{
	int i;
	visited[s]=true;
	for(i=0;i<v[s].size();i++)
	{
		if(visited[v[s][i]]==false)
			dfs(v[s][i]);
	}
}

void initialize()
{
	for(int i=0;i<10;i++)
		visited[i]=false;
}

int main()
{
	int n,e,x,y,CC=0;
	cin>>n;                      //Number of nodes
	cin>>e;                      //Number of edges
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	initialize();
	
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			dfs(i);
			CC++;			
		}	
	}
	
	cout<<"Number of connected components : "<<CC<<endl;
	
	return 0;
}
