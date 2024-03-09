編譯參數：-std=c++14 -Wall -Wshadow (-fsanitize=undefined)

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int randint(int lb, int ub)
{ return uniform_int_distribution<int>(lb, ub)(gen); }

#define SECs ((double)clock() / CLOCKS_PER_SEC)
double startTime;
bool TIME() { // 比最大可執行時間小一點
    return SECs - startTime > 0.8;
}
int main() {
    startTime = SECs;
}

struct KeyHasher {
	size_t operator()(const Key& k) const {
		return k.first + k.second * 100000;
}	};
typedef unordered_map<Key,int,KeyHasher> map_t;
// builtin function 可以代的值為int32
__builtin_popcountll    // 二進位有幾個1
__builtin_clzll         // 左起第一個1之前0的個數
__builtin_parityll      // 1的個數的奇偶性
__builtin_mul_overflow(a,b,&h) // a*b是否溢位
