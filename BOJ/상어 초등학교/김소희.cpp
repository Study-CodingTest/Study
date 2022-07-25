//
// Created by Kim So Hee on 2022/07/21.
//

#include <bits/stdc++.h>

using namespace std;
int N;

int students[22][22];
vector<int> like[404];
int dx[4]{0, 1, 0, -1};
int dy[4]{-1, 0, 1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int student;
            cin >> student;
            for (int k = 0; k < 4; ++k) {
                int l;
                cin >> l;
                like[student].push_back(l);
            }

            // 자리 배치
            // (인접한 칸에) 좋아 하는 학생 수 > 비어 있는 칸 > 행 > 열
            int y = -1, x = -1, adj = -1, empty = -1;
            for (int row = N; row >= 1; row--) {
                for (int col = N; col >= 1; col--) {
                    if (students[row][col]) continue;
                    int emptyNumber = 0, adjNumber = 0;
                    for (int k = 0; k < 4; ++k) {
                        int nextY = row + dy[k];
                        int nextX = col + dx[k];

                        if (nextY < 1 || nextY > N || nextX < 1 || nextX > N) continue;
                        if (!students[nextY][nextX]) emptyNumber++;
                        if (find(like[student].begin(), like[student].end(), students[nextY][nextX]) !=
                            like[student].end())
                            adjNumber++;
                    }
                    if (adjNumber > adj || (adjNumber == adj && emptyNumber >= empty)) {
                        adj = adjNumber, empty = emptyNumber, y = row, x = col;
                    }
                }
            }
            students[y][x] = student;
        }
    }
    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; j++) {
            int exp = -1;
            for (int k = 0; k < 4; ++k) {
                if (find(like[students[i][j]].begin(), like[students[i][j]].end(),
                         students[i + dy[k]][j + dx[k]]) != like[students[i][j]].end())
                    exp++;
            }
            answer += (int) pow(10, exp);
        }
    }
    cout << answer;
}