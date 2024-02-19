int roundINT(int x, int pos) {
    int t = qpow(10, pos);
    return (x+(t>>1))/t*t;
}