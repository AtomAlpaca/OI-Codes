#include <iostream>

using std::cin;
using std::cout;

int k;
int ans[15] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881, 13482720};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> k;
	cout << ans[k];
	return 0;
}
