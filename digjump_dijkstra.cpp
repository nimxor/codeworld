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
	int i,j,k;
	string s;
	cin>>s;
	
	G=new vector<pair<int,int> > [10];
	vector<int> D(10,0);
	vector<bool> F(10,false);
	
	for(i=0;i<s.size();i++)
	{
		G[s[i]-'0'].pb(i+1,1);
	}
	
	vector<pair<int,int> >:: iterator it;
	D[1]=0;
	Q.push(pii(1,0));
	
	
	
	return 0;
}

/*
0 1 2 1 3 4 4 4 4 4 4 4 4 4 4 3 2
*/
