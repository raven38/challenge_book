#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 1 << 17;

// セグメント木を持つグローバル配列
int n, dat[2 * MAX_N - 1];

// 初期化
void init(int n_){
  // 簡単のため、要素数を2のべき乗に
  n = 1;
  while(n < n_) n *= 2;

  // すべての値をINT_MAXに
  for(int i = 0; i < 2 * n - 1; i++) dat[i] = INT_MAX;
}

// k番目の値(0-indexed)をaに変更
void update(int k, int a){
  // 葉の接点
  k += n - 1;
  dat[k] = a;
  // 登りながら更新
  while(k > 0){
    k = (k - 1) / 2;
    dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
  }
}

// [a, b]の最小値を求める
// 後ろの方の引数は計算の簡単のための引数。
// kは接点の番号、1, rはその接点が[l,r)に対応づいていることを表す
// したがって、外からはquery(a, b, 0, 0, n)として呼ぶ。
int query(int a, int b, int k, int l, int r){
  // [a, b)と[l, r)が交差しなければ、INT_MAX
  if(r <= a || b <= l) return INT_MAX;

  // [a, b)が[l, r)を完全に含んでいれば、この接点の値
  if(a <= l && r <= b) return dat[k];
  else{
    // そうでなければ、２つの子の最小値
    int vl = query(a, b, k * 2 + 1, l, (l+r) / 2);
    int vr = query(a, b, k * 2 + 2, (l+r) / 2, r);
    return min(vl, vr);
  }
}

int main(){
  int n, op;
  scanf("%d", &n);
  init(n);
  while(1){
    scanf("%d", &op);
    if(op){
      int s, t;
      scanf("%d%d", &s, &t);
      printf("%d\n",query(s, t, 0, 0, n));
    }else{
      int i, x;
      scanf("%d%d", &i, &x);
      update(i, x);
    }
  }
  return 0;
}
