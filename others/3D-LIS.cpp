#define lowbit(x) (x&-x)
const int MAXN=1e5+5;
struct BIT {
	int n;
	vector<int> bit;
	BIT( int _n ):n(_n), bit(_n+1,0) {}
	int query( int x ) {
		int res=0;
		for(; x > 0 ; x-=lowbit(x) ) res=max(res,bit[x]);
		return res;
	}
	void update( int x, int val ) {
		for(; x <= n ; x+=lowbit(x) ) {
			if( val < 0 ) bit[x]=0;
			else bit[x]=max(bit[x],val);
		}
	}
}bt(MAXN);
struct triple {
	int u, v, w, ans, cnt;
	bool operator<( triple b ) { return u<b.u; }
};
bool cmp( triple a, triple b ) {return a.v<b.v;}
void cdq( int L, int R, vector<triple>& arr ) {
	if( R-L <= 1 ) return;
	int mid=L+R>>1;
	cdq(L,mid,arr);
	sort(arr.begin()+L,arr.begin()+mid,cmp);
	sort(arr.begin()+mid,arr.begin()+R,cmp);
	for( int i=L, j=mid ; i < mid || j < R ; ) {
		for(; i < mid && ( j >= R || arr[i].v < arr[j].v ) ; i++ ) bt.update(arr[i].w,arr[i].ans);
		if( j < R ) {
			arr[j].ans=max(bt.query(arr[j].w-1)+1,arr[j].ans);
			j++;
		}
	}
	for( int i=L ; i < mid ; i++ ) bt.update(arr[i].w,-1);
	sort(arr.begin()+L,arr.begin()+R);
	cdq(mid,R,arr);
}
signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, res=0;
	cin>>n;
	vector<int> ls;
	vector<triple> arr;
	for( int i=0 ; i < n ; i++ ) {
		int a, b;
		cin>>a>>b;
		arr.push_back({i,a,b,1,1});//{第一維,第二維,第三維,答案,數量}
		ls.push_back(b); 
	}
	sort(ls.begin(),ls.end());
	ls.resize(unique(ls.begin(),ls.end())-ls.begin());
	for( auto &t : arr ) t.w=lower_bound(ls.begin(),ls.end(),t.w)-ls.begin()+1;
	n=arr.size();
	cdq(0,n,arr);
	for( int i=0 ; i < n ; i++ ) res=max(res,arr[i].ans);
	cout<<res<<'\n';
}