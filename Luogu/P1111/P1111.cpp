#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

int n, m;
int father[1005];

struct Update
{
	int x, y, time;
} upd[100005];

int find(int num)
{
	if (father[num] != num)
	{
		father[num] = find(father[num]);
	}
	return father[num];
}

void reunion(int x, int y)
{
	father[y] = x;
	return ;
}

bool cmp(Update u1, Update u2)
{
	return (u1.time < u2.time);
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)	
	{
		cin >> upd[i].x >> upd[i].y >> upd[i].time;
	}

	for (int i = 0; i < n; ++i)
	{
		father[i] = i;
	}

	std::sort(upd, upd + m, cmp);
	
	for (int i = 0; i < m; ++i)
	{
		int x = find(upd[i].x);
		int y = find(upd[i].y);
		if (x != y)
		{
			reunion(x, y);
			--n;
		}
		if (n == 1)
		{
			cout << upd[i].time;
			return 0;
		}
	}

	cout << -1;
	return 0;
}