#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
#include<string>
using namespace std;
int arr[100001];
int t, n;
int par[100001];
bool flag[100001];
vector<int> v;
void dfs(int n,int s) {
	if (flag[n])return;
	if (par[n] ==s) {
		flag[n] = true;
	}
	else
	par[n] = s;
	dfs(arr[n],s);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for (int a = 0; a < t; a++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			par[i] = 0;
			flag[i] = false;
		}
		int counter = 0;
		for (int i = 1; i <= n; i++) {
			if(par[i]==0)
			dfs(i, i);
			if (!flag[i])counter++;
			flag[i] = true;
		}
		//for (int i = 1; i <= n; i++)
		cout << counter << '\n';

	}
}