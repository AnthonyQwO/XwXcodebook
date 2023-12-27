#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MXN = (int)4e5 + 1;

int arr[MXN];
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

signed main(){
    int n = gen() % (int)2e2;
    int q = gen() % (int)2e2;
    for(int i = 0; i < n; i++) arr[i] = gen() % (int)1e6;

    cout << n << '\n'; 
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << '\n' << q << '\n';


    for(int i = 0; i < q; i++){
        int c =  gen() % 3;
        int l = gen() % n;
        int v = gen() % (int)1e4;
        while(l == 0) l = gen() % n;
        int r = gen() % (n+1);
        while(r < l) r = gen() % n;
        
        if(i == q-1) c = 2;
        if(c == 1){
            cout << 1 << ' ';
            cout << l << ' ' << r <<  ' ' << v;
            
        }
        if(c == 2){
            cout << 2 << ' ';
            cout << l << ' ' << r;
        }
        if(c == 0){
            cout << 3 << ' ';
            cout << l << ' ' << r <<  ' ' << v;
        }

        cout<<'\n';
    }
}

