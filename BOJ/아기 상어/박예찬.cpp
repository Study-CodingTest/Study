#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
int n, m;
int map[21][21];
int start[2];
int eatcount;
int level = 2;
bool flag[21][21];
int c[21][21];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
bool canEat[21][21];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				start[0] = i;
				start[1] = j;
				map[i][j] = 0;
			}
		}
	}
	bool cant = false;
	int second = 0;
	while (1) {
		cant = true;
		queue<pair<int, int>> q;
		q.push({ start[0], start[1] });
		flag[start[0]][start[1]] = true;
		c[start[0]][start[1]] = 0;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int x2 = x + dx[i];
				int y2 = y + dy[i];
				if (x2 > 0 && y2 > 0 && x2 <= n && y2 <= n && !flag[x2][y2] && map[x2][y2] <= level)
				{
					if (map[x2][y2] < level && map[x2][y2] != 0)canEat[x2][y2] = true;
					flag[x2][y2] = true;
					c[x2][y2] = c[x][y] + 1;
					q.push({ x2,y2 });
				}
			}
		}
		int minDistance = 9999;
		int minx = -1;
		int miny = -1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (canEat[i][j] && minDistance > c[i][j])
				{
					minDistance = c[i][j];
					minx = i;
					miny = j;
				}

			}
		}
		if (minx == -1) {
			break;
		}
		eatcount++;
		if (eatcount == level) {
			eatcount = 0;
			level++;
		}
		second += minDistance;
		map[minx][miny] = 0; //이미 먹은 곳을 0으로
		start[0] = minx; //먹은 곳을 시작 지점으로
		start[1] = miny;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
			{
				canEat[i][j] = false; //초기화 후 다시 먹이 먹기 연산
				flag[i][j] = false;
				c[i][j] = 0;
			}
		}
	}
	cout << second;
}