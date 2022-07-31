//
// Created by Kim So Hee on 2022/07/11.
//

#include <bits/stdc++.h>

using namespace std;

int N, M;
int inputs[501][501];
vector<vector<vector<bool>>> block = {
        {
                {1, 1, 1, 1}
        },
        {
                {1, 1},    {1, 1}
        },
        {
                {1, 0},    {1, 0}, {1, 1}
        },
        {
                {0, 1},    {0, 1}, {1, 1}
        },
        {
                {1, 0},    {1, 1}, {0, 1}
        },
        {
                {0, 1},    {1, 1}, {1, 0}
        },
        {
                {1, 1, 1}, {0, 1, 0}
        }
};

void generate() {
    for (int i = 0; i < 7; ++i) {
        vector<vector<bool>> temp = block[i];


        for (int z = 0; z < 3; z++) {
            auto n = temp.size(), m = temp[0].size();
            vector<vector<bool>> rotate(m, vector<bool>(n));
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    rotate[j][k] = temp[n - k - 1][j];
                }
            }
            block.push_back(rotate);
            temp = rotate;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    generate();
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> inputs[i][j];
        }
    }
    int answer = 0;
    for (const auto &b: block) {
        int n = b.size(), m = b[0].size();
        for (int i = 0; i <= N - n; ++i) {
            for (int j = 0; j <= M - m; ++j) {
                bool fail = false;
                int sum = 0;
                for (int k = 0; k < n; ++k) {
                    for (int l = 0; l < m; ++l) {
                        int checkY = i + k, checkX = j + l;
                        if (checkY >= N || checkX >= M) fail = true;
                        else if (b[k][l]) {
                            sum += inputs[checkY][checkX];

                        }


                    }
                }
                if (!fail) answer = max(answer, sum);
            }
        }
    }
    cout << answer;
}