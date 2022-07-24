#include <iostream>
#include <string.h>
#include <queue>
#include <memory.h>
using namespace std;

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int R, C;
  cin >> R >> C;

  string lake[R];               /* lake status info */
  pair<int, int> swan;          /* src swan */
  queue<pair<int, int>> water;  /* water coordinate list for expansion */
  for(int rdx = 0; rdx < R; rdx++){
    cin >> lake[rdx];
    for(int cdx = 0; cdx < C; cdx++){
      if(lake[rdx][cdx] == 'L'){
        swan = {rdx, cdx};
        water.push({rdx, cdx});
      }
      if(lake[rdx][cdx] == '.')
        water.push({rdx, cdx});
    }
  }

  bool visit[1500][1500];           /* visit array for bfs search from src swan to dst swan */
  queue<pair<int, int>> route[2];   /* route[toggle]: queue for current bfs search, route[!toggle] : queue for next bfs search */
  int toggle = 0;
  route[toggle].push(swan);
  visit[swan.first][swan.second] = true;
  memset(visit, 0, sizeof(visit));
  pair<int, int> dir[4] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
  int day_count = 0;
  while(++day_count){
    while(!route[toggle].empty()){
      pair<int, int> curr = route[toggle].front();
      route[toggle].pop();
      if(curr != swan && lake[curr.first][curr.second] == 'L'){
        cout << day_count - 1 << endl;
        return 0;
      }
      for(int ddx = 0; ddx < 4; ddx++){
        pair<int, int> next = {curr.first + dir[ddx].first, curr.second + dir[ddx].second};
        if(next.first < 0 || next.second < 0 || next.first >= R || next.second >= C)
          continue;
        if(visit[next.first][next.second])
          continue;
        if(lake[next.first][next.second] == 'X'){
          route[!toggle].push(next);
          visit[next.first][next.second] = true;
        }
        else{
          route[toggle].push(next);
          visit[next.first][next.second] = true;
        }
      }
    }
    toggle = !toggle;

    /* next day, ice breaking process */
    int ice_count = water.size();
    for(int idx = 0; idx < ice_count; idx++){
      pair<int, int> curr = water.front();
      water.pop();

      for(int ddx = 0; ddx < 4; ddx++){
        pair<int, int> next = {curr.first + dir[ddx].first, curr.second + dir[ddx].second};
        if(next.first < 0 || next.second < 0 || next.first >= R || next.second >= C)
          continue;
        if(lake[next.first][next.second] != 'X')
          continue;

        lake[next.first][next.second] = '.';
        water.push(next);
      }
    }
  }
}
