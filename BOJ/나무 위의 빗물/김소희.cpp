//
// Created by Kim So Hee on 2022/07/13.
//

#include <bits/stdc++.h>

using namespace std;
int N, W;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> W;
    vector<vector<int>> inputs(N + 1, vector<int>());
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        inputs[u].push_back(v);
        inputs[v].push_back(u);
    }

    queue<int> q;
    vector<bool> visited(N + 1, false);

    q.push(1);
    visited[1] = true;
    int answer = 0;
    /**
     * 굳이 BFS 탐색을 하지 않아도
     * 연결된 노드 개수 만으로(1개, 루트 제외) 리프 여부를 알 수 있다..
     */
    while (!q.empty()) {
        int here = q.front();
        q.pop();

        auto count = inputs[here].size();
        if (here != 1 && count == 1) {
            answer++;
        }
        for (const auto &child: inputs[here]) {
            if (!visited[child]) {
                visited[child] = true;
                q.push(child);
            }
        }
    }
    cout.precision(11);
    cout << W / (double) answer;
}