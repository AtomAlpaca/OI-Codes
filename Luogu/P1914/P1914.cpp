#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string str;
	int num;
	cin >> num >> str;
	for (int i = 0,len = str.length(); i < len; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			if (str[i] == 'z')
			{
				str[i] = 'a';
			}
			else
			{
				++str[i];
			}
		}
	}
	cout << str;
	return 0;
}