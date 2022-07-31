//
// Created by Kim So Hee on 2022/07/26.
//

#include <bits/stdc++.h>

static const int INF = 987654321;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /**
     * 밸만 - 포드 알고리즘 (DP)
     *  - 그래프 내 음수 간선 존재
     *  - 음수 사이클을 피해 최단 거리 계산
     *
     *  인접 간선을 검사 하고 거리를 갱신 하는 과정을 V - 1번으로 제한 한다!
     *   --> V 번째 간선이 추가되면? 사이클에 진입한 것이다
     *
     *   다익스트라는 해당 노드에 붙어 있는 간선만 확인하는데,
     *   밸만 포드는 전체 간선을 방문 한다.
     *
     *   시간 복잡도 : O(VE)
다    */
    int tc; cin>>tc;
    while (tc--) {
        int n, m, w; cin>>n>>m>>w;
        vector<pair<int,int>> inputs[501];
        vector<int> visited(n+1, INF);
        for (int i = 0; i < m; ++i) {
            int s, e, t; cin>>s>>e>>t;
            inputs[s].emplace_back(e, t);
            inputs[e].emplace_back(s, t);
        }
        for (int i = 0; i < w; ++i) {
            int s, e, t; cin>>s>>e>>t;
            inputs[s].emplace_back(e, -t);
        }


        visited[1] = 0;
        bool cycle = false;

        // 음수 사이클이 있으면 YES
        for (int i = 0; i < n; ++i) {
            // edge 순회
            for (int here = 1; here <= n; here++) {
                for (const auto [next, distance]: inputs[here]) {
                    if (visited[next] > visited[here] + distance) {
                        visited[next] = visited[here] + distance;
                        if(i == n - 1) cycle = true;
                    }
                }
            }
        }
        if(cycle) cout<<"YES\n";
        else cout << "NO\n";
    }
}