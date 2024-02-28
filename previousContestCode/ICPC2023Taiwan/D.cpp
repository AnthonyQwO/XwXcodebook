#include <bits/stdc++.h>
#define int long long
using namespace std;

bool in( int n, int m, int x, int y ) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int odx[]={1,-1,0,0}, ody[]={0,0,1,-1};
int tdx[]={1,-1,1,-1}, tdy[]={1,-1,-1,1};

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    for( int i=1 ; i <= T ; i++ ) {
        int n, m, d1, d2;
        cin>>n>>m>>d1>>d2;
        vector<vector<char>> arr(n,vector<char>(m));
        vector<vector<int>> res(n,vector<int>(m,0));
        for( int i=0 ; i < n ; i++ ) for( int j=0 ; j < m ; j++ )  cin>>arr[i][j];
        for( int i=0 ; i < n ; i++ ) {
            for( int j=0 ; j < m ; j++ ) {
                if( arr[i][j] == 'V' ) {
                    for( int k=0 ; k < 4 ; k++ ) {
                        int x=i+odx[k], y=j+ody[k];
                        if( in(n,m,x,y) ) res[x][y]=d1;
                    }
                }
            }
        }
        for( int i=0 ; i < n ; i++ ) {
            for( int j=0 ; j < m ; j++ ) {
                if( arr[i][j] == 'V' ) {
                    for( int k=0 ; k < 4 ; k++ ) {
                        int x=i+tdx[k], y=j+tdy[k];
                        if( in(n,m,x,y) ) res[x][y]=max(res[x][y],d2);
                    }
                }
            }
        }
        cout<<"Airplane #"<<i<<":\n";
        for( int i=0 ; i < n ; i++ ) {
            for( int j=0 ; j < m ; j++ ) {
                if( arr[i][j] == 'V' ) cout<<'V';
                else cout<<res[i][j];
            }
            cout<<'\n';
        }
        if( i < T ) cout<<'\n';
    }
}