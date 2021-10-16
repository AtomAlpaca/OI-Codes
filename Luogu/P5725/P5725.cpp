#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	short n;
	cin >> n;
	for (int i = 1; i <= n * n; ++i)
	{
		if (i % n == 1 and i != 1)
		{
			cout << endl;
		}
		if (i < 10)
		{
			cout << "0" << i;
		}
		else
		{
			cout << i;
		}
	}
	cout << endl << endl;
	int sum = 1;
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			cout << "  ";
		}
		for (int j = n; j > i; --j)
		{
			if (sum < 10)
			{
				cout << "0" << sum;
			}
			else
			{
				cout << sum;
			}
			++sum;
		}
		cout << endl;
	}
	return 0;
}