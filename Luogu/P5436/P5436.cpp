#include <iostream>

using std::cout;
using std::cin;

int main()
{
	int * n = new int;
	cin >> *n;
	unsigned long long ans[*n], sum;
	for (int i = 0; i < *n; ++i)
	{
		cin >> sum;
		if (sum == 1)
		{
			ans[i] = 1;
		}
		else
		{
			ans[i] = sum * (sum - 1);
		}
	}
	for (int i = 0; i < *n; ++i)
	{
		cout << ans[i] << "\n";
	}
	delete n;
	return 0;
}
