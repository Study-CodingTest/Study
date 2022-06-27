#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dp;

void topologicalSort(const vector<vector<pair<int, int>>>& adj, vector<int>& in_degree, const int& src, const int& dest) {
	const int& n = in_degree.size() - 1;

	queue<pair<int, int>> q;
	q.emplace(src, 0);

	while (!q.empty()) {
		const int cur_node = q.front().first;
		q.pop();

		for (auto next : adj[cur_node]) {
			const int next_node = next.first;
			const int next_cost = dp[cur_node] + next.second;

			dp[next_node] = max(dp[next_node], next_cost);

			if (--in_degree[next_node] == 0) {
				q.emplace(next_node, next_cost);
			}
		}
	}
}

void DFS(const vector<vector<pair<int, int>>>& adj, const int& cur) {
	for (auto next : adj[cur]) {
		const int& new_cost = dp[cur] + next.second;
		if (new_cost > dp[next.first]) {
			dp[next.first] = new_cost;
			DFS(adj, next.first);
		}
	}
}

void DFS(const vector<vector<pair<int, int>>>& adj, const int& cur, vector<bool>& visit, int& count) {
	if (visit[cur]) {
		return;
	}

	visit[cur] = true;
	for (auto next : adj[cur]) {
		if (dp[cur] - next.second == dp[next.first]) {
			DFS(adj, next.first, visit, ++count);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	dp.assign(n + 1, 0);
	vector<vector<pair<int, int>>> adj(n + 1);
	vector<vector<pair<int, int>>> reverse_adj(n + 1);
	vector<int> in_degree(n + 1);

	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		reverse_adj[v].emplace_back(u, w);
		in_degree[v]++;
	}

	int src, dest;
	cin >> src >> dest;
	
	//topologicalSort(adj, in_degree, src, dest);
	DFS(adj, src);
	cout << dp[dest] << '\n';

	int count = 0;
	vector<bool> visit(n + 1);
	DFS(reverse_adj, dest, visit, count);
	cout << count;
	
	return 0;
}