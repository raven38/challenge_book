#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define MAX_W 10000

int dp[MAX_N+1][MAX_W+1];
int n, W;
int w[MAX_N], v[MAX_N];


int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d%d", w+i, v+i);
  scanf("%d", &W);
  memset(dp, 0, sizeof(dp));

  for(int i = 0; i < n; i++){
    for(int j = 0; j <= W; j++){
      if(j < w[i]){
	dp[i+1][j] = dp[i][j];
      }else{
	dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
      }
    }
  }

  printf("%d\n", dp[n][W]);
  return 0;
}
