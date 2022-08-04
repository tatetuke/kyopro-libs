/*
�Z�O�����g�؁�ACL���g����
�������t�@�����X
https://atcoder.github.io/ac-library/production/document_ja/segtree.html

�x���Z�O�����g�؁�ACL���g����
�`�[�g�V�[�g
https://betrue12.hateblo.jp/entry/2020/09/23/005940
���
https://betrue12.hateblo.jp/entry/2020/09/22/194541
�������t�@�����X
https://atcoder.github.io/ac-library/document_ja/lazysegtree.html




//mapping��composition�ɂ���
���I�ɍP���ʑ��Ƃ��Ĉ����l�� ID �Ƃ��܂��B���̂Ƃ��ʑ��������֐��ł��� mapping �� composition �͂��ꂼ��ȉ��̂悤�ɂȂ�܂��B

S mapping(F f, S x)�Ff �� ID �Ȃ�΂��̂܂� x ��Ԃ��B�����łȂ���΋�ԓ��̒l�S�Ă� f �ɕύX����̂ŁAx.value = x.size * f �Ƃ���B
F composition(F f, F g)�Ff �� ID �Ȃ�΂��̂܂� g ��Ԃ��B�����łȂ���΁A�ォ��̑���ŏ㏑�������̂� f ��Ԃ��B









////���/////////
�x���Z�O�����g��
https://algo-logic.info/segment-tree/
RMQ�F[0,n-1] �ɂ��āA��Ԃ��Ƃ̍ŏ��l���Ǘ�����\����
    update(i,x): i �Ԗڂ̗v�f�� x �ɍX�V�BO(log(n))
    query(a,b): [a,b) �ł̍ŏ��̗v�f���擾�BO(log(n))

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
    if (lazy[k] == INF) return;  // �X�V������̂�������ΏI��
    if (k < n - 1) {             // �t�łȂ���Ύq�ɓ`��
        lazy[k * 2 + 1] = lazy[k];
        lazy[k * 2 + 2] = lazy[k];
    }
    // ���g���X�V
    dat[k] = lazy[k];
    lazy[k] = INF;
}
void update(int a, int b, T x, int k, int l, int r) {
    eval(k);
    if (a <= l && r <= b) {  // ���S�ɓ����̎�
        lazy[k] = x;
        eval(k);
    }
    else if (a < r && l < b) {                     // �ꕔ��Ԃ���鎞
        update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // ���̎q
        update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // �E�̎q
        dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}
void update(int a, int b, T x) { update(a, b, x, 0, 0, n); }
T query_sub(int a, int b, int k, int l, int r) {
    eval(k);
    if (r <= a || b <= l) {  // ���S�ɊO���̎�
        return INF;
    }
    else if (a <= l && r <= b) {  // ���S�ɓ����̎�
        return dat[k];
    }
    else {  // �ꕔ��Ԃ���鎞
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



//�Z�O�����g��1�C
template <typename T>
struct RMQ {
	const T INF = numeric_limits<T>::max();
	int n;         // �t�̐�
	vector<T> dat; // ���S�񕪖؂̔z��
	RMQ(int n_) : n(), dat(n_ * 4, 0) { // �t�̐��� 2^x �̌`
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
		if (r <= a || b <= l) {//��O����(�P�ʌ���Ԃ�a*e=a)
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
�Z�O�����g��(gcd)�ő���񐔂̒P�ʌ���0�D0�͂��ׂĂ̐��̖�?
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


st.get(0, i)//(0�`i-1�܂ł�gcd)


*/