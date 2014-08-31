#include <cstdio>

#define MAX_N 10000

int bit[MAX_N + 1], n;

int sum(int i){
  int s = 0;
  while(i > 0){
    s += bit[i];
    i -= i & -i; // i = i & (i-1) と同義
  }
  return s;
}

void add(int i, int x){
  while(i <= n){
    bit[i] += x;
    i += i & -i;
  }
}

int main(){
  scanf("%d", &n);
  while(1){
    int op;
    scanf("%d", &op);
    if(op){
      int i;
      scanf("%d", &i);
      printf("%d\n", sum(i));
    }else{
      int i, x;
      scanf("%d%d", &i, &x);
      add(i, x);
    }
  }
  return 0;
}
