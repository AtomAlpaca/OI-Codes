#include <iostream>

using std::cin;
using std::cout;

int n, m, op, x, y;
int father[10005];

int find(int x)
{
	if (father[x] == x)
	{
		return x;	
	}
	else
	{
		return father[x] = find(father[x]);
	}
}

void init()
{
	for (int i = 0; i <= 10005; ++i)
	{
		father[i] = i;
	}
	return ;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	init();

	cin >> n >> m;

	while (m--)
	{
		cin >> op >> x >> y;
		if (op == 1)
		{
			father[find(y)] = father[find(x)];
		}
		else
		{
			if (find(x) == find(y))
			{
				cout << "Y\n";
			}
			else
			{
				cout << "N\n";
			}
		}
	}

	return 0;
}
