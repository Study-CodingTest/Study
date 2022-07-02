#include <iostream>
#include <vector>

using namespace std;

const int WALL = 1;
const int HORIZONTAL = 0;
const int VERTICAL = 1;
const int DIAGONAL = 2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<vector<int>> map(N + 1, vector<int>(N + 1));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(N + 1, vector<long long>(3)));
	dp[1][2][HORIZONTAL] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == WALL) {
				continue;
			}

			dp[i][j][HORIZONTAL] += dp[i][j - 1][HORIZONTAL] + dp[i][j - 1][DIAGONAL];
			dp[i][j][VERTICAL] += dp[i - 1][j][VERTICAL] + dp[i - 1][j][DIAGONAL];

			if (map[i - 1][j] != WALL && map[i][j - 1] != WALL) {
				dp[i][j][DIAGONAL] += dp[i - 1][j - 1][DIAGONAL] + dp[i - 1][j - 1][VERTICAL] + dp[i - 1][j - 1][HORIZONTAL];
			}
		}
	}

	cout << dp[N][N][HORIZONTAL] + dp[N][N][VERTICAL] + dp[N][N][DIAGONAL];

	return 0;
}