//矩陣乘法
for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
            ret[i][j] += a[i][k] * b[k][j];
        }
    }
}
//矩陣快速冪
int base[2][2] = {   int ans[2][2] = {
  {1, 1},              {1, 0},
  {1, 0}               {0, 1}
};                   };
                         
int mypow(int y){
  while(y){
    if( y&1 ) { ans = mul(ans, base); } //實作矩陣乘法
    base = mul(base, base);//實作矩陣乘法
    y >>= 1;
  }
  return ans[0][0];    
}