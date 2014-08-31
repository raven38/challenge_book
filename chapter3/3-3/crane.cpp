#include <cstdio>
#include <cmath>

#define MAX_N 10000
#define MAX_C 10000

const int ST_SIZE = (1 << 15) - 1;

int N, C;
int L[MAX_N];
int S[MAX_C], A[MAX_N];

// segment tree
double vx[ST_SIZE], vy[ST_SIZE]; // 各接点のベクトル
double ang[ST_SIZE];

// 角度の変化を調べるため、現在の角度を保存しておく
double prv[MAX_N];

// init segment tree
// kは接点の番号、1,rはその接点が[l, r)に対応づいていること表す
void init(int k, int l, int r){
  ang[k] = vx[k] = 0.0;

  if(r - l == 1){
    // 葉
    vy[k] =  L[l];
  }else{
    // は出ない接点
    int chl  = k * 2 + 1, chr = k * 2 + 2;
    init(chl, l, (l + r) / 2);
    init(chr, (l + r) / 2, r);
    vy[k] = vy[chl] + vy[chr];
  }
}

// 場所sの角度がaだけ変更になった
// vは接点の番号、1,rはその接点が[l, r)に対応づいていることを表す
void change(int s, double a, int v, int l, int r){
  if(s <= l) return;
  else if(s < r){
    int chl = v * 2 + 1, chr = v * 2 + 2;
    int m = (l + r) / 2;
    change(s, a, chl, l, m);
    change(s, a, chr, m, r);
    if(s <= m) ang[v] += a;

    double s = sin(ang[v]), c = cos(ang[v]);
    vx[v] = vx[chl] + (c * vx[chr] - s * vy[chr]);
    vy[v] = vy[chl] + (s * vx[chr] + c * vy[chr]);
  }
}

void solve(){
  // 初期化
  init(0, 0, N);
  for(int i = 1; i < N; i++) prv[i] = M_PI;

  // query
  for(int i = 0; i < C; i++){
    int s = S[i];
    double a = A[i] / 360.0 * 2 * M_PI; // ラジアンの治す

    change(s, a - prv[s], 0, 0, N);
    prv[s] = a;

    printf("%.2f %.2f\n", vx[0], vy[0]);
  }
}

int main(){
  scanf("%d%d", &N, &C);
  for(int i = 0; i < N; i++) scanf("%d", L+i);
  for(int i = 0; i < C; i++) scanf("%d%d",S+i, A+i);

  solve();

  return 0;
}
