#include <iostream>
#include <vector>

using namespace std;

int dfs(const int &cur, const vector<int> &adj, vector<bool> &isFinished, vector<bool> &isVisited) {
    int cnt = 0;
    int next = adj[cur];
    isVisited[cur] = true;

    if (!isVisited[next]) {
        cnt = dfs(next, adj, isFinished, isVisited);
    } else if (!isFinished[next]) {
        while (next != cur) {
            next = adj[next];
            cnt++;
        }
        cnt++;
    }
    
    isFinished[cur] = true;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> adj(n + 1);
        vector<bool> isVisited(n + 1);
        vector<bool> isFinished(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> adj[i];
        }

        int ans = n;
        for (int i = 1; i <= n; i++) {
            if (!isVisited[i]) {
                const int cnt = dfs(i, adj, isFinished, isVisited);
                ans -= cnt;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
