//
// Created by Kim So Hee on 2022/07/12.
//

#include <bits/stdc++.h>

#define MAX 987654321

using namespace std;

int n, m, x;
int visited[1001][2];

/**
 * 다익스트라 알고리즘
 *   한 번 선택된 노드는 최단 거리를 갱신하고, 그 후 다시 갱신하지 않는다.
 *   선택 되지 않는 자식 노드 중, 거리가 가장 작은 노드를 선택한다. (우선 순위 큐)
 */

void run(int start, vector<pair<int, int>> (&load)[1001], int v) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    visited[start][v] = 0;

    while (!pq.empty()) {
        int here = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        for (const auto &nextP: load[here]) {
            int next = nextP.second + distance;
            if(visited[nextP.first][v] > next ){
                visited[nextP.first][v] = next;
                pq.push({next, nextP.first});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill(&visited[0][0], &visited[1000][2], MAX);
    cin >> n >> m >> x;
    vector<pair<int,int>> goLoad[1001], returnLoad[1001];

    for (int i = 0; i < m; ++i) {
        int s, e, t;
        cin >> s >> e >> t;

        goLoad[s].emplace_back(e, t);
        returnLoad[e].emplace_back(s, t);
    }

    /**
     * 간선을 거꾸로 저장하면
     * 다익스트라 2번 만으로 n -- x 왕복 거리를 구할 수 있다
     */
    run(x, goLoad, 0);
    run(x, returnLoad, 1);


    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        answer = max(answer, visited[i][0] + visited[i][1]);
    }
    cout << answer;
}