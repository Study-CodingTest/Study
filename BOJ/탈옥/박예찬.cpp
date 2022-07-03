#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<tuple>
using namespace std;
int n, m;
char arr[102][102];
pair<int, int> pri[3];
bool fi;
bool op[102][102];
bool flag[102][102];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int meanArr[102][102][3];
bool flag2[102][102];
void bfs(int num) {
	for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= m+1; j++) {
			flag[i][j] = false;
		}
	}
	priority_queue<tuple<int, int, int>> q;
	q.push({ 0,pri[num].first,pri[num].second });
	while (!q.empty()) {
		int d = get<0>(q.top());
		int x = get<1>(q.top());
		int y = get<2>(q.top());
		q.pop();
		if (flag[x][y])continue;		
		flag[x][y] = true;
		flag2[x][y] = true;
		meanArr[x][y][num] = -d;

		for (int i = 0; i < 4; i++) {
			int x2 = x + dx[i];
			int y2 = y + dy[i];
			if (x2<0 || y2<0 || x2>n + 1 || y2>m + 1) { continue; }
			if (arr[x2][y2] == '#') {				
				q.push({ d-1,x2,y2 });
			}
			if (arr[x2][y2] == '.' || arr[x2][y2] == '$') {
				q.push({ d,x2,y2 });				
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	for (int a = 0; a < t; a++) {
		fi = false;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '$') {
					if (!fi) {
						pri[1].first = i;
						pri[1].second = j;
						fi = true;
					}
					else {
						pri[2].first = i;
						pri[2].second = j;
					}
				}
			}
		}
		for (int i = 0; i <= n + 1; i++)arr[i][0] = '.';
		for (int j = 0; j <= m + 1; j++)arr[0][j] = '.';
		for (int i = 0; i <= n + 1; i++)arr[i][m + 1] = '.';
		for (int j = 0; j <= m + 1; j++)arr[n + 1][j] = '.';
		bfs(0);
		bfs(1);
		bfs(2);
	
		int mini = 10001;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] == '*')continue;
				if (!flag2[i][j])continue;
				for (int k = 1; k < 3; k++) {
					meanArr[i][j][0] += meanArr[i][j][k];
				}

				if (arr[i][j] == '#')meanArr[i][j][0] -= 2;
				mini = min(mini, meanArr[i][j][0]);
			}
		}
		cout << mini<<'\n';
	}
}
