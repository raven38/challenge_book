#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 100

int n, W, w[MAX_N], v[MAX_N];

int dfs(int i, int j){
  int res = 0;
  if(i == n){
    res = 0;
  }else if(j < w[i]){
    res = dfs(i+1, j);
  }else{
    res = max(dfs(i+1, j), dfs(i+1, j-w[i]) + v[i]);
  }
  return res;
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d%d", w+i, v+i);
  scanf("%d", &W);

  printf("%d\n", dfs(0, W));
  return 0;
}
