mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
struct Treap {
    int key, pri, sz, tag, sum;
    Treap *L, *R;   
    Treap(int val): sum(val), key(val), pri(gen()), sz(1), tag(0), L(0), R(0) {}
};
int Size(Treap *a) {
    return !a ? 0 : a->sz;
}
void pull(Treap *a) {
    a->sz = Size(a->L) + Size(a->R) + 1;
    a->sum = a->key;
    if(a->L) a->sum += a->L->sum;
    if(a->R) a->sum += a->R->sum;
}
void push(Treap *a) {
    if(a && a->tag) {
        swap(a->L,a->R);
        if(a->L) a->L->tag ^= 1;
        if(a->R) a->R->tag ^= 1;
        a->tag = 0;
    }
}
Treap *merge(Treap *a, Treap *b) {
    if(!a || !b) return a ? a : b;
    push(a), push(b);
    if(a->pri > b->pri) {
        a->R = merge(a->R, b);
        pull(a);
        return a;
    }
    b->L = merge(a, b->L);
    pull(b);
    return b;
}
void print(Treap *a) {
    if(!a) return;
    push(a);
    print(a->L);
    putchar(a->key);
    print(a->R);
}
Treap *build(int n) {
    Treap *root = NULL;
    int a;
    for(int i=0; i < n; i++) {
        cin >> a;
        root = merge(root, new Treap(a));
    }
    return root;
}
void splitbyk(Treap *x, int k, Treap *&a, Treap *&b) {
    if(!x) a = b = NULL;
    else if(x->key <= k) {
        a = x;
        splitbyk(x->R, k, a->R, b);
        pull(a);
    }
    else {
        b = x;
        splitbyk(x->L, k, a, b->L);
        pull(b);        
    }
}
void splitByTh(Treap *x, int k, Treap *&a, Treap *&b) {
    if(!x) return a = b = NULL, void();
    push(x);
    if(Size(x->L) + 1 <= k) {
        a = x;
        splitByTh(x->R, k - Size(x->L) - 1, a->R, b);
        pull(a);
    }
    else {
        b = x;
        splitByTh(x->L, k, a, b->L);
        pull(b);
    } 
}