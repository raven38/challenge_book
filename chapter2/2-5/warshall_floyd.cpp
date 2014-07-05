#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_V 100
#define INF 1 << 29

using namespace std;

vector<vector<int> > d(MAX_V, vector<int>(MAX_V, INF)); // d[u][v] is cost of edge e=(u,v)
int V; // vertex

void warshall_floyd(){
  for(int k = 0; k < V; k++)
    for(int i = 0; i < V; i++)
      for(int j = 0; j < V; j++)
	d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main(){
  int edge;
  scanf("%d%d", &V, &edge);
  while(edge--){
    int from, to, cost;
    scanf("%d%d%d", &from, &to, &cost);
    d[from][to] = cost;
  }
  int s, g;
  scanf("%d%d", &s, &g);
  for(int i = 0; i < V; i++) d[i][i] = 0;
  warshall_floyd();
  printf("%d\n", d[s][g]);
  return 0;
}
