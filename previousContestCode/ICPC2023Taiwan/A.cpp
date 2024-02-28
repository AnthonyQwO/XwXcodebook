#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    for(;T--;) {
        string str;
        int flag=1, res=0;
        cin>>str;
        for(; str.size()%3 != 0 ;) str='0'+str;
        vector<int> arr;
        for( int i=str.size()-3 ; i >= 0 ; i-=3 ) {
            arr.push_back(stoi(str.substr(i,3)));
        }
        res=arr[0];
        for( int i=1 ; i < arr.size() ; i++ ) {
            if( flag ) res-=arr[i];
            else res+=arr[i];
            flag=!flag;
        }
        cout<<abs(res)<<' ';
        for( ;res<=0; res+=13);
        if( res%13 == 0 ) cout<<"YES\n";
        else cout<<"NO\n";
    }
}