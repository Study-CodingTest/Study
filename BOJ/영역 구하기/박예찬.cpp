#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstdlib>
#include<algorithm>
using namespace std;
int squaress[101][101];
int n, m, k;
int grid[10001];
int counter;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
void dfs(int a, int b) {
	squaress[a][b] = -1;
	grid[counter]++;
	for (int i = 0; i < 4; i++) {
		int x2 = a + dx[i];
		int y2 = b + dy[i];
		if (x2 >= 0 && y2 >= 0 && x2 < n && y2 < m && squaress[x2][y2] == 0) {
			dfs(x2, y2);
		}
	}
}
int main() {
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++) {
			for (int l = x1; l < x2; l++) {
				squaress[l][j] = 1;
			}
		}
	}
	for (int j = 0; j < m; j++) {
		for (int l = 0; l < n; l++) {
			if (squaress[l][j] == 0)
			{
				dfs(l, j);
				counter++;
			}
		}
	}
	sort(grid, grid + counter);
	cout << counter << '\n';
	for (int i = 0; i < counter; i++) {
		cout << grid[i] << ' ';
	}
}
