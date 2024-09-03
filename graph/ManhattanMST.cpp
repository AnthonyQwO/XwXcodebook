//return {{u,v},w}: u <-> v (w), 需要再手動去重
//need Point definition
vector<pair<pair<int,int>, int>> ManhattanMST(vector<Pt> P) {
	vector<int> id(P.size());
	iota(id.begin(),id.end(), 0);
	vector<pair<pair<int,int>, int>> edg;
	for (int k = 0; k < 4; k++) {
		sort(id.begin(),id.end(), [&](int i, int j) {
			return (P[i] - P[j]).x < (P[j] - P[i]).y;
		});
		map<int, int> sweep;
		for (int i : id) {
			auto it = sweep.lower_bound(-P[i].y);
			while (it != sweep.end()) {
				int j = it->second;
				Pt d = P[i] - P[j];
				if (d.y > d.x) break;
				edg.push_back({{i, j},d.x + d.y});
				it = sweep.erase(it);
			}
			sweep[-P[i].y] = i;
		}
		for (Pt &p : P) {
			if (k % 2) p.x = -p.x;
			else swap(p.x, p.y);
		}
	}
	return edg;
}