//
// Created by Kim So Hee on 2022/07/23.
//

#include <bits/stdc++.h>

using namespace std;

int r, c;
char inputs[1501][1501];
bool visited[1501][1501], check[1501][1501];

int dx[4]{0, 1, 0, -1};
int dy[4]{-1, 0, 1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> r >> c;

    queue<pair<int, int>> swanQ, another, bfs;
    pair<int, int> swan = {-1, -1};

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            char in;
            cin >> in;
            inputs[i][j] = in;
            if (in != 'X') {
                if (in == 'L') {
                    if (swan.first != -1) swanQ.push({i, j});
                    swan = {i, j};
                }
                visited[i][j] = true;
                bfs.push({i, j});
            }
        }
    }

    int day = -1;
    while (!bfs.empty()) {
        day++;

        while (!swanQ.empty()) {
            const auto [swanY, swanX] = swanQ.front();
            swanQ.pop();
            for (int j = 0; j < 4; ++j) {
                int nextY = swanY + dy[j], nextX = swanX + dx[j];
                if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) continue;

                if (check[nextY][nextX]) continue;
                check[nextY][nextX] = true;

                // 탐색 도중 다른 백조의 위치를 찾으면 종료
                if (make_pair(nextY, nextX) != swan && inputs[nextY][nextX] == 'L') {
                    cout << day;
                    return 0;
                }

                // 얼음은 다음 날에 탐색
                if (inputs[nextY][nextX] == 'X') another.push({nextY, nextX});
                else swanQ.push({nextY, nextX});
            }
        }

        // 다음 날에 사용할 큐 스위칭
        swanQ = another;
        another = queue<pair<int, int>>();

        // depth 별 순회
        auto size = bfs.size();

        // 1 depth 녹는 빙하
        for (int i = 0; i < size; ++i) {
            auto [y, x] = bfs.front();
            bfs.pop();
            for (int j = 0; j < 4; ++j) {
                int nextY = y + dy[j], nextX = x + dx[j];
                if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) continue;

                if (visited[nextY][nextX]) continue;
                visited[nextY][nextX] = true;

                inputs[nextY][nextX] = '.';
                bfs.push({nextY, nextX});
            }
        }
    }
}