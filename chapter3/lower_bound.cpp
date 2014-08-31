#include <cstdio>

#define MAX_N 1000000

int n, k;
int a[MAX_N];

void solve(){
  // 解の存在範囲を初期化
  int lb = -1, ub = n;

  // 解の存在範囲が１より大きい間、繰り返す
  while(ub - lb > 1){
    int mid = (ub+lb)/2;
    if(a[mid] >= k) ub = mid;
    else lb = mid;
  }

  // この時点で、lb + 1 = ubとなってる
  printf("%d\n", ub);
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", a+i);
  scanf("%d", &k);

  solve();
}
