#include <cstdio>
#include <cmath>

#define INF 1<<30
#define MAX_N 10000

int N, K;
double L[MAX_N];

bool C(double d){
  int c = 0;
  for(int i = 0; i < N; i++) c += (int)(L[i]/d);
  return c >= K;
}

void solve(){
  double lb = 0, ub = INF;

  for(int i = 0; i < 100; i++){
    double mid = (lb + ub)/2;
    if(C(mid)) lb = mid;
    else ub = mid;
  }

  printf("%.2f\n", floor(ub * 100)/100);
}

int main(){
  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; i++) scanf("%lf", L+i);

  solve();
}
