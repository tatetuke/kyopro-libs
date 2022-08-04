
/*
*�s��ݏ�[ex)�t�B�{�i�b�`����������ɉ���
https://pione.hatenablog.com/entry/2021/04/04/231809

#define vvl vector<vector<ll>>

/// �s���
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

/// �s��ݏ�
vvl mat_pow(vvl a, long long n) {
    vvl res(a.size(), vector<ll>(a.size()));
    // �P�ʍs��ŏ�����
    for (int i = 0; i < a.size(); i++)
        res[i][i] = 1;
    // �J��Ԃ����@
    while (n > 0) {
        if (n & 1) res = mat_mul(a, res);
        a = mat_mul(a, a);
        n >>= 1;
    }
    return res;
}

*/