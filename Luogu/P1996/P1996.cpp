#include <iostream>

using std::cout;
using std::cin;

struct node
{
	int data;
	node * last;
	node * next;
};

int main()
{
	int * n = new int;
	int * m = new int;

	cin >> *n >> *m;

	node peo[*n];
	for (int i = 1; i < *n - 1; ++i)
	{
		peo[i].data = i + 1;
		peo[i].last = & peo[i - 1];
		peo[i].next = & peo[i + 1];
	}
	
	peo[0].data = 1;
	peo[0].next = & peo[1];
	peo[0].last = & peo[*n - 1];

	peo[*n - 1].data = *n;
	peo[*n - 1].next = & peo[0];
	peo[*n - 1].last = & peo[*n - 2];
	
	node * now = & peo[0];

	for (int i = 0; i < *n; ++i)
	{
		for (int j = 0; j < *m - 1; ++j)
		{
			now = now -> next;
		}
		cout << now -> data << ' ';
		now -> last -> next = now -> next;
		now -> next -> last = now -> last;
		now = now -> next;
	}

	return 0;
}
