vector<int> virTree(vector<int> ver, LCA &lca) {
	auto cmp = [&](int u, int v){return time_in[u] < time_in[v];};
    sort(ver.begin(),ver.end(),cmp); //用dfn排序
    vector<int>res(ver.begin(),ver.end());
    for(int i = 1; i < ver.size(); i++){
        res.push_back(lca.getLCA(ver[i-1],ver[i]));//把LCA丟進虛樹內   
    }
    sort(res.begin(),res.end(),cmp); //再用dfn排序
    res.erase(unique(res.begin(),res.end()), res.end()); //去掉重複的點
    return res;
}