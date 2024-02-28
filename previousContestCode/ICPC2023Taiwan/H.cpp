#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c, t;
    cin>>c; cin.get();
    stringstream ss;
    string s;
    getline(cin,s);
    ss<<s;
    vector<int> v, w, dp(c+1,0);
    for(;ss>>t;) v.push_back(t);
    int n=v.size();
    for( int i=0 ; i < n ; i++ ) { 
        cin>>t; w.push_back(t);
    }
    
    for( int i=0 ; i < n ; i++ ) {
        for( int j=c ; j >= w[i] ; j-- ) dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    }
    cout<<dp[c]<<'\n';
}