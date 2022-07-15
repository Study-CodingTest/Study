#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

struct el{
  int row, col, stage;
};

int N, M, P;
char board[1000][1000];
queue<struct el> bfs[10];
int s[10];
int res[10];
pair<int, int> dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

bool range_check(struct el curr){
  int row = curr.row;
  int col = curr.col;
  if(row >= N || row < 0 || col >= M || col < 0)
    return false;
  if(board[row][col] != '.')
    return false;
  return true;
}


int main(){
  cin >> N >> M >> P;
  for(int pdx = 1; pdx <= P; pdx++)
    cin >> s[pdx];
  for(int ndx = 0; ndx < N; ndx++){
    for(int mdx = 0; mdx < M; mdx++){
      cin >> board[ndx][mdx];
      char tmp = board[ndx][mdx];
      if(tmp >= '1' && tmp <= '9')
        bfs[tmp-'1'+1].push({ndx, mdx, 0});
    }
  }
  while(true){
    bool flag = false;
    for(int pdx = 1; pdx <= P; pdx++){
      int curr_stage = bfs[pdx].front().stage;
      while(!bfs[pdx].empty() && bfs[pdx].front().stage < curr_stage + s[pdx]){
        struct el curr = bfs[pdx].front();
        bfs[pdx].pop();
        for(int ddx = 0; ddx < 4; ddx++){
          struct el next = {curr.row + dir[ddx].first, curr.col + dir[ddx].second, curr.stage + 1};
          if(!range_check(next))
            continue;
          board[next.row][next.col] = '0' + pdx;
          bfs[pdx].push(next);
          flag = true;
        }
      }
    }
    if(!flag)
      break;
  }

  memset(res, 0, sizeof(res));
  for(int ndx = 0; ndx < N; ndx++){
    for(int mdx = 0; mdx < M; mdx++){
      char tmp = board[ndx][mdx];
      if(tmp >= '1' && tmp <= '9')
        res[tmp-'1'+1]++;
    }
  }

  for(int pdx = 1; pdx <= P; pdx++)
    cout << res[pdx] << ' ';
}
