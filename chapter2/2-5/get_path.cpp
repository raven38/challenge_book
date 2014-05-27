#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_V 50
#define INF 50000

using namespace std;

int prev[MAX_V], cost[MAX_V][MAX_V], d[MAX_V];
bool used[MAX_V];
int V;

void dijkstra(int s){
  fill(d, d + V, INF);
  fill(used, used + V, false);
  fill(prev, prev + V, -1);
  d[s] = 0;

  while(true){
    int v = -1;
    for(int u = 0; u < V; u++)
      if(!used[u] && (v == -1 || d[u] < d[v])) v = u; 

    if(v == -1) break;
    used[v] = true;
    //    printf("%d\n", v);
    for(int u = 0; u < V; u++){
      if(d[u] > d[v] + cost[v][u]){
	d[u] = d[v] + cost[v][u];
	prev[u] = v;
      }
    }
  }
}

// shortest path to vertex t
vector<int> get_path(int t){
  vector<int> path;
  
  for(; t != -1; t = prev[t]) path.push_back(t);

  reverse(path.begin(), path.end());
  return path;
}

int main(){
  int n;
  scanf("%d%d", &V, &n);
  for(int i = 0; i < V; i++) for(int j = 0; j < V; j++) cost[i][j] = INF;
  for(int i = 0; i < n; i++){
    int from, to, c;
    scanf("%d%d%d", &from, &to, &c);
    cost[from][to] = c;
  }
  dijkstra(0);
  vector<int> res;
  /*  for(int i = 0; i < V; i++){
    for(int j = 0; j < V; j++) printf("%d ", cost[i][j]);
   puts("");
   }*/

  //  for(int i = 0; i < V; i++) printf("%d ", d[i]);
  //  puts("");
  res =  get_path(V-1);
  for(int i = 0; i < res.size(); i++) printf(i?" %d":"%d", res[i]);

  puts(""); 
  return 0;
}
