#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct tree{
  map<string, struct tree*> child;
};

void input(struct tree *root, vector<string> &feed, int floor, int &K){
  if(floor == K)
    return;

  auto iter = root->child.find(feed[floor]);
  if(iter == root->child.end()){
    struct tree *add = new struct tree;
    root->child.insert({feed[floor], add});
    input(add, feed, floor + 1, K);
  }
  else
    input(iter->second, feed, floor + 1, K);
}

void output(struct tree *root, int floor){
  for(auto iter = root->child.begin(); iter != root->child.end(); iter++){
    for(int fdx = 0; fdx < floor; fdx++)
      cout << "--";
    cout << iter->first << endl;
    output(iter->second, floor + 1);
  }
}

int main(){
  int N, K;
  cin >> N;
  struct tree *root = new struct tree;
  vector<string> feed(15);

  for(int ndx = 0; ndx < N; ndx++){
    cin >> K;
    for(int kdx = 0; kdx < K; kdx++)
      cin >> feed[kdx];
    input(root, feed, 0, K);
  }

  output(root, 0);
}
