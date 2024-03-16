vector<int> edge[MXN];
int TreeCentroid(int now, int pre){
    //tot: 以now為root的子樹size
    int tot = 1, ret = 0;
    // now下方的子樹
    for (auto nxt: edge[now]){
        if (nxt != pre){
            ret = TreeCentroid(nxt, now);
            tot += ret;
            cost[now] = max(cost[now], ret);
        }
    }
    // now頭上的子樹
    cost[now] = max(cost[now], n - tot);
    return tot;
}
