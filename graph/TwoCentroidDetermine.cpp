int cost[MXN] = {0}; //以 now 為原點的最大子樹大小
int mini = INF;
int root = 0, root2 = -1;
for (int i = 1; i <= n; i++){
    if(cost[i] == mini) root2 = i;
    else if (cost[i] < mini){
        mini = cost[i];
        root = i;
        root2 = -1;
    }
}