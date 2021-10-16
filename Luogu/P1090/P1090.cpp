#include <bits/stdc++.h>
using namespace std;

int tree[10005];

int size = 0;



void put(int num)
{
	tree[++size] = num;
	int pa;
	int ch = size;
	while (ch > 1)
	{
		pa = ch >> 1;
		if (tree[ch] >= tree[pa])
		{
			break;
		}
		else
		{
			swap(tree[ch],tree[pa]);
		}
		ch = pa;
	}
}

int get()
{
	int pa,ch,an;
	an = tree[1];
	tree[1] = tree[size--];
	pa = 1;
	while ((pa << 1) <= size)
	{
		ch = pa << 1;
		if (tree[ch + 1] < tree[ch] and ch < size)
		{
			++ch;
		}
		if (tree[pa] <= tree[ch])
		{
			break;
		}
		else
		{
			swap(tree[pa],tree[ch]);
		}
		pa = ch;
	}
	return an;
}

void start(int n)
{
	int a,b,ans = 0,sum;
	for (int i = 1;i <= n;++i)
	{
		cin >> sum;
		put(sum);
	}
	for (int i = 1;i <  n;++i)
	{
		a = get();
		b = get();
		ans += a + b;
		put(a + b);
	}
	cout << ans << endl;
}

int main()
{
	int n;
	cin >> n;
	start(n);
	return 0;
}
