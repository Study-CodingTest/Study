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

	int g;
	int count = 0;
	while (P--) {
                cin >> g;
		
		if (find(g) == 0) {
			break;
		}

		count++;
		merge(g - 1, g);
	}

	cout << count;

	return 0;
}
