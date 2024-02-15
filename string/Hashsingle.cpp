//1-base
//H[R] - H[L-1] * p^(R-L+1)
//cmp的+modl是為了防止負數
const int p = 75577, modl = 1e9 + 7;
vector<int> build(const string& s) {
    vector<int> ret(1, 0);
    for(int i=1; i<=s.size(); i++)
        ret.push_back((ret.back() * p + s[i-1]) % modl);
    return ret;
}
int qpow(int n, int k){
    int ret = 1;
    for(;k; k >>= 1, n = n * n % modl) if(k & 1) ret = ret * n % modl;
    return ret;
}
bool cmp(const vector<int>& h, int i, int len, int Hash) {
    return (h[i+len-1] - h[i-1] * qpow(p, len) % modl + modl) % modl == Hash;
}