#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     
     int n;
     cin >> n;
     
     vector<ll>dp(n+1,0);
     dp[1] = 0;
     
     for (int i = 2; i<=n; i++){
          ll res = dp[i-1] + i;
          
          if(i%2 == 0){
               res = min(res,dp[i/2]+i);
          }
           if(i%3 == 0){
               res = min(res,dp[i/3]+i);
          }
          dp[i] = res;
     }
     cout << dp[n] << "\n";

}
