#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

/* recursivly, make tree structure from undirected graph */
void make_tree(int cur, bool *visit, vector<int> *edge, vector<int> *tree){
  visit[cur] = true;
  for(int edx = 0; edx < edge[cur].size(); edx++){
    if(!visit[edge[cur][edx]]){
      tree[cur].push_back(edge[cur][edx]);
      make_tree(edge[cur][edx], visit, edge, tree);
    }
  }
}

/* recursivly, search for # of early adopters with memoization */
int dfsearch(bool is_early, int cur, vector<int> *tree, vector<int> *dp){
  if(dp[is_early][cur] != -1)
    return dp[is_early][cur];

  dp[is_early][cur] = 0;
  /* if current node -> early adopter */
  if(is_early){
    dp[is_early][cur] += 1;
    for(int cdx = 0; cdx < tree[cur].size(); cdx++){
      int child = tree[cur][cdx];
      dp[is_early][cur] += min(dfsearch(1, child, tree, dp), dfsearch(0, child, tree, dp));
    }
  }
  /* if current node -> not an early adopter */
  else{
    for(int cdx = 0; cdx < tree[cur].size(); cdx++)
      dp[is_early][cur] += dfsearch(1, tree[cur][cdx], tree, dp);
  }
  return dp[is_early][cur];
}

int main(){
  int N, src, dst;
  cin >> N;
  vector<int> edge[N+1];
  vector<int> tree[N+1];
  vector<int> dp[2];
  dp[0] = vector<int>(N+1, -1);
  dp[1] = vector<int>(N+1, -1);
  bool visit[N+1] = {0, };

  for(int ndx = 0; ndx < N-1; ndx++){
    cin >> src >> dst;
    edge[src].push_back(dst);
    edge[dst].push_back(src);
  }

  make_tree(src, visit, edge, tree);

  int case1 = dfsearch(0, src, tree, dp);
  int case2 = dfsearch(1, src, tree, dp);

  cout << min(case1, case2) << endl;
}
