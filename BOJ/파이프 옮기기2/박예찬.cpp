#include <iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<cmath>
using namespace std;
int n;
long long dp[33][33][3];
int arr[33][33];
long long dpf(int x, int y, int t) {
	if (dp[x][y][t] != -1)return dp[x][y][t];
	if (arr[x][y] == 1)return 0;
	if (t == 0) {	
		dp[x][y][t] = dpf(x - 1, y, 0)+ dpf(x - 1, y, 2);
		
	}
	if (t == 1) {		
		dp[x][y][t] = dpf(x , y-1, 1) + dpf(x, y-1, 2);
	}
	if (t == 2) {		
		if (arr[x - 1][y] == 1)return 0;
		if (arr[x][y - 1] == 1)return 0;
		dp[x][y][t] = dpf(x - 1, y - 1, 0) + dpf(x - 1, y - 1, 1) + dpf(x - 1, y - 1, 2);
	}
	return dp[x][y][t];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k <= 2; k++)
				dp[i][j][k] = -1;
			cin >> arr[i][j];
		}
	}
	dp[1][2][1] = 1;
	cout << dpf(n, n,0)+dpf(n, n, 1)+ dpf(n, n, 2);

}