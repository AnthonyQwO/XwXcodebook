for(int i = 1; i <= n; i++) {
	for(int j = i; j <= n; j++) {
		dis[i][j] = 0;
		for(int k = i; k <= j; k++) dis[i][j] += abs(arr[k] - arr[i + j >> 1]);
		if(i == 1) dp[i][j] = dis[i][j];
	}
}
for(int i = 2; i <= p; i++) {
	for(int j = i; j <= n; j++) {
		dp[i][j] = INF;
		for(int k = i; k <= j; k++) {
			if(dp[i][j] > dp[i - 1][k - 1] + dis[k][j]) {
				dp[i][j] = dp[i - 1][k - 1] + dis[k][j];
				fa[i][j] = k - 1;
			}
		}
	}
}