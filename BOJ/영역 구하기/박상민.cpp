#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;
bool space[100][100];
pair<int, int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

/* breadth-first-search from given {rdx, cdx} coordinate */
int bfs_search(int &rdx, int &cdx, int &row, int &col, queue<pair<int, int>> &search){
  search.push({rdx, cdx});
  space[rdx][cdx] = true;
  int space_area = 0;

  while(!search.empty()){
    pair<int, int> curr = search.front();
    search.pop();
    space_area += 1;

    for(int ddx = 0; ddx < 4; ddx++){
      pair<int, int> next = {curr.first + dir[ddx].first, curr.second + dir[ddx].second};

      if(min(next.first, next.second) < 0 || next.first >= row || next.second >= col)
        continue;
      if(space[next.first][next.second])
        continue;

      search.push(next);
      space[next.first][next.second] = true;
    }
  }
  return space_area;
}

int main(){
  memset(space, 0, sizeof(space));
  int M, N, K;
  cin >> M >> N >> K;

  for(int kdx = 0; kdx < K; kdx++){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for(int x = x1; x < x2; x++)
      for(int y = y1; y < y2; y++)
        space[y][x] = true;
  }

  vector<int> empty_space;
  queue<pair<int, int>> search;

  for(int rdx = 0; rdx < M; rdx++){
    for(int cdx = 0; cdx < N; cdx++){
      if(space[rdx][cdx])
        continue;
      empty_space.push_back(bfs_search(rdx, cdx, M, N, search));
    }
  }

  sort(empty_space.begin(), empty_space.end());
  int vector_size = empty_space.size();
  cout << vector_size << '\n';
  for(int vdx = 0; vdx < vector_size; vdx++)
    cout << empty_space[vdx] << ' ';
}
