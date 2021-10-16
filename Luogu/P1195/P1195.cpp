#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

int n, m, k, ans;
int father[1005];
struct Edge
{
	int left, right, cost;
} edge[10005];

bool cmp(Edge edge1, Edge edge2)
{
	return edge1.cost < edge2.cost;
}

int find(int num)
{
	if (num != father[num])
	{
		father[num] = find(father[num]);
	}
	return father[num];
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	if (n - m > k)
	{
		cout << "No Answer";
		return 0;
	}

	for (int i = 0; i < n; ++i)
	{
		father[i] = i;
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> edge[i].left >> edge[i].right >> edge[i].cost;
	}

	std::sort(edge, edge + m, cmp);

	for (int i = 0; i < m, n != k; ++i)
	{
		int fatherLeft = find(edge[i].left), fatherRight = find(edge[i].right);
		if (fatherLeft != fatherRight)
		{
			ans += edge[i].cost;
			father[fatherRight] = fatherLeft;
			--n;
		}
		if (n == k)
		{
			cout << ans;
			return 0;
		}
	}

	cout << "No Answer";

	return 0;
}