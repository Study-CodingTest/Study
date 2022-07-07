#include <iostream>
#include <vector>

using namespace std;

const int NORMAL = 0;
const int ADAPTOR = 1;

void dfs(const vector<vector<int>> &adj, vector<vector<int>> &dp, vector<bool> &visit, int cur) {
    visit[cur] = true;
    dp[cur][ADAPTOR] = 1;

    for (auto next : adj[cur]) {
        if (visit[next]) {
            continue;
        }

        dfs(adj, dp, visit, next);
        dp[cur][NORMAL] += dp[next][ADAPTOR];
        dp[cur][ADAPTOR] += min(dp[next][NORMAL], dp[next][ADAPTOR]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<bool> visit(N + 1);
    vector<vector<int>> adj(N + 1, vector<int>());
    vector<vector<int>> dp(N + 1, vector<int>(2));
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(adj, dp, visit, 1);
    cout << min(dp[1][ADAPTOR], dp[1][NORMAL]);

    return 0;
}
