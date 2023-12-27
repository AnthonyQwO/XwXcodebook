#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int MXN = (int)1e5+3;

struct AreaofRectangles{
#define cl(x) (x<<1)
#define cr(x) (x<<1|1)
    ll n, id, sid;
    pair<ll,ll> tree[MXN<<3]; // count, area
    vector<ll> ind;
    tuple<ll,ll,ll,ll> scan[MXN<<1];
    void pull(int i, int l, int r){
        if(tree[i].first) tree[i].second = ind[r+1] - ind[l];
        else if(l != r){
            int mid = (l+r)>>1;
            tree[i].second = tree[cl(i)].second + tree[cr(i)].second;
        }
        else tree[i].second = 0;
    }
    void upd(int i, int l, int r, int ql, int qr, int v) {
        if(ql <= l && r <= qr){
            tree[i].first += v;
            pull(i, l, r); return;
        }
        int mid = (l+r) >> 1;
        if(ql <= mid) upd(cl(i), l, mid, ql, qr, v);
        if(qr > mid) upd(cr(i), mid+1, r, ql, qr, v);
        pull(i, l, r);
    }
    void init(int _n){
        n = _n; id = sid = 0;
        ind.clear(); ind.resize(n<<1);
        fill(tree, tree+(n<<2), make_pair(0, 0));
    }
    void addRectangle(int lx, int ly, int rx, int ry){
        ind[id++] = lx; ind[id++] = rx;
        scan[sid++] = make_tuple(ly, 1, lx, rx);
        scan[sid++] = make_tuple(ry, -1, lx, rx);
    }
    ll solve(){
        sort(ind.begin(), ind.end());
        ind.resize(unique(ind.begin(), ind.end()) - ind.begin());
        sort(scan, scan + sid);
        ll area = 0, pre = get<0>(scan[0]);
        for(int i = 0; i < sid; i++){
            auto &[x, v, l, r] = scan[i];
            //int x = get<0>(scan[i]), v = get<1>(scan[i]), l = get<2>(scan[i]), r = get<3>(scan[i]);
            area += tree[1].second * (x-pre);
            upd(1, 0, ind.size()-1, lower_bound(ind.begin(), ind.end(), l)-ind.begin(),lower_bound(ind.begin(),ind.end(),r)-ind.begin()-1, v);
            pre = x;
        }
        return area;
} }rect;

signed main(){
    int n, x1, x2, y1, y2;
    cin >> n;
    rect.init(n);
    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        rect.addRectangle(x1, y1, x2, y2);
    }

    cout << rect.solve();
    return 0;
}