for(int i=0; i < N-1; i++) {
    for(int j=0; j < M; j++) {
        if(dis[edge[j].from]+edge[j].len > dis[edge[j].to]) dis[edge[j].to] = dis[edge[j].from]+edge[j].len;
    }
}