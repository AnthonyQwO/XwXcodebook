#include <bits/stdc++.h>
#define int long long
using namespace std;

struct ord {
    int id, d, pen;
};

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    for(;T--;) {
        int n;
        cin>>n;
        vector<ord> arr(n+1), que;
        vector<int> days, pens, mul;
        for( int i=1 ; i <= n ; i++ ) {
            int a, b;
            cin>>a>>b;
            arr[i]={i,a,b};
        }
        for( int k=1 ; k <= n ; k++ ) {
            int SD=0, SP=0, tol=INT64_MAX, pos=0;
            mul=days=pens=vector<int>(n+1,0);
            for( int i=1 ; i <= que.size() ; i++ ) {
                days[i]=days[i-1]+que[i-1].d;
                pens[i]=pens[i-1]+que[i-1].pen;
                //if( que[i].d < SD ) pens[i]+=que[i-1].pen;
                SD+=que[i-1].d, SP+=que[i-1].pen;
            }
            cout<<k<<":\n"<<SD<<' '<<SP<<'\n';
            for( int i=1 ; i <= que.size() ; i++ ) {
                int sd=days[i-1], sp=SP-pens[i-1], rd=SD-sd;
                int Lres=
                if( (sd+arr[k].d)*sp+arr[k].d+pens[i-1] <= tol ) pos=i-1, tol=min((sd+arr[k].d)*sp+arr[k].d+pens[i-1],tol);
            }
            //cout<<pos<<' ';
            que.insert(que.begin()+pos,arr[k]);
            for( auto temp : que ) cout<<temp.id<<' ';
            cout<<'\n';
        }
        
        cout<<'\n';
    }
}