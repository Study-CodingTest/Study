#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
int n, m, k;
vector<pair<int, int>> v[1001];
int dij[1001][1001];
bool flag[1001][1001];
int max_ = 1000000000;
void dijkstra1(int s) {
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //{거리,목표 점}
	pq.push({ 0,s });
	dij[s][0] = 0;
	while (!pq.empty()) {
		int x = pq.top().first;
		int y = pq.top().second;
		pq.pop();
		if (flag[y][0]) continue;
		flag[y][0] = true;
		dij[y][0] = x;
		for (int i = 0; i < v[y].size(); i++) {
			int d = x + v[y][i].second;
			int dest = v[y][i].first;
			if (dij[dest][0] > d) {
				pq.push({ d,dest });
			}
		}
	}
}
int dijkstra2(int s,int e) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{거리,목표 점}
	pq.push({ 0,s });
	dij[s][s] = 0;
	while (!pq.empty()) {
		int x = pq.top().first;
		int y = pq.top().second;
		pq.pop();
		if (flag[y][s]) continue;
		flag[y][s] = true;
		dij[y][s] = x;
		if (y == e)return dij[y][s];
		for (int i = 0; i < v[y].size(); i++) {
			int d = x + v[y][i].second;
			int dest = v[y][i].first;
			if (dij[dest][s] > d) {
				pq.push({ d,dest });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
	int x, y, z;
	cin >> x >> y >> z;
    v[x].push_back({ y,z });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dij[i][j] = max_;
		}
	}
	dijkstra1(k);
	int maxTime = 0;
	for (int i = 1; i <= n; i++) {
		int t=dij[i][0]+dijkstra2(i, k);
		//cout << t << endl;
		if (t > maxTime) {
			maxTime = t;
		}
	}
	cout << maxTime;
}