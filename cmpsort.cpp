#include<bits/stdc++.h>
using namespace std;

bool comp(int i,int j)
{
	return i>j;
}

void print(int *a)
{
	for(int i=0;i<10;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


int main()
{
	int a[10]={3,322,12,23,45,67,332,23,5656,1};
	sort(a,a+10);
	print(a);
	sort(a,a+10,comp);
	print(a);
	return 0;
}
