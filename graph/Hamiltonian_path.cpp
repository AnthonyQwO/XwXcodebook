//dp[i][j] = 目前在j節點走過{i}節點的最短路徑
for(int i=1 ; i < (1 << n) ; i++ ) {
  for(int j = 1 ; j < n ; j++ ) {
    if(!((1 << j) & i)&&(i&1)) {
      for( int k = 0 ; k < n ; k++ ) {
        if(j == k) continue;
        if( (1<<k)&i ) dp[j][i|(1<<j)]=
          min(dp[j][i|(1<<j)],dp[k][i]+dis[k][j]);
      }
    }
  }
}