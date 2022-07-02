#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> path_front[N+1];
  vector<pair<int, int>> path_back[N+1];
  int ind[N+1];
  int dist[N+1];
  bool visit[N+1];
  memset(ind, 0, sizeof(ind));
  memset(dist, 0, sizeof(dist));
  memset(visit, 0, sizeof(visit));

  for(int mdx = 0; mdx < M; mdx++){
    int src, dst, time;
    cin >> src >> dst >> time;

    path_front[src].push_back({dst, time});
    path_back[dst].push_back({src, time});
    ind[dst] += 1;
  }

  int src, dst;
  cin >> src >> dst;
  queue<int> search;
  search.push(src);

  while(!search.empty()){
    int curr = search.front();
    search.pop();

    for(int idx = 0; idx < path_front[curr].size(); idx++){
      int node = path_front[curr][idx].first;
      int time = path_front[curr][idx].second;

      ind[node] -= 1;
      if(ind[node] == 0)
        search.push(node);
      dist[node] = max(dist[node], dist[curr] + time);
    }
  }

  search.push(dst);
  int count = 0;
  while(!search.empty()){
    int curr = search.front();
    search.pop();

    for(int idx = 0; idx < path_back[curr].size(); idx++){
      int node = path_back[curr][idx].first;
      int time = path_back[curr][idx].second;

      if(time == dist[curr] - dist[node]){
        count += 1;
        if(!visit[node]){
          visit[node] = true;
          search.push(node);
        }
      }
    }
  }

  cout << dist[dst] << '\n' << count << endl;
}
