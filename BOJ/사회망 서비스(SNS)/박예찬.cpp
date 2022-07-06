#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>
using namespace std;
int n;
vector<int> v[1000001];
int dp[1000001][2];
bool flag[1000001];
int sol;
void dpf(int n) {
	flag[n] = true;
	dp[n][0] = 1;//�ڽ��� �󸮾����
	dp[n][1] = 0;//�ڽ��� �󸮾���Ͱ� x
	for (int i = 0; i < v[n].size(); i++) {
		if (flag[v[n][i]])continue;
		dpf(v[n][i]);
		dp[n][0] += min(dp[v[n][i]][0], dp[v[n][i]][1]);//���� �󸮾���͸� �ڽĵ��� ��� X �� �� �� ���� ���
		dp[n][1] += dp[v[n][i]][0];//���� �����Ͱ� �ƴ� ��,�ڽĵ��� ��� �󸮾����
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	dpf(1);
	sol = min(dp[1][0], dp[1][1]);
	cout << sol;
}