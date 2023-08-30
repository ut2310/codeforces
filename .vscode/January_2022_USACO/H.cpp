#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 1;
const int mxK = 31;
const int M = 1e9+7;

int dp[mxN][mxK][mxK];

int main()
{
   
   int a[mxK][mxK];
   memset(a, 0, sizeof(a));
   for(int i = 2; i < mxK; i++)
   {
        for (int j = 1; j <= i; j++)
        {
            for (int k = 1; k <= i; k++)
            {
                if (__gcd(j,k) > 2)
                {
                    a[i][j]++;
                }  
            }
        }
   }
   for (int i = 0; i < mxN; i++)
   {
      [p0p]
         for (int k = 0; k < mxK; k++){
            dp[i][j][k] = 1;
         }
      }
   }
   for (int k = 2; k <= 30; k++){
      //k is upper constraint
      for (int n = 2; n < mxN; n++){ 
         //n is number of elements
         for (int h = 1; h <= k; h++){
            //h is last element
            dp[n][k][h] = ((dp[n][k][h] * a[k][h]) % M + M) % M;
         }
      }
   }   
   int t;
   cin >> t;
   while (t--){
      int n,k;
      cin >> n >> k;
      int ans = 0;
      for (int h = 2; h <= k; h++){
         ans = ((ans + dp[n][k][h]) % M + M) % M;
      }
      cout << ans << "\n";
   }
}