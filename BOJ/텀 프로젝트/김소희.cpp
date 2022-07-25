//
// Created by Kim So Hee on 2022/07/23.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> inputs(n + 1);
        vector<int> visited(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> inputs[i];
        }
        int teams = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;
            int next = i;
            do {
                visited[next] = i;
            } while (!visited[next = inputs[next]]);

            if (visited[next] == i) {
                // 사이클 형성과 이전에 탐색한 for문 구분
                // 1. 방문한 경로 저장 - std find
                // 2. **int visited 배열 사용**
                int cycle = next, number = 1;
                while ((next = inputs[next]) != cycle) number++;
                teams += number;
            }
        }
        cout << n - teams << '\n';
    }
}