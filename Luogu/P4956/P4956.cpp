#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	long long n;
	cin >> n;
	n /= 364;
	if (n <= 103)
	{
		cout << n - 3 << endl << 1;
	}
	else
	{
		if(n % 3 == 0) 
		{
			cout << 99 << endl << (n - 99) / 3;
		}
		else if(n % 3 == 1) 
		{
			cout << 100 << endl << (n - 100) / 3;
		}
		else
		{
			cout << 98 << endl << (n - 98) / 3;
		}
	}
	return 0;
}