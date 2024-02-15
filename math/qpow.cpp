int qpow(int n, int k) {
    int ret = 1;
    for(;k; k >>= 1, n = n * n % modl) if(k & 1) ret = ret * n % modl;
    return ret;
}