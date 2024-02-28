#include <bits/stdc++.h>
#define int long long
#define cl(x) (x*2)
#define cr(x) (x*2+1)
using namespace std;

struct  segmentTree {
    int n;
    vector<int> seg, tag, broke;
    segmentTree( int _n ): n(_n) {
        seg=tag=broke=vector<int>(n*4,0);
    }
    void push( int i, int L, int R ) {
        if( tag[i] ) {
            seg[i]=(R-L+1-broke[i])-seg[i];
            if( L < R ) {
                tag[cl(i)]^=1;
                tag[cr(i)]^=1;
            }
            tag[i]^=1;
        }
    }
    void pull( int i, int L, int R ) {
        if( L >= R ) return;
        int mid=L+R>>1;
        push(cl(i),L,mid);
        push(cr(i),mid+1,R);
        seg[i]=seg[cl(i)]+seg[cr(i)];
        broke[i]=broke[cl(i)]+broke[cr(i)];
    }
    void build( vector<int>& arr, int i=1, int L=1, int R=-1 ) {
        if( R == -1 ) R=n;
        if( L == R ) {
            if( arr[L] == -1 ) broke[i]=1;
            else seg[i]=arr[L];
            return;
        }
        int mid=L+R>>1;
        build(arr,cl(i),L,mid);
        build(arr,cr(i),mid+1,R);
        pull(i,L,R);
    }
    int query( int rL, int rR, int i=1,  int L=1, int R=-1 ) {
        if( R == -1 ) R=n;
        push(i,L,R);
        if( rL <= L && R <= rR ) return seg[i];
        int mid=L+R>>1, ret=0;
        if( rL <= mid ) ret+=query(rL,rR,cl(i),L,mid);
        if( mid < rR ) ret+=query(rL,rR,cr(i),mid+1,R);
        return ret;
    }
    void update( int rL, int rR, int i=1, int L=1, int R=-1 ) {
        if( R == -1 ) R=n;
        push(i,L,R);
        if( rL <= L && R <= rR ) {
            tag[i]^=1;
            return;
        }
        int mid=L+R>>1;
        if( rL <= mid ) update(rL,rR,cl(i),L,mid);
        if( mid < rR ) update(rL,rR,cr(i),mid+1,R);
        pull(i,L,R);
    }
};


signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q, res=0, t;
    cin>>n>>q;
    vector<int> arr(n+1);
    for( int i=1 ; i <= n ; i++ ) {
        cin>>arr[i]>>t;
        res+=t;
    }
    segmentTree SMT(n);
    SMT.build(arr);
    for(;q--;) {
        char c;
        int a, b;
        cin>>c>>a;
        if( c == 'W' ) {
            cin>>b;
            a++, b++;
            SMT.update(a,b);
        }
        else res+=SMT.query(1,n)*a;
    }
    cout<<res<<'\n';
}