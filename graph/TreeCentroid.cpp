vector<int> edge[MXN]; //鄰接表
int cost[MXN]; //以 now 為根的最大子樹大小
int dfs(int now, int pre){
    //tot: 以now為root的子樹size
    int tot = 1, ret = 0;
    // now下方的子樹
    for (auto nxt: edge[now]){
        if (nxt != pre){
            ret = dfs(nxt, now);
            tot += ret;
            cost[now] = max(cost[now], ret);
        }
    }
    // now頭上的子樹
    cost[now] = max(cost[now], n - tot);
    return tot;
}

int TreeCentroid(int node = 1){ // can pick any node on tree 
    dfs(node, -1);
    int mini = INF, root = 0;
    for (int i = 1; i <= n; i++) {
        if (cost[i] < mini){
            mini = cost[i];
            root = i;
        }
    }
    return root;
}