#include <iostream>

using std::cin;
using std::cout;
using std::swap;

const int INF = (2 << 29) - 1;
int op, v, n;

struct Heap
{
	int t[1000005];
	int tot;

	Heap()
	{
		tot = 0;
		for (int i = 0; i <= 1000004; ++i)
		{
			t[i] = -INF;
		}
	}

	void pushUp(int x)
	{
		while (t[x >> 1] > t[x] and x > 1)
		{
			std::swap(t[x], t[x >> 1]);
			x >>= 1;
		}
		return ;
	}

	void pushDown(int x)
	{
		while (true)
		{
			int k = x;
			if (t[k] > t[x << 1] and t[x << 1] != -INF)
			{
				k = x << 1;
			}
			if (t[k] > t[(x << 1) + 1] and t[(x << 1) + 1] != -INF)
			{
				k = (x << 1) + 1;
			}
			if (k == x)
			{
				return ;
			}
			swap(t[k], t[x]);
			x = k;
		}
	}

	void add(int val)
	{
		++tot;
		t[tot] = val;
		pushUp(tot);
		return ;
	}

	void del()
	{
		swap(t[1], t[tot]);
		t[tot] = -INF;
		tot--;
		pushDown(1);
		return ;
	}

	int get()
	{
		return t[1];
	}
} h;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	while (n--)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> v;
			h.add(v);
		}
		else if (op == 2)
		{
			cout << h.get() << '\n';
		}
		else
		{
			h.del();
		}
	}

	return 0;
}
