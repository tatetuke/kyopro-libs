
/*
*行列累乗ーex)フィボナッチ数列を高速に解く
https://pione.hatenablog.com/entry/2021/04/04/231809

#define vvl vector<vector<ll>>

/// 行列積
vvl mat_mul(vvl& a, vvl& b) {
    vvl res(a.size(), vector<ll>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                (res[i][j] += a[i][k] * b[k][j]) %= MOD;
            }
        }
    }
    return res;
}

/// 行列累乗
vvl mat_pow(vvl a, long long n) {
    vvl res(a.size(), vector<ll>(a.size()));
    // 単位行列で初期化
    for (int i = 0; i < a.size(); i++)
        res[i][i] = 1;
    // 繰り返し二乗法
    while (n > 0) {
        if (n & 1) res = mat_mul(a, res);
        a = mat_mul(a, a);
        n >>= 1;
    }
    return res;
}

*/