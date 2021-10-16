#include <iostream>
using namespace std;
int main()
{
	int * n = new int;
	int * m = new int;
	cin >> *n >> *m;
	char nums[*n][*m] = {0};
	short nu[*n + 2][*m + 2] = {0};
	for (int i = 0;i < *n;++i)
	{
		for(int j = 0;j < *m;++j)
		{
			cin >> nums[i][j];
			if (nums[i][j] == '*')
			{
				++nu[i][j];
				++nu[i + 1][j];
				++nu[i + 2][j];
				++nu[i][j + 1];
				++nu[i + 2][j + 1];
				++nu[i][j + 2];
				++nu[i + 1][j + 2];
				++nu[i + 2][j + 2];
				nu[i + 1][j + 1] = -10; 
			}
		}
	}
	for (int i = 1;i <= *n;++i)
	{
		for (int j = 1;j <= *m;++j)
		{
			if (nu[i][j] < 0)
			{
				cout << '*';
			}
			else
			{
				cout << nu[i][j];
			}
		}
		cout << endl;
	}


	delete n;
	delete m;
	return 0;
}
