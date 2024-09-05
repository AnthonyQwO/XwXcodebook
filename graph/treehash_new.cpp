map<vector<int>, int> id;
int dfs(int x, int f){
	vector<int> sub;
	for (int v : edge[x]){
		if (v != f)
			sub.push_back(dfs(v, x));
	}
	sort(sub.begin(), sub.end());
	if (!id.count(sub))
		id[sub] = id.size();
	return id[sub];
}