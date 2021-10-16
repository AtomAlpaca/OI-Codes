#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,k;
	cin >> n >> k;
	cout << n + (n - 1) / (k - 1);
	return 0;
}