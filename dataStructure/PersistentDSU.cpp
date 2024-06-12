struct DSU {
    int n;
    vector<int> fa, sz;
    vector<tuple<int, int, int, int>> ver;
    DSU(int _n): n(_n), fa(n), sz(n, 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        return fa[x] == x ? x : find(fa[x]);
    }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if(sz[x] < sz[y]) swap(x, y);
        ver.push_back({x, sz[x], y, fa[y]});
        if(x == y) return;
        sz[x] += sz[y];
        fa[y] = x; 
    }
    void undo() {
        if(ver.empty()) return;
        auto [x, szx, y, fy] = ver.back(); 
        ver.pop_back();
        sz[x] = szx;
        fa[y] = fy;
    }
};
