int GAUSS_MOD;
struct GAUSS{
	int n;
	vector<vector<int> > v;
	vector<vector<int> > rev;
	int mul(int x,int y,int mod){
		int ret=x*y-(int)((long double)x/mod*y)*mod;
		return ret<0?ret+mod:ret;
	}
	int ppow(int a, int b){//res=(a^b)%m
		int res=1, k=a;
		while(b){
			if((b&1)) res=mul(res,k,GAUSS_MOD)%GAUSS_MOD;
			k=mul(k,k,GAUSS_MOD)%GAUSS_MOD;
			b>>=1;
		}
		return res%GAUSS_MOD;
	}
	bool solve(){
		for(int now = 0; now < n; now++){
			int ch;
			for(ch = now; ch < n && !v[ch][now]; ch++);
			if(ch >= n) return 0;
			for(int i = now; i < n; i++) if(v[now][now] == 0 && v[i][now] != 0){
					swap(v[i] , v[now]); // det = -det;
					swap(rev[i], rev[now]);
			}
			if(v[now][now] == 0) return 0;
			int inv = ppow(v[now][now] , GAUSS_MOD - 2);
			for(int i = 0; i < n; i++) if(i != now){
				int tmp = v[i][now] * inv % GAUSS_MOD;
				for(int j = 0; j < n; j++) {
					(v[i][j] += GAUSS_MOD - tmp * v[now][j] % GAUSS_MOD) %= GAUSS_MOD;
					(rev[i][j] += GAUSS_MOD - tmp * rev[now][j] % GAUSS_MOD) %= GAUSS_MOD;
				}
			}
		}
		return 1;
}} gs;

signed main(){
  int n, p; //n*n matrix, MOD=p
	cin>>n>>p; //if(!n && !p) return 0;
	GAUSS_MOD = p; gs.n = n;
	gs.v.clear() , gs.v.resize(n + 1, vector<int>(n + 2 , 0));
	gs.rev.clear() , gs.rev.resize(n + 1, vector<int>(n + 2 , 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>gs.v[i][j];
			if(i == j) gs.rev[i][j] = 1;
		}
	}
	if(!gs.solve()) cout << "singular\n";
	else{
		for(int i = 0; i < n; i++){
			int inv = gs.ppow(gs.v[i][i] , p - 2);
			for(int j = 0; j < n; j++)
					cout << (gs.rev[i][j] * inv % p) <<" ";
			cout<<"\n";
		}
	}
	cout << "\n";
}