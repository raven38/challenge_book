#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100000
#define MAX_M 5000

const int B = 1000; // バケットのサイズ

int N, M;
int A[MAX_N];
int I[MAX_M], J[MAX_M], K[MAX_M];

int nums[MAX_N]; // Aをソートしたもの
vector<vector<int> >bucket(MAX_N /  B); // 各バケットをソートしたもの

void solve(){
  for(int i = 0; i < N; i++){
    bucket[i / B].push_back(A[i]);
    nums[i] = A[i];
  }

  sort(nums, nums + N);

  // B個にみたない最後のバケットをソートしていないがもんだいない
  for(int i = 0; i < N / B; i++) sort(bucket[i].begin(), bucket[i].end());

  for(int i = 0; i < M; i++){
    // [l, r)のk番目の数を求める
    int l = I[i], r = J[i] + 1, k =  K[i];

    int lb = -1, ub = N - 1;
    while(ub - lb > 1){
      int md = (lb + ub) / 2;
      int x = nums[md];
      int tl = l, tr = r, c = 0;

      // バケットをはみ出す部分
      while(tl < tr && tl % B != 0) if(A[tl++] <= x) c++;
      while(tl < tr && tr % B != 0) if(A[--tr] <= x) c++;

      // バケットごと
      while(tl < tr){
	int b = tl / B;
	c += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin();
	tl += B;
      }

      if(c >= k) ub = md;
      else lb  = md;
    }

    printf("%d\n", nums[ub]);
  }
}

int main(){
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; i++) scanf("%d", A+i+1);
  for(int i = 0; i < M; i++) scanf("%d%d%d", I+i, J+i, K+i);

  solve();

  return 0;
}
