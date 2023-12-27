//cdq分治使用的結構u, v, w為排序物的三個維度
//ans記錄了有幾項三維都小於等於自己
//cnt記錄了相同物有幾個，在使用cdq之前必先去重，
//並且將相同元素紀錄至cnt中，可使用map來做到這步
//cdq使用的BIT就是普通求和的BIT，大小就開維度的
//值域範圍，若值域大於2e6則要先進行離散化
struct triple {int u, v, w, ans, cnt;};
int n, k;
BIT *bt;
void cdq( int L, int R, vector<triple>& arr ) {
  if( R-L <= 1 ) return;
  int mid=L+R>>1;
  vector<triple> temp;
  cdq(L,mid,arr), cdq(mid,R,arr);
  for( int i=L, j=mid ; i < mid || j < R ; ) {
    for(; i < mid && ( j >= R || arr[i].v <= arr[j].v ) ; i++ ) {
      bt->update(arr[i].w,arr[i].cnt);
      temp.push_back(arr[i]);
    }
    if( j < R ) {
      arr[j].ans+=bt->query(arr[j].w);
      temp.push_back(arr[j]);
      j++;
    }
  }
  for( int i=L ; i < mid ; i++ ) 
    bt->update(arr[i].w,-arr[i].cnt);
  copy(temp.begin(),temp.end(),arr.begin()+L);
}
signed main()
{
  cin>>n>>k;
  map<tuple<int,int,int>,int> mp;
  vector<int> res(n,0);
  vector<triple> arr;
  bt=new BIT(k+1);
  for( int i=0 ; i < n ; i++ ) {
      int x, y, z;
      cin>>x>>y>>z;
      mp[{x,y,z}]++;
  }
  for( auto t : mp ) 
    arr.push_back({get<0>(t.first),get<1>(t.first),get<2>(t.first),0,t.second});
  cdq(0,arr.size(),arr);
  for( auto &[x,y,z,a,b] : arr ) res[a+b-1]+=b;
  for( int i : res ) cout<<i<<'\n';
}