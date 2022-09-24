#include <iostream>

using std::cin;
using std::cout;

int MAGIC = 17; //this is magic
int n[33], m, f[100015];

void init()
{
	for (int i = 1; i <= 100005; ++i)
	{
		f[i] = i;
	}

	for (int i = 1; i <= MAGIC; ++i)
	{
		n[i] = i * i * i * i;
		f[n[i]] = 1;
	}
	return ;
}

int main()
{
	cin >> m;
	init();

	for (int i = 1; i <= MAGIC; ++i)
	{
		for (int j = n[i]; j <= m; ++j)
		{
			f[j] = std::min(f[j], f[j - n[i]] + 1);
		}
	}

	cout << f[m];
	return 0;
}
