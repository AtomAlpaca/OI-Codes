#include <iostream>
using namespace std;
int main()
{
	int * n = new int;
	cin >> *n;
	int nums[*n + 1][*n + 1] = {0};
	int m;
	cin >> m;
	int x1,x2,y1,y2;
	for	(int i = 0;i < m;++i)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for	(int x = x1;x <= x2;++x)
		{
			for (int y = y1;y <= y2;++y)
			{
				++nums[x][y];
			}
		}
	}
	for	(int i = 1;i <= *n;++i)
	{
		for (int j = 1;j <= *n;++j)
		{
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}
}
