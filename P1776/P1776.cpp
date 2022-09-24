#include <iostream>

using std::cin;
using std::cout;

const int MAX = 1e6 + 5;

int n, W, v[MAX], w[MAX], o, p, q, tot, f[MAX];
int ans = -1;

void add(int o, int p, int q)
{
	int t = 1;
	while (q >= t)
	{
		v[tot] = o * t;
		w[tot] = p * t;
		++tot;
		q -= t, t <<= 1;
	}
	v[tot] = o * q;
	w[tot] = p * q;
	++tot;
	return ;
}

int main()
{	
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> W;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> o >> p >> q;
		add(o, p, q);
	}

	for (int i = 0; i < tot; ++i)
	{
		for (int j = W; j >= w[i]; --j)
		{
			f[j] = std::max(f[j], f[j - w[i]] + v[i]);
		}
	}

	for (int i = 0; i <= W; ++i)
	{
		ans = std::max(ans, f[i]);
	}

	cout << ans;
	return 0;
}

