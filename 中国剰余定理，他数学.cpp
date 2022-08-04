/*
ax=b(mod M)
https://drken1215.hatenablog.com/entry/2020/12/20/015100


ユークリッドの互除法、拡張ユークリッドの互除法
https://qiita.com/drken/items/b97ff231e43bce50199a
拡張ユークリッドの互除法
ax+by=gcd(a,b)を満たす (x,y) の一つを求めるアルゴリズム

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}




中国剰余定理(CRT)
x≡b1	(mod m1)
x≡b2	(mod m2)
...
x≡bN	(mod mN)
を満たすxを求める。そのようなxは0以上lcm(m1xm2x...xmN)以下に必ず一つ含まれる。

https://qiita.com/drken/items/ae02240cd1f8edfc86fd
2
https://scrapbox.io/pocala-kyopro/%E4%B8%AD%E5%9B%BD%E5%89%B0%E4%BD%99%E5%AE%9A%E7%90%86
二つの合同式をひとつにまとめる
m1 と m2 を互いに素な正の整数とする。

x≡b1 (mod.m1)
x≡b2 (mod.m2)
を満たす整数 x が 0 以上 m1*m2 未満にただ 1 つ存在する。特にそれをrとすると
x≡r (mod.m1m2)



struct ES {//エラトステネスの篩
	vector<ll>e;//Nまでの素数
	vector<bool>check;//素数ならtrue;
	ll N;
	ES(ll n):check(n+1,true) {
		N = n;
	}
	void es(){
		for (ll i = 2; i <= N; i++) {
			if (!check[i])continue;
			for (ll j = i * 2; j <= N; j+=i ) {
				check[j] = false;
			}
		}
		for (ll i = 2; i <= N; i++) {
			if (!check[i])continue;
			e.push_back(i);
		}
	}
};


nCkを求める。
https://algo-logic.info/combination/
期待値の計算
https://drken1215.hatenablog.com/entry/2019/03/23/214500

*/