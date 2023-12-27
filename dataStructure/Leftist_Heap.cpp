const int MAXN = 10000;
struct Node{
  int num,lc,rc;
  Node() : num(0), lc(-1), rc(-1){}
  Node( int _v ) : num(_v), lc(-1), rc(-1){}
}tree[ MAXN ];
int merge( int x, int y ){
  if( x == -1 ) return y;
  if( y == -1 ) return x;
  if( tree[ x ].num < tree[ y ].num )
    swap(x, y);
  tree[ x ].rc = merge(tree[ x ].rc, y);
  swap(tree[ x ].lc, tree[ x ].rc);
  return x;
}
/* Usage
merge: root = merge(x, y)
delmin: root = merge(root.lc, root.rc)
*/
