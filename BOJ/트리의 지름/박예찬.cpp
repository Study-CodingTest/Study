#include<iostream>
#include<queue>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
using namespace std;
int n;
vector<pair<int, int>> con[100001];
bool flag[100001];
int dis[100001];
void dfs(int a) {
	flag[a] = true;
	for (int i = 0; i < con[a].size(); i++) {
		if (flag[con[a][i].first] == false)
		{
			dis[con[a][i].first] = dis[a] + con[a][i].second;
			dfs(con[a][i].first);
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	int x, y, d;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		while (y != -1) {
			cin >> d;
			con[x].push_back({ y,d });
			con[y].push_back({ x,d });
			cin >> y;
		}

	}
	int maxD = 0;
	int maxN = 0;
	dis[1] = 0;
	dfs(1);
	for (int i = 1; i <= n; i++) {
		if (dis[i] > maxD) {
			maxD = dis[i];
			maxN = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		flag[i] = false;
		dis[i] = 0;
	}
	dfs(maxN);
	for (int i = 1; i <= n; i++) {
		if (dis[i] > maxD) {
			maxD = dis[i];
			maxN = i;
		}
	}
	cout << maxD;

}