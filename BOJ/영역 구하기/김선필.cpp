#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int DFS(const vector<vector<bool>>& isRec, vector<vector<bool>>& isVisit, const int row, const int col) {
	const int& n = isRec.size();
	const int& m = isRec[0].size();
	int area_size = 1;

	isVisit[row][col] = true;
	for (int i = 0; i < 4; i++) {
		const int next_row = row + dr[i];
		const int next_col = col + dc[i];

		if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) {
			continue;
		}
		if (isRec[next_row][next_col] || isVisit[next_row][next_col]) {
			continue;
		}

		area_size += DFS(isRec, isVisit, next_row, next_col);
	}

	return area_size;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int M, N, K;
	cin >> M >> N >> K;

	vector<vector<bool>> isRec(M, vector<bool>(N));
	vector<vector<bool>> isVisit(M, vector<bool>(N));

	while (K--) {
		int col1, row1, col2, row2;
		cin >> col1 >> row1 >> col2 >> row2;

		for (int row = row1; row < row2; row++) {
			for (int col = col1; col < col2; col++) {
				isRec[row][col] = true;
			}
		}
	}

	vector<int> area_sizes;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!isRec[i][j] && !isVisit[i][j]) {
				const int area_size = DFS(isRec, isVisit, i, j);
				area_sizes.push_back(area_size);
			}
		}
	}

	sort(area_sizes.begin(), area_sizes.end());

	cout << area_sizes.size() << '\n';
	for (auto area_size : area_sizes) {
		cout << area_size << ' ';
	}

	return 0;
}