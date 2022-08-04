/*



//強連結成分分解
//お互い行き来できるグループ分け(UnionFindの制限が強いtype)//蟻本改良版(287p)
struct SCC{
	vector<bool> used; // 1回目の見たかどうか
	vector<vector<int>>G;//グラフの隣接リスト表現
	vector<vector<int>>rG;//辺の向きを逆にしたグラフ
	vector<int>vs;//帰りがけの順
	vector<int>cmp;//DAGの番号付け
	int V;//頂点数
	int K;
	map<ll, ll>cmpM;
	SCC(int N) : used(N),G(N),rG(N),vs(N),cmp(N) { //頂点数N
		V = N;
		K = 0;
	}
	void add_edge(int from, int to) {//from→to
		G[from].push_back(to);
		rG[to].push_back(from);
	}

	void dfs(int v) {//一度目のdfs
		used[v] = true;
		for (auto i : G[v]) {
			if (!used[i])dfs(i);
		}
		vs.push_back(v);
	}
	void rdfs(int v, int k) {//二度目のdfs
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

	int DAGnnum(int n) {//番号nのDAG上に含まれる頂点の数
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