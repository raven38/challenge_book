#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_V 100
#define INF 1 << 30

using namespace std;

struct edge { int to, cost;};

// first:cost second:vertex num
typedef pair<int , int> P;

vector<vector<edge> > G(MAX_V);
vector<int> d(MAX_V, INF);
int V;

void dijkstra(int s){
  // ascending
  priority_queue<P, vector<P>, greater<P> > que;
  d[s] = 0;
  que.push(P(0,s));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(int i = 0; i < G[v].size(); i++){
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost){
	d[e.to] = d[v] + e.cost;
	que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main(){
  int N; 
  scanf("%d%d", &V, &N);
  edge e;
  while(N--){
    int from;
    scanf("%d %d %d", &from, &e.to, &e.cost);
    G[from].push_back(e);
  }
  int s, g;
  scanf("%d%d", &s, &g);
  dijkstra(s);
  printf("%d\n", d[g]);
  return 0;
}
