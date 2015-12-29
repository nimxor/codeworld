#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int visit[10];
vector<int>v[10];
queue<int>Q;

void BFS(int k)
{
	Q.push(k);
	visit[k]=1;
	while(!Q.empty())
	{
		k=Q.front();
		cout<<k<<endl;
		Q.pop();
		for(int i;i<v[k].size();i++)
		{
			if(!visit[v[k][i]])
			{
				Q.push(v[k][i]);
				visit[v[k][i]]=1;
			}
		}
	}
}

void init()
{
	for(int i=0;i<10;i++)
		visit[i]=0;
}

int main()
{
	int i,j,k,n,e,x,y;
	cout<<"Enter number of nodes"<<endl;
	cin>>n;
	cout<<"Enter nmber of edges"<<endl;
	cin>>e;
	for(i=0;i<e;i++)
	{
		cout<<"Enter the value of x and y"<<endl;
		cin>>x>>y;
		v[x].pb(y);
	}
	init();
	cout<<"Select the verstex to begin BFS"<<endl;
	cin>>k;
	BFS(k);
	return 0;	
}
