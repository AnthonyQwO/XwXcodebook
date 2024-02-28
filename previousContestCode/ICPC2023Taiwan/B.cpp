#include <bits/stdc++.h>
#define int long long
using namespace std;

int qpow( int n, int k ) {
    int res=1;
    for(;k; n*=n, k>>=1 ) if( k&1 ) res*=n;
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    for(;T--;) {
        int a,b;
        cin >> a >> b;
        string str_a,str_b;
        cin >> str_a >> str_b;

        string mother_str = "";
        for(int i=0 ; i<str_b.length(); ++i){
            mother_str += "9";
        }
        int mother = stoi(mother_str);
        mother *= qpow(10,str_a.length());
        
        int son = stoi(str_a + str_b);
        son -= stoi(str_a);

        int GGCD = 1;
        if( !(!mother && !son) ) GGCD=__gcd(mother,son);
        else mother=1;
        cout << son/GGCD << " " << mother/GGCD << "\n";
    }
}