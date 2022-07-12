#include <iostream>
#include <vector>
using namespace std;

/* dfs search, finding leafnode */
void make_tree(int cur, bool *visit, vector<int> *edge, double &count){
  visit[cur] = true;
  bool is_leafnode = true;
  for(int edx = 0; edx < edge[cur].size(); edx++){
    if(!visit[edge[cur][edx]]){
      is_leafnode = false;
      make_tree(edge[cur][edx], visit, edge, count);
    }
  }
  if(is_leafnode)
      count++;
}

int main(){
  int N, src, dst;
  double W;
  cin >> N >> W;
  cout.precision(10);

  vector<int> edge[N+1];
  for(int edx = 1; edx < N; edx++){
    cin >> src >> dst;
    edge[src].push_back(dst);
    edge[dst].push_back(src);
  }

  bool visit[N+1] = {0, };
  double count = 0;
  make_tree(1, visit, edge, count);

  cout << W / count << endl;
}
