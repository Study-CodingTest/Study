#include <iostream>
#include <vector>

using namespace std;

const int ITEM = 1;
const int OBSTACLE = 2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, A, B;
    cin >> N >> M >> A >> B;

    int row, col;
    vector<vector<int>> map(N + 1, vector<int>(M + 1));
    for (int i = 0; i < A; i++) {
        cin >> row >> col;
        map[row][col] = ITEM;
    }
    for (int i = 0; i < B; i++) {
        cin >> row >> col;
        map[row][col] = OBSTACLE;
    }

    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(M + 1, vector<int>(A + 1)));
    dp[1][1][0] = 1;
    if (map[1][1] == ITEM) {
        dp[1][1][1] = 1;
    }

    for (row = 1; row <= N; row++) {
        for (col = 1; col <= M; col++) {
            const int &type = map[row][col];
            if (type == OBSTACLE) {
                continue;
            }
            
            for (int item = 0; item <= A; item++) {
                dp[row][col][item + type] += dp[row - 1][col][item];
                dp[row][col][item + type] += dp[row][col - 1][item];
            }
        }
    }

    cout << dp[N][M][A];

    return 0;
}
