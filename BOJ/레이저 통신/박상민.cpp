#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> rc;

/* character 2D array for space status */
char map[100][100];
/* integer 2D array for minimum # of mirror to reach position */
int mir[100][100];
/* unit for search */
struct el{int dir; int r; int c; int mirror;};
/* compare function for priority_queue */
struct compare{
  bool operator()(struct el &a, struct el &b){
    return a.mirror > b.mirror;
  }
};
/* coordinate validity check function for bfs search */
bool range_check(int &row, int &col, rc &curr){
  return (curr.first < 0 || curr.second < 0 || curr.first >= row || curr.second >= col);
}

int main(){
  rc move[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
  int row, col, count = 0;
  rc src, dst;
  priority_queue<struct el, vector<struct el>, compare> search;
  memset(mir, 0x3f, sizeof(mir));

  cin >> col >> row;
  for(int rdx = 0; rdx < row; rdx++){
    cin >> map[rdx];
    for(int cdx = 0; cdx < col; cdx++){
      if(map[rdx][cdx] == 'C'){
        if(count++ == 0)
          src = {rdx, cdx};
        else
          dst = {rdx, cdx};
      }
    }
  }

  /* push initial elements to search queue */
  mir[src.first][src.second] = 0;
  for(int ddx = 0; ddx < 4; ddx++){
    rc next = {src.first + move[ddx].first, src.second + move[ddx].second};

    if(range_check(row, col, next))
      continue;
    if(map[next.first][next.second] == '*')
      continue;

    struct el to_add = {ddx, next.first, next.second, 0};
    search.push(to_add);
    mir[next.first][next.second] = 0;
  }

  while(!search.empty()){
    struct el curr = search.top();
    search.pop();
    /* found the other laser! hurray */
    if(curr.r == dst.first && curr.c == dst.second)
      break;
    /* if not recently updated one */
    if(mir[curr.r][curr.c] < curr.mirror)
      continue;

    for(int ddx = 0; ddx < 4; ddx++){
      /* unreachable if opposite direction */
      if(ddx == (curr.dir + 2) % 4)
        continue;
      rc next = {curr.r + move[ddx].first, curr.c + move[ddx].second};

      if(range_check(row, col, next))
        continue;
      if(map[next.first][next.second] == '*')
        continue;

      int next_mir = (ddx == curr.dir)? curr.mirror : curr.mirror + 1;

      if(next_mir <= mir[next.first][next.second]){
        struct el to_add = {ddx, next.first, next.second, next_mir};
        search.push(to_add);
        mir[next.first][next.second] = next_mir;
      }
    }
  }
  cout << mir[dst.first][dst.second];
}
