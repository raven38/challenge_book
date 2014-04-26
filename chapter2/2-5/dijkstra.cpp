#include <cstdio>
#include <algorithm>
#define MAX_V 50
#define INF 1<<30
using namespace std;

int cost[MAX_V][MAX_V]; // cost[u][v] is cost of edge e=(u,v). (not exist INF)
int d[MAX_V];           // shortest distance from vertex s
bool used[MAX_V];       // used flag
int V;                  // vertex number

// evaluate shotest distance from vertex s to every vertex
void dijkstra(int s){
  fill(d, d + V, INF);
  fill(used, used + V, false);
  d[s] = 0;

  while(true){
    int v = -1;
    // find shotest distance in not used vertex
    for(int u = 0; u < V; u++){
      if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
    }

    if(v == -1) break;

    used[v] = true;

    for(int u = 0; u < V; u++)
      d[u] = min(d[u], d[v] + cost[v][u]);
  }
}

int main(){
  scanf("%d", &V);
  for(int i = 0; i < V; ++i) for(int j = 0; j < V; ++j) cost[i][j] = INF;
  int edge, from, to, c;
  scanf("%d", &edge); // how many edge
  while(edge--){
    scanf("%d %d %d", &from, &to, &c);
    cost[from][to] = c;
  }
  int s, g;
  scanf("%d %d", &s, &g);
  dijkstra(s);
  printf("%d\n", d[g]);
  return 0;
}
