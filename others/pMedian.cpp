fill(fa, fa + n + 1, INF);
for(int i = 1; i <= n; i++) {
	for(int j = i; j <= n; j++) {
		dis[i][j] = 0;
		for(int k = i; k <= j; k++) dis[i][j] += abs(arr[k] - arr[i + j >> 1]);
		if(i == 1) dp[1][j] = dis[1][j];
	}
}
for(int i = 2; i <= p; i++) {
	for(int j = 1; j <= n; j++) {
		dp[i][j] = INF;
		for(int k = p; k <= j; k++) {
			if(dp[i][j] > dp[i - 1][k - 1] + dis[k][j]) {
				dp[i][j] = dp[i - 1][k - 1] + dis[k][j];
				fa[j] = k - 1;
			}
		}
	}
}