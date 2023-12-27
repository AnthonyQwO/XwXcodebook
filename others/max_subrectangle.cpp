const int N = 1e5+5;
int n, a[N],l[N], r[N];
long long ans;
int main() {
  while (cin>>n) { 
    ans = 0;
    for (int i = 1; i <= n; i++) cin>>a[i], l[i] = r[i] = i;
    for (int i = 1; i <= n; i++)
      while (l[i] > 1 && a[i] <= a[l[i] - 1]) l[i] = l[l[i] - 1];
    for (int i = n; i >= 1; i--)
      while (r[i] < n && a[i] <= a[r[i] + 1]) r[i] = r[r[i] + 1];
    for (int i = 1; i <= n; i++)
      ans = max(ans, (long long)(r[i] - l[i] + 1) * a[i]);
    cout<<ans<<"\n";
  }
}