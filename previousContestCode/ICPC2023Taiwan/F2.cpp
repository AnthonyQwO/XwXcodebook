#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    for(;T--;) {
        int n;
        cin>>n;
        vector<int> D(n+1), S(n+1);
        //vector<int> days, pens, mul;
        for( int i=1 ; i <= n ; i++ ) {
            cin >> D[i] >> S[i];
        }
        vector<int> res(1);
        //res = push_back(0);
        for( int i=1 ; i <= n ; i++ ) {
            vector<int> arr(n), sum(n);
            arr.push_back(0); sum.push_back(0);
            for( int j=1 ; j <= i; i++ ) {
                arr.push_back()
            }
            
            for( int j=1 ; j <= i; i++ ) {
                arr.push_back()
            }
        }
        
        cout<<'\n';
    }
}