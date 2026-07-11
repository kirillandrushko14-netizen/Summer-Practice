#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = array<ll,2>;
const ll inf = 1e18;
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     ll n,m;
     cin >> n >> m;

     vector<vector<pll>>g(n);
     for(int i = 0; i < m; i++){
          ll u,v,w;
          cin >> u >> v >> w;
          --u;
          --v;
          g[u].push_back({v, w});
     }
     vector<ll> d(n, inf);
     vector<ll> parent(n, -1);
     d[0] = 0;
     priority_queue<pll,vector<pll>, greater<pll>> pq;
     pq.push({0,0});

     while (pq.size()){
          pll top = pq.top();
          pq.pop();
          ll dist = top[0], v = top[1];
          if (dist > d[v]){
               continue;
          }
          for(pll edge : g[v]){
               ll w = edge[0], vec = edge[1];
               if(d[v] + vec < d[w]){
                    d[w] = d[v] + vec;
                    parent[w] = v;
                    pq.push({d[w], w});
               }
          }
     }

     if(d[n-1] == inf){
          cout << -1 << "\n";
     } else {
          vector<ll> path;
          ll cur = n-1;
          while(cur != -1){
               path.push_back(cur);
               cur = parent[cur];
          }
          reverse(path.begin(), path.end());
          for(ll x : path){
               cout << x + 1 << " ";
          }
          cout << "\n";
     }
}
