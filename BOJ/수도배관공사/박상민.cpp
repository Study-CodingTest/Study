#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
  int D, P, l_i, c_i;
  cin >> D >> P;
  int capa[2][D+1];
  memset(capa, 0, sizeof(capa));

  cin >> l_i >> c_i;
  capa[0][l_i] = c_i;
  /* toggle switch for tracking prev, current dp value */
  bool toggle = 0;

  /* dynamic programming - akin to traditional knapsack problem */
  for(int pdx = 1; pdx < P; pdx++){
    toggle = !toggle;
    cin >> l_i >> c_i;
    capa[toggle][l_i] = max(c_i, capa[!toggle][l_i]);
    for(int ldx = 1; ldx < D+1; ldx++){
      if(capa[!toggle][ldx] != 0){
        capa[toggle][ldx] = max(capa[toggle][ldx], capa[!toggle][ldx]);
        int length_sum_i = l_i + ldx;
        if(length_sum_i < D+1)
          capa[toggle][length_sum_i] = max(capa[toggle][length_sum_i], min(c_i, capa[!toggle][ldx]));
      }
    }
  }

  /* at least one subset of pipes with length sum D, guaranteed */
  cout << capa[toggle][D];
}
