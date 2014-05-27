#include <cstdio>
#include <algorithm>

#define MAX_V 50
#define INF 1 << 30
using namespace std;
int cost[MAX_V][MAX_V]; // cout[u][v] is cost of edge e = (u, v). if not exist INF
int mincost[MAX_V]; // min cost from set X to edge
bool used[MAX_V]; // is X include vertex i?
int V; // vertex

int prim(){
  for(int i = 0; i < V; ++i){
    mincost[i] = INF;
    used[i] = false;
  }
  mincost[0] = 0;
  int res = 0;

  while(true){
    int v = -1;
    // Xに属さない頂点のうちXからの辺のコストが最小になる頂点を探す
    for(int u = 0; u < V; u++)
      if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;

    if(v == -1) break;
    used[v] = true; // add vertex v to X
    res += mincost[v]; // add edge cost

    for(int u = 0; u < V; u++)
      mincost[u] = min(mincost[u], cost[v][u]);
  }
  return res;
}

int main(){
  for(int i = 0; i < MAX_V; i++) for(int j = 0; j < MAX_V; j++) cost[i][j] = INF;
  int E, from, to, c;
  scanf("%d%d", &V, &E);
  while(E--){
    scanf("%d%d%d", &from, &to, &c);
    cost[from][to] = c;
    cost[to][from] = c;
  }
  printf("%d\n", prim());
  return 0;
}
