#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

vector<int>v[5];
stack<int>s;
int visited[5]={0};
int visit[5]={0};

void DFS_ITERATIVE(int k)
{
	int i,j;
	s.push(k);
	visited[k]=1;
	while(!s.empty())
	{
		j=s.top();
		cout<<j<<" ";
		s.pop();
		for(i=0;i<v[j].size();i++)
		{
			if(!visited[v[j][i]])
			{
				s.push(v[j][i]);
				visited[v[j][i]]=1;
			}	
		}
	}
}

void DFS_RECURSIVE(int k)
{
	int i;
	visit[k]=1;
	cout<<k<<" ";
	for(i=0;i<v[k].size();i++)
	{
		if(!v[k][i])
			DFS_RECURSIVE(v[k][i]);
			
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
	cout<<"Select the vertex from which you want DFS to begin ."<<endl;
	cin>>k;
	//DFS_ITERATIVE(k);
	cout<<endl;
	DFS_RECURSIVE(k);
	return 0;
}
