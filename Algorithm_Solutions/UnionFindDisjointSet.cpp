/*Union-Find is a data structure that tracks a set of elements partitioned into a number of disjoint (non-overlapping) subsets, 
like finding connected components in a graph*/
#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
private:
	vector <int> p,rank;

public:
	UnionFind(int N)
	{
		rank.assign(N,0);
		p.assign(N,0);
		for (int i = 0; i < N; ++i)
		{
			p[i]=i;
		}
	}
	int findSet(int i)
	{
		if(p[i]==i)
		{
			return i;
		}
		else
		{
			return (p[i]=findSet(p[i]));
		}
	}
	bool isSameSet(int i,int j)
	{
		return (findSet(i)==findSet(j));
	}
	void unionSet(int i, int j)
	{
		if(!isSameSet(i,j))//if from different set
		{
			int x=findSet(i),y=findSet(j);
			if(rank[x]>rank[y])
			{
				p[y]=p[x];//rank keeps tree short
			}
			else
			{
				p[x]=p[y];
				if(rank[x]==rank[y])
					rank[y]++;
			}
		}
	}
};

int main()
{
	UnionFind U(9);
	
	U.unionSet(1,3);
	U.unionSet(0,2);
	U.unionSet(2,3);
	U.unionSet(3,4);
	U.unionSet(5,6);
	U.unionSet(6,7);
	cout << U.findSet(2) << endl;
	cout << U.findSet(7) << endl;
	cout << U.findSet(8) << endl;
}
