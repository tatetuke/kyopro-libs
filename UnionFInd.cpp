/*
ACL���t�@�����X
https://atcoder.github.io/ac-library/production/document_ja/dsu.html

UnionFind
https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396
struct UnionFind {
	vector<ll> d; // d[i]:i�̐e�̔ԍ��@(��) d[3] = 2 : 3�̐e��2 d[3] = -3 : 3�͍��ŁA���̘A�������̃T�C�Y��3

	UnionFind(ll N) : d(N, -1) {} // ���Ȃ獪�ł��� �񕉂Ȃ�q�ł���

	ll root(ll x) { // �f�[�^x��������؂̍����ċA�œ���Froot(x) = {x�̖؂̍�}
		if (d[x] < 0) return x; //���Ȃ獪�ł��邩�獪��Ԃ�
		return d[x] = root(d[x]);
	}

	bool unite(ll x, ll y) { // x��y�̖؂𕹍�
		ll rx = root(x); //x�̍���rx
		ll ry = root(y); //y�̍���ry
		if (rx == ry) return false; //x��y�̍�������(=�����؂ɂ���)���͂��̂܂�
		if (d[rx] > d[ry])swap(rx, ry); //�؂̃T�C�Y���傫���ق��ɂ�������
		d[rx] += d[ry]; //�T�C�Y����悹�����
		d[ry] = rx; //y�̍���x�ɂȂ�
		return true;
	}

	bool same(ll x, ll y) { // 2�̃f�[�^x, y��������؂������Ȃ�true��Ԃ�
		ll rx = root(x);
		ll ry = root(y);
		return rx == ry;
	}
	ll size(ll x) {
		return -d[root(x)];
	}
};




*/