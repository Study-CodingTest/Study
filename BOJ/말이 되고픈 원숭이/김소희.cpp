//
// Created by Kim So Hee on 2022/07/07.
//

#include <bits/stdc++.h>

using namespace std;
int K, W, H;
// 1 == 장애물
bool inputs[201][201];
int dx[4]{0, 1, 0, -1};
int dy[4]{-1, 0, 1, 0};
int horseX[8]{1, 2, 2, 1, -1, -2, -2, -1};
int horseY[8]{2, 1, -1, -2, -2, -1, 1, 2};
bool visited[201][201][31];

struct Cord {
    int y;
    int x;
    int k;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> K >> W >> H;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> inputs[i][j];
        }
    }

    queue<Cord> q;
    q.push({0, 0, K});
    int distance = -1;

    while (!q.empty()) {
        auto size = q.size();
        distance++;
        for (int i = 0; i < size; i++) {
            auto here = q.front();
            q.pop();
            int hereY = here.y, hereX = here.x, horseCount = here.k;

            if (hereY < 0 || hereX < 0 || hereY >= H || hereX >= W) continue;
            if (visited[hereY][hereX][horseCount]) continue;
            visited[hereY][hereX][horseCount] = true;

            if (inputs[hereY][hereX] == 1) continue;
            if (hereY == H - 1 && hereX == W - 1) {
                cout << distance;
                return 0;
            }

            for (int j = 0; j < 4; ++j) {
                q.push({hereY + dy[j], hereX + dx[j], horseCount});
            }
            if (horseCount > 0) {
                for (int j = 0; j < 8; ++j) {
                    q.push({hereY + horseY[j], hereX + horseX[j], horseCount - 1});
                }
            }
        }
    }
    cout << -1;
}