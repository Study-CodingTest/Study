#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;
typedef pair<int, int> xy;
struct el{xy cod; int type;};

char map[100][100];
int door[100][100][3];
xy dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

struct compare_door{
  bool operator()(struct el &a, struct el &b){
    return door[a.cod.first][a.cod.second][a.type] > door[b.cod.first][b.cod.second][b.type];
  }
};

vector<xy> prisoner;
priority_queue<struct el, vector<struct el>, compare_door> search;

bool xy_check(xy &position, int &row, int &col, int &type){
  if(position.first < 0 || position.first >= row || position.second < 0 || position.second >= col)
    return true;

  if(door[position.first][position.second][type] != -1)
    return true;

  if(map[position.first][position.second] == '*')
    return true;

  return false;
}

void dijkstra_search(int &row, int &col){
  while(!search.empty()){
    xy curr = search.top().cod;
    int type = search.top().type;
    search.pop();

    for(int ddx = 0; ddx < 4; ddx++){
      xy next = {curr.first + dir[ddx].first, curr.second + dir[ddx].second};

      if(xy_check(next, row, col, type))
        continue;

      if(map[next.first][next.second] == '.' || map[next.first][next.second] == '$'){
        door[next.first][next.second][type] = door[curr.first][curr.second][type];
        search.push({next, type});
      }

      else if(map[next.first][next.second] == '#'){
        door[next.first][next.second][type] = door[curr.first][curr.second][type] + 1;
        search.push({next, type});
      }
    }
  }
}


int main(){
  int num_t, h, w;
  cin >> num_t;

  for(int tdx = 0; tdx < num_t; tdx++){
    memset(door, -1, sizeof(door));
    cin >> h >> w;

    for(int rdx = 0; rdx < h; rdx++){
      cin >> map[rdx];
      for(int cdx = 0; cdx < w; cdx++){
        if(map[rdx][cdx] == '$')
          prisoner.push_back({rdx, cdx});

        else if(rdx == 0 || cdx == 0 || rdx == h-1 || cdx == w-1){
          if(map[rdx][cdx] == '.'){
            door[rdx][cdx][2] = 0;
            search.push({{rdx, cdx}, 2});
          }
          else if(map[rdx][cdx] == '#'){
            door[rdx][cdx][2] = 1;
            search.push({{rdx, cdx}, 2});
          }
        }
      }
    }

    dijkstra_search(h, w);

    door[prisoner[0].first][prisoner[0].second][0] = 0;
    search.push({prisoner[0], 0});
    dijkstra_search(h, w);

    door[prisoner[1].first][prisoner[1].second][1] = 0;
    search.push({prisoner[1], 1});
    dijkstra_search(h, w);

    /* if two prisoner meets */
    int door_min = h * w;
    for(int rdx = 0; rdx < h; rdx++){
      for(int cdx = 0; cdx < w; cdx++){
        if(door[rdx][cdx][0] == -1 || door[rdx][cdx][1] == -1 || door[rdx][cdx][2] == -1)
          continue;

        door[rdx][cdx][2] += (door[rdx][cdx][0] + door[rdx][cdx][1]);

        if(map[rdx][cdx] == '#')
          door[rdx][cdx][2] -= 2;

        door_min = min(door_min, door[rdx][cdx][2]);
      }
    }

    /* if two prisoners do not meet */
    int min_prisoner1 = h * w;
    int min_prisoner2 = h * w;

    for(int rdx = 0; rdx < h; rdx++){
      for(int cdx = 0; cdx < w; cdx++){
        if(rdx == 0 || cdx == 0 || rdx == h-1 || cdx == w-1){
          if(door[rdx][cdx][0] != -1)
            min_prisoner1 = min(min_prisoner1, door[rdx][cdx][0]);
          if(door[rdx][cdx][1] != -1)
            min_prisoner2 = min(min_prisoner2, door[rdx][cdx][1]);
        }
      }
    }

    cout << min(door_min, min_prisoner1 + min_prisoner2) << endl;
    prisoner.clear();
  }
}
