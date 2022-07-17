#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int D, P;
    cin >> D >> P;
    vector<int> dp(D + 1);
    dp[0] = INF;

    int l, c;
    for (int i = 0; i < P; i++) {
        cin >> l >> c;
        for (int j = D; j >= l; j--) {
            dp[j] = max(dp[j], min(dp[j - l], c));
        }
    }

    cout << dp[D];

    return 0;
}
