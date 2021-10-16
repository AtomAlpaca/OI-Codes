#include <iostream>

using std::cin;
using std::cout;

int j = 600, n, w, sum, cac, line;
int poc[605];

int main(int argc, char const *argv[])
{
	cin >> n >> w;

	for (int i = 0; i < n; ++i)
	{
		cin >> cac;
		++poc[cac];

		line = std::max(1, (i + 1) * w / 100);

		while (j >= 0 and sum < line)
		{
			sum += poc[j];
			--j;
		}

		cout << j + 1 << ' ';
		j = 600;
		sum = 0;
	}
	return 0;
}