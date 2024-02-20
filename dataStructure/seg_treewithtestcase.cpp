// !!!注意build()時初始化用的陣列也是1-base
// !!!query(0, 0) 會報錯
#define cl(x) (x*2)
#define cr(x) (x*2+1)

struct segmentTree {
    int n;
    vector<int> seg, tag, cov;
    segmentTree(int _n): n(_n) {
        seg=tag=cov=vector<int>(n*4,0);
    }
    void push(int i, int L, int R) {
        if(cov[i]) {
            seg[i]=cov[i]*(R-L+1);
            if( L < R ) {
                cov[cl(i)]=cov[cr(i)]=cov[i];
                tag[cl(i)]=tag[cr(i)]=0;
            }
            cov[i]=0;
        }
        if(tag[i]) {
            seg[i]+=tag[i]*(R-L+1);
            if(L < R) {
                tag[cl(i)]+=tag[i];
                tag[cr(i)]+=tag[i];
            }
            tag[i]=0;
        }
    }
    void pull(int i, int L, int R) {
        if(L >= R) return;
        int mid=(L+R)>>1;
        push(cl(i),L,mid);
        push(cr(i),mid+1,R);
        seg[i]=seg[cl(i)]+seg[cr(i)];
    }
    void build(vector<int>& arr, int i=1, int L=1, int R=-1) {
        if(R == -1) R=n;
        if(L == R) {
            seg[i]=arr[L];
            return;
        }
        int mid=(L+R)>>1;
        build(arr,cl(i),L,mid);
        build(arr,cr(i),mid+1,R);
        pull(i,L,R);
    }
    int query(int rL, int rR, int i=1, int L=1, int R=-1) {
        if(R == -1) R=n;
        push(i,L,R);
        if(rL <= L && R <= rR) return seg[i];
        int mid=(L+R)>>1, ret=0;
        if(rL <= mid) ret+=query(rL,rR,cl(i),L,mid);
        if(mid < rR) ret+=query(rL,rR,cr(i),mid+1,R);
        return ret;
    }
    void update(int rL, int rR, int val, int i=1, int L=1, int R=-1) {
        if(R == -1) R=n;
        push(i,L,R);
        if(rL <= L && R <= rR) {
            tag[i]=val;
            return;
        }
        int mid=(L+R)>>1;
        if(rL <= mid) update(rL,rR,val,cl(i),L,mid);
        if(mid < rR) update(rL,rR,val,cr(i),mid+1,R);
        pull(i,L,R);
    }
    void cover(int rL, int rR, int val, int i=1, int L=1, int R=-1) {
        if(R == -1) R=n;
        push(i,L,R);
        if(rL <= L && R <= rR) {
            cov[i]=val;
            return;
        }
        int mid=(L+R)>>1;
        if(rL <= mid) cover(rL,rR,val,cl(i),L,mid);
        if(mid < rR) cover(rL,rR,val,cr(i),mid+1,R);
        pull(i,L,R);
    }
};
/*  Test Case:
    4
    1 2 3 4
    5
    2 1 3
    1 1 3 1
    2 1 3
    1 1 4 1
    2 1 4
*/