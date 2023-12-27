//區間移除使用bitset維護區間值
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
struct Treap {
char key;
int pri, sz;
bitset<128> tag;
	Treap *L, *R;   
	Treap( char val ) {
		key=val, pri=gen(), sz=1;
		L=R=NULL;
		tag.set(key);
}; };
int Size( Treap *a ) { return !a?0:a->sz;}
void pull( Treap *a ) {
	if( !a ) return;
	a->sz=Size(a->L)+Size(a->R)+1;
	a->tag=a->tag.reset();
	a->tag=a->tag.set(a->key);
	if( a->L ) a->tag|=a->L->tag;
	if( a->R ) a->tag|=a->R->tag;
}
Treap *merge( Treap *a, Treap *b ) {
	if( !a || !b ) return a?a:b;
	if( a->pri > b->pri ) {
		a->R=merge(a->R,b);
		pull(a);
		return a;
	}
	b->L=merge(a,b->L);
	pull(b);
	return b;
}
Treap *buildTreap( int n, string& str ) {
	Treap *root=NULL;
	for( int i=0 ; i < n ; i++ ) 
		root=merge(root,new Treap(str[i]));
	return root;
}
void print( Treap *a ) {
	if( !a ) return;
	print(a->L);
	cout.put(a->key);
	print(a->R);
}
void splitByTh( Treap *x, int k, Treap *&a, Treap *&b ) {
	if( !x ) { a=b=NULL; return; }
	if( Size(x->L)+1 <= k ) {
		a=x;
		splitByTh(x->R,k-Size(x->L)-1,a->R,b);
		pull(a);
	}
	else {
		b=x;
		splitByTh(x->L,k,a,b->L);
		pull(b);
	} 
}
void erase( Treap *&x, char ch ) {
	if( !x || !x->tag.test(ch) ) return;
	erase(x->L,ch);
	erase(x->R,ch);
	if( x->key == ch ) {
		Treap *l=x->L, *r=x->R;
		x=NULL;
		x=merge(l,r);
	}
	pull(x);
}
signed main() {
	string str;
	int n, m;
	cin>>n>>m>>str;
	Treap *root;
	root=buildTreap(n,str);
	for( int i=0 ; i < m ; i++ ) {
		char c;
		int a, b;
		cin>>a>>b>>c;
		Treap *l, *m, *r;
		if( !root || !root->tag.test(c) ) continue;
		splitByTh(root,b,l,r);
		splitByTh(l,a-1,l,m);
		if( m || !m->tag.test(c) ) erase(m,c);
		root=merge(l,merge(m,r));
	}
	print(root);
}