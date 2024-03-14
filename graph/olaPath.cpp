// 記得 reverse()
vector<int> path;
void dfs(int x) {
    while(!edge[x].empty()) {
        int u = edge[x].back();
        edge[x].pop_back();
        dfs(u);
    }
    path.push_back(x);
}