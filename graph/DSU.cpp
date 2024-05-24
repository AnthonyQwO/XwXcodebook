struct DSU {// 並查集
    vector<int> fa, sz;
    DSU(int n = 0) : fa(n), sz(n, 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int Find(int x) { // 路徑壓縮
        while (x != fa[x])
            x = fa[x] = fa[fa[x]];
        return x;
    }
    bool Merge(int x, int y) { //合併
        x = Find(x), y = Find(y);
        if (x == y) return false; // 是否為連通
        if (sz[x] > sz[y]) swap(x, y);
        fa[x] = y;
        sz[y] += sz[x];
        return true;
    }
};