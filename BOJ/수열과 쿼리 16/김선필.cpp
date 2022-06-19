#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const pair<int, int> INF = make_pair(1e9, 1e5);

int N;
vector<int> A;
vector<pair<int, int>> tree;

pair<int, int> init(const int start, const int end, const int node) {
	if (start == end) {
		return tree[node] = make_pair(A[start], start);
	}

	const int leftNode = node * 2;
	const int rightNode = leftNode + 1;
	const int mid = (start + end) / 2;

	auto leftChild = init(start, mid, leftNode);
	auto rightChild = init(mid + 1, end, rightNode);

	return tree[node] = min(leftChild, rightChild);
}

pair<int, int> find(const int start, const int end, const int node, const int& left, const int& right) {
	if (left > end || right < start) {
		return INF;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}

	const int leftNode = node * 2;
	const int rightNode = leftNode + 1;
	const int mid = (start + end) / 2;

	auto leftChild = find(start, mid, leftNode, left, right);
	auto rightChild = find(mid + 1, end, rightNode, left, right);

	return min(leftChild, rightChild);
}

void update(const int start, const int end, const int node, const int& index, const int& change) {
	if (index < start || index > end) {
		return;
	}
	if (start == end) {
		tree[node] = make_pair(change, index);
		return;
	}

	const int leftNode = node * 2;
	const int rightNode = leftNode + 1;
	const int mid = (start + end) / 2;

	update(start, mid, leftNode, index, change);
	update(mid + 1, end, rightNode, index, change);

	tree[node] = min(tree[leftNode], tree[rightNode]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	const int h = ceil(log2(N));
	tree.assign(1 << (h + 1), INF);
	init(0, N - 1, 1);

	int M, q, i, j, v;
	cin >> M;
	while (M--) {
		cin >> q >> i;

		if (q == 1) {
			cin >> v;
			update(0, N - 1, 1, i - 1, v);
		}
		else if (q == 2) {
			cin >> j;
			auto res = find(0, N - 1, 1, i - 1, j - 1);
			cout << res.second + 1 << '\n';
		}
	}

	return 0;
}