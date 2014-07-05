#include <cstdio>
#include <algorithm>

#define MAX_E 50
#define MAX_V 50
#define INF 1 << 30

using namespace std;

struct edge { int u, v, cost; };

int par[MAX_V], rank[MAX_V];

void init_union_find(int n){
  for(int i = 0; i < n; ++i){
    par[i] = i;
    rank[i] = 0;
  }
}

int find(int x){
  if(par[x] == x) return x; // if x is root
  else return par[x] = find(par[x]);
}

void unite(int x, int y){
  x = find(x); y = find(y);
  if(x == y) return;
  if(rank[x] < rank[y]) par[x] = y;
  else {
    par[y] = x;
    if(rank[x] == rank[y]) rank[x]++;
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}

bool comp(const edge& e1, const edge& e2){ return e1.cost < e2.cost;}

edge es[MAX_E];
int V, E; // vertex and edge

int kruskal(){
  sort(es, es + E, comp);
  init_union_find(V);
  int res = 0;
  for(int i = 0; i < E; i++){
    edge e = es[i];
    if(!same(e.u, e.v)){
      unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}

int main(){
  scanf("%d%d", &V, &E);
  for(int i = 0; i < E; i++)
    scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].cost);

  printf("%d\n", kruskal());
  return 0;
}
