#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	long long a[102];
	for (int i = 0; i < 102; ++i)
	{
		a[i] = 1;
	}
	int i = 1;
	while (a[i - 1] != 0)
	{
		cin >> a[i];
		++i;
	}
	i -= 2;
	for (; i > 0; --i)
	{
		cout << a[i] << " ";
	}
	return 0;
}