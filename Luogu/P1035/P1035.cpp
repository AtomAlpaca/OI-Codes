#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	short k;
	double n = 0;
	double num = 0.000000;
	cin >> k;
	while(num <= k)
	{
		++n;
		num += (1 / n);
	}
	cout << n;
	return 0;
}