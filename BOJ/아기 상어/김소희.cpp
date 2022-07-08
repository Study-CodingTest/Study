//
// Created by Kim So Hee on 2022/07/04.
//

#include <bits/stdc++.h>

using namespace std;
int N;

// 자신 크기보다 큰 칸은 지나갈 수 없다.
// 자신 크기보다 작은 물고기만 먹을 수 있다. (가장 위, 가장 왼쪽)
int babyShark = 2, eat = 0, callMother = 0;

int fishes[21][21];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

pair<int, int> moveShark(const pair<int, int> &start) {
    /**
     *  1. 상어가 물고기를 먹을 수 있디면
     *     그 칸으로 이동 후, 이동한 좌표를 반환한다.
     *     이동한 거리를 callMother에 더한다.
     *
     *  2. 상어가 물고기를 먹을 수 없다면
     *     {-1, -1}을 반환한다.
     */
    queue<pair<int, int>> q;
    q.push(start);
    int visited[21][21]{};
    int distance = -1;
    while (!q.empty()) {
        auto size = q.size();
        distance++;

        /**
         * priority queue
         *   가장 위, 가장 왼쪽의 물고기 좌표를 정렬 하기 위해 사용
         */
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (int i = 0; i < size; ++i) {
            int hereY = q.front().first, hereX = q.front().second;
            q.pop();
            if (hereY < 0 || hereX < 0 || hereY >= N || hereX >= N) continue;
            if (visited[hereY][hereX]) continue;
            visited[hereY][hereX] = true;

            int status = fishes[hereY][hereX];

            if (status > babyShark) continue;

            if (status != 0 && status < babyShark) {
                pq.push({hereY, hereX});
            }

            for (int j = 0; j < 4; ++j) {
                q.push({hereY + dy[j], hereX + dx[j]});
            }

        }
        /**
         * 물고기 발견!
         *   물고기 칸 0으로 초기화
         *   먹은 히스토리 처리
         *   callMother 시간 증가
         */
        if (!pq.empty()) {
            auto eatFish = pq.top();
            fishes[eatFish.first][eatFish.second] = 0;
            eat++;
            if (eat == babyShark) eat = 0, babyShark++;
            callMother += distance;
            return eatFish;
        }
    }

    /**
     * 물고기를 못 찾았다..ㅜㅜ
     */
    return {-1, -1};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    pair<int, int> cord;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> fishes[i][j];
            if (fishes[i][j] == 9) cord = {i, j}, fishes[i][j] = 0;
        }
    }

    while ((cord = moveShark(cord)).first != -1) {};

    cout << callMother;
}