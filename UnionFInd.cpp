/*
ACLリファレンス
https://atcoder.github.io/ac-library/production/document_ja/dsu.html

UnionFind
https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396
struct UnionFind {
	vector<ll> d; // d[i]:iの親の番号　(例) d[3] = 2 : 3の親が2 d[3] = -3 : 3は根で、その連結成分のサイズは3

	UnionFind(ll N) : d(N, -1) {} // 負なら根である 非負なら子である

	ll root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
		if (d[x] < 0) return x; //負なら根であるから根を返す
		return d[x] = root(d[x]);
	}

	bool unite(ll x, ll y) { // xとyの木を併合
		ll rx = root(x); //xの根をrx
		ll ry = root(y); //yの根をry
		if (rx == ry) return false; //xとyの根が同じ(=同じ木にある)時はそのまま
		if (d[rx] > d[ry])swap(rx, ry); //木のサイズが大きいほうにくっつける
		d[rx] += d[ry]; //サイズが上乗せされる
		d[ry] = rx; //yの根はxになる
		return true;
	}

	bool same(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
		ll rx = root(x);
		ll ry = root(y);
		return rx == ry;
	}
	ll size(ll x) {
		return -d[root(x)];
	}
};




*/