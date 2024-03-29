//拆出[a,b]區間就如同下面所展示先使用splitByTh()拆出
//左右,再把左區間拆成l, m最後merge()回去
//反轉區間時又記得使用^=可以直接反轉01

//treap拆區間時從後面拆是因為這樣[a,b]的關係
//不用重新考慮，要是先拆前面b的位置會變成b-a+1
//0-base
//splitByTh(root,a-1,l,m);
//splitByTh(m,b-a+1,m,r); 

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
struct Treap {
	int key, pri, sz, tag, sum;
	Treap *L, *R;   
	Treap( int val ) {
    sum=key=val, pri=gen(), sz=1, tag=0;
    L=R=NULL;
};};
int Size( Treap *a ) { return !a?0:a->sz;}
void pull( Treap *a ) {
	a->sz=Size(a->L)+Size(a->R)+1;
	a->sum=a->key;
	if( a->L ) a->sum+=a->L->sum;
	if( a->R ) a->sum+=a->R->sum;
}
void push( Treap *a ) {
	if( a && a->tag ) {
		swap(a->L,a->R);
		if( a->L ) a->L->tag^=1;
		if( a->R ) a->R->tag^=1;
		a->tag=0;
}}
Treap *merge(Treap *a, Treap *b) {
	if( !a || !b ) return a?a:b;
	push(a), push(b);
	if( a->pri > b->pri ) {
		a->R=merge(a->R,b);
		pull(a); return a;
	}
	b->L=merge(a,b->L);
	pull(b); return b;
}
void print(Treap *a) {
	if( !a ) return;
	push(a);
	print(a->L);
	cout.put(a->key);
	print(a->R);
}
Treap *buildTreap( int n, string& str ) {
	Treap *root=NULL;
	for( int i=0 ; i < n ; i++ ) 
		root=merge(root,new Treap(str[i]));
	return root;
}
void splitbyk( Treap *x, int k, Treap *&a, Treap *&b ) {
	if(!x) a=b=NULL;
	else if( x->key <= k ) {
		a=x;
		splitbyk(x->R,k,a->R,b);
		pull(a);
	}
	else {
		b=x;
		splitbyk(x->L,k,a,b->L);
		pull(b);        
	}
}
void splitByTh( Treap *x, int k, Treap *&a, Treap *&b ) {
	if( !x ) { a=b=NULL; return; }
	push(x);
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
signed main() {
	string str;
	int n, m;
	cin>>n>>m>>str;
	Treap *root;
	root=buildTreap(n,str);
	for( int i=0 ; i < m ; i++ ) {
		int a, b;
		cin>>a>>b;
		Treap *l, *m, *r;
		splitByTh(root,b,l,r);
		splitByTh(l,a-1,l,m);
		m->tag^=1;
		root=merge(l,merge(m,r));
	}
	print(root);
}