#include <bits/stdc++.h>
using namespace std;

struct node
{
	char lChild;
	char rChild;
};
node n[30];
void find(char ch)
{
	if (ch == '*')
	{
		return ;
	}
	else
	{
		cout << ch;
		find(n[int(ch - '0')].lChild);
		find(n[int(ch - '0')].rChild);
		return ;
	}
}

int main(int argc, char const *argv[])
{
	int a;
	cin >> a;
	char c;
	char root;
	cin >> root;
	cin >> n[int(root - '0')].lChild >> n[int(root - '0')].rChild;
	for (int i = 1; i < a; ++i)
	{
		cin >> c;
		cin >> n[int(c - '0')].lChild >> n[int(c - '0')].rChild;
	}
	find(root);
	return 0;
}