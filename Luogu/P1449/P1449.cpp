#include <iostream>

using std::cin;
using std::cout;

int ptr;
int sta[55];
char ch;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	while (true)
	{
		cin >> ch;
		if (ch == '@')
		{
			break;
		}
		if (ch >= '0' and ch <= '9')
		{
			++ptr;
			sta[ptr] = (ch - '0');
			while (true)
			{
				cin >> ch;
				if (ch == '.')
				{
					break;
				}
				else
				{
					sta[ptr] = sta[ptr] * 10 + int(ch - '0');
				}
			}
		}
		else
		{
			int n1 = sta[ptr], n2 = sta[ptr - 1];
			--ptr;
			if (ch == '+')
			{
				sta[ptr] = n1 + n2;
			}
			else if (ch == '*')
			{
				sta[ptr] = n1 * n2;
			}
			else if (ch == '-')
			{
				sta[ptr] = n2 - n1;
			}
			else
			{
				sta[ptr] = n2 / n1;
			}
		}
	}

	cout << sta[ptr];

	return 0;
}

