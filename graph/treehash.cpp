//限定root = 1
//從 dfs(1,1) 開始
int subtree_sz[MXN];
vector<int> edge[MXN];

int dfs(int u, int f) {
  vector<pair<int, int>> h;
  subtree_sz[u] = 1;
  for (int child : edge[u]) {
    if (child == f) continue;
    int tmp = dfs(child, u);
    h.push_back(make_pair(tmp, subtree_sz[child]));
    subtree_sz[u] += subtree_sz[child];
  }
  sort(h.begin(), h.end());
  int ret = subtree_sz[u];
  for (auto v : h) {
    ret = ((ret * p) % MOD + v.first) % MOD;
    ret = ret * v.second % MOD;
  }
  return ret;
}