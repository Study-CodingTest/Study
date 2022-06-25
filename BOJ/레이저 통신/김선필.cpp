#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

const int INF = 1e9;
const int INIT = -1;
const char C = 'C';
const char WALL = '*';

int W, H;
pair<int, int> src, dest;
vector<string> map;
vector<vector<int>> dp;

struct Node {

	int row;
	int col;
	int dir;
	int mirrors;

	Node(int row, int col, int dir, int mirrors)
		: row(row), col(col), dir(dir), mirrors(mirrors) {}

};

void BFS() {
	queue<Node> q;

	q.push(Node(src.first, src.second, -1, -1));
	dp[src.first][src.second] = 0;

	int cur = 1, next = 0;
	while (!q.empty()) {
		int row = q.front().row;
		int col = q.front().col;
		int dir = q.front().dir;
		int mirrors = q.front().mirrors;

		q.pop();
		if (mirrors > dp[row][col]) {
			continue;
		}

		for (int next_dir = 0; next_dir < 4; next_dir++) {
			int next_row = row + dr[next_dir];
			int next_col = col + dc[next_dir];

			if (next_row < 0 || next_row >= H || next_col < 0 || next_col >= W) {
				continue;
			}
			if (map[next_row][next_col] == WALL) {
				continue;
			}

			int count = mirrors;
			if (dir != next_dir) {
				count++;
			}

			int& cost = dp[next_row][next_col];
			if (cost >= count) {
				cost = count;
				q.push(Node(next_row, next_col, next_dir, cost));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> W >> H;
	map.resize(H);
	dp.assign(H, vector<int>(W, INF));

	for (int i = 0; i < H; i++) {
		cin >> map[i];
		for (int j = 0; j < W; j++) {
			if (map[i][j] == C) {
				if (src == make_pair(0, 0)) {
					src = make_pair(i, j);
				}
				else {
					dest = make_pair(i, j);
				}
			}
		}
	}

	BFS();
	cout << dp[dest.first][dest.second];

	return 0;
}
