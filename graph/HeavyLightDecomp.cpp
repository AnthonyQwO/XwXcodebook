// 詢問,修改複雜度 O(log^2 n)
// 1-base

int sz[MXN], dep[MXN], son[MXN], fa[MXN];

// 第一次 dfs
// 找重兒子 需要紀錄當前節點的子樹大小(sz)、深度(dep)、重兒子(son)、父節點(fa)
// 沒有子節點 son[x] = 0
void dfs_sz(int x, int f, int d) { //當前節點 x ，父節點 f，深度 d
    sz[x] = 1;  dep[x] = d;  fa[x] = f;
    for(int i : edge[x]) {
        if(i == f)    continue;
        dfs_sz(i, x, d+1);
        sz[x] += sz[i];
        if(sz[son[x]] < sz[i])    son[x] = i;
    }
}

// 第二次 dfs
int top[MXN]; // 每個節點所在的鏈的頂端節點
int dfn[MXN]; // 節點編號,編號為在線段樹上的位置
int rnk[MXN]; // 編號為哪個節點
int bottom[MXN]; // 維護每個節點的子樹中最大 dfn 編號
int cnt = 0;
int dfs_hld(int x, int f){
    top[x] = (son[fa[x]] == x ? top[fa[x]] : x);
    rnk[cnt] = x; 
    bottom[x] = dfn[x] = cnt++;
    if(son[x])    bottom[x] = max(bottom[x], dfs_hld(son[x], x)); // 更新子樹最大編號
    for(int i : edge[x]){
        if(i == f || i == son[x])    continue;
        bottom[x] = max(bottom[x], dfs_hld(i, x)); // 更新子樹最大編號
    }
    return bottom[x];
}

// 求出 lca 
// 不斷跳鏈，直到 u,v 跳到同一條鏈上為止
// 每次跳鏈選所在的鏈頂端深度較深的一端往上跳
int getLca(int u, int v) {
    while(top[u] != top[v]){
      if(dep[top[u]] > dep[top[v]])
          u = fa[top[u]];
      else
          v = fa[top[v]];
    }
    return dep[u] > dep[v] ? v : u;
}

// 路徑權重總和
int query(int u, int v) {
    int ret = 0;
    while(top[u] != top[v]){
        if (dep[top[u]] > dep[top[v]]){
            ret += segtree.query(dfn[top[u]], dfn[u]);
            u = fa[top[u]];  
        }
        else{
            ret += segtree.query(dfn[top[v]], dfn[v]);
            v = fa[top[v]];
        }
    }
    // 最後到同一條鏈上
    ret += segtree.query(min(dfn[u], dfn[v]), max(dfn[u], dfn[v]));
    return ret;
}