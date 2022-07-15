#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp[100002][2]; //길이, 개수
int d, p;
pair<int, int> arr[351]; //first->길이 , second-> 용량
int main() {
	cin >> d >> p;
	for (int i = 1; i <= p; i++) {
		int x, y;
		cin >> x >> y;
		arr[i] = { x,y };
	}
	for (int i = 1; i <= p; i++) {
		int l = arr[i].first;
		for (int j = 1; j <= d; j++) {
			if (j - l < 0)continue;
			if (l == j) {
				dp[j][1] = max(dp[j][1], arr[i].second);
			}
			if (dp[j - l][0] != 0) {
				int k = min(dp[j - l][0], arr[i].second);
				dp[j][1] = max(k, dp[j][1]);
			}
		}
		for (int j = 1; j <= d; j++) {
			dp[j][0] = dp[j][1];
		}
	}
	cout << dp[d][1];


}