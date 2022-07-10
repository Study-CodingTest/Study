//
// Created by Kim So Hee on 2022/07/07.
//

#include <bits/stdc++.h>

using namespace std;
int N, M, A, B;
/**
 * 오른쪽, 위쪽 이동 가능
 */
int inputs[101][101];
int ***dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M >> A >> B;

    dp = new int **[N + 1];

    for (int i = 0; i < N + 1; i++) {
        dp[i] = new int *[M + 1];
        for (int j = 0; j < M + 1; j++) {
            dp[i][j] = new int[A + 2];
        }
    }
    for (int i = 0; i < A; ++i) {
        int n, m;
        cin >> n >> m;
        inputs[n][m] = 1;
    }
    for (int i = 0; i < B; ++i) {
        int n, m;
        cin >> n >> m;
        inputs[n][m] = -1;
    }
    dp[1][1][0] = 1;
    if (inputs[1][1] == 1) dp[1][1][1] = 1;


    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; j++) {
            if (inputs[i][j] != -1)
                for (int k = 0; k <= A; k++) {
                    int isItem = inputs[i][j] == 1 ? 1 : 0;
                    dp[i][j][k + isItem] += dp[i - 1][j][k];
                    dp[i][j][k + isItem] += dp[i][j - 1][k];
                }
        }
    }
    cout << dp[N][M][A];
}