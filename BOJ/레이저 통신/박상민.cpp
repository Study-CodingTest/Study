#include <iostream>
#include <queue>
#include <memory.h>
#include <cmath>
using namespace std;

typedef pair<int, int> cod;

char map[100][100];
int mir[100][100];

struct el{
  int dir;
  int r;
  int c;
  int mirror;
};

struct compare{
  bool operator()(struct el a, struct el b){
    return a.mirror > b.mirror;
  }
};

int main(){
  cod move[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
  int col, row;
  queue<cod> laserlist;
  priority_queue<struct el, vector<struct el>, compare> search;

  memset(mir, 0x3f, sizeof(mir));

  cin >> col >> row;

  for(int rdx = 0; rdx < row; rdx++){
    cin >> map[rdx];
    for(int cdx = 0; cdx < col; cdx++){
      if(map[rdx][cdx] == 'C')
        laserlist.push({rdx, cdx});
    }
  }

  cod src = laserlist.front();
  laserlist.pop();
  mir[src.first][src.second] = 0;
  cod dst = laserlist.front();

  for(int ddx = 0; ddx < 4; ddx++){
    cod next = {src.first + move[ddx].first, src.second + move[ddx].second};

    if(next.first < 0 || next.second < 0 || next.first >= row || next.second >= col)
      continue;

    if(map[next.first][next.second] == '*')
      continue;

    struct el added = {ddx, next.first, next.second, 0};
    search.push(added);
    mir[next.first][next.second] = 0;
  }

  while(!search.empty()){
    struct el curr = search.top();
    search.pop();

    if(curr.r == dst.first && curr.c == dst.second)
      break;

    if(mir[curr.r][curr.c] < curr.mirror)
      continue;

    for(int ddx = 0; ddx < 4; ddx++){
      if(ddx == (curr.dir + 2) % 4)
        continue;
      cod next = {curr.r + move[ddx].first, curr.c + move[ddx].second};
      int next_mir;

      if(next.first < 0 || next.second < 0 || next.first >= row || next.second >= col)
        continue;

      if(map[next.first][next.second] == '*')
        continue;

      next_mir = (ddx == curr.dir)? curr.mirror : curr.mirror + 1;

      if(next_mir <= mir[next.first][next.second]){
        struct el added = {ddx, next.first, next.second, next_mir};
        search.push(added);
        mir[next.first][next.second] = next_mir;
      }
    }
  }

  cout << mir[dst.first][dst.second];
}
