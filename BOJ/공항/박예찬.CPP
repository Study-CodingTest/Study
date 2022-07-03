#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<tuple>
using namespace std;
int n, m;
int par[100001];
int counter;
int findPar(int x) {
	if (par[x] == x)return x;
	return par[x]=findPar(par[x]);
}
void merge(int x, int y) {
	if (findPar(x) == findPar(y))return;
	if (par[x] > par[y]) {
		par[x] = par[y];
	}
	else par[y] = par[x];
	
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++)par[i] = i;
	for (int i = 0; i < m; i++) {
		bool f = false;
		int k;
		cin >> k;
		int p = findPar(k);
		if (p != 0) {
			merge(p, p - 1);
			counter++;
		}
		else break;
	}
	cout << counter;
}
