#include <iostream>

using std::cin;
using std::cout;

int a, x, y, n, k, ans;
int father[3 * 5 * 10000 + 5];

int find(int num)
{
	if (father[num] != num)
	{
		father[num] = find(father[num]);
	}
	return father[num];
}

int main(int argc, char const *argv[])
{
	cin >> n >> k;
	for (int i = 1; i <= n * 3; ++i)
	{
		father[i] = i;
	}

	while (k--)
	{
		cin >> a >> x >> y;
		if (x > n or y > n)
		{
			++ans;
			continue;
		}
		if (a == 1)
		{
			if (find(x) == find(y + n) or find(x + n) == find(y))
			{
				++ans;
			}
			else
			{
				father[find(x)] = find(y);
				father[find(x + n)] = find(y + n);
				father[find(x + 2 * n)] = find(y + 2 * n);
			}
		}
		else
		{
			if (x == y or find(x) == find(y) or find(x) == find(y + n))
			{
				++ans;
			}
			else
			{
				father[find(x + n)] = find(y);
				father[find(x + 2 * n)] = find(y + n);
				father[find(x)] = find(y + 2 * n);
			}
		}
	}

	cout << ans;
	return 0;
}