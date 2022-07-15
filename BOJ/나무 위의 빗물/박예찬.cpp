#include<iostream>
#include<vector>
using namespace std;
double arr[500001];
vector<int> v[500001];
int n, w;
bool flag[500001];
void dfs(int n) {
	flag[n] = true;
	bool meet = false;
	int counter = 0;
	for (int i = 0; i < v[n].size(); i++) {
		if (!flag[v[n][i]]) {
			counter++;
		}
	}
	double cur = arr[n] / counter;
	for (int i = 0; i < v[n].size(); i++) {
		if (!flag[v[n][i]]) {
			meet = true;
			arr[v[n][i]] = cur;
			dfs(v[n][i]);
		}
	}
	if (meet) {
		arr[n] = 0;
	}
}
int main() {
	cin >> n >> w;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	arr[1] = w;
	dfs(1);
	double sum = 0;
	int counter = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] != 0) {
			//cout << i << ' ' << arr[i] << endl;
			sum += arr[i];
			counter++;
		}
	}
	cout << fixed<<sum / counter;
}