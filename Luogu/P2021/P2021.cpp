#include <bits/stdc++.h>
using namespace std;
queue<int>a;
int k[1000005],ans[1000005],n;
int main(int argc, char const *argv[]){
	cin >> n;
	for (int i = 1; i <= n; ++i){
		a.push(i);
	}
	for (int i = 0;a.empty() == false; ++i){
		a.push(a.front());	a.pop();
		k[i] = a.front();	a.pop();
	}
	for (int i = 1; i <= n; ++i){
		ans[k[i]] = i;
	}
	for (int i = 1; i <= n; ++i){	
		cout << ans[i] + 1 << " ";
	}
	return 0;
}