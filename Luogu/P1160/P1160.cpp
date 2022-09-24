#include <iostream>

using std::cin;
using std::cout;

const int MAX = 100005;

int head, a[MAX], nxt[MAX], pre[MAX], op, to, n, m;
bool dl[MAX];

void add(int k, int l, int p)
{
	if (p == 0)
	{
		nxt[pre[k]] = l;
		pre[l] = pre[k];
		k[pre] = l;
		nxt[l] = k;
	}
	else
	{
		nxt[l] = nxt[k];
		pre[l] = k;
		pre[nxt[k]] = l;
		nxt[k] = l ;
	}
	return ;
}

void del(int x)
{
	nxt[pre[x]] = nxt[x];
	pre[nxt[x]] = pre[x];

	return ;
}

void print(int o)
{
	cout << o << ' ';
	while (nxt[o])
	{
		cout << nxt[o] << ' ';
		o = nxt[o];
	}
	return ;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	head = 1;
	
	for (int i = 2; i <= n; ++i)
	{
		cin >> to >> op;
		if (to == head and op == 0)
		{
			head = i;
		}

		add(to, i, op);
	}

	cin >> m;
	
	for (int i = 1; i <= m; ++i)
	{
		cin >> op;
		
		if (!dl[op])
		{
			if (op == head)
			{
				head = nxt[op];
			}
			del(op);
			dl[op] = true;
		}
	}

	print(head);

	return 0;
}

