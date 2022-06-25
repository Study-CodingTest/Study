#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int N, M, q, r;
vector<pair<int, int>> P;
list<pair<int, int>> ans;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

void print(const list<pair<int, int>>& l) {
	for (auto iter = l.begin(); iter != l.end(); ++iter) {
		cout << (*iter).second;
	}
}

void delete_zero(list<pair<int, int>>::iterator& iter) {
	while (ans.size() > 1 && ans.front().second == 0) {
		r += (*iter).first;
		if (P[1].first <= r) {
			*iter = P[1];
			r -= P[1].first;
			break;
		}

		iter = ans.erase(iter);
	}
}

void update(list<pair<int, int>>::iterator& iter) {
	while (iter != ans.end()) {
		pair<int, int> target = *iter;
		for (int i = 0; i < N; i++) {
			if ((*iter).first + r >= P[i].first && target.second < P[i].second) {
				target = P[i];
			}
		}

		if (target.second != (*iter).second) {
			r -= target.first - (*iter).first;
			*iter = target;
		}
		++iter;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	P.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> P[i].first;
		P[i].second = i;
	}
	sort(P.begin(), P.end(), compare);
	cin >> M;

	q = M / P[0].first;
	r = M % P[0].first;

	for (int i = 0; i < q; i++) {
		ans.push_back(P[0]);
	}

	if (N == 1 && ans.front().second == 0) {
		cout << 0;
	}
	else {
		auto iter = ans.begin();
		if ((r == 0 && ans.front().second == 0) || r != 0) {
			delete_zero(iter);
			update(iter);
		}
		print(ans);
	}

	return 0;
}