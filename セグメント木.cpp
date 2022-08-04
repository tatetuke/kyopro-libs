/*
セグメント木→ACLを使おう
公式リファレンス
https://atcoder.github.io/ac-library/production/document_ja/segtree.html

遅延セグメント木→ACLを使おう
チートシート
https://betrue12.hateblo.jp/entry/2020/09/23/005940
解説
https://betrue12.hateblo.jp/entry/2020/09/22/194541
公式リファレンス
https://atcoder.github.io/ac-library/document_ja/lazysegtree.html




//mappingとcompositionについて
似的に恒等写像として扱う値を ID とします。このとき写像を扱う関数である mapping と composition はそれぞれ以下のようになります。

S mapping(F f, S x)：f が ID ならばそのまま x を返す。そうでなければ区間内の値全てを f に変更するので、x.value = x.size * f とする。
F composition(F f, F g)：f が ID ならばそのまま g を返す。そうでなければ、後からの操作で上書きされるので f を返す。









////墓場/////////
遅延セグメント木
https://algo-logic.info/segment-tree/
RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))

template <typename T>
struct RMQ {
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat, lazy;
    RMQ(int n_) : n(), dat(n_ * 4, INF), lazy(n_ * 4, INF) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }
    // lazy eval
void eval(int k) {
    if (lazy[k] == INF) return;  // 更新するものが無ければ終了
    if (k < n - 1) {             // 葉でなければ子に伝搬
        lazy[k * 2 + 1] = lazy[k];
        lazy[k * 2 + 2] = lazy[k];
    }
    // 自身を更新
    dat[k] = lazy[k];
    lazy[k] = INF;
}
void update(int a, int b, T x, int k, int l, int r) {
    eval(k);
    if (a <= l && r <= b) {  // 完全に内側の時
        lazy[k] = x;
        eval(k);
    }
    else if (a < r && l < b) {                     // 一部区間が被る時
        update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
        update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
        dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}
void update(int a, int b, T x) { update(a, b, x, 0, 0, n); }
T query_sub(int a, int b, int k, int l, int r) {
    eval(k);
    if (r <= a || b <= l) {  // 完全に外側の時
        return INF;
    }
    else if (a <= l && r <= b) {  // 完全に内側の時
        return dat[k];
    }
    else {  // 一部区間が被る時
        T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
}
T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
//debug
inline T operator[](int a) { return query(a, a + 1); }
void print() {
    for (int i = 0; i < 2 * n - 1; ++i) {
        cout << (*this)[i];
        if (i != n) cout << ",";
    }
    cout << endl;
}
};



//セグメント木1，
template <typename T>
struct RMQ {
	const T INF = numeric_limits<T>::max();
	int n;         // 葉の数
	vector<T> dat; // 完全二分木の配列
	RMQ(int n_) : n(), dat(n_ * 4, 0) { // 葉の数は 2^x の形
		int x = 1;
		while (n_ > x) {
			x *= 2;
		}
		n = x;
	}
	void update(int i, T x) {
		i += n - 1;
		dat[i] = x;
		while (i > 0) {
			i = (i - 1) / 2;  
			// parent
			//----------
			//|        |
			//c(i*2+1) c(i*2+2)
			dat[i] = dat[i * 2 + 1]|dat[i * 2 + 2];
		}
	}
	// element of [a,b)
	T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
	T query_sub(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) {//例外処理(単位元を返すa*e=a)
			return 0;
		}
		else if (a <= l && r <= b) {
			return dat[k];
		}
		else {
			T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
			T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
			return vl|vr;
		}
	}
};













https://atcoder.jp/contests/abc125/submissions/5169320
セグメント木(gcd)最大公約数の単位元は0．0はすべての数の約数?
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
#define def 0
template<class V, int NV> struct SegTree { //[l,r)
    V comp(V& l, V& r) { return gcd(l, r); };

    vector<V> val; SegTree() { val = vector<V>(NV * 2, def); }
    V get(int x, int y, int l = 0, int r = NV, int k = 1) {
        if (r <= x || y <= l)return def; if (x <= l && r <= y)return val[k];
        auto a = get(x, y, l, (l + r) / 2, k * 2);
        auto b = get(x, y, (l + r) / 2, r, k * 2 + 1);
        return comp(a, b);
    }
    void update(int i, V v) {
        i += NV; val[i] = v;
        while (i>1) i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]);
    }
    void add(int i, V v) { update(i, val[i + NV] + v); }
    V operator[](int x) { return get(x, x + 1); }
};
SegTree<int, 1 << 17> st;


st.get(0, i)//(0～i-1までのgcd)


*/