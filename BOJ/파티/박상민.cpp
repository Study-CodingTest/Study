#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int main(){
  int N, M, X, src, dst, dist, max_time;
  cin >> N >> M >> X;

  vector<pair<int, int>> edge[N+1];

  for(int mdx = 0; mdx < M; mdx++){
    cin >> src >> dst >> dist;
    edge[src].push_back({dist, dst});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijkstra;
  int distance[N+1];

  /* going to X node */
  for(int ndx = 1; ndx <= N; ndx++){
    memset(distance, 0x3f, sizeof(distance));
    distance[ndx] = 0;
    dijkstra.push({0, ndx});

    while(!dijkstra.empty()){
      pair<int, int> curr = dijkstra.top();
      dijkstra.pop();

      if(curr.second == X)
        break;

      if(curr.first > distance[curr.second])
        continue;

      for(int edx = 0; edx < edge[curr.second].size(); edx++){
        pair<int, int> next = {curr.first + edge[curr.second][edx].first, edge[curr.second][edx].second};
        if(next.first < distance[next.second]){
          distance[next.second] = next.first;
          dijkstra.push(next);
        }
      }
    }

    while(!dijkstra.empty())
      dijkstra.pop();
    int front = distance[X];

    /* returning home node */
    memset(distance, 0x3f, sizeof(distance));
    distance[X] = 0;
    dijkstra.push({0, X});

    while(!dijkstra.empty()){
      pair<int, int> curr = dijkstra.top();
      dijkstra.pop();

      if(curr.second == ndx)
        break;

      if(curr.first > distance[curr.second])
        continue;

      for(int edx = 0; edx < edge[curr.second].size(); edx++){
        pair<int, int> next = {curr.first + edge[curr.second][edx].first, edge[curr.second][edx].second};
        if(next.first < distance[next.second]){
          distance[next.second] = next.first;
          dijkstra.push(next);
        }
      }
    }

    while(!dijkstra.empty())
      dijkstra.pop();
    int back = distance[ndx];

    max_time = max(front + back, max_time);
  }
  cout << max_time;
}
