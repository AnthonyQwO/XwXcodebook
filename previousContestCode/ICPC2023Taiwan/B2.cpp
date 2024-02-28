#include <bits/stdc++.h>
#define int __int128
using namespace std;

int STOI( string s ) {
    __int128 res=0;
    for( char c : s ) res=res*10+c-'0';
    return res;
}

signed main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long T;
    cin>>T;
    for(;T--;) {
        long long a, b;
        cin >> a >> b;
        string str_a,str_b, d, u;
        cin >> str_a >> str_b;
        /*
        for( int i=0 ; i < a ; i++ ) d=d*10+9;
        if( STOI(str_a) == 0 ) d=1;
        for( int i=0 ; i < b ; i++ ) d=d*10;
        string s=str_a+str_b;
        cout<<s<<'\n';
        */
        if( STOI(str_b) == 0 ) d='1', u=str_a;
        else {
            for( int i=0 ; i < b ; i++ ) d+='9';
            u=str_a+str_b;
        }
        for( int i=0 ; i < a ; i++ ) d+='0';
        //cout<<u<<' '<<d<<'\n';
        int de=0;
        if( STOI(str_b) != 0 ) de=STOI(str_a);
        int D=STOI(d), U=STOI(u)-de;
        int GCD=__gcd(U,D);
        cout<<(long long)(U/GCD)<<' '<<(long long)(D/GCD)<<'\n';
    }
}