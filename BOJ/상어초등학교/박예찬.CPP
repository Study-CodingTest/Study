#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
#include<string>
using namespace std;
int n;
int pf[401][4];
int arr[21][21];
int counter = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
void select(int k) {
	vector<pair<int, int>> v;
	int maxF = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] != 0)continue;
			int m = 0;
			for (int l = 0; l < 4; l++) {		
				int x2 = i + dx[l];
				int y2 = j + dy[l];
				if (x2 > 0 && y2 > 0 && x2 <= n && y2 <= n) {
					for (int p = 0; p < 4; p++) {
						if (arr[x2][y2] == pf[k][p]) {
							m++;
						}
					}
				}
			}
				if (m > maxF) {
					maxF = m;				
					v.clear();
					v.push_back({ i,j });
				}
				else if (m == maxF) {
					v.push_back({ i,j });
				}
			
		}
	}
	if (v.size() == 1) {
		arr[v[0].first][v[0].second] = k;
	}
	else {
		int x = 0;
		int y = 0;
		int m = -1;
		for (int i = 0; i < v.size(); i++) {
			int m2 = 0;	
			for (int l = 0; l < 4; l++) {
				int x2 = v[i].first + dx[l];
				int y2 = v[i].second + dy[l];
				if (x2 > 0 && y2 > 0 && x2 <= n && y2 <= n && arr[x2][y2] == 0) {
					m2++;
				}
			}
		
			if (m2 > m) {
			
				m = m2;
				x = v[i].first;
				y = v[i].second;
			}
		}
		arr[x][y] = k;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n*n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < 4; j++) {
			cin >> pf[k][j];	
		}
		select(k);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int f = 0;
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (x<1 || y<1 || x>n || y>n)continue;
				for (int l = 0; l < 4; l++) {
					if (arr[x][y] == pf[arr[i][j]][l])
						f++;
				}
			}
			if (f == 1)counter++;
			if (f == 2)counter += 10;
			if (f == 3)counter += 100;
			if (f == 4)counter += 1000;
		}
	}

	cout << counter;
}