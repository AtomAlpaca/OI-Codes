#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,j = 0;
	bool flag = false;
	cin >> n;
	string str = to_string(n);
	if (str[0] == '-')
	{
		cout << "-";
		++j;
	}
	for (int i = str.length() - 1; i >= j; --i)
	{
		if (str[i] != '0' and flag == false)
		{
			flag = true;
			cout << str[i];
		}
		else if (str[i] == '0' and flag == false)
		{
			/* code */
		}
		else
		{
			cout << str[i];
		}

	}
	return 0;
}