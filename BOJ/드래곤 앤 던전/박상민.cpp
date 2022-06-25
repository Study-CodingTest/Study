#include <iostream>
using namespace std;
typedef long long ll;

int main(){
  ll N, ATK;
  ll HP_cur = 0, HP_max = 0;
  cin >> N >> ATK;

  for(int ndx = 0; ndx < N; ndx++){
    ll flag, attack, hp;
    cin >> flag >> attack >> hp;

    if(flag == 1){
      ll temp = (ll)((hp - 1) / ATK) * attack;
      if(temp > HP_cur){
        HP_max += (temp - HP_cur);
        HP_cur = 0;
      }
      else
        HP_cur -= temp;
    }
    else{
      ATK += attack;
      HP_cur = (HP_cur + hp > HP_max)? HP_max : HP_cur + hp;
    }
  }
  cout << HP_max+1 << endl;
}
