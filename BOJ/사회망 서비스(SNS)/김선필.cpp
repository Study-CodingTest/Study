#include <iostream>
#include <vector>

using namespace std;

const int NORMAL = 0;
const int ADAPTOR = 1;

vector<int> dfs(const vector<vector<int>> &adj, vector<bool> &visit, int cur) {
    vector<int> res(2);
    res[ADAPTOR] = 1;
    visit[cur] = true;

    for (auto next : adj[cur]) {
        if (visit[next]) {
            continue;
        }

        const vector<int> child = dfs(adj, visit, next);
        res[NORMAL] += child[ADAPTOR];
        res[ADAPTOR] += min(child[NORMAL], child[ADAPTOR]);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<bool> visit(N + 1);
    vector<vector<int>> adj(N + 1, vector<int>());
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const vector<int> ans = dfs(adj, visit, 1);
    cout << min(ans[ADAPTOR], ans[NORMAL]);

    return 0;
}
