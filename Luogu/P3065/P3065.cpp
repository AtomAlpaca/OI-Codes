#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
using std::queue;

const int MAX = 1e7 + 5;

int n, sum, cnt = 1;
std::string str[30005];
int in[27];
int nxt[MAX][27];
vector <int> e[27], ans;
bool end[MAX];

bool topo()
{
	queue <int> q;
	for (int i = 0; i <= 25; ++i)
	{
		if (!in[i])
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int x = q.front();
		const int len = e[x].size();

		for (int i = 0; i < len; ++i)
		{
			int y = e[x].at(i);
			--in[y];
			if (!in[y])
			{
				q.push(y);
			}
		}
		q.pop();
	}

	for (int i = 0; i <= 25; ++i)
	{
		if (in[i])
		{
			return false;
		}
	}
	return true;
}

void ins(std::string s)
{
	const int len = s.size();
	int p = 1;
	for (int i = 0; i < len; ++i)
	{
		int c = s[i] - 'a';
		if (!nxt[p][c])
		{
			nxt[p][c] = ++cnt;
		}
		p = nxt[p][c];
	}
	end[p] = true;
}

bool check(std::string s)
{
	const int len = s.size();
	int p = 1;
	for (int i = 0; i < len; ++i)
	{
		int c = s[i] - 'a';
		if (end[p])
		{
			return false;
		}

		for (int j = 0; j < 26; ++j)
		{
			if (nxt[p][j] and j != c)
			{
				e[c].push_back(j);
				++in[j];
			}
		}
		p = nxt[p][c];
	}
	return topo();
}

void init()
{
	for (int i = 0; i <= 25; ++i)
	{
		e[i].clear();
		in[i] = 0;
	}
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> str[i];
		ins(str[i]);
	}

	for (int i = 1; i <= n; ++i)
	{
		init();
		if (check(str[i]))
		{
			++sum;
			ans.push_back(i);
		}
	}

	cout << sum << '\n';

	const int len = ans.size();
	for (int i = 0; i < len; ++i)
	{
		cout << str[ans.at(i)] << '\n';
	}
}

