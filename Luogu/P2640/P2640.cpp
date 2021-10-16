#include <iostream>

using std::cin;
using std::cout;

bool isPr(int num)
{
	if (num == 2 or num == 3 or num == 5 or num == 7 or num == 11 or num == 13)
	{
		return true;
	}
	else if (num % 2 == 0 or num == 9 or num == 15)
	{
		return false;
	}
	else
	{
		for (int i = 3; i * i <= num; i += 2)
		{
			if (num % i == 0)
			{
				return false;
			}
		}
		return true;
	}
}

int main()
{
	int * n = new int;
	int * k = new int;
	
	cin >> *n >> *k;

	bool isNotEmp = false;

	for (int i = 2; i + (*k) < *n; ++i)
	{
		if (isPr(i) and isPr(i + (*k)))
		{
			cout << i << " " << i + *k << "\n";
			isNotEmp = true;
		}
	}
	if (isNotEmp == false)
	{
		cout << "empty";
	}

	delete n;
	delete k;
	return 0;
}
