#include <bits/stdc++.h> 
using namespace std; 
typedef long long int lli; 
const int m = 1e9 + 7; 
const int K = 550; 
int dp[K + 5][K + 5]; 
lli add(lli a, lli b){ 
   return ((a % m) + (b % m)) % m; 
} 
lli mul(lli a, lli b){ 
   return ((a % m) * (b % m)) % m; 
} 
class Solution { 
   public: 
   void pre(){ 
      for (int i = 0; i < K; i++) { 
         for (int j = 0; j < K; j++) { 
            dp[i][j] = -1; 
         } 
      } 
   } 
   int solve(int inPickup, int left, int i, int j){ 
      if (i == 0 && j == 0) 
      return 1; 
      if (dp[i][j] != -1) 
      return dp[i][j]; 
      int ret = 0; 
      if (i > 0) { 
         ret = add(ret, mul(left, solve(inPickup + 1, left - 1, i 
         - 1, j))); 
      } 
      if (j > i) { 
         ret = add(ret, mul(inPickup, solve(inPickup - 1, left, i, 
         j - 1))); 
      } 
      return dp[i][j] = ret; 
   } 
   int countOrders(int n){ 
      pre(); 
      return solve(0, n, n, n); 
   } 
}; 