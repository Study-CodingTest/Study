#include <iostream>
using namespace std;

/* {q,u,a,c,k} => {0, 1, 2, 3, 4} */
int index_match(char &letter){
  switch(letter){
    case 'q' :
      return 0;
    case 'u' :
      return 1;
    case 'a' :
      return 2;
    case 'c' :
      return 3;
    case 'k' :
      return 4;
  }
  return -1;
}

int main(){
  string input;
  cin >> input;
  /* tracking min # of ducks */
  int count[5] = {0, };

  for(int idx = 0; idx < input.length(); idx++){
    int cdx = index_match(input[idx]);
    /* if undefined letter, or incorrect order */
    if(cdx == -1 || (input[idx] != 'q' && count[cdx-1] == 0)){
      cout << -1 << endl;
      return 0;
    }
    /* for minimum # of ducks */
    if(count[4] != 0 && input[idx] == 'q')
      count[4]--;
    /* tracking status of duck cry */
    count[cdx-1] -= 1;
    count[cdx] += 1;
  }
  /* if unfinished crying exists */
  for(int cdx = 0; cdx < 4; cdx++){
    if(count[cdx] != 0){
      cout << -1 << endl;
      return 0;
    }
  }
  /* if normal input */
  cout << count[4] << endl;
}
