#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
int n, m, p;
char arr[1001][1001];
int s[10];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int c[10];
queue <pair<int,int>> q[10];
bool game() {
	bool e = false;
	for (int i = 1; i <= p; i++) {

		int l = s[i];
		while (!q[i].empty() && l--)
		{
			int si = q[i].size();
			while (si--) {
				int x = q[i].front().first;
				int y = q[i].front().second;
				q[i].pop();
				for (int j = 0; j < 4; j++) {
					int x2 = x + dx[j];
					int y2 = y + dy[j];
					if (x2 > n || x2<1 || y2>m || y2 < 1 || arr[x2][y2] != '.')continue;
					e = true;
					arr[x2][y2] = i + '0';
					q[i].push({ x2,y2 });
				}

			}
		}
	}
	return e;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++)cin >> s[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > '0')q[arr[i][j] - '0'].push({ i,j });
		}
	}
	
	while (game()) {
		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << endl;
		}*/
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] > '0') {
				c[arr[i][j] - '0']++;
			}
		}
	}
	for (int i = 1; i <= p; i++)cout << c[i] << ' ';
}