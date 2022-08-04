/*
* 
高速なpow計算
//オーバーフロー対策版
ll modpow(ll x, ll n, ll m) {
    if (n == 0)
        return 1;
    x %= m;
    if (n % 2 == 0)
        return modpow(x * x % m, n / 2, m);
    else
        return x * modpow(x, n - 1, m) % m;
}

https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#3-%E5%89%B2%E3%82%8A%E7%AE%97-a--b
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}




高速な逆元計算
フェルマーの小定理によるものa^mod-2
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

ユークリッドの互除法によるもの
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}






*/