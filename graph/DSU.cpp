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
int MST(int n, int m,vector<tuple<int, int, int>> &edge){ //0 base
    sort(edge.begin(), edge.end());
    DSU dsu(n+1); // 初始化並查集
    int res = 0, flag=1; // 最小生成樹邊權和
    for (auto &[w, u, v] : edge) 
        if(dsu.Merge(u, v)) {
            res += w; //合併並統計答案
            //graph[u].push_back({v,w});
            //graph[v].push_back({u,w});
        }
        //else edges.push_back({w,u,v});
    return res;
}
int main(){
    int n, m; //點數,邊數
    cin >> n >> m;
    vector<tuple<int, int, int>> edge(m);
    for (auto &[w, u, v] : edge) cin >> u >> v >> w;
    cout << MST(n, m, edge);
}