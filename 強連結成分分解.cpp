/*



//���A����������
//���݂��s�����ł���O���[�v����(UnionFind�̐���������type)//�a�{���ǔ�(287p)
struct SCC{
	vector<bool> used; // 1��ڂ̌������ǂ���
	vector<vector<int>>G;//�O���t�̗אڃ��X�g�\��
	vector<vector<int>>rG;//�ӂ̌������t�ɂ����O���t
	vector<int>vs;//�A�肪���̏�
	vector<int>cmp;//DAG�̔ԍ��t��
	int V;//���_��
	int K;
	map<ll, ll>cmpM;
	SCC(int N) : used(N),G(N),rG(N),vs(N),cmp(N) { //���_��N
		V = N;
		K = 0;
	}
	void add_edge(int from, int to) {//from��to
		G[from].push_back(to);
		rG[to].push_back(from);
	}

	void dfs(int v) {//��x�ڂ�dfs
		used[v] = true;
		for (auto i : G[v]) {
			if (!used[i])dfs(i);
		}
		vs.push_back(v);
	}
	void rdfs(int v, int k) {//��x�ڂ�dfs
		used[v] = true;
		cmp[v] = k;
		cmpM[k]++;
		for (auto i : rG[v]) {
			if (!used[i])rdfs(i, k);
		}
	}
	void scc() {
		fill(used.begin(), used.end(), false);
		vs.clear();
		rep(v, V) {
			if (!used[v])dfs(v);
		}
		fill(used.begin(), used.end(), false);
		int k = 0;
		for (int i = vs.size() - 1; i >= 0; i--) {
			if (!used[vs[i]])rdfs(vs[i], k++);
		}
		K = k;
	}

	int DAGnnum(int n) {//�ԍ�n��DAG��Ɋ܂܂�钸�_�̐�
		return cmpM[n];
	}

	ll tenkei90() {
		ll ret = 0;
		for(int i=0;i<=K;i++) {
			ll tmp=DAGnnum(i);
			ret += tmp * (tmp-1) / 2;

		}
		return ret;
	}

};







*/