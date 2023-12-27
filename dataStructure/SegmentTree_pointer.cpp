struct node{
  node *l, *r;
  int val;
};
 
vector<node *> ver;
int arr[MXN] = {0};
 
//0-base
struct SegmentTree{
  int n;
  node *root;
  void build(int _n){
    n = _n;
    root = build(0, n-1);
  }
  node* build(int L, int R){
    node *x = new node();
    if(L == R){ x->val = arr[L]; return x;}
    int mid = (L+R)/2;
    x->l = build(L, mid);
    x->r  = build(mid + 1, R);
    x->val = x->l->val + x->r->val;
    return x;
  }
  int query(node *ro, int L, int R){return query(ro, 0, n-1, L, R);}
  int query(int L, int R){return query(root, 0, n-1, L, R);}
  int query(node *x, int L, int R, int recL, int recR){
    if(recL <= L && R <= recR) return x->val;
    int mid = (L+R)/2, res = 0;
    if(recL <= mid) res += query(x->l, L, mid, recL, recR);
    if(mid  < recR) res += query(x->r, mid+1, R, recL, recR);
    return res;
  }
  void update(int pos, int v){update(root, 0, n-1, pos, v);}
  void update(node *x, int L, int R, int pos, int v){
    if(L == R){ x->val = v; arr[L] = v; return;}
    int mid = (L+R)/2;
    if(pos <= mid) update(x->l, L, mid, pos, v);
    else           update(x->r, mid+1, R, pos, v);
    x->val = x->l->val + x->r->val;
  }
  node *update_ver(node *pre, int l, int r, int pos, int v){
    node *x = new node();    //當前位置建立新節點
    if(l == r){
      x->val = v;
      return x;
    }
    int mid = (l+r)>>1;
    if(pos <= mid){ //更新左邊
      x->l = update_ver(pre->l, l, mid, pos, v); //左邊節點連向新節點
      x->r = pre->r; //右邊連到原本的右邊
    }
    else{ //更新右邊
      x->l = pre->l; //左邊連到原本的左邊
      x->r = update_ver(pre->r, mid+1, r, pos, v);  //右邊節點連向新節點
    }
    x->val = x->l->val + x->r->val;
    return x;
}} seg;
 
void add_ver(int x,int v){    //修改位置 x 的值為 v
    ver.push_back(seg.update_ver(ver.back(), 0, seg.n-1, x, v));
}