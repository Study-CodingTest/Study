#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

vector<int> Dijkstra(const vector<vector<pair<int, int>>> &adj, const int &N, const int &X) {
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    vector<int> dist(N + 1, INF);

    dist[X] = 0;
    pq.emplace(X, 0);

    while (!pq.empty()) {
        const int cur_node = pq.top().first;
        const int cur_cost = pq.top().second;
        pq.pop();

        for (auto next: adj[cur_node]) {
            const int next_node = next.first;
            const int next_cost = next.second + cur_cost;

            if (dist[next_node] < next_cost) {
                continue;
            }
            dist[next_node] = next_cost;
            pq.emplace(next_node, next_cost);
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> adj(N + 1);
    vector<vector<pair<int, int>>> rev_adj(N + 1);

    int u, v, w;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        rev_adj[v].emplace_back(u, w);
    }

    vector<int> ans(N + 1);
    vector<int> len = Dijkstra(adj, N, X);
    for (int i = 1; i <= N; i++) {
        ans[i] += len[i];
    }

    len = Dijkstra(rev_adj, N, X);
    for (int i = 1; i <= N; i++) {
        ans[i] += len[i];
    }

    sort(ans.begin(), ans.end());
    cout << ans.back();

    return 0;
}
