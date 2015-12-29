#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int> &left ,const pair<int,int> &right)
{
	return left.second>right.second || (left.second==right.second  && left.first>right.first);
}

//void print(pair<int ,int> &p)

int main()
{
	int i,j,k,n;
	cin>>n;
	pair<int ,int> p[n];
	for(i=0;i<n;i++)
	{
		cin>>p[i].first;
		cin>>p[i].second;
	}
	sort(p,p+n,cmp);
	for(i=0;i<n;i++)
	{
		cout<<p[i].first<<" "<<p[i].second<<endl;
	}
	return 0;	
}
