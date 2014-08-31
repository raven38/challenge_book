#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 100000
#define MAX_Q 100000

typedef long long ll;

const int DAT_SIZE = (1 << 18) -1;

int N, Q;
int A[MAX_N];
char T[MAX_Q];
int L[MAX_Q], R[MAX_Q], X[MAX_Q];

// segment tree
ll data[DAT_SIZE], datb[DAT_SIZE];

// [a, b)にxを加算する
// kは接点の番号で、区間[l, r)に対応する
void add(int a, int b, int x, int k, int l, int r){
  if(a <= l && r <= b){
    data[k] += x;
  }else if(l < b && a < r){
    datb[k] += (min(b, r) - max(a, l)) * x;
    add(a, b, x, k * 2 + 1, l, (l + r) / 2);
    add(a, b, x, k * 2 + 2, (l + r) / 2, r);
  }
}

// [a, b)の和を計算する
ll sum(int a, int b, int k, int l, int r){
  if(b <= l || r <= a){
    return 0;
  }else if(a <= l && r <= b){
    return data[k] * (r - l) + datb[k];
  }else{
    ll res = (min(b, r) - max(a, l)) * data[k];
    res += sum(a, b, k * 2 + 1, l, (l + r) / 2);
    res += sum(a, b, k * 2 + 2, (l + r) / 2, r);
    return res;
  }
}

void solve(){
  for(int i = 0; i < N; i++){
    add(i, i + 1, A[i], 0, 0, N);
  }

  for(int i = 0; i < Q; i++){
    if(T[i] == 'C'){
      add(L[i], R[i] + 1, X[i], 0, 0, N);
    }else{
      printf("%lld\n", sum(L[i], R[i] + 1, 0, 0, N));
    }
  }
}


int main(){
  scanf("%d%d", &N, &Q);
  for(int i = 0; i < N; i++) scanf("%d", A+i);
  for(int i = 0; i < Q; i++){
    char op[8];
    scanf("%s", op);
    T[i] = op[0]; 
    int l, r, x;
    if(op[0] == 'C'){
      scanf("%d%d%d", &l, &r, &x);
      L[i] = l; R[i] = r; X[i] = x;
    }else{
      scanf("%d%d", &l, &r);
      L[i] = l; R[i] = r;
    }
  }

  solve();

  return 0;
}
