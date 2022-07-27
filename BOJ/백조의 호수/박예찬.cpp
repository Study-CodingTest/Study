#include <iostream>
#include <algorithm>
#include <stack>
#include<queue>
#include<cmath>
using namespace std;
int n, m;
char map[1502][1502];
int day[1502][1502];
bool flag[1502][1502];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int start[2];
int endt[2];
bool findFirst;
bool canGo(int d) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			flag[i][j] = false;
		}
	}
	queue<pair<int, int>> q;
	q.push({ start[0],start[1] });
	flag[start[0]][start[1]] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == endt[0] && y == endt[1]) {
			return true;
		}
		for (int k = 0; k < 4; k++) {
			int x2 = x + dx[k];
			int y2 = y + dy[k];
			if (x2 > 0 && y2 > 0 && x2 <= n && y2 <= m && !flag[x2][y2] && day[x2][y2] <= d) {
				flag[x2][y2] = true;
				q.push({ x2,y2 });
			}
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			day[i][j] = -1;
		}
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == '.' || map[i][j] == 'L') {
				day[i][j] = 0;
				q.push({ i,j });
			}
			if (map[i][j] == 'L') {
				if (!findFirst) {
					findFirst = true;
					start[0] = i;
					start[1] = j;
				}
				else {
					endt[0] = i;
					endt[1] = j;
				}
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int x2 = x + dx[k];
			int y2 = y + dy[k];
			if (x2 > 0 && y2 > 0 && x2 <= n && y2 <= m && map[x2][y2] == 'X' && !flag[x2][y2]) {
				flag[x2][y2] = true;
				day[x2][y2] = day[x][y] + 1;
				q.push({ x2,y2 });
			}
		}
	}
	int s = 0;
	int e = max(n, m);
	int mid = 0;
	while (s <= e) {
		mid = (s + e) / 2;
		bool g = canGo(mid);
		if (g) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	cout << s;
}