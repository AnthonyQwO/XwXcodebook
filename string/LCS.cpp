int LCS(string& s1, string& s2) {
  vector<int> p[128];  // 假設字元範圍為 0 ~ 127
  for (int i = 0; i < s2.size(); ++i) p[s2[i]].push_back(i);
  vector<int> v;
  v.push_back(-1);

  for (int i = 0; i < s1.size(); ++i)
    for (int j = p[s1[i]].size() - 1; j >= 0; --j) {
      int n = p[s1[i]][j];

      if (n > v.back())
        v.push_back(n);
      else
        *lower_bound(v.begin(), v.end(), n) = n;
    }
  return v.size() - 1;
};