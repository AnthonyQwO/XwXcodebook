#define lowbit(x) (x&-x)
struct BIT {
    int n;
    vector<int> bit;
    BIT(int _n):n(_n), bit(_n + 1), C(_n + 1) {}
    void update(int x, int val) {
        for(; x <= n; x += lowbit(x)) bit[x] += val;
    }
    void update(int L, int R, int val) {
        update(L, val), update(R + 1, -val);        
    }
    int query(int x) {
        int res = 0;
        for(; x; x -= lowbit(x)) res += bit[x];
        return res;
    }
    int query(int L, int R) {
        return query(R) - query(L - 1);
    }
    int getmax(int l, int r) {
        int ans = 0;
        while(l <= r) {
            ans = max(ans, bit[r--]);
            for (; l <= r - lowbit(r); r -= lowbit(r)) ans = max(ans, C[r]);
        }
        return ans;
    }
    int kth(int k) {
        int sum = 0, x = 0;
        for (int i = __lg(n); ~i; i--) {
            x += 1 << i;
            if (x >= n || sum + bit[x] >= k) x -= 1 << i;
            else sum += bit[x];
        }
        return x + 1;
    }
};
