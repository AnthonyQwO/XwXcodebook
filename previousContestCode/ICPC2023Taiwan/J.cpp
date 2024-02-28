#include <bits/stdc++.h>
#define int long long
using namespace std;

int st, ed, res=0;
vector<int> nT, val;
vector<vector<pair<int,int>>> graph;

struct pos{
    int cur;
    vector<int> pth;
};

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    for(;cin>>n>>m;) {
        int t;
        char c;
        res=0;
        graph=vector<vector<pair<int,int>>>(n);
        val=nT=vector<int>(n,0);
        vector<int> in(n,0), out(n,0);
        for( int i=0 ; i < n ; i++ ) {
            cin>>nT[i];
            if( i+1 < n ) cin>>c;
        }
        for( int i=0 ; i < m ; i++ ) {
            int a, b, c;
            cin>>a>>b>>c;
            in[b]++, out[a]++;
            graph[a].push_back({b,c});
        }
        queue<pos> que;
        for( int i=0 ; i < n ; i++ ) {
            if( !in[i] ) que.push({i,{i}}), st=i, val[st]=nT[st];
            if( !out[i] ) ed=i;
        }
        cout<<val[st]<<'\n';
        for(;!que.empty();) {
            int t=que.size();
            for( int k=0 ; k < t ; k++ ) {
                int x=que.front().cur;
                vector<int> spath=que.front().pth;
                que.pop();
                for( auto& temp : graph[x] ) {
                    int a=temp.first, b=temp.second;
                    if( !--in[a] ) {
                        if( !spath.empty() ) val[a]=max(val[a],b+nT[a]+val[spath.back()]);
                        else val[a]=max(val[a],b+nT[a]);
                        spath.push_back(a);
                        que.push({a,spath});
                        spath.pop_back();
                        cout<<a<<' '<<val[a]<<'\n';

                    }
                }
            }
        }
        cout<<ed<<'\n';
        cout<<val[ed]+nT[ed]<<'\n';
    }
}