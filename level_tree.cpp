#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

vector<int>v[10];
int level[10];
bool visit[10]={false};

void bfs(int s)
{
	queue<int>q;
	q.push(s);
	level[s]=0;    // Setting the level of source node as 0
	visit[s]=true;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(int i=0;i<v[p].size();i++)
		{
			if(!visit[v[p][i]])
			{
				level[v[p][i]]=level[p]+1;  //Add this line only
				q.push(v[p][i]);
				visit[v[p][i]]=1;
			}
		}
	}
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
	bfs(k);
	return 0;	
}
