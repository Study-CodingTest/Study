//
// Created by Kim So Hee on 2022/07/15.
//

#include <bits/stdc++.h>

using namespace std;

int N, M, P;
int inputs[1001][1001];
int depth[10];
int dx[4]{0, 1, 0, -1};
int dy[4]{-1, 0, 1, 0};

struct Cord {
    int y;
    int x;
    int player;
    int limit;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<pair<int, int>>> castles(10);
    cin >> N >> M >> P;
    for (int i = 1; i <= P; ++i) {
        cin >> depth[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            if (c == '.') inputs[i][j] = 0;
            else if (c == '#') inputs[i][j] = -1;
            else {
                int number = c - '0';
                inputs[i][j] = number;
                castles[number].push_back({i, j});
            }
        }
    }

    queue<Cord> q;
    for (int i = 1; i < castles.size(); i++) {
        for (const auto &castle: castles[i]) {
            q.push({castle.first, castle.second, i, depth[i]});
        }
    }

    while (!q.empty()) {
        /**
         * Si는 BFS의 depth 제한이다
         * Player마다 돌아가면서 가능한 depth 단위(Si)로 BFS를 실행한다
         *
         * 바깥의 큐는 플레이어 턴의 실행 대기열이다
         *  - 큐가 empty, 즉 확장을 더 이상 할 수 없을 때 종료한다
         *
         * 안쪽의 큐는 플레이어 하나 당 실행하는 BFS 큐이다
         *  - 플레이어 당 제한된 depth 만 실행한다
         *  - 0인 칸만 확장할 수 있다
         *  - 마지막 depth 탐색 시, 다음 탐색할 칸을 바깥 큐에 넣는다
         */
        int player = q.front().player;
        queue<Cord> run;
        while (!q.empty() && q.front().player == player) {
            auto here = q.front();
            run.push(here);
            q.pop();
            if (inputs[here.y][here.x] == 0)
                inputs[here.y][here.x] = player;
        }

        // BFS 실행
        while (!run.empty()) {
            auto [y, x, p, limit] = run.front();
            run.pop();

            for (int i = 0; i < 4; ++i) {
                int nextY = y + dy[i], nextX = x + dx[i];
                /**
                 * 1. 인덱스 범위 처리, 방문 예외 처리
                 * 2. 0 인 칸만 방문
                 * 3. limit 가 1 이면 바깥 큐에 삽입 (턴 종료)
                 */
                if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= M) continue;
                if (inputs[nextY][nextX] != 0) continue;
                inputs[nextY][nextX] = player;

                if (limit == 1) q.push({nextY, nextX, player, depth[player]});
                else {
                    run.push({nextY, nextX, player, limit - 1});
                }
            }
        }
    }
    vector<int> answer(P);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (inputs[i][j] >= 1) answer[inputs[i][j] - 1]++;
        }
    }
    for (const auto &a: answer) {
        cout << a << ' ';
    }
}