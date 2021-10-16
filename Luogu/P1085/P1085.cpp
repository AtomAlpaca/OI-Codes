//P1085 [NOIP2004 普及组] 不高兴的津津 www.luogu.com.cn/problem/P1085
//2021.1.15

#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	bool flag = false;
	int happy[7] = {0};
	int classSch[7] = {0};	//学校上课
	int classMom[7] = {0};	//额外上课
	for (int i = 0; i < 7; ++i)
	{
		cin >> classSch[i] >> classMom[i];
		if ((classSch[i] + classMom[i]) > 8)
		{
			happy[i] = (classSch[i] + classMom[i]) - 8;
			flag = true;
		}
		else
		{
			happy[i] = 0;
		}
	}
	if (flag == false)
	{
		cout << 0;
	}
	else
	{
		int max = 0;
		int day = 0;
		for (int i = 0; i < 7; ++i)
		{
			if (happy[i] > max)
			{
				day = i;
				max = happy[i];
			}
		}
		cout << day + 1;
	}
	return 0;
}