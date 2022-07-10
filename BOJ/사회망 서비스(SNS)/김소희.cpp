//
// Created by Kim So Hee on 2022/07/06.
//

#include <bits/stdc++.h>

using namespace std;

int N; // 최대 1,000,000

vector<int> sns[1000001];
int answer[1000001][2];

/**
 * 1. 부모 노드가 얼리어답터
 * --> 자식 노드는 얼리어답터이거나, 아니거나
 *
 * 2. 부모 노드가 얼리어답터 X
 * --> 자식 노드는 모두 얼리어답터
 */

int dp(int person, bool adaptor, int parent) {

    if (answer[person][adaptor])
        return answer[person][adaptor];

    int ret = 0;

    for (const int &child: sns[person]) {
        if (child != parent) {
            if (adaptor) {
                ret += min(dp(child, true, person), dp(child, false, person));
            } else {
                ret += dp(child, true, person);
            }
        }
    }
    return answer[person][adaptor] = ret + adaptor;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    sns[0].push_back(1);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        sns[u].push_back(v);
        sns[v].push_back(u);
    }
    cout << dp(0, true, 0) - 1;
}
