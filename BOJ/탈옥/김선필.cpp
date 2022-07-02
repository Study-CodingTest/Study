#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int INF = 1e5;
const char WALL = '*';
const char DOOR = '#';
const char PRISONER = '$';
const char VACANT = '.';

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

vector<vector<int>> BFS(const vector<vector<char>>& map, const pair<int, int>& start) {
	const int& n = map.size();
	const int& m = map[0].size();

	vector<vector<int>> dp(n, vector<int>(m, INF));
	dp[start.first][start.second] = 0;

	deque<pair<int, pair<int, int>>> dq;
	dq.emplace_back(0, make_pair(start.first, start.second));

	while (!dq.empty()) {
		const int cost = dq.front().first;
		const int row = dq.front().second.first;
		const int col = dq.front().second.second;
		dq.pop_front();

		if (dp[row][col] < cost) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			const int next_row = row + dr[i];
			const int next_col = col + dc[i];
			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) {
				continue;
			}

			const char& room_type = map[next_row][next_col];
			if (room_type == WALL) {
				continue;
			}

			int new_cost = cost;
			int& next_cost = dp[next_row][next_col];
			if (room_type == DOOR) {
				if (next_cost <= ++new_cost) {
					continue;
				}
				dq.emplace_back(new_cost, make_pair(next_row, next_col));
			}
			else {
				if (next_cost <= new_cost) {
					continue;
				}
				dq.emplace_front(new_cost, make_pair(next_row, next_col));
			}

			next_cost = min(next_cost, new_cost);
		}
	}

	return dp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	
	while (T--) {
		int h, w;
		cin >> h >> w;

		vector<pair<int, int>> prisoners;
		vector<vector<char>> map(h + 2, vector<char>(w + 2, VACANT));
		for (int i = 1; i <= h; i++) {
			string input;
			cin >> input;
			
			for (int j = 1; j <= w; j++) {
				map[i][j] = input[j - 1];
				if (map[i][j] == PRISONER) {
					prisoners.emplace_back(i, j);
				}
			}
		}
		prisoners.emplace_back(0, 0);

		vector<vector<vector<int>>> dp(3);
		for (int i = 0; i < 3; i++) {
			dp[i] = BFS(map, prisoners[i]);
		}

		int answer = INF;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (map[i][j] == WALL) {
					continue;
				}

				if (map[i][j] == DOOR) {
					answer = min(answer, dp[0][i][j] + dp[1][i][j] + dp[2][i][j] - 2);
				}
				else {
					answer = min(answer, dp[0][i][j] + dp[1][i][j] + dp[2][i][j]);
				}
			}
		}

		cout << answer << '\n';
	}
	
	return 0;
}