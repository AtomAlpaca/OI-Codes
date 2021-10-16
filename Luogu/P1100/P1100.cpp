#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	unsigned int num;
	cin >> num;
	cout << (num >> 16) + (num << 16);
	return 0;
}