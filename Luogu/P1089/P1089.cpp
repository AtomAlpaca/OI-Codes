#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int cost[12];
	int money = 0;
	int ans = 0;
	int bank = 0;
	bool flag = false;
	for (int i = 0; i < 12; ++i)
	{
		cin >> cost[i];
		money += 300;
		money -= cost[i];
		if (money < 0 and flag == false)
		{
			flag = true; 
			ans = -i;
		}
		else
		{
			bank += money / 100 * 100;
			money %= 100;
		}
	}
	if (flag == true)
	{
		cout << ans - 1;
	}
	else
	{
		cout << money + bank * 1.2;
	}
	return 0;
}