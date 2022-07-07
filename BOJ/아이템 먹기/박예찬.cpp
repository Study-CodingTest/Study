#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
int n, m, a, b;
vector<pair<int, int>> v;
bool arr[101][101];
int dp[101][101];
bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}
int dpf(int x, int y,pair<int,int> e, pair<int, int> s){
	if (dp[x][y] != -1)return dp[x][y];
	if (x < s.first || y < s.second)return 0;
	int sum = 0;
	if (!arr[x - 1][y])sum += dpf(x - 1, y, e, s);
	if (!arr[x][y - 1])sum += dpf(x, y - 1, e, s);
	return sum;
}
int path(pair<int, int> s, pair<int, int> e) {
	dp[s.first][s.second] = 1;	
	return dpf(e.first, e.second, e, s);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> a >> b;
	v.push_back({ 1,1 });
	for (int i = 0; i < a; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	for (int j = 0; j < b; j++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = true;
	}
	v.push_back({ n, m });
	sort(v.begin(), v.end(), compare);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = -1;
		}
	}
	int sol = 1;
	for (int i = 1; i <= a + 1; i++) {
		sol *= path(v[i - 1], v[i]);
	}
	cout << sol;
}