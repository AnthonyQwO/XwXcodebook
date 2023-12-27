const ll mod = 1e9 + 7;
ll fac[(int)2e6 + 1], inv[(int)2e6 + 1];
ll getinv(ll a){ return qpow(a, mod-2); }
void init(int n){
  fac[0] = 1;
  for(int i = 1; i <= n; i++){
    fac[i] = fac[i-1] * i % mod;
  }
  inv[n] = getinv(fac[n]);
  for(int i = n - 1; i >= 0; i--){
    inv[i] = inv[i + 1] * (i + 1) % mod;
  }
}
ll C(int n, int m){
  if(m > n) return 0;
  return fac[n] * inv[m] % mod * inv[n-m] % mod;
}
