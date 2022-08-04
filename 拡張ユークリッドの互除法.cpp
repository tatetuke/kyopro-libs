/*


ax=b(mod M)
https://drken1215.hatenablog.com/entry/2020/12/20/015100


ユークリッドの互除法、拡張ユークリッドの互除法
https://qiita.com/drken/items/b97ff231e43bce50199a
https://qiita.com/drken/items/b97ff231e43bce50199a#3-4-%E6%8B%A1%E5%BC%B5%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95%E3%81%AE%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E7%9A%84%E8%A8%98%E8%BF%B0
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



拡張ユークリッドの互除法（高校数学レベル）
ax+by=gcd(a,b)を満たす (x,y) の一つを求めるアルゴリズム
一次不定方程式ax+by=cの整数解の一つを求めるアルゴリズム

・すべての解を求める時
※A,Bはa,bをgcd(a,b)で割ったもの.
※x1,y1は一時不定方程式を満たす解の一つ
x=Bt+x1
y=-At+y1

解の一つを(x1,y1)とする
ax+by=c
ax1+by1=c
a(x-x1)=-b(y-y1)
a,bをgcd(a,b)で割ったものをA,B
A(x-x1)=-B(y-y1)
x=Bt+x1
y=-At+y1







*/