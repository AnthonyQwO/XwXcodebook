
//字串雜湊前的idx是0-base，雜湊後為1-base
//即區間為 [0,n-1] -> [1,n]
//若要取得區間[L,R]的值則
//H[R] - H[L-1] * p^(R-L+1)
//cmp為比較從i開始長度為len的字串和
//從j開始長度為len的字串是否相同
#define x first
#define y second
pair<int,int> Hash[MXN];
void build(const string& s){
  pair<int,int> val = make_pair(0,0);
  Hash[0]=val;
  for(int i=1; i<=s.size(); i++){
  val.x = (val.x * P1 + s[i-1]) % MOD;
  val.y = (val.y * P2 + s[i-1]) % MOD;
  Hash[i] = val;
  }
}
bool cmp( int i, int j, int len ) {
    return ((Hash[i+len-1].x-Hash[i-1].x*qpow(P1,len)%MOD+MOD)%MOD == (Hash[j+len-1].x-Hash[j-1].x*qpow(P1,len)%MOD+MOD)%MOD)
    && ((Hash[i+len-1].y-Hash[i-1].y*qpow(P2,len)%MOD+MOD)%MOD == (Hash[j+len-1].y-Hash[j-1].y*qpow(P2,len)%MOD+MOD)%MOD);
}