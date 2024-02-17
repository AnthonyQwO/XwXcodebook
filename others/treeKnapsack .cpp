int dfs(int u) {
  int p = 1;
  dp[u][1] = s[u];
  for (int v : edge[u]) {
    int siz = dfs(v);
    for (int i = min(p, m + 1); i; i--)
      for (int j = 1; j <= siz && i + j <= m + 1; j++)
        dp[u][i + j] = max(dp[u][i + j], dp[u][i] + dp[v][j]);
    p += siz;
  }
  return p;
}
