/*
–¢ŒŸØ
ˆø—pŒ³
https://atcoder.jp/contests/abc165/submissions/12625799
–â‘èW
https://blog.hamayanhamayan.com/entry/2017/05/21/001252


typedef int V;
// NV=3010101 -> 38MB
#define NV 6010101
#define def 0
struct PersistentSegmentTree { //[L,R)
	V comp(V a, V b) { return max(a, b); }




	// -- template ---------------------
	struct S { int l, r; V x; } v[NV];
	int cnt = 1, n = -1;
	void init(int _n) { n = _n; rep(i, 0, NV) v[i].l = v[i].r = 0, v[i].x = def; }
	void add(int& root, int l, int r, int i, int val) {
		v[cnt] = v[root]; root = cnt++; if (l + 1 == r) { v[root].x += val; return; }
		int mi = (l + r) / 2; if (i < mi) add(v[root].l, l, mi, i, val);
		else add(v[root].r, mi, r, i, val);
		v[root].x = comp(v[v[root].l].x, v[v[root].r].x);
	}
	void add(int& root, int i, int val) { assert(0 < n); add(root, 0, n, i, val); }
	void update(int& root, int l, int r, int i, int val) {
		v[cnt] = v[root]; root = cnt++;
		if (l + 1 == r) { v[root].x = val; return; }int mi = (l + r) / 2;
		if (i < mi) update(v[root].l, l, mi, i, val); else update(v[root].r, mi, r, i, val);
		v[root].x = comp(v[v[root].l].x, v[v[root].r].x);
	}
	void update(int& root, int i, int val) { assert(0 < n); update(root, 0, n, i, val); }
	V allget(int root) { assert(0 < n); return v[root].x; }
	V get(int root, int l, int r, int L, int R) {
		if (l >= r) return def; if (l == L && r == R) return v[root].x; int mi = (L + R) / 2;
		V le = get(v[root].l, max(l, L), min(r, mi), L, mi);
		V ri = get(v[root].r, max(l, mi), min(r, R), mi, R); return comp(le, ri);
	}
	V get(int root, int l, int r) { assert(0 < n); return get(root, l, r, 0, n); }
};


*/