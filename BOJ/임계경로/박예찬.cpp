#include <iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<cmath>
using namespace std;
int n, m, s, e;
vector <pair<int, int>> v[100001];//길
vector<pair<int, int>> rev[100001];//역으로
int d[100001];
bool flag[100001];
int inDegree[10001];
int outDegree[10001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back({ y,z });
		rev[y].push_back({ x,z });
		inDegree[y]++;
		outDegree[x]++;
	}
	cin >> s >> e;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int dis = v[x][i].second;
			int next = v[x][i].first;
			d[next] = max(d[next], d[x] + dis);
			inDegree[next]--;
			if (inDegree[next] == 0)q.push(next);
		}
	}
	cout << d[e] << '\n';
	int counter = 0;
	flag[e] = true;
	q.push(e);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < rev[x].size(); i++) {
			int next = rev[x][i].first;
			int dis = rev[x][i].second;
			if (flag[x] && d[x] - dis == d[next]) {
				counter++;
				flag[next] = true;
			}
			outDegree[next]--;
			if (outDegree[next] == 0)q.push(next);
		}
	}
	cout << counter;
}