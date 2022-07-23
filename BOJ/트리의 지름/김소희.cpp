//
// Created by Kim So Hee on 2022/07/21.
//

#include <bits/stdc++.h>

using namespace std;

int V;
vector<unordered_map<int, int>> inputs;
priority_queue<int> answer;
vector<bool> visited;

/**
 * 자식 노드 개수
 *  1개 :
 *   - 서브 트리 최대 depth + 간선 길이 (answer push, return)
 *  2개 이상 :
 *   - 서브 트리 최대 depth 2개 합 (answer push)
 *   - 서브 트리 최대 depth + 간선 길이 (return)
 */

int dfs(int v) {

    priority_queue<int> sorted;

    for (const auto [next, distance]: inputs[v]) {
        if (!visited[next]) {
            visited[next] = true;
            sorted.push(dfs(next) + distance);
        }
    }

    if (sorted.size() == 1) {
        int ret = sorted.top();
        answer.push(ret);
        return ret;
    }

    if (sorted.size() >= 2) {
        int first = sorted.top();
        sorted.pop();
        int second = sorted.top();
        answer.push(first + second);
        return first;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> V;
    inputs.resize(V + 1);
    visited.resize(V + 1);
    for (int i = 0; i < V; ++i) {
        int v;
        cin >> v;
        while (true) {
            int e, distance;
            cin >> e;
            if (e == -1) break;
            cin >> distance;
            inputs[v][e] = distance;
        }
    }
    visited[1] = true;
    dfs(1);
    cout << answer.top();
}