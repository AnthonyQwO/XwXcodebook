#define N 5010
#define M 60010
#define ll long long
#define inf 1ll<<62
ll to[ M ] , nxt[ M ] , head[ M ];
ll cnt , ceng[ M ] , que[ M ] , w[ M ];
ll n , m , start , End;
void add( ll a , ll b , ll flow ){
  to[ cnt ] = b , nxt[ cnt ] = head[ a ] , w[ cnt ] = flow , head[ a ] = cnt ++;
  to[ cnt ] = a , nxt[ cnt ] = head[ b ] , w[ cnt ] = flow , head[ b ] = cnt ++;
}
void read(){
  memset(head,-1,sizeof head);
  //memset(nxt,-1,sizeof nxt);
  scanf( "%lld%lld" , &n , &m );
  ll a , b , flow;
  for( ll i = 1 ; i <= m ; i ++ ){
    scanf( "%lld%lld%lld" , &a , &b , &flow );
    add( a , b , flow );
  }
  End = n ,start = 1;
}
bool bfs(){
  memset( ceng , -1 , sizeof(ceng) );
  ll h = 1 , t = 2;
  ceng[ start ] = 0;
  que[ 1 ] = start;
  while( h < t ){
    ll sta = que[ h ++ ];
    for( ll i = head[ sta ] ; ~i ; i = nxt[ i ] )
      if( w[ i ] > 0 && ceng[ to[ i ] ] < 0 ){
        ceng[ to[ i ] ] = ceng[ sta ] + 1;
        que[ t ++ ] = to[ i ];
      }
  }
  return ceng[ End ] != -1;
}
ll find( ll x , ll low ){
  ll tmp = 0 , result = 0;
  if( x == End ) return low;
  for( ll i = head[ x ] ; ~i && result < low ; i = nxt[ i ] )
    if( w[ i ] > 0 && ceng[ to[ i ] ] == ceng[ x ] + 1 ){
      tmp = find( to[ i ] , min( w[ i ] , low - result ) );
      w[ i ] -= tmp;
      w[ i^1 ] += tmp;
      result += tmp;
    }
  if( !result ) ceng[ x ] = -1;
  return result;
}
ll dinic(){
  ll ans = 0 , tmp;
  while( bfs() ) ans += find( start , inf );
  return ans;
}
int main(){
  read();
  cout << dinic() << endl;
}
