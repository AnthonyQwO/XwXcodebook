struct LCA {
  int n, ti, lgN;
  int anc[MXN + 5][__lg(MXN) + 1] = {0};
  int MaxLength[MXN][__lg(MXN) + 1] = {0};
  int time_in[MXN] = {0};
  int time_out[MXN] = {0};
  LCA( int _n, int f ):n(_n), ti(0), lgN(__lg(n)) {
    dfs(f,f,0);
    build();
  }
  void dfs(int now, int f, int len_to_father) {  // dfs for anc, time, Lenth
    ti++;
    anc[now][0] = f;
    time_in[now] = ti;
    MaxLength[now][0] = len_to_father;
    for (auto i : graph[now]) {
        if (i.first == f) continue;
        dfs(i.first, now, i.second);
    }
    time_out[now] = ti;
  }
  void build() {  // build anc[][], MaxLength[][]
    for (int i = 1; i <= lgN; ++i) {
      for (int u = 1; u <= n; ++u) {
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
        MaxLength[u][i] = max(MaxLength[u][i - 1],
                  MaxLength[anc[u][i - 1]][i - 1]);
      }
    }
  }
  bool isAncestor(int x, int y) {
    if (time_in[x] <= time_in[y] && time_out[x] >= time_out[y]) return true;
    return false;
  }
  int getLCA(int u, int v) {
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;
    for (int i = lgN; i >= 0; --i) {
      if (!isAncestor(anc[u][i], v)) {
        u = anc[u][i];
      }
    }
    return anc[u][0];
  }
  int getMAX(int u, int v) { //獲得路徑上最大邊權
    int lca = getLCA(u, v);
    int maxx = -1;
    for (int i = lgN; i >= 0; --i) {
      // u to lca
      if (!isAncestor(anc[u][i], lca)) {
        maxx = max(maxx, MaxLength[u][i]);
        u = anc[u][i];
      }

      // v to lca
      if (!isAncestor(anc[v][i], lca)) {
        maxx = max(maxx, MaxLength[v][i]);
        v = anc[v][i];
      }
    }
    if (u != lca) maxx = max(maxx, MaxLength[u][0]);
    if (v != lca) maxx = max(maxx, MaxLength[v][0]);
    return maxx;
  }
};