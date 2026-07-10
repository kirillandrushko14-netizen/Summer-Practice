#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = array<ll,2>;
const ll inf = 1e18;


int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     
     ll n,m,k;
     cin >> n >> m >> k;
     vector<vector<ll>>g(n);
     for(ll i = 0; i < m; ++i){
          ll u,v;
          cin >> u >> v;
          --u;
          --v;
          g[u].push_back(v);
          g[v].push_back(u);
     }
     ll s = k-1;
     queue<ll> q;
     vector<ll>d(n, inf);
     d[s] = 0;
     q.push(s);
     while(q.size()){
          ll u = q.front();
          q.pop();
          for(ll v : g[u]){
               if(d[v] == inf){
                    d[v] = d[u] + 1;
                    q.push(v);
               }
          }
     }
     for(ll i = 0; i < n; ++i){
          if(d[i] == inf){
               cout << -1 << " ";
          }else {
               cout << d[i] << " ";
          }
     }
     cout << "\n";
}
