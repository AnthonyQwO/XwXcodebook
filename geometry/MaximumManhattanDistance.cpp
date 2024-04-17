int dis[MAXD][MXN], mini[MAXD], maxi[MAXD];
vector<int> arr[MXN];
void dist(int n, int d) {
	for(int i = 0; i < (1 << d); i++) {
		for(int j = 0; j < n; j++) {
			dis[i][j] = 0;
			for(int k = 0; k < d; k++) dis[i][j] += (i&(1 << k) ? -1 : 1) * arr[j][k];
		}
	}
}
int slove(int n, int d) {
	int ret = 0;
	for(int i = 0; i < (1 << d); i++) {
		maxi[i] = -INF, mini[i] = INF;
		for(int j = 0; j < n; j++) {
			maxi[i] = max(maxi[i], dis[i][j]);
			mini[i] = min(mini[i], dis[i][j]);
		}
	}
	for(int i = 0; i < (1 << d); i++) ret = max(ret, maxi[i] - mini[i]);
	return ret;
}
