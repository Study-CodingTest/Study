#include <iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<queue>
using namespace std;
int n,m;
int arr[100001];
int tree[400001];
int FindMin(int x, int y) {
	if (x == -1)return y;
	if (y == -1)return x;
	if (arr[x] == arr[y])return min(x, y);
	if (arr[x] < arr[y])return x;
	return y;
}
int MakeTree(int s, int e, int node) {
	if (s == e)return tree[node] = s;
	int mi = (s + e) / 2;
	return tree[node] = FindMin(MakeTree(s, mi, node * 2), MakeTree(mi + 1, e, node * 2+1));
}
int Update(int s, int e, int node, int index) {
	if (s > index || e < index)return tree[node];
	if (s == e)return tree[node];
	int mi = (s + e) / 2;
	return tree[node] = FindMin(Update(s, mi, node * 2, index), Update(mi + 1, e, node * 2 + 1, index));
}
int Query(int s, int e, int node, int left, int right) {
	if (s > right || e < left)return -1;
	if (left <= s && e <= right)return tree[node];
	int mi = (s + e) / 2;
	return FindMin(Query(s, mi, node * 2, left, right), Query(mi+1, e, node * 2 + 1, left, right));
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	cin >> m;
	MakeTree(1, n, 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a>>b>>c;
		if (a == 1) {
			arr[b] = c;
			Update(1, n, 1, b);
		}
		else {
			cout << Query(1, n, 1, b, c)<<'\n';
		}


	}
}