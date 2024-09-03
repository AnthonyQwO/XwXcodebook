// O(nlogn)
// 傳入 vector<Line>
// (半平面為點 st 往 ed 的逆時針方向)
// 回傳值為形成的凸多邊形的頂點 vector
// assume that Lines intersect
vector<Pt> HPI(vector<Line> P) {
    sort(P.begin(), P.end(), [&](Line l, Line m) {
        if (argcmp(l.v, m.v)) return true;
        if (argcmp(m.v, l.v)) return false;
        return PtSide(l.s, m) > 0;
    });
    int n = P.size(), l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        if (i and !argcmp(P[i - 1].v, P[i].v)) continue;
        while (l < r and PtSide(LLIntersect(P[r-1], P[r]), P[i]) <= 0) r--;
        while (l < r and PtSide(LLIntersect(P[l], P[l+1]), P[i]) <= 0) l++;
        P[++r] = P[i];
    }
    while (l < r and PtSide(LLIntersect(P[r-1], P[r]), P[l]) <= 0) r--;
    while (l < r and PtSide(LLIntersect(P[l], P[l+1]), P[r]) <= 0) l++;
    if (r - l <= 1 or !argcmp(P[l].v, P[r].v))
        return {}; // empty
    if (PtSide(LLIntersect(P[l], P[r]), P[l+1]) <= 0) {
        assert(0);
        return {}; // infinity
    }
    vector<Line> lns = vector(P.begin() + l, P.begin() + r + 1);
	lns.push_back(lns[0]);
	vector<Pt> hpi;
	for(int i = 1; i < lns.size(); i++) hpi.push_back(LLIntersect(lns[i-1], lns[i]));
	return hpi;
}