#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

long long ans;
int p; // Edge num
int k;
int L, R;

int father[1000005];

struct Edge
{
	int u, v;
	long long c;
} edge[5000005];

inline long long gcd(long long x, long long y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return gcd(y, x % y);
	}
}

inline long long lcm(long long x, long long y)
{
	if (x < y)
	{
		std::swap(x, y);
	}
	return (x / gcd(x, y)) * y;
}

int find(int x)
{
	if (father[x] == x)
	{
		return father[x];
	}
	else
	{
		return father[x] = find(father[x]);
	}
}

bool cmp(Edge edge1, Edge edge2)
{
	return edge1.c < edge2.c;
}

void build(int u, int v)
{
	edge[p].u = u;
	edge[p].v = v;
	edge[p].c = lcm(u, v); 
	++p;
}

int main()
{
	cin >> L >> R;
	
	/* Init */
	for (int i = L; i <= R; ++i)
	{
		father[i] = i;
	}

	/* Build */

	for (int i = 2; i < (R / 2) + 1; ++i)
	{
		int t = L / i;
		if (L % i != 0)
		{
			++t;
		}
		int n = t * i;
		while (i * t <= R)
		{
			build(n, i * t);
			++t;
		}
	}

	for (int i = L; i <= R; ++i)
	{
		if (gcd(i, L) == 1)
		{
			build(L, i);
		}
	}

	std::sort(edge, edge + p, cmp);
	
	for (int i = 0; i < p and k != R - L; ++i)
	{
		int fatherU = find(edge[i].u);
		int fatherV = find(edge[i].v);
		if (fatherU != fatherV)
		{
			ans += edge[i].c;
			father[fatherV] = fatherU;
			++k;
		}
	}

	cout << ans;
	return 0;
}
