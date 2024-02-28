#include <bits/stdc++.h>
#define int long long
using namespace std;

bool cmp( pair<int,int> a, pair<int,int> b ) {
    return a.second < b.second || a.second == b.second && a.first < b.first;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    for(;T--;) {
        int n;
        cin>>n;
        pair<int,int> arr[n+1];
        for( int i=0 ; i < n ; i++ ) cin>>arr[i].first;
        for( int i=0 ; i < n ; i++ ) cin>>arr[i].second;
        sort(arr,arr+n,cmp);
        for( int i=0 ; i < n ; i++ ) cout<<arr[i].first<<' ';
        cout<<'\n';
    }
}