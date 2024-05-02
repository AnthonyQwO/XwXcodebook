// 1-based
// n is the number of patterns
struct Automaton {
    static const int MXN = 1e6;
    int n, cnt, vis[MXN], rev[MXN], indeg[MXN], ans[MXN];
    queue<int> q;
    struct trie_node {
        vector<int> son;
        int fail, flag, ans;
        trie_node(): son(27), fail(0), flag(0) {}
    } trie[MXN];
    void init(int _n) {
        n = _n, cnt = 1;
        for (int i = 1; i <= n; i++) vis[i] = 0;
    }
    // insert a string s with number num
    // num is the index of the pattern
    void insert(string s, int num) {
        int u = 1, len = s.size();
        for (int i = 0; i < len; i++) {
            int v = s[i] - 'a';
            if (!trie[u].son[v]) trie[u].son[v] = ++cnt;
            u = trie[u].son[v];
        }
        if (!trie[u].flag) trie[u].flag = num;
        rev[num] = trie[u].flag;
    }
    void getfail() {
        for (int i = 0; i < 26; i++) trie[0].son[i] = 1;
        q.push(1);
        trie[1].fail = 0;
        while (q.size()) {
            int u = q.front(); q.pop();
            int Fail = trie[u].fail;
            for (int i = 0; i < 26; i++) {
                int v = trie[u].son[i];
                if (!v) {
                    trie[u].son[i] = trie[Fail].son[i];
                    continue;
                }
                trie[v].fail = trie[Fail].son[i];
                indeg[trie[Fail].son[i]]++;
                q.push(v);
            }
        }
    }
    void topu() {
        for (int i = 1; i <= cnt; i++)
            if (!indeg[i]) q.push(i);
        while (q.size()) {
            int fr = q.front(); q.pop();
            vis[trie[fr].flag] = trie[fr].ans;
            int u = trie[fr].fail;
            trie[u].ans += trie[fr].ans;
            if (!--indeg[u]) q.push(u);
        }
    }
    void query(string &s) {
        int u = 1, len = s.size();
        for (int i = 0; i < len; i++) u = trie[u].son[s[i] - 'a'], trie[u].ans++;
    }
    void solve(string &s) {
        getfail();
        query(s);
        topu();
        for (int i = 1; i <= n; i++) ans[i] = vis[rev[i]];
    }
} AC;