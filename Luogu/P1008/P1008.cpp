#include <iostream>
using namespace std;
//362880
int main(int argc, char const *argv[])
{
	string num0,num1,num2;
	int ans1,ans2;
	int sum = 1;
	for (int i = 123; i < 333; ++i)
	{
		ans1 = i * 2;
		ans2 = i * 3;
		num0 = to_string(i);
		num1 = to_string(ans1);
		num2 = to_string(ans2);
		for (int j = 0; j < 3; ++j)
		{
			sum *= int(num0[j] - '0');
		}
		for (int j = 0; j < 3; ++j)
		{
			sum *= int(num1[j] - '0');
		}
		for (int j = 0; j < 3; ++j)
		{
			sum *= int(num2[j] - '0');
		}
		if (sum == 362880)
		{
			cout << i << " " << ans1 << " "<< ans2 << endl;
		}
		sum = 1;
	}
	return 0;
}