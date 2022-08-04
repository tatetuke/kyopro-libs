/*









:����Z�[���X�}�����
https://algo-logic.info/bit-dp/

�a�{173p

ll max_N=17;
vector<vector<ll>>d(max_N, vector<ll>(max_N));
vector<vector<ll>>dp(1<<max_N, vector<ll>(max_N));
ll n;//���񂷂钸�_��
void solve() {
	for (ll S = 0; S < 1 << n; S++) {
		fill(dp[S].begin(), dp[S].begin() + n, inf);

	}
	dp[(1 << n) - 1][0] = 0;
	for (ll S = (1 << n) - 2; S >= 0; S--) {
		for (int v = 0; v < n; v++) {
			for (int u = 0; u < n; u++) {
				if (!(S >> u & 1)) {
					dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + d[v][u]);
				}
			}
		}
	}
}


����Z�[���X�}��(�o�H����)
struct TSPV {
	ll cost; ll p;//p=�e,�o�H�����p

};
ll max_N=17;
vector<vector<ll>>d(max_N, vector<ll>(max_N));
vector<vector<TSPV>>dp(1 << max_N, vector<TSPV>(max_N));
ll n;//���񂷂钸�_��
void solve() {
	for (ll S = 0; S < 1 << n; S++) {
		for (int i = 0; i < dp[S].size(); i++) {
			dp[S][i].cost = inf;
			dp[S][i].p = -1;


		}

	}
	dp[(1 << n) - 1][0].cost = 0;
	for (ll S = (1 << n) - 2; S >= 0; S--) {
		for (int v = 0; v < n; v++) {
			for (int u = 0; u < n; u++) {
				if (!(S >> u & 1)) {
					if (dp[S][v].cost > dp[S | 1 << u][u].cost + d[v][u]) {
						dp[S][v].cost = dp[S | 1 << u][u].cost + d[v][u];
						dp[S][v].p = u;

					}

				}
			}
		}
	}
};

//�o�H����(pv{from,to})
ll S = 0;
	vector<pair<ll, ll>>pv;
	ll e=0;
	while (dp[S][e].p != -1) {
		pv.push_back({ e,dp[S][e].p });
		cout << dp[S][e].p << endl;
		e =dp[S][e].p;
		S |= 1<<e;

	}





*/