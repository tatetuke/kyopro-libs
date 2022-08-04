/*
* 
* 
//コンビネーション
const int MAX = 510000;


long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}



//パスカルの三角形を利用したMODを使わないnCk
// Combination Table
ll C[51][51]; // C[n][k] -> nCk

void comb_table(int N) {
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 or j == i) {
                C[i][j] = 1LL;
            }
            else {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
            }
        }
    }
}




*/