#include <bits/stdc++.h>
using std::cin;
using std::cout;

inline int quickRead()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' or ch > '9')
	{
		if(ch == '-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while(ch >= '0' and ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}						
	return x*f;
}
int main()
{
	int k;
	int * n = new int;
	*n = quickRead();
	k  = quickRead();
	int nums[*n];
	for (int i = 0; i < *n; ++i)
	{
		nums[i] = quickRead();
	}
	std::sort(nums,nums + *n);
	cout << nums[k];
	delete n;
	return 0;
}
