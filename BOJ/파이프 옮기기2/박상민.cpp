#include <iostream>
#include <memory.h>
using namespace std;
typedef long long ll;

bool map[33][33];
ll dp[33][33][3];


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(dp, 0, sizeof(dp));

  int n;
  cin >> n;

  for(int idx = 0; idx < n; idx++)
    for(int jdx = 0; jdx < n; jdx++)
      cin >> map[idx][jdx];

  dp[0][1][0] = 1;
  for(int idx = 0; idx < n; idx++){
    for(int jdx = 0; jdx < n; jdx++){
      if(map[idx][jdx + 1] == 0)
        dp[idx][jdx+1][0] += dp[idx][jdx][0] + dp[idx][jdx][2];
      if(map[idx + 1][jdx] == 0)
        dp[idx+1][jdx][1] += dp[idx][jdx][1] + dp[idx][jdx][2];
      if((map[idx + 1][jdx + 1] || map[idx + 1][jdx] || map[idx][jdx + 1]) == 0)
        dp[idx+1][jdx+1][2] += dp[idx][jdx][0] + dp[idx][jdx][1] + dp[idx][jdx][2];
    }
  }

  ll dp_sum = dp[n-1][n-1][0] + dp[n-1][n-1][1] + dp[n-1][n-1][2];
  cout << dp_sum;
}
