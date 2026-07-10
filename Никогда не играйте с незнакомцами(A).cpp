#include <iostream>
#include <vector>
#include <algorithm>

#define all(x) x.begin(), x.end()
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     
     int n;
     if(!(cin >> n)) return 0;
     
     vector<int> c(n);
       for(int i = 0; i<n; i++){
            cin >> c[i];
       }
       
       sort(all(c));
       
       bool ok = true;
       for(int i = 1; i < n; i++){
            if (c[i] != c[i-1] + 1){
                 ok = false;
                 break;
            }
       }
       if  (ok){
            cout << "Deck looks good\n";
          
       } else {
            cout << "Scammed\n";
       }
       return 0;
       
}
