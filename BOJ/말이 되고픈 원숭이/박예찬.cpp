#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
int n, m, k;
int counter[201][201][31];
int arr[201][201];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int jux[] = { 2,2,-2,-2,1,1,-1,-1 };
int juy[] = { 1,-1,1,-1,2,-2,2,-2 };
int max_ = 1000000000;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> k >> n >> m;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			for (int l = 0; l <= k; l++) {
				counter[i][j][l] = max_;
			}
		}
	counter[1][1][0] = 0;
	queue<tuple<int, int, int>> q;
	q.push({ 1,1,0});
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int z=  get<2>(q.front());
		q.pop();
		//cout << x << ' ' << y << ' ' << z << endl;
		if (x == m && y == n) {
			cout << counter[x][y][z];
			return 0;
		}
		for (int i = 0; i < 4; i++) {		
			int x2 = x + dx[i];
			int y2 = y + dy[i];
			if (arr[x2][y2] == 1||x2<1||y2<1||x2>m||y2>n)continue;
			if (counter[x2][y2][z] > counter[x][y][z]+1) {
				counter[x2][y2][z] = counter[x][y][z]+1;
				q.push({ x2,y2,z});
			}
		}
		if (z < k) {
			for (int i = 0; i < 8; i++) {
				int x2 = x + jux[i];
				int y2 = y + juy[i];
				if (arr[x2][y2] == 1 || x2<1 || y2<1 || x2>m|| y2>n)continue;
				if (counter[x2][y2][z+1] > counter[x][y][z] + 1) {
					counter[x2][y2][z+1] = counter[x][y][z] + 1;
					q.push({ x2,y2,z+1});
				}
			}
		}
	}
	cout << -1;
}