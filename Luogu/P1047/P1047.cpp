#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int * l = new int;
	int ans = 0;
	cin >> *l;
	bool tree[*l + 1];
	for (int i = 0; i <= *l; ++i)
	{
		tree[i] = true;
	}
	int num;
	cin >> num;
	int rm1,rm2;
	for (int i = 0; i < num; ++i)
	{
		cin >> rm1 >> rm2;
		for (int j = rm1; j <= rm2; ++j)
		{
			tree[j] = false;
		}
	}
	for (int i = 0; i <= *l; ++i)
	{
		if (tree[i] == true)
		{
			++ans;
		}
	}
	cout << ans;
	delete l;
	return 0;
}