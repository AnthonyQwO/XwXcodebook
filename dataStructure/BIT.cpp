#define lowbit(x) (x&-x)
struct BIT {    
    int n;
    vector<int> bit;
    BIT( int t ) {
        n=t;
        bit=vector<int>(n+1,0);
    }
    ~BIT() {bit.clear();}
    void update( int pos, int val ) {
        while ( pos <= n ) {
            bit[pos]+=val;
            pos+=lowbit(pos);
        }
    }
    void range_update( int L, int R, int val ) {
        update(L,val);
        update(R+1,-val);
    }
    int query( int pos ) {
        int res=0;
        while( pos ) {
            res+=bit[pos];
            pos-=lowbit(pos);
        }
        return res;
    }
    int range_query( int L, int R ) {
        return query(R)-query(L-1);
    }
};