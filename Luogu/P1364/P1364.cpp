#include <iostream>
#include <vector>

using std::cin;
using std::cout;


const int MAX = 105;
const int INF = (1 << 30) - 1;

int l, r, ans = INF, n;
int siz[MAX], f[MAX];

std::vector <int> e[MAX << 1 | 1];

void add(int s, int t)
{
	e[s].push_back(t);
	e[t].push_back(s);
	return ;
}

void dfs(int x, int fa, int dep)
{
	f[1] += dep * siz[x];
	const int len = e[x].size();
	
	for (int i = 0; i < len; ++i)
	{
		if (e[x].at(i) == fa)
		{
			continue;
		}
		dfs(e[x].at(i), x, dep + 1);
		siz[x] += siz[e[x].at(i)];
	}

}

void dp(int x, int fa)
{
	const int len = e[x].size();

	for (int i = 0; i < len; ++i)
	{
		if (e[x].at(i) == fa)
		{
			continue;
		}
		f[e[x].at(i)] = f[x] - 2 * siz[e[x].at(i)] + siz[1];
		dp(e[x].at(i), x);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> siz[i] >> l >> r;
		if (l)
		{
			add(l, i);
		}
		if (r)
		{
			add(r, i);
		}
	}

	dfs(1, 0, 0);
	dp(1, 0);

	for (int i = 1; i <= n; ++i)
	{
		ans = std::min(ans, f[i]);
	}

	cout << ans;

}
