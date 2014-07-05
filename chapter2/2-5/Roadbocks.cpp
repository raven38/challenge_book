#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 5000
#define INF 1 << 30

typedef pair<int, int> P;

struct edge{
  int to;
  int cost;
};

int N, R;
vector<vector<edge> >G(MAX_N);
int dist[MAX_N];
int dist2[MAX_N];

int solve(){
  priority_queue<P, vector<P>, greater<P> >que;
  fill(dist, dist + N, INF);
  fill(dist2, dist2 + N, INF);
  dist[0] = 0;
  que.push(P(0,0));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second, d = p.first;
    if(dist2[v] < d) continue;
    for(int i = 0; i < G[v].size(); ++i){
      edge &e = G[v][i];
      int d2 = d + e.cost;
      if(dist[e.to] > d2){
	swap(dist[e.to], d2);
	que.push(P(dist[e.to], e.to));
      }
      if(dist2[e.to] > d2 && dist[e.to] < d2){
	dist2[e.to] = d2;
	que.push(P(dist2[e.to], e.to));
      }
    }
  }
  return dist2[N-1];
}

int main(){
  scanf("%d%d", &N, &R);
  for(int i = 0; i < R; ++i){
    int from;
    edge e;
    scanf("%d%d%d", &from, &e.to, &e.cost);
    //    printf("%d %d %d\n", from, e.to, e.cost);
    --from; --e.to;
    G[from].push_back(e);
    swap(e.to, from);
    G[from].push_back(e);
  }
  printf("%d\n", solve());
  return 0;
}
