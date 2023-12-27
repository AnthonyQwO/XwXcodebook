#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MXN = (int)4e5 + 1;

int arr[MXN] = {0};

signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    int q; cin >> q;

    for(int i = 0 ; i < q; i++){
        int c, l, r, v; cin>>c;
        if(c == 1){
            cin >> l >> r >> v;
            for(int j = l; j <= r; j++) arr[j] += v;
        }
        else if(c == 2){
            cin >> l >> r;
            int res = 0;
            for(int j = l; j <= r; j++) res += arr[j];
            cout << res << '\n';
        }
        else{
            cin >> l >> r >> v;
            for(int j = l; j <= r; j++) arr[j] = v;
        }
    }
}