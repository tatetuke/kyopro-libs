/*
ax=b(mod M)
https://drken1215.hatenablog.com/entry/2020/12/20/015100


���[�N���b�h�̌ݏ��@�A�g�����[�N���b�h�̌ݏ��@
https://qiita.com/drken/items/b97ff231e43bce50199a
�g�����[�N���b�h�̌ݏ��@
ax+by=gcd(a,b)�𖞂��� (x,y) �̈�����߂�A���S���Y��

// �Ԃ�l: a �� b �̍ő����
// ax + by = gcd(a, b) �𖞂��� (x, y) ���i�[�����
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




������]�藝(CRT)
x��b1	(mod m1)
x��b2	(mod m2)
...
x��bN	(mod mN)
�𖞂���x�����߂�B���̂悤��x��0�ȏ�lcm(m1xm2x...xmN)�ȉ��ɕK����܂܂��B

https://qiita.com/drken/items/ae02240cd1f8edfc86fd
2
https://scrapbox.io/pocala-kyopro/%E4%B8%AD%E5%9B%BD%E5%89%B0%E4%BD%99%E5%AE%9A%E7%90%86
��̍��������ЂƂɂ܂Ƃ߂�
m1 �� m2 ���݂��ɑf�Ȑ��̐����Ƃ���B

x��b1 (mod.m1)
x��b2 (mod.m2)
�𖞂������� x �� 0 �ȏ� m1*m2 �����ɂ��� 1 ���݂���B���ɂ����r�Ƃ����
x��r (mod.m1m2)



struct ES {//�G���g�X�e�l�X���
	vector<ll>e;//N�܂ł̑f��
	vector<bool>check;//�f���Ȃ�true;
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


nCk�����߂�B
https://algo-logic.info/combination/
���Ғl�̌v�Z
https://drken1215.hatenablog.com/entry/2019/03/23/214500

*/