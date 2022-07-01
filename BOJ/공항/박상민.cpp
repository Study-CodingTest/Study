#include <iostream>
using namespace std;

int dockfind(int node, int *parent){
  if(parent[node] == node)
    return node;
  return parent[node] = dockfind(parent[node], parent);
}

void dockunion(int node1, int node2, int *parent){
  node1 = dockfind(node1, parent);
  node2 = dockfind(node2, parent);
  parent[node1] = node2;
}


int main(){
  int G, P, g_i, count = 0;
  cin >> G >> P;
  int parent[G+1] = {0, };

  for(int gdx = 1; gdx <= G; gdx++)
    parent[gdx] = gdx;


  for(int pdx = 0; pdx < P; pdx++){
    cin >> g_i;

    if(dockfind(g_i, parent) == 0)
      break;

    count++;
    dockunion(dockfind(g_i, parent), dockfind(g_i, parent) - 1, parent);
  }

  cout << count << endl;
}
