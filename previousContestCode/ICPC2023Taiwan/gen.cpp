#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=10;
    srand(time(NULL));
    cout<<T<<'\n';
    for(;T--;) {
        int a=100, b=100;
        string sa, sb;
        for(; a+b > 10 ;) a=rand()%10+1, b=rand()%10+1;
        cout<<a<<' '<<b<<'\n';
        for( int i=0 ; i < a ; i++ ) sa+=(char)(rand()%10+'0');
        for( int i=0 ; i < b ; i++ ) sb+=(char)(rand()%10+'0');
        cout<<sa<<' '<<sb<<'\n';
    }

}