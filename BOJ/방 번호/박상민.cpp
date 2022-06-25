#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
  int N, M, min_idx = 0, temp = 0;
  int info[11];
  memset(info, 0x7f, sizeof(info));

  cin >> N;
  for(int idx = 0; idx < N; idx++){
    cin >> info[idx];

    if(idx == 0)
      continue;
    /* find the index with minimum price in range [1, N-1] */
    min_idx = (info[idx] <= info[10])? idx : min_idx;
    info[10] = info[min_idx];
  }
  cin >> M;

  /* if found index not affordable, print 0 */
  if(M < info[min_idx]){
    cout << 0 << endl;
    return 0;
  }

  vector<int> result;
  /* X0...0 form */
  if(info[min_idx] > info[0]){
    result.push_back(min_idx);
    M -= info[min_idx];
    for(int cdx = 0; cdx < (M / info[0]); cdx++)
      result.push_back(0);
    M -= info[0] * (M / info[0]);
  }
  /* X...X form */
  else{
    result.assign((M / info[min_idx]), min_idx);
    M -= info[min_idx] * (M / info[min_idx]);
  }

  /* alter the choice if budget is affordable for bigger numbers */
  int iter = 0;
  while(iter != result.size()){
    for(int idx = 9; idx > result[iter]; idx--){
      if(info[idx] <= M + info[result[iter]]){
        M -= (info[idx] - info[result[iter]]);
        result[iter] = idx;
        break;
      }
    }
    iter++;
  }

  /* print result */
  for(int vdx = 0; vdx < result.size(); vdx++)
    cout << result[vdx];

}
