#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	double len;
	cin >> len;
	int ans;
	double num = 0;
	double swim = 2;
	while (num < len)
	{
		num += swim;
		swim = swim * 98 * 1.0 / 100;
		++ans;
	}
	cout << ans;
	return 0;
}