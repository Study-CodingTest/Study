#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin >> N >> W;
    vector<int> adj(N + 1);

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u]++;
        adj[v]++;
    }

    int leaves = 0;
    for (int i = 2; i <= N; i++) {
        if (adj[i] == 1) {
            leaves++;
        }
    }

    cout.precision(4);
    cout << fixed << (double)W / leaves;

    return 0;
}
