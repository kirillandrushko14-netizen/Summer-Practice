#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll M = 1e9 + 7;

ll bpow(ll x, ll p){
     ll ans = 1;
     x %= M;
     while(p){
          if(p & 1){
               ans = ans * x % M;
          }
          x = x * x % M;
          p /= 2;
     }
     return ans;
}

int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     
     ll t;
     if (!(cin >> t)) return 0;
     
     while(t--){
          ll b1, q, n;
          cin >> b1 >> q >> n;
          

          if(n == 0){
               cout << 0 << "\n";
               continue;
          }
          
          if(q == 1){
               cout << (b1 * n) % M << "\n";
               continue;
          }
          

          ll numerator = (b1 * ((bpow(q, n) - 1 + M) % M)) % M;
          ll denominator = (q - 1 + M) % M;
          
          ll inv_denominator = bpow(denominator, M - 2);
          ll ans = (numerator * inv_denominator) % M;
          
          cout << ans << "\n";
     }
     
     return 0;
}
