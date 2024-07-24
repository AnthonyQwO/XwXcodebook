LL intSqrt(LL S) { //return origin val when S <= 0
    if (S <= 0) return S;
    LL x = S;
    for (LL nx;;x = nx){
        nx = (x+S/x)>>1LL;
        if(nx >= x) break;
    }
    return x;
}