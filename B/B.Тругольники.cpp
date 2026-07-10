#include <iostream>
#include <vector>
#include <algorithm>
 
#define all(x) x.begin(), x.end()
using namespace std;
 
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int n;
     cin >> n;
     vector<int>dt(n);
     for (int i = 0; i<n; i++){
          cin >> dt[i];
     }
     sort(all(dt));
     
     int count = 0;
     for(int i= 0; i < n; i++){
          for(int j = i+1; j < n; j++){
               for(int k = j+1; k < n; k++){
                    if(dt[i] + dt[j] > dt[k]){
                         count++;
                    }
               }
          } 
     }
     cout << count << "\n";
}
