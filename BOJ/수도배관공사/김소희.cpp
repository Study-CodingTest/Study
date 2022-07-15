//
// Created by Kim So Hee on 2022/07/13.
//

#include <bits/stdc++.h>

using namespace std;

int d, p;
int dp[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> d >> p;
    dp[0] = 1e9;
    for (int i = 0; i < p; ++i) {
        int l, c;
        cin >> l >> c;
        for (int j = d; j >= l; j--) {
            dp[j] = max(dp[j], min(dp[j - l], c));
        }
    }
    cout << dp[d];
}