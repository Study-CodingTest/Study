#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>
using namespace std;
typedef pair<int, int> idx_val;

pair<int, int> min_val(pair<int, int> a, pair<int, int> b){
  if(a.second == b.second)
    return (a.first < b.first)? a : b;
  return (a.second < b.second)? a : b;
}

int init_tree(int curr_len, int curr_height, vector<vector<idx_val>> &min_tree){
  if(curr_len == 1)
    return curr_height;

  for(int idx = 0; idx < curr_len; idx += 2)
    min_tree[curr_height+1].push_back(min_val(min_tree[curr_height][idx], min_tree[curr_height][idx+1]));
  return init_tree(curr_len/2, curr_height+1, min_tree);
}

void update_tree(int idx, int curr_height, int height, vector<vector<idx_val>> &min_tree){
  if(curr_height == height)
    return;

  min_tree[curr_height+1][idx/2] = min_val(min_tree[curr_height][(idx/2)*2], min_tree[curr_height][(idx/2)*2+1]);
  update_tree(idx/2, curr_height+1, height, min_tree);
}

pair<int, int> sum_tree(int idx, int target_start, int target_end, int curr_start, int curr_end, int curr_height, vector<vector<idx_val>> &min_tree){
  if(curr_start >= target_start && curr_end <= target_end)
    return min_tree[curr_height][idx];

  if(curr_start > target_end || curr_end < target_start)
    return {INT_MAX, INT_MAX};

  int mid = (curr_start + curr_end) / 2;
  return min_val(sum_tree(idx*2, target_start, target_end, curr_start, mid, curr_height-1, min_tree), sum_tree(idx*2+1, target_start, target_end, mid+1, curr_end, curr_height-1, min_tree));
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M, val, i, j;
  cin >> N;

  vector<vector<idx_val>> min_tree(N, vector<idx_val>(0));
  for(int ndx = 0; ndx < N; ndx++){
    cin >> val;
    min_tree[0].push_back({ndx, val});
  }
  int lowest_len = (int)pow(2, ceil(log2(N)));

  while(min_tree[0].size() != lowest_len)
    min_tree[0].push_back({INT_MAX, INT_MAX});

  int height = init_tree(min_tree[0].size(), 0, min_tree);


  cin >> M;
  for(int mdx = 0; mdx < M; mdx++){
    cin >> val >> i >> j;
    if(val == 1){
      min_tree[0][i-1].second = j;
      update_tree(i-1, 0, height, min_tree);
    }
    else{
      idx_val tmp = sum_tree(0, i-1, j-1, 0, lowest_len-1, height, min_tree);
      cout << tmp.first + 1 << '\n';
    }
  }
}
