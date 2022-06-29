#include <iostream>
#include <vector>

using namespace std;

vector<int> par;

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) {
		u = find(--u);
	}

	par[v] = u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int G, P;
	cin >> G >> P;
	
	par.resize(G + 1);
	for (int i = 1; i <= G; i++) {
		par[i] = i;
	}

	vector<int> g(P);
	for (int i = 0; i < P; i++) {
		cin >> g[i];
	}

	int count = 0;
	for (int i = 0; i < P; i++) {
		if (find(g[i]) == 0) {
			break;
		}

		count++;
		merge(g[i] - 1, g[i]);
	}

	cout << count;

	return 0;
}