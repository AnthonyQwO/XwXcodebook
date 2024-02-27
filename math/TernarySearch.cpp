while(L <= R) {
    int ml = L + (R - L) / 3, mr = R - (R - L) / 3;
    if(L == R) return L;
    else if( checker(ml) < checker(mr) ) L = ml + 1;
    else R = mr - 1;
}