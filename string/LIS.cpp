vector<int> getLIS(vector<int> a){
  vector<int> lis;
  for(int i : a){
    if(lis.empty() || lis.back() < i)    lis.push_Back(i);
    else      *lower_bound(lis.begin(), lis.end(), i) = i;
  }
  return lis;
}