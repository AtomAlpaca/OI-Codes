#include <iostream>
using namespace std;

inline bool isPr(int num)
{
	for (int i = 3;i * i <= num;++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}
inline bool isPa(int num)
{
	string str = to_string(num);
	int left = 0,right = str.length() - 1;
	while (left < right)
	{
		if (str[left] != str[right])
		{
			return false;
		}
		++left;
		--right;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	long long a,b;
	cin >> a >> b;
	if (a % 2 == 0)
	{
		++a;
	}
	for (int i = a; i <= b; i += 2)
	{
		if (isPa(i) == true )
		{
			if (isPr(i) == true)
			{
				cout << i << "\n";
			}
			
		}
		if (i > 9989899)
		{
			return 0;
		}
	}
	return 0;
}